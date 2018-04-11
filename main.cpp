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
    scheduler.schedule(SJF);
    fileUtils.appendToLog(SJF,scheduler.getAverageArray());

    processList = scheduler.getProcesslist();

    for(Process i:processList){
        std::cout <<"P" << i.getId() << " Wait: "<< i.getWaitTime() <<
                  " Return: " << i.getReturnTime() <<
                  " Response: " << i.getResponseTime() << " Burst:" <<
                  i.getExecutionTime() << " Arrival:" << i.getArrivalTime() << std::endl;
    }

    return 0;
}