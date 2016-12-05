

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
        
        @statistic[dropped](title="drop event";record=vector,count;interpolationmode=none);
        @statistic[waitTime](title="queueing time at dequeue";record=vector,mean,max;unit=s;interpolationmode=none);
        @statistic[job1](title="queueing time at dequeue for job with priority 1";record=vector,mean,max;unit=s;interpolationmode=none);
        @statistic[job2](title="queueing time at dequeue for job with priority 2";record=vector,mean,max;unit=s;interpolationmode=none);
        @statistic[job3](title="queueing time at dequeue for job with priority 3";record=vector,mean,max;unit=s;interpolationmode=none);
        @statistic[job4](title="queueing time at dequeue for job with priority 4";record=vector,mean,max;unit=s;interpolationmode=none);
        @statistic[job5](title="queueing time at dequeue for job with priority 5";record=vector,mean,max;unit=s;interpolationmode=none);
        @statistic[job6](title="queueing time at dequeue for job with priority 6";record=vector,mean,max;unit=s;interpolationmode=none);
        @statistic[job7](title="queueing time at dequeue for job with priority 7";record=vector,mean,max;unit=s;interpolationmode=none);
        @statistic[job8](title="queueing time at dequeue for job with priority 8";record=vector,mean,max;unit=s;interpolationmode=none);
        @statistic[job9](title="queueing time at dequeue for job with priority 9";record=vector,mean,max;unit=s;interpolationmode=none);
        @statistic[job10](title="queueing time at dequeue for job with priority 10";record=vector,mean,max;unit=s;interpolationmode=none);
 
        
        volatile double mean @unit(s) = default(uniform(1s, 2s));
        volatile double stdev @unit(s) = default((mean/2));
        volatile double serviceTime @unit(s) = default(truncnormal(mean, stdev));
      
    gates:
        input in[];
        output out;
}
