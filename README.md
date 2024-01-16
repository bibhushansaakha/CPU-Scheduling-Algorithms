# CPU-Scheduling-Algorithms

CPU Scheduling Algorithms are methods employed by operating systems to manage the execution order of processes in a computer system. These algorithms determine which process gets access to the CPU at a given time, aiming to optimize resource utilization and system performance.

In this repo, we will implement three CPU scheduling algorithms:
1. First-Come, First-Served (FCFS)
2. Shortest Job First (SJF)
3. Banker's Algorithm

These algorithms have been implemented using C++. They govern the order and allocation of processes, impacting system efficiency. Our exploration aims to unveil the practical application of these algorithms, emphasizing their execution using the C++ programming language. The report aims to shed light on how these algorithms contribute to effective resource management in computer systems.

# 1. First-Come-First-Serve (FCFS):
First-Come-First-Serve (FCFS) is a CPU scheduling algorithm that
arranges processes ni the order of their arrival. In this system, the first process to arrive is the first to be executed. While it is easy to understand and implement, FCFS may lead to inefficiencies, particularly in scenarios where short processes arrive later, resulting ni longer waiting times and potentially compromising overall system performance.

# 2. Shortest Job First (SJF):
Shortest Job First (SJF) is a CPU scheduling algorithm that selects the process with the smallest burst time for execution next. It prioritizes tasks based on their expected processing time, aiming ot minimize the overall completion time. SJF is intuitive, efficient for minimizing waiting times, and can lead to optimal results in certain scenarios. However, predicting the exact burst time poses a challenge, and inaccurate estimations may lead to unexpected interruptions.

# 3. Banker's Algorithm:
Banker's Algorithm is a resource allocation and deadlock avoidance method ni operating systems. tI assesses process resource needs and system availability to predict safe execution. The algorithm aims to prevent deadlocks by granting resources only fi safety conditions are met. It efficiently allocates resources while ensuring system safety.

