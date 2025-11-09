#include <stdio.h>
#include <stdlib.h>

// Structure for a Node in the linked list
struct Node {
    int data;
    struct Node *next;
};

int main() {
    // Initialize head, temporary, and new node pointers to NULL
    struct Node *head = NULL, *temp = NULL, *newNode;
    int num, count = 0;

    printf("Enter integers to add to the list (0 to stop): \n");

    // Loop to continuously read integers and create nodes
    while (1) {
        // Read the integer from the user
        scanf("%d", &num);

        // Check for the termination condition (0)
        if (num == 0) {
            break;
        }

        // Dynamically allocate memory for a new node
        newNode = (struct Node *)malloc(sizeof(struct Node));
        // Assign the input data to the new node
        newNode->data = num;
        // The new node is the last node, so its next pointer is NULL
        newNode->next = NULL;

        // Check if the list is empty (head is NULL)
        if (head == NULL) {
            // If empty, the new node is the head
            head = newNode;
        } else {
            // If not empty, link the previous last node (temp->next) to the new node
            temp->next = newNode;
        }
        // Update the 'temp' pointer to the newly added node (the new tail)
        temp = newNode;
    }

    // Traversal and display of linked list elements
    printf("\nLinked List Elements : \n");
    // Start traversal from the head
    temp = head;

    // Loop until the end of the list (temp becomes NULL)
    while (temp != NULL) {
        printf("%d => ", temp->data);
        // Move to the next node
        temp = temp->next;
        // Increment the node count
        count++;
    }

    printf("NULL\n");
    printf("Total number of nodes = %d\n", count);

    return 0;
}
