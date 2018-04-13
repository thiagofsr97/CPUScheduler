//
// Created by thiagofsr on 09/04/18.
//


#include <algorithm>
#include <iostream>
#include "Scheduler.h"

bool sortByArrival(Process& a,Process& b){
    return a.getArrivalTime() < b.getArrivalTime();

}

bool sortByBurstTime(Process& a,Process& b){
    return a.getBurstTime() < b.getBurstTime();

}

void Scheduler::sort(SortBy sortBy) {
    switch(sortBy){
        case ARRIVAL:
            std::sort(processList.begin(),processList.end(),sortByArrival);
            break;
        case BURST:
            std::sort(processList.begin(),processList.end(),sortByBurstTime);
            break;

    }
}
void Scheduler::calculateAverage() {
    int fullResponseTime, fullWaitTime, fullReturnTime;
    fullResponseTime = fullWaitTime = fullReturnTime = 0;
    for(Process i:executionQueue){
        fullResponseTime+= i.getResponseTime();
        fullReturnTime += i.getReturnTime();
        fullWaitTime += i.getWaitTime();
    }
    this->responseAverage = double(fullResponseTime)/executionQueue.size();
    this->returnAverage = double(fullReturnTime)/executionQueue.size();
    this->waitAverage = double(fullWaitTime)/executionQueue.size();

}

Scheduler::Scheduler(std::vector<Process> processList):processList(processList) {}

std::vector<Process> Scheduler::getProcesslist() {
    return executionQueue;

}

void Scheduler::setProcessList(std::vector<Process> processList) {
    this->processList = processList;

}

void Scheduler::addProcess(Process process) {
    processList.push_back(process);


}


double Scheduler::getWaitAverage() {return this->waitAverage;}

double Scheduler::getResponseAverage() {return this->responseAverage;}

double Scheduler::getReturnAverage() {return this->returnAverage;}

void Scheduler::fcfs() {
    currentTime =0;
    std::sort(processList.begin(),processList.end(),sortByArrival);
    int n_process = processList.size();


    while(executionQueue.size() <= n_process){


        while(!processList.empty() && processList.front().getArrivalTime() <= currentTime){
            readyQueue.push_back(processList.front());
            processList.erase(processList.begin());
        }

        if ((readyQueue.front().getBurstTime() == 0)) {
            executionQueue.push_back(readyQueue.front());
            readyQueue.erase(readyQueue.begin());
            if(readyQueue.size() == 0 && processList.size() == 0)
                break;

        } else {
            readyQueue.front().decrementBurstTime();
            readyQueue.front().incrementReturnTime();
            for (int i = 1; i < readyQueue.size(); i++) {
                readyQueue.at(i).incrementWaitTime();
                readyQueue.at(i).incrementResponseTime();
                readyQueue.at(i).incrementReturnTime();
            }
        }




        currentTime++;
    }
    calculateAverage();


}

void Scheduler::sjf() {
    currentTime =0;
    std::sort(processList.begin(),processList.end(),sortByArrival);
    int n_process = processList.size();


    while(executionQueue.size() <= n_process){


        while(!processList.empty() && processList.front().getArrivalTime() <= currentTime){
            readyQueue.push_back(processList.front());
            processList.erase(processList.begin());
        }
        if(!readyQueue.empty())
            std::sort(readyQueue.begin(),readyQueue.end(),sortByBurstTime);

            if ((readyQueue.front().getBurstTime() == 0)) {
                executionQueue.push_back(readyQueue.front());
                readyQueue.erase(readyQueue.begin());
                if(readyQueue.size() == 0 && processList.size() == 0)
                    break;

            } else {
                readyQueue.front().decrementBurstTime();
                readyQueue.front().incrementReturnTime();
                for (int i = 1; i < readyQueue.size(); i++) {
                    readyQueue.at(i).incrementWaitTime();
                    readyQueue.at(i).incrementResponseTime();
                    readyQueue.at(i).incrementReturnTime();
                }
            }




        currentTime++;
    }
    calculateAverage();



}

void Scheduler::schedule(scheduleAlgorithm algorithm) {
    switch(algorithm){
        case FCFS:
            fcfs();
            break;
        case SJF:
             sjf();
            break;
        case RR:
  //          rr();
            break;
    }

}

std::array<double,3> Scheduler::getAverageArray() {
    return std::array<double,3> {returnAverage,responseAverage,waitAverage};
}



