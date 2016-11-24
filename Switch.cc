#include <omnetpp.h>
#include <mm1Queue.h>
#include <Switch.h>

using namespace omnetpp;

Define_Module(Switch);

void Switch::initialize()
{
    numGates = gateSize("out");
}

void Switch::handleMessage(cMessage *msg)
{
    if (numGates > 1) {
        mm1Queue *mm11 = (mm1Queue *)(gate(2621440)->getNextGate()->getOwner());
        mm1Queue *mm12 = (mm1Queue *)(gate(2621441)->getNextGate()->getOwner());
        mm1Queue *mm13 = (mm1Queue *)(gate(2621442)->getNextGate()->getOwner());

        int lengths[3];
        int capacities[3];
        // Poracunaj kapacitete in trenutno zasedenost
        lengths[0] = mm11->getLength();
        lengths[1] = mm12->getLength();
        lengths[2] = mm13->getLength();
        capacities[0] = mm11->getCapacity();
        capacities[1] = mm12->getCapacity();
        capacities[2] = mm13->getCapacity();

        // Najdi najmanj zaseden MM1 in mu poslji msg
        int most_free_space = capacities[0] - lengths[0];
        int gate = 0;
        for (int i=1; i<3; i++) {
            if (capacities[i] - lengths[i] > most_free_space) {
                most_free_space = capacities[i] - lengths[i];
                gate = i;
            }
        }
        send(msg, "out", gate);

    } else {
        // Samo en izhod (Switch pred MMC)
        send(msg, "out", 0);
    }
}

