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

package seminarska1;

simple mySource
{
    parameters:
        @display("i=block/source");
        int maxJobs = default(100);
        int numJobs = default(2);               // number of jobs to be generated (-1 means no limit)
        double mean @unit(s) = default(uniform(0.1s, 0.8s));
        double stdev @unit(s) = default(mean/2);
        volatile double interArrivalTime @unit(s) = default(truncnormal(mean, stdev)); // time between generated jobs
        double startTime @unit(s) = default(10 s); // when the module sends out the first job
        double stopTime @unit(s) = default(50000s); // when the module stops the job generation (-1 means no limit)
 
        
    gates:
        output out;
}
