

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
        
        @statistic[dropped](title="drop event";record=vector,count;interpolationmode=none);
        @statistic[waitTime](title="queueing time at dequeue";record=vector,mean,max;unit=s;interpolationmode=none);
 
        
        volatile double mean @unit(s) = default(uniform(1s, 2s));
        volatile double stdev @unit(s) = default((mean/2));
        volatile double serviceTime @unit(s) = default(truncnormal(mean, stdev));
      
    gates:
        input in[];
        output out;
}
