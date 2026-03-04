#include<stdio.h>
void main()
{
    int n,large,sec_large,count=0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                count++;
            }
        }
    }
    printf("Number of duplicate elements = %d",count);
}
