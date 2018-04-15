/**
 *  @file    FileUtil.h
 *  @author  Thiago Filipe Soares da Rocha
 *  @date    04/15/2018
 *  @version 1.0
 *
 *  @brief Header file of a File Utilitary.
 *
 */

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
