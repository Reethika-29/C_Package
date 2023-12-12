
// C program for implementation of FCFS scheduling
#include<stdio.h>

void findWaitingTime( int processes[ ] , int n ,
                     int bt[ ], int wt[ ])
{
    // waiting time for first process is 0
    wt[ 0 ] = 0;

    // calculating waiting time
    for ( int i = 1 ; i < n ; i++ )
        wt[ i ] = bt[ i - 1 ] + wt[ i - 1 ] ;
}

void findTurnAroundTime ( int processes[ ], int n,
                        int bt[ ] , int wt [ ] , int tat[ ] )
{
    for(int i=0;i<n;i++)
    {
        tat[i] = bt[i] + wt[i];
    }

}

// Function to calculate average time
void findavgTime(int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // waiting time of all processes
    findWaitingTime(processes, n, bt, wt);

    // turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("Processes Burst time Waiting time Turn around time\n");

    // Calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf(" %d ", (i + 1));
        printf("         %d ", bt[i]);
        printf("         %d", wt[i]);
        printf("            %d\n", tat[i]);
    }
    int s = (float)total_wt / (float)n;
    int t = (float)total_tat / (float)n;
    printf("Average waiting time = %d", s);
    printf("\n");
    printf("Average turn around time = %d ", t);
}

void drawGanttChart(int processes[], int n, int bt[]) {
    int startTime[n], endTime[n];
    int currentTime = 0;

    // Calculate start and end times for each process
    for (int i = 0; i < n; i++) {
        startTime[i] = currentTime;
        endTime[i] = currentTime + bt[i];
        currentTime = endTime[i];
    }

    // Draw Gantt chart
    printf("\nGantt Chart:\n");
    printf(" ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bt[i]; j++) {
            printf("--");
        }
        printf(" ");
    }
    printf("\n|");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bt[i] - 1; j++) {
            printf(" ");
        }
        printf("P%d", processes[i] + 1);

        for (int j = 0; j < bt[i] - 1; j++) {
            printf(" ");
        }
        printf("|");
    }
    printf("\n ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bt[i]; j++) {
            printf("--");
        }
        printf(" ");
    }
    printf("\n");

    // Print timeline
    printf("0");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bt[i]; j++) {
            printf("  ");
        }
        printf("%d", endTime[i]);
    }
    printf("\n\n");
}

int main()
{
    // process id's
    int n;
    printf("\nEnter number of processes: ");
    scanf("%d",&n);
    int process[n];
    int burst_time[n];
    for(int i=0;i<n;i++)
    {
         process[i]=i;
         printf("\nEnter burst time of process %d:",i+1);
         scanf("%d",&burst_time[i]);
    }


    findavgTime(process, n, burst_time);
    drawGanttChart(process, n, burst_time);
    return 0;
}
