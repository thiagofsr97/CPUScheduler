//
// Created by thiagofsr on 09/04/18.
//


#include <algorithm>
#include "Scheduler.h"

void Scheduler::calculateAverage() {
    int fullResponseTime, fullWaitTime, fullReturnTime;
    fullResponseTime = fullWaitTime = fullReturnTime = 0;
    for(Process i:processList){
        fullResponseTime+= i.getResponseTime();
        fullReturnTime += i.getReturnTime();
        fullWaitTime += i.getWaitTime();
    }
    this->responseAverage = double(fullResponseTime)/processList.size();
    this->returnAverage = double(fullReturnTime)/processList.size();
    this->waitAverage = double(fullWaitTime)/processList.size();

}

Scheduler::Scheduler(std::vector<Process> processList):processList(processList) {sortByArrival();}

std::vector<Process> Scheduler::getProcesslist() {
    return processList;

}

void Scheduler::setProcessList(std::vector<Process> processList) {
    this->processList = processList;

}

void Scheduler::addProcess(Process process) {
    processList.push_back(process);
    sortByArrival();

}

void Scheduler::sortByArrival() {
    std::sort(processList.begin(),processList.end());

}

double Scheduler::getWaitAverage() {return this->waitAverage;}

double Scheduler::getResponseAverage() {return this->responseAverage;}

double Scheduler::getReturnAverage() {return this->returnAverage;}

void Scheduler::fcfs() {

    processList.at(0).setReturnTime(processList.at(0).getExecutionTime());
    processList.at(0).setWaitTime(0);
    processList.at(0).setResponseTime(0);
    int waitTime,responseTime,returnTime;
    waitTime = 0;
    for(int i = 1; i < processList.size();i++){
        waitTime += processList.at(i-1).getArrivalTime() + processList.at(i-1).getExecutionTime() -
                                                          processList.at(i).getArrivalTime();
        if(waitTime < 0)
            waitTime = 0;
        processList.at(i).setWaitTime(waitTime);
        returnTime = processList.at(i).getWaitTime() + processList.at(i).getExecutionTime();
        processList.at(i).setReturnTime(returnTime);
        responseTime = waitTime;
        processList.at(i).setResponseTime(responseTime);
    }

    calculateAverage();
}

void Scheduler::schedule(scheduleAlgorithm algorithm) {
    switch(algorithm){
        case FCFS:
            fcfs();
            break;
        case SJF:
//            sjf();
            break;
        case RR:
  //          rr();
            break;
    }

}

std::array<double,3> Scheduler::getAverageArray() {
    return std::array<double,3> {returnAverage,responseAverage,waitAverage};
}


