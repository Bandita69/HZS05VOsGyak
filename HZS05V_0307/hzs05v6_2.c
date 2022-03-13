// C++ program to SJF
#include <bits/stdc++.h>
using namespace std;
 
struct Process {
    int pid;
    int bt; 	//cpu ido
    int art; //erkezes
};
 


void findWaitingTime(Process proc[], int n,
                                int wt[])
{
    int rt[n];
 

    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;
 
    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;
 

    while (complete != n) {
 
        for (int j = 0; j < n; j++) {
            if ((proc[j].art <= t) &&
            (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }
 
        if (check == false) {
            t++;
            continue;
        }
 

        rt[shortest]--;
 

        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;
 

        if (rt[shortest] == 0) {
 

            complete++;
            check = false;
 
            finish_time = t + 1;
            wt[shortest] = finish_time -
                        proc[shortest].bt -
                        proc[shortest].art;
 
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }

        t++;
    }
}
 

void findTurnAroundTime(Process proc[], int n,
                        int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}
 

void findavgTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0,
                    total_tat = 0;
 
    findWaitingTime(proc, n, wt);
 
    findTurnAroundTime(proc, n, wt, tat);
 
    cout << "SJF        "
        << " CPU ido      "
        << " Varakozasi ido     "
        << " Befejezsi ido      "
	<< " Erkezesi ido\n";

    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << proc[i].pid << "\t\t"
            << proc[i].bt << "\t\t " << wt[i]
            << "\t\t " << tat[i] << "\t\t" << proc[i].art << endl;
    }
 
    cout << "\nAtlag varakozasi ido = "
        << (float)total_wt / (float)n;
    cout << "\nAtlag befejezesi ido = "
        << (float)total_tat / (float)n;
}
 

int main()
{
    Process proc[] = { { 1, 3, 0 }, { 2, 8, 1 },
                    { 3, 2, 3 }, { 4, 20, 9 }, {5, 5, 12} };
    int n = sizeof(proc) / sizeof(proc[0]);
 
    findavgTime(proc, n);
    return 0;
}
