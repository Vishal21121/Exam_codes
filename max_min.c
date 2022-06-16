#include<stdio.h>

int maximum(int arr[],int index,int length){
    int max;
    if(index >= length-2)
    {
        if(arr[index] > arr[index + 1])
            return arr[index];
        else
            return arr[index + 1];
    }

    max = maximum(arr, index + 1, length);
    
    if(arr[index] > max)
        return arr[index];
    else
        return max;
}

int min(int arr[],int index,int length){
    int min_num;
    if(index>=length-2){
        if(arr[index]>arr[index+1]){
            return arr[index+1];
        }
        else{
            return arr[index];
        }
    }
    min_num = min(arr,index+1,length);
    if(min_num<arr[index]){
        return min_num;
    }
    else{
        return arr[index];
    }
}

int main()
{
    int arr[100];
    int max_num,min_num,n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("Enter the array elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    max_num = maximum(arr,0,n);
    min_num = min(arr,0,n);

    printf("The max element is : %d\n",max_num);
    printf("The min element is : %d\n",min_num);
    
    return 0;
}