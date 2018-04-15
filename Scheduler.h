/**
 *  @file    Scheduler.h
 *  @author  Thiago Filipe Soares da Rocha
 *  @date    04/15/2018
 *  @version 1.0
 *
 *  @brief Header file of a Scheduler.
 *
 */


#ifndef CPUSCHEDULER_SCHEDULER_H
#define CPUSCHEDULER_SCHEDULER_H


#include <vector>
#include "Process.h"
#include "FileUtil.h"
#include "Utils.h"
#include <algorithm>
#include <iostream>

#define QUANTUM 2


class Scheduler {
private:
    std::vector<Process> idleQueue;
    std::vector<Process> readyExecQueue;
    std::vector<Process> executedQueue;
    std::vector<Process> aux;
    FileUtil *file;
    double waitAverage, responseAverage, returnAverage;
    void calculateAverage();
    void fcfs();
    void sjf();
    void rr();
    void ClearAll();


public:
    Scheduler(FileUtil*);
    std::vector<Process> getProcesslist();
    void schedule(scheduleAlgorithm);
    double getWaitAverage();
    double getResponseAverage();
    double getReturnAverage();

};


#endif //CPUSCHEDULER_SCHEDULER_H
