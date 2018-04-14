//
// Created by thiagofsr on 09/04/18.
//

#ifndef CPUSCHEDULER_SCHEDULER_H
#define CPUSCHEDULER_SCHEDULER_H


#include <vector>
#include "Process.h"
#include "FileUtil.h"
#include <array>
#include "Utils.h"

#define QUANTUM 2


class Scheduler {
private:
    std::vector<Process> idleQueue;
    std::vector<Process> readyExecQueue;
    std::vector<Process> executedQueue;
    std::vector<Process> aux;
    FileUtil *file;
    double waitAverage, responseAverage, returnAverage;
    void sort(SortBy);
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
    std::array<double, 3> getAverageArray();
};


#endif //CPUSCHEDULER_SCHEDULER_H
