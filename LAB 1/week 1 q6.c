#include<stdio.h>
#include<limits.h>
void main()
{
    int n,large,sec_large,pos;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter position of element to be deleted: ");
    scanf("%d",&pos);
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[pos-1])
        {
            a[i]=a[i+1];
        }
    }
    n--;
    printf("Array after deletion: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
