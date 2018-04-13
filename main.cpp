#include <iostream>
#include "FileUtil.h"
#include "Scheduler.h"
#define BadArgs() std::cout << "Wrong or missing arguments." << std::endl;exit(1);

int main(int argc,char**argv) {
//    if(argc < 3){
//        BadArgs();
//    }

    FileUtil fileUtils("in.txt","out.txt");
    std::vector<Process> processList;
    Scheduler scheduler(&fileUtils);
    scheduler.schedule(RR);
    fileUtils.appendToLog(RR,scheduler.getAverageArray());

    processList = scheduler.getProcesslist();

    for(Process i:processList){
        std::cout <<"P" << i.getId() << " Wait: "<< i.getWaitTime() <<
                  " Return: " << i.getReturnTime() <<
                  " Response: " << i.getResponseTime() << " Burst:" <<
                  i.getBurstTime() << " Arrival:" << i.getArrivalTime() << std::endl;
    }

    return 0;
}