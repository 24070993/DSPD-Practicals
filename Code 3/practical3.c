#include <stdio.h>
#define MAX 5

char Q[MAX];
int front = -1, rear = -1;

void insert() {
    char ch;
    if (rear == MAX - 1) {
        printf("Queue overflow!\n");
        return;
    }
    printf("Enter character to insert: ");
    scanf(" %c", &ch);
    if (front == -1) front = 0;
    Q[++rear] = ch;
    printf("%c inserted into queue\n", ch);
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue underflow!\n");
        return;
    }
    printf("%c deleted from queue\n", Q[front++]);
    if (front > rear) front = rear = -1;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%c ", Q[i]);
    printf("\n");
}

void demonstrateOverflow() {
    printf("Demonstrating queue overflow:\n");
    while (rear < MAX - 1) {
        rear++;
        Q[rear] = 'A' + rear;
        if (front == -1) front = 0;
        printf("%c inserted into queue\n", Q[rear]);
    }
    insert();
}

void demonstrateUnderflow() {
    printf("Demonstrating queue underflow:\n");
    while (front <= rear)
        delete();
    delete();
}

int main() {
    int choice;
    while (1) {
        printf("\nQueue Menu:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Demonstrate overflow\n");
        printf("4. Demonstrate underflow\n");
        printf("5. Display queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); 
            break;
            case 2: delete(); 
            break;
            case 3: demonstrateOverflow(); 
            break;
            case 4: demonstrateUnderflow(); 
            break;
            case 5: display();
            break;
            case 6: 
            return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

