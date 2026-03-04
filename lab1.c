#include<stdio.h>
int main()
{
    int n,bt[20], wt[20], tat[20], at[20], ct[20];
    int i;
    int temp;
    float twt=0.0, ttat=0.0, awt, att;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("Enter arrival time for process %d: ",i+1);
        scanf("%d",&at[i]);
        printf("Enter burst time for process %d: ",i+1);
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(at[j]<at[i])
            {
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
            }
        }
    }
    ct[0]=at[0]+bt[0];
    wt[0]=0;
    tat[0]=bt[0];
    for(i=1;i<n;i++)
    {
        if(ct[i-1]<at[i])
        {
            ct[i]=at[i]+bt[i];
            wt[i]=0;
        }
        else
        {
            wt[i]=ct[i-1]-at[i];
            ct[i]=ct[i-1]+bt[i];
        }
        tat[i]=wt[i]+bt[i];
    }
    for(i=0;i<n;i++)
    {
        twt+=wt[i];
        ttat+=tat[i];
    }
    awt=twt/n;
    att=ttat/n;
    printf("\nPROCESS\tAT\tBT\tCT\tWT\tTAT");
    for(i=0;i<n;i++)
    {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",i+1,at[i],bt[i],ct[i],wt[i],tat[i]);
    }
    printf("\nAverage waiting time = %.2f",awt);
    printf("\nAverage turnaround time = %.2f",att);
}
