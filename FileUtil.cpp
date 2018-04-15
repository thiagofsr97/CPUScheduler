/**
 *  @file    FileUtil.cpp
 *  @author  Thiago Filipe Soares da Rocha
 *  @date    04/15/2018
 *  @version 1.0
 *
 *  @brief Implementation of a File Utilitary.
 *
 */


#include "FileUtil.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#define ErrorOpenFile(filePath) std::cout << "Error opening file in the path: " << filePath << std::endl; exit(1);

/***
  * Class Constructor of a File Utilitary. Opens up both input and output files
  * to manipulation.
  * @param [in] inputPath Path of the input File.
  * @param [out] outputPath Path of the output file.
  * @return FileUtil object.
  */

FileUtil::FileUtil(std::string inputPath, std::string outputPath) {
    inputFile.open(inputPath,std::ios::in);
    outputFile.open(outputPath,std::ios::out);
    if(!inputFile.is_open()){ErrorOpenFile(inputPath);}
    if(!outputFile.is_open()){ ErrorOpenFile(outputPath);}

}

/***
  * Reads the input file, loading all the processes into a vector of processes.
  * @param none
  * @return list of processes to be executed.
  */
std::vector<Process> FileUtil::getProcess() {
    std::string line; char* aux;
    int executionTime, arrivalTime;

    if(processList.empty()) {
        while (!inputFile.eof()) {
            getline(inputFile, line);
            if (!line.empty()) {
                aux = strdup(line.c_str());
                char *tokenized = strtok(aux, " ");

                arrivalTime = std::stoi(tokenized, NULL, 10);
                tokenized = strtok(NULL, " ");
                executionTime = std::stoi(tokenized);
                processList.push_back(Process(executionTime, arrivalTime));
            }

        }
    }

    return processList;

}

/***
  * Object Destructor. Closes up all the files previously opened.
  * @param none.
  * @return none
  */

FileUtil::~FileUtil() {
    inputFile.close();
    outputFile.close();

}

/***
  * Appends information of the averages times of a Scheduling Algorithm to the output file.
  * @param [in] algorithm Which algorithm was used in the scheduling.
  * @param [in] returnAverage The return average of the processes.
  * @param [in] responseAverage The response average of the processes.
  * @param [in] waitAverage The wait average of the processes.
  * @return none
  */
void FileUtil::appendToLog(scheduleAlgorithm algorithm, double returnAverage,double responseAverage,double waitAverage ){
    std::string algorithmName;
    switch(algorithm){
        case FCFS:
            algorithmName = "FCFS";
            break;
        case SJF:
            algorithmName = "SJF";
            break;
        case RR:
            algorithmName = "RR";
            break;

    }
    outputFile << algorithmName << " " <<std::setprecision (4) << returnAverage << " " << std::setprecision (4)<< responseAverage << " " <<std::setprecision (4) <<waitAverage << std::endl;

}
