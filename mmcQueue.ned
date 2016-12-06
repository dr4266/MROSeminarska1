

package seminarska1;

simple mmcQueue
{
   parameters:
        @display("i=block/queue");
        
        int capacity = default(100);   
        int resources = default(2);
        int primer = default(0);
        //Statistics
        @signal[dropped](type=long);
        @signal[waitTime](type=simtime_t);
        @signal[job1] (type=simtime_t);
        @signal[job2] (type=simtime_t);
        @signal[job3] (type=simtime_t);
        @signal[job4] (type=simtime_t);
        @signal[job5] (type=simtime_t);
        @signal[job6] (type=simtime_t);
        @signal[job7] (type=simtime_t);
        @signal[job8] (type=simtime_t);
        @signal[job9] (type=simtime_t);
        @signal[job10] (type=simtime_t);
       	@signal[dropped1](type=long);
        @signal[dropped2](type=long);
        @signal[dropped3](type=long);
        @signal[dropped4](type=long);
        @signal[dropped5](type=long);
        @signal[dropped6](type=long);
        @signal[dropped7](type=long);
        @signal[dropped8](type=long);
        @signal[dropped9](type=long);
        @signal[dropped10](type=long);
        
        @statistic[dropped](title="drop event";record=vector,count;interpolationmode=none);
        @statistic[dropped1](title="drop event; job 1";record=vector,count;interpolationmode=none);
        @statistic[dropped2](title="drop event; job 2";record=vector,count;interpolationmode=none);
        @statistic[dropped3](title="drop event; job 3";record=vector,count;interpolationmode=none);
        @statistic[dropped4](title="drop event; job 4";record=vector,count;interpolationmode=none);
        @statistic[dropped5](title="drop event; job 5";record=vector,count;interpolationmode=none);
        @statistic[dropped6](title="drop event; job 6";record=vector,count;interpolationmode=none);
        @statistic[dropped7](title="drop event; job 7";record=vector,count;interpolationmode=none);
        @statistic[dropped8](title="drop event; job 8";record=vector,count;interpolationmode=none);
        @statistic[dropped9](title="drop event; job 9";record=vector,count;interpolationmode=none);
        @statistic[dropped10](title="drop event; job 10";record=vector,count;interpolationmode=none);
        
        @statistic[waitTime](title="queueing time at dequeue";record=vector,mean,max;unit=s;interpolationmode=none);
        @statistic[job1](title="time in queue; job priority 1";record=vector,mean,max;unit=s;interpolationmode=none);
        @statistic[job2](title="time in queue; job priority 2";record=vector,mean,max;unit=s;interpolationmode=none);
        @statistic[job3](title="time in queue; job priority 3";record=vector,mean,max;unit=s;interpolationmode=none);
        @statistic[job4](title="time in queue; job priority 4";record=vector,mean,max;unit=s;interpolationmode=none);
        @statistic[job5](title="time in queue; job priority 5";record=vector,mean,max;unit=s;interpolationmode=none);
        @statistic[job6](title="time in queue; job priority 6";record=vector,mean,max;unit=s;interpolationmode=none);
        @statistic[job7](title="time in queue; job priority 7";record=vector,mean,max;unit=s;interpolationmode=none);
        @statistic[job8](title="time in queue; job priority 8";record=vector,mean,max;unit=s;interpolationmode=none);
        @statistic[job9](title="time in queue; job priority 9";record=vector,mean,max;unit=s;interpolationmode=none);
        @statistic[job10](title="time in queue; job priority 10";record=vector,mean,max;unit=s;interpolationmode=none);
 
        
        volatile double mean @unit(s) = default(uniform(1s, 2s));
        volatile double stdev @unit(s) = default((mean/2));
        volatile double serviceTime @unit(s) = default(truncnormal(mean, stdev));
      
    gates:
        input in[];
        output out;
}
