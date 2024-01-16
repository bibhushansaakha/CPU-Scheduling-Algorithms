#include<iostream>
using namespace std;

// Structure to represent a process
struct Process {
    int processId;      // Unique identifier for the process
    int burstTime;      // Time required by the process for execution
    int arrivalTime;    // Time at which the process arrives in the system
};

// Function to implement the Bubble Sort algorithm for sorting processes by burst time
void bubbleSort(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Compare burst times of adjacent processes
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                // Swap processes[j] and processes[j+1] if they are out of order
                swap(processes[j], processes[j + 1]);
            }
        }
    }
}

// Function to calculate waiting time, completion time, turnaround time, and display the results
void calculateTimes(Process processes[], int n, int wt[], int ct[], int tat[]) {
    // Sort processes based on burst time using the Bubble Sort algorithm
    bubbleSort(processes, n);

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        // Check if the current time is less than the arrival time of the current process
        if (currentTime < processes[i].arrivalTime) {
            // If so, update the current time to the arrival time of the current process
            currentTime = processes[i].arrivalTime;
        }

        // Calculate waiting time, completion time, and turnaround time for the current process
        wt[i] = currentTime - processes[i].arrivalTime;
        currentTime += processes[i].burstTime;
        ct[i] = currentTime;
        tat[i] = ct[i] - processes[i].arrivalTime;
    }

    // Display a table with the calculated metrics for each process
    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; i++)
        cout << processes[i].processId << "\t" << processes[i].arrivalTime << "\t\t" << processes[i].burstTime << "\t\t"
             << ct[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << endl;

    // Calculate and display the average burst time for all processes
    double averageBurstTime = 0;
    for (int i = 0; i < n; i++)
        averageBurstTime += processes[i].burstTime;

    averageBurstTime /= n;

    cout << "\nAverage Burst Time: " << averageBurstTime << endl;
}

// Main function where the program starts execution
int main() {
    const int n = 5;
    Process processes[n];
    int waitingTime[n], completionTime[n], turnaroundTime[n];

    // Prompt the user to input arrival and burst times for each process
    cout << "Enter Arrival Time and Burst Time for 5 processes:\n";
    for (int i = 0; i < n; i++) {
        processes[i].processId = i + 1;
        cout << "Process " << processes[i].processId << " Arrival Time: ";
        cin >> processes[i].arrivalTime;
        cout << "Process " << processes[i].processId << " Burst Time: ";
        cin >> processes[i].burstTime;
    }

    // Calculate and display waiting time, completion time, turnaround time, and average burst time
    calculateTimes(processes, n, waitingTime, completionTime, turnaroundTime);

    return 0;
}
