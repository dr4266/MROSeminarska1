//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "mySource.h"

Define_Module(mySource);
using namespace omnetpp;

mySource::mySource() {
	generateJobMsg = NULL;
}

mySource::~mySource() {
	cancelAndDelete(generateJobMsg);
}

void mySource::initialize()
{
	generateJobMsg = new cMessage("generate");
	startTime = par("startTime");	// zacetek generiranja
    stopTime = par("stopTime");		// konec generiranja
    numJobs = par("numJobs");		// koliko se jih zgenerira naenkrat
    maxJobs = par("maxJobs");		// maksimalno stevilo zgeneriranih

    jobCounter = 0;

    scheduleAt(startTime, generateJobMsg);
}

void mySource::handleMessage(cMessage *msg)
{
    if (msg == generateJobMsg)
    {
    	if ((maxJobs < 0 || maxJobs > jobCounter) && (stopTime < 0 || stopTime > simTime()))
    	{
    		scheduleAt(simTime() + par("interArrivalTime").doubleValue(), msg);

    		for (int i=0; i<numJobs; i++)
			{
				cMessage *job = new cMessage();
				job->setKind(0);
				int random_priority = rand() % 10 + 1;
				job->setSchedulingPriority(random_priority);
				send(job, "out");
				jobCounter++;
			}
			updateDisplay(jobCounter);
		}
		else
		{
			delete msg;
		}
    }
}

void mySource::updateDisplay(int i)
{
    char buf[10];
    sprintf(buf, "%ld", (long) i);
    getDisplayString().setTagArg("t",0,buf);
}
