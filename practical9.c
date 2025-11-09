#include <stdio.h>

int main() {
    int hash[7], i, key, index, n;
    
    // Initialize table with -1 (empty)
    for (i = 0; i < 7; i++)
        hash[i] = -1;

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter key: ");
        scanf("%d", &key);
        
        index = key % 7; // Compute initial hash index

        // Linear probing loop
        while (hash[index] != -1)
            index = (index + 1) % 7;
        
        hash[index] = key; // Place key in the empty slot
    }

    printf("\nFinal Hash Table:\n");
    for(i = 0; i < 7; i++) {
        printf("Slot %d: %d\n", i, hash[i]);
    }
return 0;
}
