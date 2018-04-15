/**
 *  @file    SortNumbers.cpp
 *  @author  Thiago Filipe Soares da Rocha
 *  @date    04/15/2018
 *  @version 1.0
 *
 *  @brief Implementation a class representing a Process.
 *
 */

#include "Process.h"

int Process::id = 0; /// initialization of static id value.

/***
  * Class Constructor of a Process. Sets burst time and arrival time of a process.
  * @param [in] burstTime Burst Time of a process in CPU.
  * @param [in] arrivalTime Time that a process arrives in CPU to be executed.
  * @return Process object.
  */

Process::Process(int burstTime, int arrivalTime):burstTime(burstTime),arrivalTime(arrivalTime) {
    this->responseTime = 0;
    this->returnTime = 0;
    this->waitTime = 0;
    this->processId = id++; /// each process gets a unique id
    this->firstResponse = true;
}

/***
  * Returns the burst time of a process in cpu.
  * @param none
  * @param none
  * @return burst time.
  */

int Process::getBurstTime() {return this->burstTime; }

/***
  * Returns the arrival time of a process in cpu.
  * @param none
  * @param none
  * @return arrival time.
  */
int Process::getArrivalTime() { return this->arrivalTime;}

/***
  * Returns the response time of a process in cpu.
  * @param none
  * @param none
  * @return response time.
  */
int Process::getResponseTime() {return this->responseTime;}
/***
  * Returns the wait time of a process in cpu.
  * @param none
  * @param none
  * @return wait time.
  */
int Process::getWaitTime() { return this->waitTime;}
/***
  * Returns the return time of a process in cpu.
  * @param none
  * @param none
  * @return return time.
  */
int Process::getReturnTime() {return this->returnTime;}
/***
  * Sets the burst time of a process in cpu.
  * @param [in] execTime Time of the burst of CPU.
  * @return none
  */
void Process::setBurstTime(int execTime) {this->burstTime = execTime;}
/***
  * Sets the response time of a process in cpu.
  * @param [in] respTime Time of the response in CPU.
  * @return none
  */
void Process::setResponseTime(int respTime) {this->responseTime = respTime;}
/***
  * Sets the wait time of a process in cpu.
  * @param [in] waitTime Time of wait in CPU.
  * @return none
  */
void Process::setWaitTime(int waitTime) {this->waitTime = waitTime;}

/***
  * Sets the return time of a process in cpu.
  * @param [in] retTime Time of Return in CPU.
  * @return none
  */
void Process::setReturnTime(int retTime) {this->returnTime = retTime;}

/***
  * Returns the unique id of a process.
  * @param none
  * @return process identifier
  */

int Process::getId() {return this->processId;}

/***
  * Decrements the burst time of a process in cpu.
  * @param none
  * @return none
  */
void Process::decrementBurstTime() {
    if(!(this->burstTime<0))
        this->burstTime--;

}

/***
  * Increments the wait time of a process in cpu.
  * @param none
  * @return none
  */

void Process::incrementWaitTime() {
    this->waitTime++;

}

/***
  * Increments the return time of a process in cpu.
  * @param none
  * @return none
  */

void Process::incrementReturnTime() {
    this->returnTime++;

}

/***
  * Increments the response time of a process in cpu.
  * @param none
  * @return none
  */

void Process::incrementResponseTime() {
            this->responseTime++;

}

/***
  * Switch the state of a process, indicating that it's had its first response in CPU.
  * @param none
  * @return none
  */

void Process::hasLeftOnce() {
    this->firstResponse = false;

}

/***
  * Returns the state of a process, indicating if it's had its first response in CPU.
  * @param none
  * @return none
  */

bool Process::isFirstResponse() {
    return this->firstResponse;
}

