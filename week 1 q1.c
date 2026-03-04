#include<stdio.h>
#include<limits.h>
void main()
{
    int n,small,sec_small;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sec_small=INT_MAX;
    small=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(a[i]<small)
        {
            sec_small=small;
            small=a[i];
        }
        if(a[i+1]<sec_small && a[i+1]!=small)
        {
            sec_small=a[i+1];
        }
    }
    printf("Second smallest element is %d",sec_small);
}
