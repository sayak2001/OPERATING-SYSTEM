# OPERATING-SYSTEM
C program for shortest remaining time first scheduling algorithm And Multi-level queue scheduling algorithm

If a new process arrives with CPU burst length less than remaining time of current executing process, preempt. This scheme is know as the Shortest-Remaining-Time-First (SRTF). If a new process arrives with a shorter burst time than remaining of current process then schedule new process. Further reduces average waiting time and average response time.

Multi-level queue scheduling algorithm is used in scenarios where the processes can be classified into groups
based on property like process type, CPU time, IO access, memory size, etc. In a multi-level queue scheduling
algorithm, there will be 'n' number of queues, where 'n' is the number of groups the processes are classified
into. Each queue will be assigned a priority and will have its own scheduling algorithm like round-robin
scheduling or FCFS. For the process in a queue to execute, all the queues of priority higher than it should be
empty, meaning the process in those high priority queues should have completed its execution. In this
scheduling algorithm, once assigned to a queue, the process will not move to any other queues.
