#include <stdio.h>
#include <stdbool.h>
bool binary(int *arr, int size, int start, int end, int key)
{
    // RECURSION METHOD
    if (end >= start)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
            return true;
        {
            if (arr[mid] < key)
                return binary(arr, size, mid + 1, end, key);
            else
                return binary(arr, size, start, mid - 1, key);
        }
    }
    return false;

    //   ITERATIVE METHOD
    // while(start<=end)
    // {
    //     if(arr[mid]==key)
    //     {
    //         return true;
    //         break;
    //     }
    //     if(arr[mid]<key)
    //     {
    //         start=mid+1;
    //     }
    //     else if(arr[mid]>key)
    //     {
    //         end=mid-1;
    //     }
    //     mid=(start+end)/2;
    // }
    // return false;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 80};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 80;
    int s = 0;
    int e = size - 1;
    if (binary(arr, size, s, e, key))
    {
        printf("found");
    }
    else
        printf("not found");
}