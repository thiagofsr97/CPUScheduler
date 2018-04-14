//
// Created by thiagofsr on 09/04/18.
//

#ifndef CPUSCHEDULER_FILEUTIL_H
#define CPUSCHEDULER_FILEUTIL_H


#include <fstream>
#include <vector>
#include "Utils.h"
#include <array>

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
    void appendToLog(scheduleAlgorithm,std::array<double,3>);


};


#endif //CPUSCHEDULER_FILEUTIL_H
