#include <stdio.h>
#include <stdbool.h>
bool ternary(int *arr, int size, int l, int r, int key)
{
    //   //RECURSION METHOD FOR TERNARY SEARCH
    if (r >= l)
    {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (arr[mid1] == key)
            return true;
        if (arr[mid2] == key)
            return true;
        if (arr[mid1] < key)
            return ternary(arr, size, mid1 + 1, r, key);
        else if (arr[mid1] > key)
            return ternary(arr, size, l, mid2 - 1, key);
    }
    return false;

    // //   ITERATIVE METHOD FOR TERNARY SEARCH
    // int l = 0;
    // int r = size - 1;
    // int mid1 = l + (r - l) / 3;
    // int mid2 = r - (r - l) / 3;
    // while (l <= r)
    // {
    //     if (arr[mid1] == key)
    //     {
    //         return true;
    //     }
    //     else if (arr[mid2] == key)
    //     {
    //         return true;
    //     }
    //     if (arr[mid1] < key)
    //     {
    //         l = mid1 + 1;
    //     }
    //     else if (arr[mid2] > key)
    //     {
    //         r = mid2 - 1;
    //     }
    //     mid1 = l + (r - l) / 3;
    //     mid2 = r - (r - l) / 3;
    // }
    // return false;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 80};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 6;
    int s = 0;
    int e = size - 1;
    if (ternary(arr, size,s,e ,key))
    {
        printf("found");
    }
    else
        printf("not found");
}