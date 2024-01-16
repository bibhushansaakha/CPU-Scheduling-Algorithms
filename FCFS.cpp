#include <iostream>
using namespace std;

// Define a structure to represent a process with its attributes
struct Process
{
    int processId;      // Unique identifier for the process
    int burstTime;      // Time required by the process for execution
    int arrivalTime;    // Time at which the process arrives in the system
};

// Function to calculate completion time, turnaround time, and waiting time for each process
void calculateTimes(Process processes[], int n, int wt[], int ct[], int tat[])
{
    // Calculate values for the first process
    wt[0] = 0;
    ct[0] = processes[0].burstTime;
    tat[0] = ct[0] - processes[0].arrivalTime;

    // Calculate values for the rest of the processes
    for (int i = 1; i < n; i++)
    {
        wt[i] = ct[i - 1];
        ct[i] = wt[i] + processes[i].burstTime;
        tat[i] = ct[i] - processes[i].arrivalTime;
    }

    // Display a table with the calculated values
    cout << "\nProcess\t| Arrival Time\t| Burst Time\t| Completion Time\t| Turnaround Time\t| Waiting Time\n";
    for (int i = 0; i < n; i++)
        cout << processes[i].processId << "\t| " << processes[i].arrivalTime << "\t\t| " << processes[i].burstTime << "\t\t| "
             << ct[i] << "\t\t\t| " << tat[i] << "\t\t\t| " << wt[i] << endl;
}

int main()
{
    const int n = 5;
    Process processes[n];
    int waitingTime[n], completionTime[n], turnaroundTime[n];

    // Input arrival time and burst time for each process
    cout << "Enter Arrival Time and Burst Time for 5 processes:\n";
    for (int i = 0; i < n; i++)
    {
        processes[i].processId = i + 1;
        cout << "Process " << processes[i].processId << " Arrival Time: ";
        cin >> processes[i].arrivalTime;
        cout << "Process " << processes[i].processId << " Burst Time: ";
        cin >> processes[i].burstTime;
    }

    // Calculate and display completion time, turnaround time, and waiting time
    calculateTimes(processes, n, waitingTime, completionTime, turnaroundTime);

    return 0;
}
