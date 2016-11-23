

package seminarska1;

simple mmcQueue
{
   parameters:
        @display("i=block/queue");
        
        int capacity = default(100);   
        int resources = default(2);
        double mean @unit(s) = default(uniform(1s, 2s));
        double stdev @unit(s) = default((mean/2));
        volatile double serviceTime @unit(s) = default(truncnormal(mean, stdev));
      
    gates:
        input in[];
        output out;
}
