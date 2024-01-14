#include<iostream>
using namespace std;

struct Process {
    int processId;
    int burstTime;
    int arrivalTime;
};

void calculateTimesRoundRobin(Process processes[], int n, int wt[], int ct[], int tat[], int timeSlice) {
    int remainingBurstTime[n];

    for (int i = 0; i < n; i++) {
        remainingBurstTime[i] = processes[i].burstTime;
    }

    int currentTime = 0;

    while (true) {
        bool allProcessesCompleted = true;

        for (int i = 0; i < n; i++) {
            if (remainingBurstTime[i] > 0) {
                allProcessesCompleted = false;

                int executionTime = min(remainingBurstTime[i], timeSlice);
                remainingBurstTime[i] -= executionTime;
                currentTime += executionTime;

                if (remainingBurstTime[i] == 0) {
                    ct[i] = currentTime;
                    tat[i] = ct[i] - processes[i].arrivalTime;
                    wt[i] = tat[i] - processes[i].burstTime;
                }
            }
        }

        if (allProcessesCompleted) {
            break;
        }
    }

    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; i++)
        cout << processes[i].processId << "\t" << processes[i].arrivalTime << "\t\t" << processes[i].burstTime << "\t\t"
             << ct[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << endl;
}

int main() {
    const int n = 5;
    Process processes[n];
    int waitingTime[n], completionTime[n], turnaroundTime[n];
    int timeSlice;

    cout << "Enter Time Slice for Round Robin: ";
    cin >> timeSlice;

    cout << "Enter Arrival Time and Burst Time for 5 processes:\n";
    for (int i = 0; i < n; i++) {
        processes[i].processId = i + 1;
        cout << "Process " << processes[i].processId << " Arrival Time: ";
        cin >> processes[i].arrivalTime;
        cout << "Process " << processes[i].processId << " Burst Time: ";
        cin >> processes[i].burstTime;
    }

    calculateTimesRoundRobin(processes, n, waitingTime, completionTime, turnaroundTime, timeSlice);

    return 0;
}
