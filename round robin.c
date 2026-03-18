#include <stdio.h>
int main()
{
    int n, tq;
    int at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20];
    int q[100], f = 0, r = 0;
    int vis[20] = {0};
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);
    int time = 0, completed = 0;
    for (int i = 0; i < n; i++)
    {
        if (at[i] <= time)
        {
            q[r++] = i;
            vis[i] = 1;
        }
    }
    while (completed < n)
    {
        if (f == r)
        {
            time++;
            for (int i = 0; i < n; i++)
            {
                if (at[i] <= time && !vis[i])
                {
                    q[r++] = i;
                    vis[i] = 1;
                }
            }
            continue;
        }
        int i = q[f++];
        if (rt[i] > tq)
        {
            time += tq;
            rt[i] -= tq;
        }
        else
        {
            time += rt[i];
            rt[i] = 0;
            ct[i] = time;
            completed++;
        }
        for (int j = 0; j < n; j++)
        {
            if (at[j] <= time && !vis[j])
            {
                q[r++] = j;
                vis[j] = 1;
            }
        }
        if (rt[i] > 0)
        {
            q[r++] = i;
        }
    }
    float ttat = 0, twt = 0;
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        ttat += tat[i];
        twt += wt[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage turnaound time = %.2f", ttat / n);
    printf("\nAverage waiting time = %.2f\n", twt / n);
    return 0;
}
