#ifndef SWITCH_H_
#define SWITCH_H_

#include <omnetpp.h>

using namespace omnetpp;

class Switch : public cSimpleModule
{
  private:
    int numGates;
    int switchMode;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
#endif /* SWITCH_H_ */
