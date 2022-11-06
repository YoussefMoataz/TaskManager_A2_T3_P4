/*
FCAI - Programming 2 - 2022 - Assignment 2 - Sheet 2 - Problem 4
Program Name:           Task Manager
Program Description:    This program shows running processes Name, ID, Memory Usage.
Last Modification Date: November 6, 2022
Version:                v1.2.0
Author:                 Youssef Moataz
ID:                     20210488
Group:                  A
Labs:                   S10
Purpose:                Make little task manager in the terminal.
*/

#ifndef TASKMANAGER_A2_T3_P4_TASKMANAGERHEADER_H
#define TASKMANAGER_A2_T3_P4_TASKMANAGERHEADER_H

#endif //TASKMANAGER_A2_T3_P4_TASKMANAGERHEADER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>

using namespace std;

inline int NamePrintLength = 35;
inline int IDPrintLength = 20;
inline int MemoryUsedPrintLength = 20;

class Process {

private:
    string ProcessName;
    int ProcessID;
    string ProcessMemoryUsage;
public:
    inline Process(string pName, int pID, string pMemoryUsage);

    inline string getProcessName();

    inline int getProcessID();

    inline string getProcessMemoryUsage();
};

class RunningProcesses {
private:
    vector<Process> RunningProcesses;

    inline void printTheRunningProcesses();

public:
    inline void getRunningProcesses();

    inline void showMenu();

};

// End of the file