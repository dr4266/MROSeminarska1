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

network SJF
{
    @display("bgb=825,395");
    types:
    submodules:
        source: mySource {
            @display("p=124,183");
        }
        sink: mySink {
            @display("p=716,183");
        }
        MM11: mm1Queue {
            @display("p=333,87");
        }
        MM12: mm1Queue {
            @display("p=333,184");
        }
        MM13: mm1Queue {
            @display("p=333,297");
        }
        switch: Switch {
            @display("p=224,184");
        }
        switch1: Switch {
            @display("p=448,183");
        }
        MMC: mmcQueue {
            @display("p=583,184");
        }
    connections:
        switch.out++ --> MM11.in++;
        switch.out++ --> MM12.in++;
        switch.out++ --> MM13.in++;
        source.out --> switch.in++;
        MM12.out --> switch1.in++;
        MM11.out --> switch1.in++;
        MM13.out --> switch1.in++;
        switch1.out++ --> MMC.in++;
        MMC.out --> sink.in++;
}
