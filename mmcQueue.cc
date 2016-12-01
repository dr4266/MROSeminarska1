#include "mmcQueue.h"

// staticna primerjalna funkcija
static int compare(cMessage* a, cMessage* b) {
    cMessage* job1 = check_and_cast<cMessage *>(a);
    cMessage* job2 = check_and_cast<cMessage *>(b);
    int priority1 = job1->getSchedulingPriority();
    int priority2 = job2->getSchedulingPriority();

    if  (priority1>priority2) {
        return 1;
    } else if (priority1 == priority2) {
        return 0;
    } else {
        return -1;
    }
}

using namespace omnetpp;

Define_Module(mmcQueue);

mmcQueue::mmcQueue() {
	//endServiceMsg = NULL;
}

mmcQueue::~mmcQueue() {

	jobsProcessingList::iterator msg;
	for (msg=jobsProcessing.begin(); msg!=jobsProcessing.end(); msg++)
	{
		cancelAndDelete(*msg);
	}
	jobsProcessing.clear();
}

void mmcQueue::initialize()
{
    capacity = par("capacity");
    serviceTime = par("serviceTime");
    primer = par("primer");

    droppedSignal = registerSignal("dropped");
    waitTimeSignal = registerSignal("waitTime");


    this->compareMSG = (CompareFunc) compare;
    queue.setup( compareMSG );

    queue.setName("queue");
    length = 0;
    resources = par("resources");
    processing = 0;
    jobsProcessing.clear();
    //send out some signals
    emit(droppedSignal, 0);
    emit(waitTimeSignal, (simtime_t)0);
}

void mmcQueue::handleMessage(cMessage *msg)
{
	// The message kind member is not used by OMNeT++, it can be used freely by the user.

	// ali je prislo sporocilo o koncu procesiranja
	if (msg->getKind() == 10)
	{
	    cMessage *job = check_and_cast<cMessage *>(msg);
		jobsProcessingList::iterator msgIterator;
		for (msgIterator=jobsProcessing.begin(); msgIterator!=jobsProcessing.end(); msgIterator++)
		{
			if ((*msgIterator)->getId()==job->getId())
			{
				jobsProcessing.erase(msgIterator);
				processing--;
				break;
			}
		}
		job->setKind(0);
		send(job, "out");
		EV << "MMC: Cas strezbe: " << simTime() - job->getTimestamp() << " s, prioriteta: " << job->getSchedulingPriority() << "\n";


		if (!queue.empty())
        {
        	job = check_and_cast<cMessage *>(queue.pop());
        	job->setKind(10);
        	jobsProcessing.push_back(job);
        	if (primer == 0) {
        	    serviceTime = job->getSchedulingPriority();
        	}
        	scheduleAt( simTime()+serviceTime, job );	// v izvajanje damo novo opravilo, ki se bo izvedlo cez serviceTime casa
        	emit(waitTimeSignal, simTime() - job->getTimestamp()); // emit a wait time signal
        	EV << "MMC: Cakalni cas:" << simTime() - job->getTimestamp() << " s";

        	job->setTimestamp(); // Za merjenje dolzine strezbe
        	processing++;
        	length--;
        }
    }
	// ali je prislo novo opravilo
    else
    {
    	cMessage *job = msg;
    	job->setKind(1);
    	if (processing < resources)
        {
    		processing ++;
    		job->setKind(10);
    		jobsProcessing.push_back(job);
    		if (primer == 0) {
    		    serviceTime = job->getSchedulingPriority();
    		}
    		emit(waitTimeSignal,(simtime_t)0); // Free resources, no waiting for the new msg
    		job->setTimestamp();
    		scheduleAt( simTime()+serviceTime, job );
        }
    	else
        {
            if (capacity >=0 && length >= capacity)
	        {
                // cakalna vrsta je presegla svojo kapaciteto
	            delete job;
	            EV << "Brisem sporocilo";
	            emit(droppedSignal, 1);
	        }
	        else
	        {
	            // vstavi v cakalno vrsto
	            job->setTimestamp();
	            queue.insert( job );
	            length++;
	        }
	    }
	}
	updateDisplay(length, processing, resources);
}

void mmcQueue::updateDisplay(int i, int p, int r)
{
    char buf[30];
    sprintf(buf, "Q_length :%ld, Resources: %ld/%ld", (long) i, (long) p, (long) r);
    getDisplayString().setTagArg("t",0,buf);
}
