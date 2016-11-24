#include <omnetpp.h>
#include <mm1Queue.h>
#include <Switch.h>
#include <string.h>

using namespace omnetpp;

Define_Module(Switch);

void Switch::initialize()
{
    numGates = gateSize("out");
    switchMode = par("mode");
}

void Switch::handleMessage(cMessage *msg)
{
    // vec izhodov -> switch1
    if (numGates > 1) {
        if (switchMode == 0) {
            // nakljucno posiljanje paketov
            int gate = intuniform(0, numGates-1);
            send(msg, "out", gate);
        } else {
            // uporabi least busy queue first
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
            int zasedenost = lengths[0];
            int gate = 0;
            for (int i=1; i<3; i++) {
                if (lengths[i] < zasedenost && capacities[i] - lengths[i]  > 0) {
                    zasedenost = lengths[i];
                    gate = i;
                }
            }
            send(msg, "out", gate);
        }
    } else {
        // Samo en izhod (Switch pred MMC)
        send(msg, "out", 0);
    }
}

