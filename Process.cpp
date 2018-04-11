//
// Created by thiagofsr on 09/04/18.
//

#include "Process.h"
int Process::id = 1;
Process::Process(int executionTime, int arrivalTime):executionTime(executionTime),arrivalTime(arrivalTime) {
    this->responseTime = 0;
    this->returnTime = 0;
    this->waitTime = 0;
    this->processId = id++;
}

int Process::getExecutionTime() {return this->executionTime; }
int Process::getArrivalTime() { return this->arrivalTime;}
int Process::getResponseTime() {return this->responseTime;}
int Process::getWaitTime() { return this->waitTime;}
int Process::getReturnTime() {return this->returnTime;}
void Process::setExecutionTime(int execTime) {this->executionTime = execTime;}
void Process::setResponseTime(int respTime) {this->responseTime = respTime;}
void Process::setWaitTime(int waitTime) {this->waitTime = waitTime;}
void Process::setReturnTime(int retTime) {this->returnTime = retTime;}

int Process::getId() {return this->processId;}

