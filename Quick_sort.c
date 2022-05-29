#include <stdio.h>
void quick_sort(int arr[], int l, int r)
{
    int i = l, j = r, pivot = l, temp;
    if (l < r)
    {
        while (i < j)
        {
            while (arr[i] <= arr[pivot])
            {
                i++;
            }
            while (arr[j] > arr[pivot])
            {
                j--;
            }
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        quick_sort(arr, l, j);
        quick_sort(arr, j + 1, r);
    }
}

int main()
{
    int n;
    printf("Enter the number of array elements:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}