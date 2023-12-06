#include <iostream>
using namespace std;

class Process
{
public:
    int pid;
    int wt;
    int bt;
    int tt;
    Process(int b, int p)
    {
        pid = p;
        bt = b;
    }
};

class ProcessQueue
{
    Process *pArray[3];

public:
    void swapProcess(Process &p1, Process &p2)
    {
        Process temp = p1;
        p1 = p2;
        p2 = temp;
    }

    void insertProcesses()
    {
        for (int i = 0; i < 3; i++)
        {
            int b;
            cout << "Please enter the process " << i + 1 << " burst time: " << endl;
            cin >> b;
            pArray[i] = new Process(b, i + 1);
        }
    }

    void displayAll()
    {
        for (int i = 0; i < 3; i++)
        {
            if (i == 0)
            {
                pArray[i]->wt = 0;
                pArray[i]->tt = pArray[i]->bt;
            }
            else
            {
                pArray[i]->wt = pArray[i - 1]->bt + pArray[i - 1]->wt;
                pArray[i]->tt = pArray[i]->wt + pArray[i]->bt;
            }
        }

        cout << "Process\t\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "P" << i + 1 << "\t\t" << pArray[i]->bt << "\t\t" << pArray[i]->wt << "\t\t" << pArray[i]->tt << endl;
        }
    }

    void displayShortestJobFirst()
    {
        // Sort the processes in ascending order based on burst time
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3 - i - 1; j++)
            {
                if (pArray[j]->bt > pArray[j + 1]->bt)
                {
                    swapProcess(*pArray[j], *pArray[j + 1]);
                }
            }
        }

        // calculate the waiting times and turnaround times then display
        displayAll();
    }
};

int main() 
{
    ProcessQueue *pq = new ProcessQueue();

    pq->insertProcesses();
    // pq->displayAll();
    pq->displayShortestJobFirst();

    return 0;
}
