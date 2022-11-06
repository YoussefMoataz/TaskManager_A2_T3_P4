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

#include "TaskManagerHeader.h"

Process::Process(string pName, int pID, string pMemoryUsage) {

    ProcessName = pName;
    ProcessID = pID;
    ProcessMemoryUsage = pMemoryUsage;

}

string Process::getProcessName() {
    return ProcessName;
}

int Process::getProcessID() {
    return ProcessID;
}

string Process::getProcessMemoryUsage() {
    return ProcessMemoryUsage;
}

void RunningProcesses::getRunningProcesses() {


    // save "tasklist" command output to file
    system("tasklist > RecentTasks.txt");

    // open that file
    ifstream tasksDataFile("RecentTasks.txt");

    // vector to store each line
    vector<string> dataLines;

    // represents a line from file
    string line;

    // fill the vector by reading the file line by line
    while (getline(tasksDataFile, line)) {

        dataLines.push_back(line);

    }

    // remove first 3 lines
    dataLines.erase(dataLines.begin(), dataLines.begin() + 3);

//    cout << dataLines[0];

    for (int i = 0; i < dataLines.size(); ++i) {

        string currentItem = dataLines[i];

        RunningProcesses.push_back(Process(currentItem.substr(0, 25),
                                           stoi(currentItem.substr(27, 8)),
                                           currentItem.substr(65, 9)));

    }

    showMenu();

}

void RunningProcesses::showMenu() {

    string sortOption;
    while (true) {
        cout << "Enter 1 to sort by Name" << endl;
        cout << "Enter 2 to sort by Process ID" << endl;
        cout << "Enter 3 to sort by Memory Usage" << endl;
        cin >> sortOption;

        if (sortOption == "1") {

            sort(RunningProcesses.begin(), RunningProcesses.end(), [](Process &lhs, Process &rhs) {
                return lhs.getProcessName() < rhs.getProcessName();
            });

            break;
        } else if (sortOption == "2") {

            sort(RunningProcesses.begin(), RunningProcesses.end(), [](Process &lhs, Process &rhs) {
                return lhs.getProcessID() < rhs.getProcessID();
            });

            break;
        } else if (sortOption == "3") {

            sort(RunningProcesses.begin(), RunningProcesses.end(), [](Process &lhs, Process &rhs) {
                return lhs.getProcessMemoryUsage() < rhs.getProcessMemoryUsage();
            });

            break;
        } else {
            cout << "Enter a valid option" << endl;
        }
    }

    // print the running processes
    printTheRunningProcesses();

}

void RunningProcesses::printTheRunningProcesses() {
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

// End of the file