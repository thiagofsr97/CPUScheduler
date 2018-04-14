#include <iostream>
#include "FileUtil.h"
#include "Scheduler.h"
#define BadArgs() std::cout << "Wrong or missing arguments." << std::endl;exit(1);

int main(int argc,char**argv) {

    FileUtil fileUtils("in.txt","out.txt");
    std::vector<Process> processList;
    Scheduler scheduler(&fileUtils);
    scheduler.schedule(FCFS);
    fileUtils.appendToLog(FCFS,scheduler.getAverageArray());
    scheduler.schedule(SJF);
    fileUtils.appendToLog(SJF,scheduler.getAverageArray());
    scheduler.schedule(RR);
    fileUtils.appendToLog(RR,scheduler.getAverageArray());

    return 0;
}