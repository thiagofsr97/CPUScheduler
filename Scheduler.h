//
// Created by thiagofsr on 09/04/18.
//

#ifndef CPUSCHEDULER_SCHEDULER_H
#define CPUSCHEDULER_SCHEDULER_H


#include <vector>
#include "Process.h"
#include <array>

#define QUANTUM 2
typedef enum {FCFS, SJF,RR} scheduleAlgorithm;
enum SortBy{ARRIVAL, BURST};

class Scheduler {
private:
    std::vector<Process> processList;
    double waitAverage, responseAverage, returnAverage;
    void calculateAverage();
    void sort(SortBy);
    void fcfs();
    void sjf();
    void rr();

public:
    Scheduler(std::vector<Process> processList);
    void setProcessList(std::vector<Process>);
    std::vector<Process> getProcesslist();
    void addProcess(Process);
    double getWaitAverage();
    double getResponseAverage();
    double getReturnAverage();
    std::array<double, 3> getAverageArray();
    void schedule(scheduleAlgorithm);
};


#endif //CPUSCHEDULER_SCHEDULER_H
