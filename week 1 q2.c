#include <stdio.h>
void main()
{
    int a[10][10];
    int n, i, j;
    int sum = 0;
    printf("Enter the order of the square matrix: ");
    scanf("%d",&n);
    printf("Enter the elements of the matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++) {
        sum+=a[i][i];
    }
    printf("Sum of left diagonal elements = %d", sum);
}
