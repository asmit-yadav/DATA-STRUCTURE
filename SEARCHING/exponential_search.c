#include<stdio.h>
#include<stdbool.h>
int linear(int *arr,int size,int n,int key)
{
    for(int i=n;i<size;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return 0;
}
int exponential(int *arr,int size,int key)
{
    if(arr[0]==key)
    {
        return 0;
    }
    int i=1;
    while(i<size&&arr[i]<=key)
    {
        i=i*2;
    }
    return linear(arr,size,i/2,key);
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key=9;
    int k=exponential(arr,size,key);
    if(k!=0)
    {
        printf(" %d found",k);
    }
    else
    printf("not found");
}