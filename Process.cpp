//
// Created by thiagofsr on 09/04/18.
//

#include "Process.h"
int Process::id = 1;
Process::Process(int burstTime, int arrivalTime):burstTime(burstTime),arrivalTime(arrivalTime) {
    this->responseTime = 0;
    this->returnTime = 0;
    this->waitTime = 0;
    this->processId = id++;
}

int Process::getBurstTime() {return this->burstTime; }
int Process::getArrivalTime() { return this->arrivalTime;}
int Process::getResponseTime() {return this->responseTime;}
int Process::getWaitTime() { return this->waitTime;}
int Process::getReturnTime() {return this->returnTime;}
void Process::setBurstTime(int execTime) {this->burstTime = execTime;}
void Process::setResponseTime(int respTime) {this->responseTime = respTime;}
void Process::setWaitTime(int waitTime) {this->waitTime = waitTime;}
void Process::setReturnTime(int retTime) {this->returnTime = retTime;}

int Process::getId() {return this->processId;}

void Process::decrementBurstTime() {
    if(!(this->burstTime<0))
        this->burstTime--;

}

void Process::incrementWaitTime() {
    this->waitTime++;

}

void Process::incrementReturnTime() {
    this->returnTime++;

}

void Process::incrementResponseTime() {
    this->responseTime++;

}

