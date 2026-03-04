#include<stdio.h>
#include<limits.h>
void main()
{
    int n,large,sec_large;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sec_large=INT_MIN;
    large=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i]>large)
        {
            sec_small=large;
            large=a[i];
        }
        if(a[i+1]>sec_large && a[i+1]!=large)
        {
            sec_large=a[i+1];
        }
    }
    printf("Second smallest element is %d",sec_large);
}

