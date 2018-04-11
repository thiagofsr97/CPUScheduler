//
// Created by thiagofsr on 09/04/18.
//

#ifndef CPUSCHEDULER_PROCESS_H
#define CPUSCHEDULER_PROCESS_H


class Process {
private:
    int executionTime;
    int arrivalTime;
    int waitTime;
    int returnTime;
    int responseTime;
    static int id;
    int processId;


public:
    Process(int,int);
    int getId();
    int getExecutionTime();
    void setExecutionTime(int);
    int getWaitTime();
    void setWaitTime(int);
    int getReturnTime();
    void setReturnTime(int);
    int getArrivalTime();
    int getResponseTime();
    void setResponseTime(int);


};


#endif //CPUSCHEDULER_PROCESS_H
