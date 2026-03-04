#include<stdio.h>
void main()
{
    int m,n;
    printf("Enter oder of matrix m x n: ");
    scanf("%d %d",&m,&n);
    int a[m][n];
    printf("Enter matrix elements: \n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d", &a[i][j]);
    }
    int row_sum,col_sum;
    for(int i=0;i<m;i++)
    {
        row_sum=0;
        for(int j=0;j<n;j++)
        {
            row_sum+=a[i][j];
        }
        printf("Row %d sum = %d\n",i+1,row_sum);
    }
    for(int j=0;j<n;j++)
    {
        col_sum=0;
        for(int i=0;i<m;i++)
        {
            col_sum+=a[i][j];
        }
        printf("Column %d sum = %d\n",j+1,col_sum);
    }
}
