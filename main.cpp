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

struct comma_separator : std::numpunct<char> {
    virtual char do_decimal_point() const override { return ','; }
};

int main(int argc,char**argv) {

    std::cout.imbue(std::locale(std::cout.getloc(), new comma_separator));
    FileUtil fileUtils("in.txt");
    Scheduler scheduler(&fileUtils);
    scheduler.schedule(FCFS);
    fileUtils.appendToLog(FCFS,scheduler.getReturnAverage(),scheduler.getResponseAverage(),scheduler.getWaitAverage());
    scheduler.schedule(SJF);
    fileUtils.appendToLog(SJF,scheduler.getReturnAverage(),scheduler.getResponseAverage(),scheduler.getWaitAverage());
    scheduler.schedule(RR);
    fileUtils.appendToLog(RR,scheduler.getReturnAverage(),scheduler.getResponseAverage(),scheduler.getWaitAverage());

    return 0;
}