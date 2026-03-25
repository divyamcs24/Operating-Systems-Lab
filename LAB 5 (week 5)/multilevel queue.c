#include<stdio.h>
int main()
{
    int n;
    int pid[20],at[20],bt[20],type[20],tat[20],start[20],wt[20],ct[20];
    int sysCount=0;
    int userCount=0;
    int systemQueue[20], userQueue[20];
    printf("Enter number of processes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter PID,AT, BT and process type for P%d: ",i+1);
        scanf("%d%d%d%d",&pid[i],&at[i],&bt[i],&type[i]);
    }
    int time=0;
    for(int i=0;i<n;i++){
        if(type[i]==0){
            systemQueue[sysCount++]=i;
        }
        else{
            userQueue[userCount++]=i;
        }
    }
    for(int i=0;i<sysCount;i++){
        for(int j=i+1;j<sysCount;j++){
            if(at[systemQueue[i]]>at[systemQueue[j]]){
                int t=systemQueue[i];
                systemQueue[i]=systemQueue[j];
                systemQueue[j]=t;
            }
        }
    }
    for(int i=0;i<userCount;i++){
        for(int j=i+1;j<userCount;j++){
            if(at[userQueue[i]]>at[userQueue[j]]){
                int t=userQueue[i];
                userQueue[i]=userQueue[j];
                userQueue[j]=t;
            }
        }
    }
    for(int i=0;i<sysCount;i++){
        int p=systemQueue[i];
        if(time<at[p])
            time=at[p];
        start[p]=time;
        time=time+bt[p];
        ct[p]=time;
        tat[p]=ct[p]-at[p];
        wt[p]=tat[p]-bt[p];
    }
    for(int i=0;i<userCount;i++){
        int p=userQueue[i];
        if(time<at[p])
            time=at[p];
        start[p]=time;
        time=time+bt[p];
        ct[p]=time;
        tat[p]=ct[p]-at[p];
        wt[p]=tat[p]-bt[p];
    }
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    return 0;
}
