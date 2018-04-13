//
// Created by thiagofsr on 09/04/18.
//

#ifndef CPUSCHEDULER_PROCESS_H
#define CPUSCHEDULER_PROCESS_H


class Process {
private:
    bool firstResponse;
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
    bool isFirstResponse();
    int getResponseTime();
    void setResponseTime(int);
    void incrementResponseTime();
    void hasLeftOnce();


};


#endif //CPUSCHEDULER_PROCESS_H
