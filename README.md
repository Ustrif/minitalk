Minitalk is a data exchange program which runs with SIGUSR1 and SIGUSR2.
In my program, i used SIGUSR1 as 0 and SIGUSR2 as 1. 

ASCII Table (256) characters send with my program also you can see other unicode charachter but this is linked with your running environment.

To Compile:
make

To Use:
./server 
./client PID "your text." 

PID: Process Id will given by server.
