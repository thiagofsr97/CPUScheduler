//
// Created by thiagofsr on 09/04/18.
//

#ifndef CPUSCHEDULER_FILEREADER_H
#define CPUSCHEDULER_FILEREADER_H


#include <fstream>
#include <vector>
#include "Scheduler.h"
#include "Process.h"

class FileUtils {
private:
    std::fstream inputFile;
    std::fstream outputFile;
public:
    FileUtils(std::string inputPath, std::string outputPath);
    ~FileUtils();
    std::vector<Process> getProcess();
    void appendToLog(scheduleAlgorithm,std::array<double,3>);


};


#endif //CPUSCHEDULER_FILEREADER_H
