#include <iostream>
using namespace std;

class Process
{

public:
    int wt;
    int bt;
    int tt;
    Process(int b)
    {

        bt = b;
    }
};

class ProcessQueue
{
    Process *pArray[3];

public:
    void insertProcesses()
    {
        for (int i = 0; i < 3; i++)
        {
            int b;
            cout << "Please enter the process " << i + 1 << " burst time: " << endl;
            cin >> b;
            pArray[i] = new Process(b);
        }
    }

    void displayAll()
    {
        //display the proccess table using the burst time information to calculate the waiting time and turn around time
        //modifying the waiting time and the turn around time of each process
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
};

int main()
{
    ProcessQueue *pq = new ProcessQueue();

    pq->insertProcesses();
    pq->displayAll();

    return 0;
}