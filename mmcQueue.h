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
