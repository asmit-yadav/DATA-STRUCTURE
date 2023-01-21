#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int linear(int *arr,int size,int n,int key)
{
    for(int i=size;i<n;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return 0;
}
int jump_search(int *arr, int size, int key)
{
    int m = pow(size, .5) - 1;
    int i = 0;
    while (m < size)
    {
        if (arr[i] <= key && arr[m] >= key)
        {
           return linear(arr,i,m+1,key);
        }
        else
        {

            i = m;
            m = m + pow(size, .5) - 1;
        }
    }
    return 0;
}

int main()
{
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 610;
    int k = jump_search(arr, size, key);
    if (k != 0)
    {
        printf("%d found", k);
    }
    else
        printf("not found");
}