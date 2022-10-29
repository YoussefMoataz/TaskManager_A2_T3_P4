//
// Created by Youssef Moataz on 10/29/2022.
//

#ifndef TASKMANAGER_A2_T3_P4_TASKMANAGERHEADER_H
#define TASKMANAGER_A2_T3_P4_TASKMANAGERHEADER_H

#endif //TASKMANAGER_A2_T3_P4_TASKMANAGERHEADER_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>

using namespace std;

inline int NamePrintLength = 35;
inline int IDPrintLength = 20;
inline int MemoryUsedPrintLength = 20;

class Process{

private:
    string ProcessName;
    string ProcessID;
    string ProcessMemoryUsage;
public:
    inline Process(string pName, string pID, string pMemoryUsage);
    inline string getProcessName();
    inline string getProcessID();
    inline string getProcessMemoryUsage();
};

class RunningProcesses{
private:
    vector<Process> RunningProcesses;
    inline void printTheRunningProcesses();
public:
    inline void getAndPrintRunningProcesses();

};
