#include<stdio.h>
int main()
{
    int n,at[20],bt[20],rt[20],ct[20],wt[20],tat[20];
    int i,time=0,count=0,min_index;
    float twt=0,ttat=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter arrival time for P%d: ",i+1);
        scanf("%d",&at[i]);
        printf("Enter burst time for P%d: ",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    while(count<n)
    {
        int min_rt=9999;
        min_index=-1;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i] > 0)
            {
                if(rt[i]<min_rt)
                {
                    min_rt=rt[i];
                    min_index=i;
                }
            }
        }
        if(min_index==-1)
        {
            time++;
        }
        else
        {
            rt[min_index]--;
            time++;
            if(rt[min_index]==0)
            {
                count++;
                ct[min_index]=time;
                tat[min_index]=ct[min_index]-at[min_index];
                wt[min_index]=tat[min_index]-bt[min_index];
                twt+=wt[min_index];
                ttat+=tat[min_index];
            }
        }
    }
    printf("\nPROCESS\tAT\tBT\tCT\tWT\tTAT");
    for(i=0;i<n;i++)
    {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",
        i+1,at[i],bt[i],ct[i],wt[i],tat[i]);
    }
    printf("\nAverage Waiting Time = %.2f",twt/n);
    printf("\nAverage Turnaround Time = %.2f",ttat/n);
    return 0;
}
