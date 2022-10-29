//
// Created by Youssef Moataz on 10/29/2022.
//

#ifndef TASKMANAGER_A2_T3_P4_TASKMANAGERHEADER_H
#define TASKMANAGER_A2_T3_P4_TASKMANAGERHEADER_H

#endif //TASKMANAGER_A2_T3_P4_TASKMANAGERHEADER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>

using namespace std;

class Process{

private:
    string ProcessName;
    string ProcessID;
    string ProcessMemoryUsage;
public:

};

class RunningProcesses{
private:
    vector<Process> RunningProcesses;
public:
    inline void getAndPrintRunningProcesses();
};