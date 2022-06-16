#include<stdio.h>
#include<limits.h>

int matrix(int arr[], int n){
    int m[n][n],j,q;

    for (int i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }

    for (int d = 2; d < n; d++)
    {
        for (int i = 1; i < n-d+1; i++)
        {   
            j = i+d-1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if(q<m[i][j]){
                    m[i][j] = q;
                }
            }
            
        }
        
    }
   return m[1][n-1];
    
}

int main()
{
    int arr[] = {10,20,30,40,30};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("The matrix is : %d",matrix(arr,size));
    return 0;
}