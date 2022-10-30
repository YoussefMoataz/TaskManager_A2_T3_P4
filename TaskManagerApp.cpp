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

#include "TaskManagerFunctions.cpp"

int main() {

    RunningProcesses().getAndPrintRunningProcesses();

    return 0;
}