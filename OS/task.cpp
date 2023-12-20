#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
};
void roundRobinScheduling(vector<Process>& processes, int time_slice) {
    int n = processes.size();
    int total_time = 0;
    int time_quantum = time_slice;
    queue<Process> processQueue;
    vector<pair<int, int>> timeChart;
    for (Process& process : processes) {
        total_time += process.burst_time;
        process.remaining_time = process.burst_time;
    }
    int currentTime = 0;
    int i = 0;
    while (currentTime < total_time) {
        Process& currentProcess = processes[i % n];
        if (currentProcess.remaining_time > 0) {
            int executeTime = min(time_quantum, currentProcess.remaining_time);
            currentProcess.remaining_time -= executeTime;
            currentTime += executeTime;
            timeChart.push_back({currentProcess.pid, currentTime});
        } else {
            i++;
            continue;
        }
        if (currentProcess.remaining_time == 0) {
            i++;
        }
    }
    cout << "Round Robin Scheduling:" << endl;
    cout << "Process\tTurnaround Time" << endl;
    for (const Process& process : processes) {
        int turnaroundTime = max(timeChart.back().second - process.arrival_time, 0);
        cout << "P" << process.pid << "\t\t" << turnaroundTime << endl;
    }
}
int main() {
    vector<Process> processes = {
        {1, 0, 0, 0},
        {2, 1, 0, 0},
        {3, 2, 0, 0},
        {4, 3, 0, 0},
        {5, 4, 0, 0},
        {6, 5, 0, 0}
    };
    for (Process& process : processes) {
        cout << "Enter burst time for P" << process.pid << ": ";
        cin >> process.burst_time;
    }
    int timeSlice = 3;
    roundRobinScheduling(processes, timeSlice);
}