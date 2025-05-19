// Online C compiler to run C program online
#include <stdio.h>

int main() {
   
  int n;
  printf("Enter no. of processes : ");
  scanf("%d",&n);
  
  int processes[n],at[n],bt[n],ct[n],tat[n],wt[n],done[n];
  
  for(int i=0;i<n;i++)
  {
      processes[i]=i+1;
      printf("Enter arrival time of P%d", processes[i]);
      scanf("%d",&at[i]);
      printf("Enter burst time of P%d", processes[i]);
      scanf("%d",&bt[i]);
      done[i]=0;
  }
  
  int completed=0,current_time=0;
  while(completed<n)
    {
        int x=-1;
        int min_bt=9999;
        
        for(int i=0;i<n;i++)
        {
          if(at[i]<=current_time && done[i]==0)/* here we are comparing arrival time and done status , mean done is indirectly executed process just marking */
          {
              if(bt[i]< min_bt) /* we are storing minimum burst time in min_bt */
              {
                  min_bt=bt[i];
                  x=i;
              }
          }
        }
        
       if(x!=-1)
       {
           current_time+=bt[x];
           ct[x]=current_time;
           tat[x]=ct[x]-at[x];
           wt[x]=tat[x]-bt[x];
           done[x]=1;
           completed++;
       }
       else
       {
           // it execute when above for loop is executed but ,in that if conditions are failed at all time of i to n, 
           // and this else indicates that here occurs idle in cpu
           
           current_time++;    
        }
      
        }// end of while loop
        
        // Print table
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    float total_tat = 0, total_wt = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", processes[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        total_tat += tat[i];
        total_wt += wt[i];
    }
          
    printf("Average TAT = %.2f\n", total_tat / n);
    printf("Average WT = %.2f\n", total_wt / n);

    return 0;
}
