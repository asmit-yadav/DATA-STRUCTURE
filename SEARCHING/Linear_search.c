#include<stdio.h>
#include<stdbool.h>
bool linear(int *arr,int size,int key)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
        {
            return true;
            break;
        }
    }
    return false;
}

int main()
{
    int arr[]={5,4,8,9,1,0,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key=0;
    if(linear(arr,size,key))
    {
        printf("found");
    }
    else
    printf("not found");
}