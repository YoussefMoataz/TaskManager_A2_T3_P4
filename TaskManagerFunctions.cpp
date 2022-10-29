//
// Created by Youssef Moataz on 10/29/2022.
//
#include "TaskManagerHeader.h"

void RunningProcesses::getAndPrintRunningProcesses(){

// Get the list of process identifiers.

    DWORD aProcesses[1024], cbNeeded, cProcesses;
    unsigned int i;

    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {
        return;
    }


    // Calculate how many process identifiers were returned.

    cProcesses = cbNeeded / sizeof(DWORD);

    // Print the name and process identifier for each process.

    DWORD processID;

    for (i = 0; i < cProcesses; i++) {
        if (aProcesses[i] != 0) {
//            PrintProcessNameAndID(aProcesses[i]);

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
                _tprintf(TEXT("%llu  (PID: %u) - "), pmc.WorkingSetSize);


                // Print the process name and identifier.

                _tprintf(TEXT("%s  (PID: %u)\n"), szProcessName, processID);
            }
            // Release the handle to the process.

            CloseHandle(hProcess);

        }
    }

}