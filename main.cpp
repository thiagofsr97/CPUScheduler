#include <iostream>
#include "FileUtil.h"
#include "Scheduler.h"
#define BadArgs() std::cout << "Wrong or missing arguments." << std::endl;exit(1);

int main(int argc,char**argv) {
    std::cout << "-----------------------------Running Scheduling Algorithms-----------------------------\n\n";
    FileUtil fileUtils("in.txt","out.txt");
    std::vector<Process> processList;

    Scheduler scheduler(&fileUtils);
    scheduler.schedule(FCFS);
    fileUtils.appendToLog(FCFS,scheduler.getReturnAverage(),scheduler.getResponseAverage(),scheduler.getWaitAverage());
    scheduler.schedule(SJF);
    fileUtils.appendToLog(SJF,scheduler.getReturnAverage(),scheduler.getResponseAverage(),scheduler.getWaitAverage());
    scheduler.schedule(RR);
    fileUtils.appendToLog(RR,scheduler.getReturnAverage(),scheduler.getResponseAverage(),scheduler.getWaitAverage());

    std::cout << "--------------------------------Check the out.txt file.--------------------------------"<< std::endl;

    return 0;
}