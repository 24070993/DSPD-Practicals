#include <stdio.h>

int main()
{
    int n, i, Sumodd = 0, Sumeven = 0;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    // Declaring a Variable Length Array (VLA)
    int arr[n]; 
    
    printf("Enter %d elements of arrays: \n", n);
    
    // Loop to read elements into the array
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    // Loop to calculate the sum of elements based on their position
    for (i = 0; i < n; i++)
    {
        // Check if the POSITION (i + 1) is EVEN
        if ((i + 1) % 2 == 0)
        {
            Sumeven += arr[i];
        }
        // If not even, the position (i + 1) must be ODD
        else
        {
            Sumodd += arr[i];
        }
    }
    
    printf("Sum of elements at odd position = %d\n", Sumodd);
    printf("Sum of elements at even position = %d\n", Sumeven);
    
    return 0;
}
