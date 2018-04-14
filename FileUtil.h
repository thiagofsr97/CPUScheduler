//
// Created by thiagofsr on 09/04/18.
//

#ifndef CPUSCHEDULER_FILEUTIL_H
#define CPUSCHEDULER_FILEUTIL_H


#include <fstream>
#include <vector>
#include "Utils.h"
#include "Process.h"

class FileUtil {
private:
    std::fstream inputFile;
    std::fstream outputFile;
    std::vector<Process> processList;
public:
    FileUtil(std::string inputPath, std::string outputPath);
    ~FileUtil();
    std::vector<Process> getProcess();
    void appendToLog(scheduleAlgorithm,double,double,double);


};


#endif //CPUSCHEDULER_FILEUTIL_H
