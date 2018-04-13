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
            std::sort(idleQueue.begin(),idleQueue.end(),sortByArrival);
            break;
        case BURST:
            std::sort(idleQueue.begin(),idleQueue.end(),sortByBurstTime);
            break;

    }
}
void Scheduler::calculateAverage() {
    int fullResponseTime, fullWaitTime, fullReturnTime;
    fullResponseTime = fullWaitTime = fullReturnTime = 0;
    for(Process i:executedQueue){
        fullResponseTime+= i.getResponseTime();
        fullReturnTime += i.getReturnTime();
        fullWaitTime += i.getWaitTime();
    }
    this->responseAverage = double(fullResponseTime)/executedQueue.size();
    this->returnAverage = double(fullReturnTime)/executedQueue.size();
    this->waitAverage = double(fullWaitTime)/executedQueue.size();

}

Scheduler::Scheduler(FileUtil* file):file(file) {

    currentTime = 0;
}

std::vector<Process> Scheduler::getProcesslist() {
    return executedQueue;

}

void Scheduler::setIdleQueue(std::vector<Process> idleQueue) {
    this->idleQueue = idleQueue;

}

void Scheduler::addProcess(Process process) {
    idleQueue.push_back(process);


}


double Scheduler::getWaitAverage() {return this->waitAverage;}

double Scheduler::getResponseAverage() {return this->responseAverage;}

double Scheduler::getReturnAverage() {return this->returnAverage;}

void Scheduler::fcfs() {
    currentTime =0;
    if(idleQueue.empty()) {
        idleQueue = this->file->getProcess();
        if(idleQueue.empty()){
            std::cout << "There's no processes to schedule" << std::endl;
        }
    }
    std::sort(idleQueue.begin(),idleQueue.end(),sortByArrival);
    int n_process = idleQueue.size();


    while(executedQueue.size() < n_process){


        while(!idleQueue.empty() && idleQueue.front().getArrivalTime() <= currentTime){
            readyExecQueue.push_back(idleQueue.front());
            idleQueue.erase(idleQueue.begin());
        }

        if ((readyExecQueue.front().getBurstTime() == 0)) {
            executedQueue.push_back(readyExecQueue.front());
            readyExecQueue.erase(readyExecQueue.begin());

        } else {
            readyExecQueue.front().decrementBurstTime();
            readyExecQueue.front().incrementReturnTime();
            for (int i = 1; i < readyExecQueue.size(); i++) {
                readyExecQueue.at(i).incrementWaitTime();
                readyExecQueue.at(i).incrementResponseTime();
                readyExecQueue.at(i).incrementReturnTime();
            }
        }




        currentTime++;
    }
    calculateAverage();


}

void Scheduler::sjf() {
    currentTime =0;
    if(idleQueue.empty()) {
        idleQueue = this->file->getProcess();
        if(idleQueue.empty()){
            std::cout << "There's no processes to schedule" << std::endl;
        }
    }
    std::sort(idleQueue.begin(),idleQueue.end(),sortByArrival);
    int n_process = idleQueue.size();


    while(executedQueue.size() < n_process){


        while(!idleQueue.empty() && idleQueue.front().getArrivalTime() <= currentTime){
            readyExecQueue.push_back(idleQueue.front());
            idleQueue.erase(idleQueue.begin());
        }
        if(!readyExecQueue.empty())
            std::sort(readyExecQueue.begin(),readyExecQueue.end(),sortByBurstTime);

            if ((readyExecQueue.front().getBurstTime() == 0)) {
                executedQueue.push_back(readyExecQueue.front());
                readyExecQueue.erase(readyExecQueue.begin());
            } else {
                readyExecQueue.front().decrementBurstTime();
                readyExecQueue.front().incrementReturnTime();
                for (int i = 1; i < readyExecQueue.size(); i++) {
                    readyExecQueue.at(i).incrementWaitTime();
                    readyExecQueue.at(i).incrementResponseTime();
                    readyExecQueue.at(i).incrementReturnTime();
                }
            }




        currentTime++;
    }
    calculateAverage();



}

void Scheduler::rr() {
    currentTime = 0;
    idleQueue = file->getProcess();
    std::sort(idleQueue.begin(),idleQueue.end(),sortByArrival);

    int n_process = idleQueue.size();
    int quantum = 0;


    while(executedQueue.size() < n_process){

            while (!idleQueue.empty() && (idleQueue.front().getArrivalTime() <= currentTime) && idleQueue.front().isFirstResponse()) {
                readyExecQueue.push_back(idleQueue.front());
                idleQueue.erase(idleQueue.begin());
            }


        if(!idleQueue.empty()){

            if(idleQueue.front().getReturnTime()> 0){

                while(!idleQueue.empty()){
                    readyExecQueue.push_back(idleQueue.front());
                    idleQueue.erase(idleQueue.begin());
                }

            }
        }



        if(quantum == QUANTUM ||readyExecQueue.front().getBurstTime() == 0 ) {
            quantum = 0;
            if(readyExecQueue.front().getBurstTime() == 0){
                executedQueue.push_back(readyExecQueue.front());
                readyExecQueue.erase(readyExecQueue.begin());


            }else{
                readyExecQueue.front().hasLeftOnce();
                idleQueue.push_back(readyExecQueue.front());
                readyExecQueue.erase(readyExecQueue.begin());

            }
        }else{
            quantum++;
            readyExecQueue.front().decrementBurstTime();
            readyExecQueue.front().incrementReturnTime();
            for(int i = 1; i < readyExecQueue.size();i++){
                if(readyExecQueue.at(i).isFirstResponse())
                    readyExecQueue.at(i).incrementResponseTime(); //won't have effect all the time
                readyExecQueue.at(i).incrementReturnTime();
                readyExecQueue.at(i).incrementWaitTime();
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
             rr();
            break;
    }

}

std::array<double,3> Scheduler::getAverageArray() {
    return std::array<double,3> {returnAverage,responseAverage,waitAverage};
}



