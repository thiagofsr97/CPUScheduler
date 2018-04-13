//
// Created by thiagofsr on 09/04/18.
//

#include "FileUtil.h"
#include <iostream>
#include <cstring>


#define ErrorOpenFile(filePath) std::cout << "Error opening file in the path: " << filePath << std::endl; exit(1);

FileUtil::FileUtil(std::string inputPath, std::string outputPath) {
    inputFile.open(inputPath,std::ios::in);
    outputFile.open(outputPath,std::ios::out);
    if(!inputFile.is_open()){ErrorOpenFile(inputPath);}
    if(!outputFile.is_open()){ ErrorOpenFile(outputPath);}

}

std::vector<Process> FileUtil::getProcess() {
    std::vector<Process> processList;
    std::string line; char* aux;
    int executionTime, arrivalTime;
    while(!inputFile.eof()){
        getline(inputFile,line);
        if(!line.empty()) {
            aux = strdup(line.c_str());
            char *tokenized = strtok(aux, " ");

            arrivalTime = std::stoi(tokenized, NULL, 10);
            tokenized = strtok(NULL," ");
            executionTime = std::stoi(tokenized);
            processList.push_back(Process(executionTime, arrivalTime));
        }

    }

    return processList;

}

FileUtil::~FileUtil() {
    inputFile.close();
    outputFile.close();

}

void FileUtil::appendToLog(scheduleAlgorithm algorithm, std::array<double,3> arr) {
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
    outputFile << algorithmName << " " << arr.at(0) << " " << arr.at(1) << " " << arr.at(2) << std::endl;

}
