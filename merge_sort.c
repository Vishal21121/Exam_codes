#include <stdio.h>

void merge(int arr[], int l, int r, int mid)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int L[n1], R[n2];
    int i, j, k;
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l+i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid+1+j];
    }
    i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <=R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,r,mid);
    }
}

int main()
{
    int n;
    printf("Enter the number of array elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,n-1);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}