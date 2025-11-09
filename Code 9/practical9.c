#include <stdio.h>

int main() {
    int hash[7], i, key, index, n;

    for (i = 0; i < 7; i++)
        hash[i] = -1;

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter key: ");
        scanf("%d", &key);
        
        index = key % 7; 

        while (hash[index] != -1)
            index = (index + 1) % 7;
        
        hash[index] = key; 
    }

    printf("\nFinal Hash Table:\n");
    for(i = 0; i < 7; i++) {
        printf("Slot %d: %d\n", i, hash[i]);
    }
return 0;
}

