#include <stdio.h>
#include <stdbool.h>
int interpolation(int *arr,int size,int key)
{
    int l=0;
    int r=size-1;
    int pos=l+((double)(r-l)/(arr[r]-arr[l]))*(key-arr[l]);
    while(l<=r)
    {
        if(arr[pos]==key)
        {
            return pos;
        }
        if(arr[pos]<key)
        {
            l=pos+1;
        }
        else if(arr[pos]>key)
        {
            r=pos-1;
        }
        pos=l+((r-l)/(arr[r]-arr[l]))*(key-arr[l]);
    }
    return 0;
}
int main()
{
    int arr[] = {10,13,15,26,28,30,50,56,58,59,60,61,67};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 67;
    int k=interpolation(arr, size, key);
    if (k!=0)
    {
        printf(" %d found",k);
    }
    else
        printf("not found");
}