#include <iostream>
#include "FileUtils.h"
#define BadArgs() std::cout << "Wrong or missing arguments." << std::endl;exit(1);

int main(int argc,char**argv) {
//    if(argc < 3){
//        BadArgs();
//    }

    FileUtils fileUtils("in.txt","out.txt");
    std::vector<Process> processList = fileUtils.getProcess();
    Scheduler scheduler(processList);
    scheduler.schedule(FCFS);
    fileUtils.appendToLog(FCFS,scheduler.getAverageArray());

    return 0;
}