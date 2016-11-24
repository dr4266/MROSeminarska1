package seminarska1;

simple Switch
{
    parameters:
        @display("i=block/switch");
        int mode = default(0);	// random (0) or least busy queue first(1)
    gates:
        input in[];
        output out[];
}


