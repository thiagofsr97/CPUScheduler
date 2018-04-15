# CPU Scheduler
Operational Systems Discipline activity. Implementation of the classic Scheduling Algorithms: First Come First Served, Shortest Job First and Round Robin.
The program simulates the scheduling of a set of processes given the input (Arrival Time and Burst Time of a process). At the end of program, the average 
of Return, Response and Wait time of the processes will be given, according by each algorithm used.
# Scheduling Process
In computing, scheduling is the method by which work specified by some means is assigned to resources that complete the work. The work may be virtual computation elements such as threads, processes or data flows, which are in turn scheduled onto hardware resources such as processors, network links or expansion cards.
You can read more about scheduling and each one of its algorithm in wikipedia. <a href="https://en.wikipedia.org/wiki/Scheduling_(computing)">Scheduling(computing) - Wikipedia</a>. 
# How to use it!

- The compilation of the file is as simple as it follows:
Go straight to the root of the project using the terminal and type the following: <br />
'<b>cmake CMakeLists.txt && make</b>' . (with no quotation marks) 

- Make sure you have cmake pre-installed (Version 3.8 or above). <a href="https://cmake.org/download/">Cmake Download Webpage</a>.
- In order to run the program properly, you must add a file named "in.txt" at the root of the program folder, containing the arrival and burst time of each process in the following format:

   0 20 <br />
   0 10 <br />
   4 6 <br />
   4 8 <br />
   
- By using this input you will get a output file named "out.txt", containg all the information of averages of the processes scheduled by each algorithm used in the following format:

  FCFS 30.5 19.5 19.5 <br />
  SJF 21.5 10.5 10.5 <br />
  RR 31.5 2 20.5 <br />
  
  [Algorithm] [Return Average] [Response Average] [Wait Average]
