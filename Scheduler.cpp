/**
 *  @file    Scheduler.cpp
 *  @author  Thiago Filipe Soares da Rocha
 *  @date    04/15/2018
 *  @version 1.0
 *
 *  @brief Implementation of Classic Scheduling Algorithms.
 *
 */



#include "Scheduler.h"

/***
  * Comparison function to sort a process by its arrival time.
  *
  * @param [in] a First Process.
  * @param [in] b Second Process.
  * @return returns either the first process is lesser than the second or not.
  */

bool sortByArrival(Process& a,Process& b){
    return a.getArrivalTime() < b.getArrivalTime();

}

/***
  * Comparison function to sort a process by its burst time.
  *
  * @param [in] a First Process.
  * @param [in] b Second Process.
  * @return returns either the first process is lesser than the second or not.
  */

bool sortByBurstTime(Process& a,Process& b){
    return a.getBurstTime() < b.getBurstTime();

}
/***
  * Comparison function to sort a process by its id.
  *
  * @param [in] a First Process.
  * @param [in] b Second Process.
  * @return returns either the first process is lesser than the second or not.
  */

bool sortById(Process &a, Process& b){
    return a.getId() < b.getId();
}


/***
  * Prints to console the info about all the scheduled and executed process,
  * sorted by id.  *
  * @param [in] process List of all the executed processes..
  * @param [in] algorithm Algorithm used to schedule them.
  * @return none.
  */
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

/***
  * Moves a process from the top of a list to back of another.
  *
  * @param [in] origin List containing the process to be moved at the top of it.
  * @param [out] destination List where the process will be moved to.
  * @return none.
  */
void moveProcess(std::vector<Process> &origin, std::vector<Process> &destination) {
    if(!origin.empty()){
        destination.push_back(origin.front());
        origin.erase(origin.begin());
    }


}

/***
  * Increments wait, response and return time of each process in both
  * execution and waiting states.  *
  * @param [in] waitExecProcesses List of all the process in execution and waiting state.
  * @return void
  */

void calculateTime(std::vector<Process>& waitExecProcesses){
    /// The first process is always the one in current execution
    waitExecProcesses.front().decrementBurstTime();
    waitExecProcesses.front().incrementReturnTime();

    ///The rest of the process are waiting to be executed
    for(int i = 1; i < waitExecProcesses.size();i++){
        if(waitExecProcesses.at(i).isFirstResponse())
            waitExecProcesses.at(i).incrementResponseTime(); /// Increments until first response
        waitExecProcesses.at(i).incrementReturnTime();
        waitExecProcesses.at(i).incrementWaitTime();
    }

}

/***
  * Used by RR algorithm. Fills the list of execution according to arrival time and process
  * that reached their quantum limit.
  * execution and waiting states.  *
  * @param [in] idleQueue List of process that didn't arrive in CPU and have reached quantum limit.
  * @param [out] readyExecQueue List of process that are executing or waiting to be executed.
  * @param [in] currentTime Current time in the CPU.
  * @return void
  */
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

/***
  * Class Constructor.
  * @param [in] file FileUtil object containg the processes load from file.
  * @return returns a Scheduler object.
  */

Scheduler::Scheduler(FileUtil* file):file(file) {


}

/***
  * It returns the list of executed and schedule process by a algorithm.
  * @param none
  * @return List os process.
  */
std::vector<Process> Scheduler::getProcesslist() {
    return executedQueue;

}

/***
  * Calculates the average of return, wait and response times of all processes scheduled.
  * @param none
  * @return none
  */

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

/***
  * Schedule a set of load processes according to the select algorithm.
  * @param [in] algorithm Which algorithm will be used (FCFS, SJF or RR).
  * @return none.
  */

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

/***
  * Schedule the processes using the First Come First Served algorithm.
  * @param none
  * @return none
  */

void Scheduler::fcfs() {

    ClearAll();
    int currentTime;
    idleQueue = file->getProcess();
    std::sort(idleQueue.begin(),idleQueue.end(),sortByArrival);
    int n_process = idleQueue.size();

    currentTime = idleQueue.front().getArrivalTime(); ///advance time to point of start of the first process

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

/***
  * Schedule the processes using the Shortest Job First algorithm.
  * @param none
  * @return none
  */


void Scheduler::sjf() {
    ClearAll();
    int currentTime;
    idleQueue = file->getProcess();

    int n_process = idleQueue.size();

    std::sort(idleQueue.begin(),idleQueue.end(),sortByArrival);
    currentTime = idleQueue.front().getArrivalTime(); ///advance time to point of start of the first process


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

/***
  * Schedule the processes using the Round Robin algorithm with Quantum.
  * @param none
  * @return none
  */

void Scheduler::rr() {
    ClearAll();
    int currentTime;
    idleQueue = file->getProcess();
    std::sort(idleQueue.begin(),idleQueue.end(),sortByArrival);

    int n_process = idleQueue.size();
    int quantum = 0;
    currentTime = idleQueue.front().getArrivalTime(); ///advance time to point of start of the first process
    while(executedQueue.size() < n_process){

        fillReadyExecQueue(idleQueue,readyExecQueue,aux,currentTime);
        if(!idleQueue.empty() && readyExecQueue.empty()) { //advance time while cpu is in idle state
            currentTime = idleQueue.front().getArrivalTime();
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


/***
  * Returns the Wait Average of all the processes.
  * @param none
  * @return double value representing the average.
  */

double Scheduler::getWaitAverage() {return this->waitAverage;}

/***
  * Returns the Response Average of all the processes.
  * @param none
  * @return double value representing the average.
  */

double Scheduler::getResponseAverage() {return this->responseAverage;}

/***
  * Returns the Return Average of all the processes.
  * @param none
  * @return double value representing the average.
  */

double Scheduler::getReturnAverage() {return this->returnAverage;}

/***
  * Sets all the lists and averages to standard values.
  * @param none
  * @return none
  */

void Scheduler::ClearAll() {
    this->readyExecQueue.clear();
    this->idleQueue.clear();
    this->executedQueue.clear();
    this->aux.clear();
    this->responseAverage = this->waitAverage = this->returnAverage = 0;

}





