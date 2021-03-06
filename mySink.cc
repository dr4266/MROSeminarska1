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

#include "mySink.h"

Define_Module(mySink);

using namespace omnetpp;

void mySink::initialize()
{
	sinked = 0;
}

void mySink::handleMessage(cMessage *msg)
{
	sinked ++;
	delete msg;
	updateDisplay(sinked);
}

void mySink::updateDisplay(int i)
{
    char buf[10];
    sprintf(buf, "%ld", (long) i);
    getDisplayString().setTagArg("t",0,buf);
}
