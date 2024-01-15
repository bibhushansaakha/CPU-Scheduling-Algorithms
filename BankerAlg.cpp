#include <iostream>
using namespace std;

const int MAX_PROCESSES = 5; // Maximum number of processes
const int MAX_RESOURCES = 3; // Maximum number of resource types

int available[MAX_RESOURCES] = {10, 5, 7};                                                              // Available resources
int maximum[MAX_PROCESSES][MAX_RESOURCES] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};    // Maximum claim by each process
int allocation[MAX_PROCESSES][MAX_RESOURCES] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}}; // Resources currently allocated to each process

void printState()
{
    cout << "Available Resources: ";
    for (int i = 0; i < MAX_RESOURCES; i++)
    {
        cout << available[i] << " ";
    }
    cout << endl;

    cout << "Process:   Max Resources:\tAlloc Resources:\n";
    for (int i = 0; i < MAX_PROCESSES; i++)
    {
        cout << i << ": \t\t";
        for (int j = 0; j < MAX_RESOURCES; j++)
        {
            cout << maximum[i][j] << " ";
        }
        cout << "\t\t";
        for (int j = 0; j < MAX_RESOURCES; j++)
        {
            cout << allocation[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int process, int request[MAX_RESOURCES])
{
    // Check if the request is less than or equal to the available resources
    for (int i = 0; i < MAX_RESOURCES; i++)
    {
        if (request[i] > available[i])
        {
            return false;
        }
    }

    // Assume the allocation and available resources to check safety
    int tempAvailable[MAX_RESOURCES];
    int tempAllocation[MAX_PROCESSES][MAX_RESOURCES];

    for (int i = 0; i < MAX_RESOURCES; i++)
    {
        tempAvailable[i] = available[i] - request[i];
        tempAllocation[process][i] = allocation[process][i] + request[i];
    }

    int need[MAX_PROCESSES][MAX_RESOURCES];
    for (int i = 0; i < MAX_PROCESSES; i++)
    {
        for (int j = 0; j < MAX_RESOURCES; j++)
        {
            need[i][j] = maximum[i][j] - tempAllocation[i][j];
        }
    }

    // Check for safety
    bool finish[MAX_PROCESSES] = {false};
    int count = 0;

    while (count < MAX_PROCESSES)
    {
        bool found = false;

        for (int i = 0; i < MAX_PROCESSES; i++)
        {
            if (!finish[i])
            {
                int j;
                for (j = 0; j < MAX_RESOURCES; j++)
                {
                    if (need[i][j] > tempAvailable[j])
                    {
                        break;
                    }
                }

                if (j == MAX_RESOURCES)
                {
                    for (int k = 0; k < MAX_RESOURCES; k++)
                    {
                        tempAvailable[k] += tempAllocation[i][k];
                    }

                    finish[i] = true;
                    found = true;
                    count++;
                }
            }
        }

        if (!found)
        {
            break;
        }
    }

    // Check if all processes are finished
    return count == MAX_PROCESSES;
}

void requestResources(int process, int request[MAX_RESOURCES])
{
    if (isSafe(process, request))
    {
        // Grant the request
        for (int i = 0; i < MAX_RESOURCES; i++)
        {
            available[i] -= request[i];
            allocation[process][i] += request[i];
        }

        cout << "Request granted. System is in safe state.\n";
        printState();
    }
    else
    {
        cout << "Request denied. Granting the request may lead to an unsafe state.\n";
    }
}

int main()
{
    int process;
    int request[MAX_RESOURCES];

    // Print the initial state
    cout << "Initial System State:\n";
    printState();

    // Input request
    cout << "\nEnter process number (0 to 4): ";
    cin >> process;

    cout << "Enter resource request (e.g., 0 1 0): ";
    for (int i = 0; i < MAX_RESOURCES; i++)
    {
        cin >> request[i];
    }

    // Check and process the request
    if (process >= 0 && process < MAX_PROCESSES)
    {
        requestResources(process, request);
    }
    else
    {
        cout << "Invalid process number.\n";
    }

    return 0;
}
