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
    int currentTime;
    FileUtil *file;
    double waitAverage, responseAverage, returnAverage;
    void calculateAverage();
    void sort(SortBy);
    void fcfs();
    void sjf();
    void rr();

public:
    Scheduler(FileUtil*);
    void setIdleQueue(std::vector<Process>);
    std::vector<Process> getProcesslist();
    void addProcess(Process);
    double getWaitAverage();
    double getResponseAverage();
    double getReturnAverage();
    std::array<double, 3> getAverageArray();
    void schedule(scheduleAlgorithm);
};


#endif //CPUSCHEDULER_SCHEDULER_H
