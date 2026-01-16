#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main() {
    int p[20], rem_bt[20];
    float bt[20], wt[20], tat[20];
    int i, n, time = 0, count, quantum;
    float wtavg = 0, tatavg = 0;
    
    system("clear");
    
    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);
    
    printf("Enter the time quantum -- ");
    scanf("%d", &quantum);
    
    for(i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter Burst Time for Process %d -- ", i);
        scanf("%f", &bt[i]);
        rem_bt[i] = (int)bt[i];  
        wt[i] = 0.0f;         
    }
    
    count = n;  
    while(count > 0) {
        for(i = 0; i < n; i++) {
            if(rem_bt[i] > 0) {
                if(rem_bt[i] > quantum) {
                    
                    time += quantum;
                    rem_bt[i] -= quantum;
                } else {
                
                    time += rem_bt[i];
                    wt[i] = (float)time - bt[i];  
                    rem_bt[i] = 0;
                    count--;
                }
            }
        }
    }
   
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];  
        wtavg += (float)wt[i];
        tatavg += (float)tat[i];
    }

    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++) {
        printf("\n\tP%d\t\t%.2f\t\t%.2f\t\t%.2f", p[i], bt[i], wt[i], tat[i]);
    }
    
    printf("\nAverage Waiting Time -- %f", wtavg / (float)n);
    printf("\nAverage Turnaround Time -- %f", tatavg / (float)n);
    
    getchar();
    return 0;
}
