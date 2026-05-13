#include <stdio.h>

int main() {
    int n, m, i, j, k, pid;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int allocation[n][m], max[n][m], need[n][m], available[m], work[m], finish[n];

    for(i = 0; i < n; i++) {
        printf("Enter allocation for P%d: ", i);
        for(j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);
        printf("Enter max for P%d: ", i);
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];
        finish[i] = 0;
    }

    printf("Enter available resources: ");
    for(i = 0; i < m; i++)
        scanf("%d", &available[i]);

    int request[m];
    printf("Enter pid requesting resources: ");
    scanf("%d", &pid);
    printf("Enter request for resources: ");
    for(i = 0; i < m; i++)
        scanf("%d", &request[i]);

    int canGrant = 1;
    for(i = 0; i < m; i++) {
        if(request[i] > need[pid][i] || request[i] > available[i]) {
            canGrant = 0;
            break;
        }
    }

    if(canGrant) {
        for(i = 0; i < m; i++) {
            available[i] -= request[i];
            allocation[pid][i] += request[i];
            need[pid][i] -= request[i];
        }
        printf("Request can be granted. Checking system state...\n");
    } else {
        printf("Request cannot be granted. System would be unsafe.\n");
        return 0;
    }

    for(i = 0; i < m; i++)
        work[i] = available[i];

    int safeSeq[n], count = 0;

    while(count < n) {
        int found = 0;
        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int flag = 1;
                for(j = 0; j < m; j++) {
                    if(need[i][j] > work[j]) {
                        flag = 0;
                        break;
                    }
                }
                if(flag) {
                    for(k = 0; k < m; k++)
                        work[k] += allocation[i][k];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if(found == 0) {
            printf("SYSTEM IS NOT IN SAFE STATE\n");
            return 0;
        }
    }

    printf("SYSTEM IS IN SAFE STATE\nThe Safe Sequence is -- ");
    for(i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");

    printf("Process\tAllocation\tMax\tNeed\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t", i);
        for(j = 0; j < m; j++)
            printf("%d ", allocation[i][j]);
        printf("\t");
        for(j = 0; j < m; j++)
            printf("%d ", max[i][j]);
        printf("\t");
        for(j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    return 0;
}
