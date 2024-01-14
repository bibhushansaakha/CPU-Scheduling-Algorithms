#include<iostream>
using namespace std;

struct Process {
    int processId;
    int burstTime;
    int arrivalTime;
};

void bubbleSort(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                // Swap processes[j] and processes[j+1]
                swap(processes[j], processes[j + 1]);
            }
        }
    }
}

void calculateTimes(Process processes[], int n, int wt[], int ct[], int tat[]) {
    bubbleSort(processes, n);

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }

        wt[i] = currentTime - processes[i].arrivalTime;
        currentTime += processes[i].burstTime;
        ct[i] = currentTime;
        tat[i] = ct[i] - processes[i].arrivalTime;
    }

    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; i++)
        cout << processes[i].processId << "\t" << processes[i].arrivalTime << "\t\t" << processes[i].burstTime << "\t\t"
             << ct[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << endl;

    // Calculate and display average burst time
    double averageBurstTime = 0;
    for (int i = 0; i < n; i++)
        averageBurstTime += processes[i].burstTime;

    averageBurstTime /= n;

    cout << "\nAverage Burst Time: " << averageBurstTime << endl;
}

int main() {
    const int n = 5;
    Process processes[n];
    int waitingTime[n], completionTime[n], turnaroundTime[n];

    cout << "Enter Arrival Time and Burst Time for 5 processes:\n";
    for (int i = 0; i < n; i++) {
        processes[i].processId = i + 1;
        cout << "Process " << processes[i].processId << " Arrival Time: ";
        cin >> processes[i].arrivalTime;
        cout << "Process " << processes[i].processId << " Burst Time: ";
        cin >> processes[i].burstTime;
    }

    calculateTimes(processes, n, waitingTime, completionTime, turnaroundTime);

    return 0;
}
