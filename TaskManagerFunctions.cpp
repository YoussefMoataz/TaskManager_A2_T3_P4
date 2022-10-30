/*
FCAI - Programming 2 - 2022 - Assignment 2 - Sheet 2 - Problem 4
Program Name:           Task Manager
Program Description:    This program shows running processes Name, ID, Memory Usage.
Last Modification Date: October 29, 2022
Version:                v1.0.0
Author:                 Youssef Moataz
ID:                     20210488
Group:                  A
Labs:                   S10
Purpose:                Make little task manager in the terminal.
*/

#include "TaskManagerHeader.h"

Process::Process(string pName, string pID, string pMemoryUsage) {

    ProcessName = pName;
    ProcessID = pID;
    ProcessMemoryUsage = pMemoryUsage;

}

string Process::getProcessName() {
    return ProcessName;
}

string Process::getProcessID() {
    return ProcessID;
}

string Process::getProcessMemoryUsage() {
    return ProcessMemoryUsage;
}

void RunningProcesses::getAndPrintRunningProcesses() {

    // Get the list of processes.
    DWORD aProcesses[1024], cbNeeded, cProcesses;
    unsigned int i;

    // dont know
    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {
        return;
    }

    // Calculate how many process identifiers were returned.
    cProcesses = cbNeeded / sizeof(DWORD);

    // Print the name and process identifier for each process.
    DWORD processID;

    string processNameToAdd;
    string processIDToAdd;
    string processMemoryUsageToAdd;

    for (i = 0; i < cProcesses; i++) {
        if (aProcesses[i] != 0) {

            processID = aProcesses[i];

            TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

            // Get a handle to the process.
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
                                          PROCESS_VM_READ,
                                          FALSE, processID);

            // Get the process name.
            if (NULL != hProcess) {
                HMODULE hMod;
                DWORD cbNeeded;

                if (EnumProcessModules(hProcess, &hMod, sizeof(hMod),
                                       &cbNeeded)) {
                    GetModuleBaseName(hProcess, hMod, szProcessName,
                                      sizeof(szProcessName) / sizeof(TCHAR));
                }
            }

            PROCESS_MEMORY_COUNTERS pmc;
            if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc))) {
//                _tprintf(TEXT("%llu  (PID: %u) - "), pmc.WorkingSetSize / 8 / 1024);

                processMemoryUsageToAdd = to_string(pmc.WorkingSetSize / 8 / 1024);


                // Print the process name and identifier.
//                _tprintf(TEXT("%s  (PID: %u)\n"), szProcessName, processID);

                processNameToAdd = szProcessName;
                processIDToAdd = to_string(processID);

                // testing
//                cout << processNameToAdd << endl << endl;
//                cout << processIDToAdd << endl << endl;
//                cout << processMemoryUsageToAdd << endl << endl;

                RunningProcesses.push_back(Process(processNameToAdd, processIDToAdd, processMemoryUsageToAdd));

            }

            // Release the handle to the process.
            CloseHandle(hProcess);

        }
    }

//    cout << RunningProcesses[RunningProcesses.size() - 1].getProcessName();

    // print the running processes
    printTheRunningProcesses();


}

void RunningProcesses::printTheRunningProcesses(){
    cout << setw(NamePrintLength) << left << "Name" << setw(IDPrintLength) << left << "ID"
         << setw(MemoryUsedPrintLength) << right << "Memory Used" << endl;

    cout << right << setw(NamePrintLength) << setfill('-') << " " << setw(IDPrintLength) << right << setfill('-') << " "
         << setw(MemoryUsedPrintLength) << left << setfill('-') << " " << endl;
    cout << setfill(' ');

    for (int j = 0; j < RunningProcesses.size(); ++j) {

        cout << setw(NamePrintLength) << left << RunningProcesses[j].getProcessName()
             << setw(IDPrintLength) << left << RunningProcesses[j].getProcessID()
             << setw(MemoryUsedPrintLength) << right << RunningProcesses[j].getProcessMemoryUsage() + " kb" << endl;

    }
}