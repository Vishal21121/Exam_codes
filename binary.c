#include <stdio.h>

int binary(int arr[], int l, int r, int key)
{
    if (l == r)
    {
        if (arr[l] == key)
        {
            return l;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            binary(arr, mid + 1, r, key);
        }
        else
        {
            binary(arr, l, mid - 1, key);
        }
    }
}

int main()
{
    int arr[10], n, key;
    printf("Enter the array size:");
    scanf("%d", &n);
    printf("Enter the array elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search:");
    scanf("%d", &key);
    int val = binary(arr, 0, n - 1, key);
    if (val == -1)
    {
        printf("The number is not present");
    }
    else
    {
        printf("the number is  present at %d",val+1);
    }
    return 0;
}