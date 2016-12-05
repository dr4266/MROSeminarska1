#ifndef MMCQUEUE_H_
#define MMCQUEUE_H_

#include <omnetpp.h>
#include <string.h>

using namespace omnetpp;

class mmcQueue : public cSimpleModule{
private:
	cQueue queue;
	//cMessage *endServiceMsg;
	int capacity;
	int length;
	int resources;
	int processing;
	simtime_t serviceTime;

	// statistics
	simsignal_t droppedSignal;
	simsignal_t waitTimeSignal;
	simsignal_t job1Signal;
	simsignal_t job2Signal;
	simsignal_t job3Signal;
	simsignal_t job4Signal;
	simsignal_t job5Signal;
	simsignal_t job6Signal;
	simsignal_t job7Signal;
	simsignal_t job8Signal;
	simsignal_t job9Signal;
	simsignal_t job10Signal;
	int primer;

	typedef std::list<cMessage *> jobsProcessingList;
	jobsProcessingList jobsProcessing;

public:
	mmcQueue();
	virtual ~mmcQueue();
	CompareFunc compareMSG;

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void updateDisplay(int i, int p, int r);
};



#endif /* MMCQUEUE_H_ */
