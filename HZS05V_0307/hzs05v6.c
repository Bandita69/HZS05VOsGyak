// C program for FCFS 
#include<stdio.h>
void findWaitingTime(int processes[], int n, 
                          int bt[], int wt[])
{
    // varakozasi ido az elso processnek 0
    wt[0] = 0;

    // calculating  varakozasi ido
    for (int  i = 1; i < n ; i++ )
        wt[i] =  bt[i-1] + wt[i-1] ;
}

void findTurnAroundTime( int processes[], int n, 
                  int bt[], int wt[], int tat[])
{
    // calculating befejzesi idp
    // bt[i] + wt[i]
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

//Function to calculate atlag ido
void findavgTime( int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    
    findWaitingTime(processes, n, bt, wt);
   
    
    findTurnAroundTime(processes, n, bt, wt, tat);
   
    
    printf("FCFS/Sorrend   CPU ido   Indulas/Varakozas   Befejezes\n");
   
    
    
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("   %d ",(i+1));
        printf("           %d ", bt[i] );
        printf("              %d",wt[i] );
        printf("                   %d\n",tat[i] );
    }
    int s=(float)total_wt / (float)n;
    int t=(float)total_tat / (float)n;
    printf("Atlag varakozasi ido = %d",s);
    printf("\n");
    printf("Atlag befejezesi ido = %d\n ",t);
}
   

int main()
{
    //process id's
    int processes[] = { 1, 2, 3, 4, 5};
    int n = sizeof processes / sizeof processes[0];
   
    //cpu idok
    int  burst_time[] = {3, 8, 2, 20, 5};
   
    findavgTime(processes, n,  burst_time);
    return 0;
}

