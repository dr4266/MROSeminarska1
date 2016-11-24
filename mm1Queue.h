

#ifndef MM1QUEUE_H_
#define MM1QUEUE_H_

#include <omnetpp.h>

using namespace omnetpp;

class mm1Queue : public cSimpleModule{
private:
	cQueue queue;					// objekt, ki predstavlja cakalno vrsto
	cMessage *currentJob;			// opravilo, ki se trenutno procesira
    cMessage *endServiceMsg;		// sporocilo, ki ga modul posilja samemu sebi
	int capacity, length;			// capacity = kapaciteta cakalne vrste (parameter), length = trenutna dolzina cakalne vrste
	simtime_t serviceTime;			// cas procesiranja (parameter)

public:
	mm1Queue();
	virtual ~mm1Queue();
	int getLength();
	int getCapacity();

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void updateDisplay(int i);
};
#endif /* MM1QUEUE_H_ */
