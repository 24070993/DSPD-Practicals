#include <stdio.h>

int main()
{
    int n, i, Sumodd = 0, Sumeven = 0;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    
    int arr[n]; 
    
    printf("Enter %d elements of arrays: \n", n);
    
    
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for (i = 0; i < n; i++)
    {
      
        if ((i + 1) % 2 == 0)
        {
            Sumeven += arr[i];
        }
       
        else
        {
            Sumodd += arr[i];
        }
    }
    
    printf("Sum of elements at odd position = %d\n", Sumodd);
    printf("Sum of elements at even position = %d\n", Sumeven);
    
    return 0;
}

