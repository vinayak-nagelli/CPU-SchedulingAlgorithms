// Online C compiler to run C program online
#include <stdio.h>

int main() {
    
    
    int n,qt;
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    
    int processes[n],at[n],bt[n],rt[n],ct[n],tat[n],wt[n];
    float total_tat=0,total_wt=0;
    
    for(int i=0;i<n;i++)
      {
           processes[i]=i+1;
           printf("Enter arrival time of P%d:",processes[i]);
            scanf("%d",&at[i]);
           printf("Enter burst time of P%d:",processes[i]);
           scanf("%d",&bt[i]);
           rt[i]=bt[i];
           ct[i]=0;
           
      }//end for
    
    printf("Enter a quantum time: ");
    scanf("%d",&qt);
    
    int completed=0;
    int x=0;
    int time=0;
    int found_process=0;
    
    while(completed<n)
    {
        found_process=0;
        int checked=0;
    while(checked<n)
  {
      if(at[x]<=time && rt[x]>0)
      {
         found_process=1;
        if(rt[x]>qt)
        {
            printf("P%d -> ", processes[x]);
            rt[x]-=qt;
            time+=qt;
        }
        else
           {  
               printf("P%d -> ", processes[x]);
               time+=rt[x];
               rt[x]=0;
               ct[x]=time;
               completed++;
           }
          x=(x+1)%n;
          break;
      }//end of if
      
      x=(x+1)%n;
      checked++;
    }//end of while completed
      
      
    // If no process found that can run, increment time (CPU idle)
      if (!found_process) {
           printf("CPU in Idle:");
            time++;
        }
    } //end of while completed
    
    printf("END\n\n");
    
    // Calculate TAT and WT
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];       // Turnaround Time = CT - AT
        wt[i] = tat[i] - bt[i];       // Waiting Time = TAT - BT
        total_tat += tat[i];
        total_wt += wt[i];
    }
    
     printf("\t|Process\t|AT\t|BT\t|CT\t|TAT\t|WT|\n");
    for (int i = 0; i < n; i++) {
        printf("\t|  P%d   \t|%d\t|%d\t|%d\t|%d\t|%d|\n", processes[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

   printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time   : %.2f\n", total_wt / n);
    return 0;
}
