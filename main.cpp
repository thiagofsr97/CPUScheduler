/**
 *  @file    main.cpp
 *  @author  Thiago Filipe Soares da Rocha
 *  @date    04/15/2018
 *  @version 1.0
 *
 *  @brief Main
 *
 */


#include <iostream>
#include "FileUtil.h"
#include "Scheduler.h"

int main(int argc,char**argv) {
    std::cout << "-----------------------------Running Scheduling Algorithms-----------------------------\n\n";
    FileUtil fileUtils("in.txt","out.txt");
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