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

bool sortById(Process &a, Process& b){
    return a.getId() < b.getId();
}

void showExecutedQueue(std::vector<Process> &process,scheduleAlgorithm algorithm)   {
    std::string schedulingAlgorithm;
    std::sort(process.begin(),process.end(),sortById);
    switch(algorithm){
        case FCFS:
            schedulingAlgorithm = "FCFS";
            break;
        case SJF:
            schedulingAlgorithm = "SJF";
            break;
        case RR:
            schedulingAlgorithm = "RR";
            break;
    }
    std::cout << "Scheduled by " << schedulingAlgorithm << " algorithm:"<<std::endl;
    for(Process i:process){

        std::cout <<"P" << i.getId() << " Wait: "<< i.getWaitTime() <<
                  " Return: " << i.getReturnTime() <<
                  " Response: " << i.getResponseTime() << " Arrival:" << i.getArrivalTime() << std::endl;

    }
    std::cout << std::endl;
}

void moveProcess(std::vector<Process> &origin, std::vector<Process> &destination) {
    if(!origin.empty()){
        destination.push_back(origin.front());
        origin.erase(origin.begin());
    }


}

void calculateTime(std::vector<Process>& waitExecProcesses){
    waitExecProcesses.front().decrementBurstTime();
    waitExecProcesses.front().incrementReturnTime();
    for(int i = 1; i < waitExecProcesses.size();i++){
        if(waitExecProcesses.at(i).isFirstResponse())
            waitExecProcesses.at(i).incrementResponseTime(); //won't have effect all the time
        waitExecProcesses.at(i).incrementReturnTime();
        waitExecProcesses.at(i).incrementWaitTime();
    }

}

void fillReadyExecQueue(std::vector<Process> &idleQueue,std::vector<Process> &readyExecQueue,std::vector<Process> &aux,int currentTime) {
    if(!idleQueue.empty()){

        if (!(idleQueue.front().getArrivalTime() <= currentTime))
            while (!aux.empty()) {
                moveProcess(aux,readyExecQueue);
            }
        else {
            while (!idleQueue.empty() && (idleQueue.front().getArrivalTime() <= currentTime) &&
                   idleQueue.front().isFirstResponse()) {
                moveProcess(idleQueue,readyExecQueue);
            }
            while (!aux.empty()) {
                moveProcess(aux,readyExecQueue);
            }
        }

    }else{
        while(!aux.empty()){
            moveProcess(aux,readyExecQueue);
        }

    }

}

Scheduler::Scheduler(FileUtil* file):file(file) {


}
std::vector<Process> Scheduler::getProcesslist() {
    return executedQueue;

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

void Scheduler::fcfs() {

    ClearAll();
    int currentTime;
    idleQueue = file->getProcess();
    std::sort(idleQueue.begin(),idleQueue.end(),sortByArrival);
    int n_process = idleQueue.size();

    currentTime = idleQueue.front().getArrivalTime(); //advance time to point of start of the first process

    while(executedQueue.size() < n_process){
        while(!idleQueue.empty() && idleQueue.front().getArrivalTime() <= currentTime){
            moveProcess(idleQueue,readyExecQueue);
        }
        if ((readyExecQueue.front().getBurstTime() == 0)) {
            moveProcess(readyExecQueue,executedQueue);

        } else
            calculateTime(readyExecQueue);

        currentTime++;
    }

    calculateAverage();
    showExecutedQueue(executedQueue,FCFS);


}

void Scheduler::sjf() {
    ClearAll();
    int currentTime;
    idleQueue = file->getProcess();

    int n_process = idleQueue.size();

    std::sort(idleQueue.begin(),idleQueue.end(),sortByArrival);
    currentTime = idleQueue.front().getArrivalTime(); //advance time to point of start of the first process


    while(executedQueue.size() < n_process){

        while(!idleQueue.empty() && idleQueue.front().getArrivalTime() <= currentTime){
            moveProcess(idleQueue,readyExecQueue);
        }
        if(!readyExecQueue.empty())
            std::sort(readyExecQueue.begin(),readyExecQueue.end(),sortByBurstTime);

        if ((readyExecQueue.front().getBurstTime() == 0)) {
            moveProcess(readyExecQueue,executedQueue);
        } else
            calculateTime(readyExecQueue);

        currentTime++;
    }
    calculateAverage();
    showExecutedQueue(executedQueue,SJF);

}

void Scheduler::rr() {
    ClearAll();
    int currentTime;
    idleQueue = file->getProcess();
    std::sort(idleQueue.begin(),idleQueue.end(),sortByArrival);

    int n_process = idleQueue.size();
    int quantum = 0;
    currentTime = idleQueue.front().getArrivalTime(); //advance time to point of start of the first process
    while(executedQueue.size() < n_process){

        fillReadyExecQueue(idleQueue,readyExecQueue,aux,currentTime);
        if(!idleQueue.empty() && readyExecQueue.empty()) { //advance time while cpu is in idle state
            currentTime++;
        }


        /* Checks if a process has finished execution or has reached its quantum limit.
         * If execution has finished, the process is moved to a queue of finished processes.
         * If quantum is reached, it's moved to an auxiliary queue, then moved to the queue
         * of waiting processes.
         * In case none of the above happened, wait, return and response times will be calculated to
         * each of the processes in both execution and waiting states.
         * */
        if(quantum == QUANTUM  ||readyExecQueue.front().getBurstTime() == 0 ) {
            quantum = 0;
            if(readyExecQueue.front().getBurstTime() == 0){
                moveProcess(readyExecQueue,executedQueue);
            }else{

                readyExecQueue.front().hasLeftOnce();
                moveProcess(readyExecQueue,aux);
            }
        }else{

            quantum++;
            currentTime++;
            calculateTime(readyExecQueue);

        }

    }

    calculateAverage();
    showExecutedQueue(executedQueue,RR);



}

double Scheduler::getWaitAverage() {return this->waitAverage;}

double Scheduler::getResponseAverage() {return this->responseAverage;}

double Scheduler::getReturnAverage() {return this->returnAverage;}

std::array<double,3> Scheduler::getAverageArray() {
    return std::array<double,3> {returnAverage,responseAverage,waitAverage};
}

void Scheduler::ClearAll() {
    this->readyExecQueue.clear();
    this->idleQueue.clear();
    this->executedQueue.clear();
    this->aux.clear();
    this->responseAverage = this->waitAverage = this->returnAverage = 0;

}





