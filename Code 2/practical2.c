#include <stdio.h>
#include <string.h>

#define MAX 5  // Maximum size of stack

int stack[MAX];
int top = -1;


void push() {
    int value;
    if(top >= MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    printf("Enter element to push: ");
    scanf("%d", &value);
    top++;
    stack[top] = value;
    printf("%d pushed onto stack.\n", value);
}
void pop() {
    if(top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("%d popped from stack.\n", stack[top]);
    top--;
}
void display() {
    if(top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
void checkPalindrome() {
    char str[50];
    char temp[50];
    int len;
    printf("Enter a number or string: ");
    scanf("%s", str);

    len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(top >= MAX - 1) {
            printf("Stack Overflow while checking palindrome!\n");
            return;
        }
        top++;
        stack[top] = str[i];
    }
    for(int i = 0; i < len; i++) {
        temp[i] = stack[top];
        top--;
    }
    temp[len] = '\0';

    if(strcmp(str, temp) == 0)
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);
}
void demonstrateOverflow() {
    int i;
    printf("Demonstrating Stack Overflow:\n");
    for(i = top + 1; i <= MAX; i++) {
        push();
    }
}
void demonstrateUnderflow() {
    printf("Demonstrating Stack Underflow:\n");
    while(top >= 0) {
        pop();
    }
    pop(); 
}

int main() {
    int choice;
    while(1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push an Element onto Stack\n");
        printf("2. Pop an Element from Stack\n");
        printf("3. Check Palindrome\n");
        printf("4. Demonstrate Overflow\n");
        printf("5. Demonstrate Underflow\n");
        printf("6. Display Stack\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: checkPalindrome(); break;
            case 4: demonstrateOverflow(); break;
            case 5: demonstrateUnderflow(); break;
            case 6: display(); break;
            case 7: return 0;
            default: 
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;

}
