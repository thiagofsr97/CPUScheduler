//
// Created by thiagofsr on 09/04/18.
//

#ifndef CPUSCHEDULER_PROCESS_H
#define CPUSCHEDULER_PROCESS_H


class Process {
private:
    int burstTime;
    int arrivalTime;
    int waitTime;
    int returnTime;
    int responseTime;
    static int id;
    int processId;


public:
    Process(int,int);
    int getId();
    int getBurstTime();
    void setBurstTime(int);
    void decrementBurstTime();
    int getWaitTime();
    void setWaitTime(int);
    void incrementWaitTime();
    int getReturnTime();
    void setReturnTime(int);
    void incrementReturnTime();

    int getArrivalTime();
    int getResponseTime();
    void setResponseTime(int);
    void incrementResponseTime();


};


#endif //CPUSCHEDULER_PROCESS_H
