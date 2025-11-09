#include <stdio.h>
#include <stdlib.h>

// Node structure for the Binary Tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the Binary Search Tree (BST)
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    // If the value is less than the current node's data, insert in the left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // Otherwise, insert in the right subtree
    else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Inorder Traversal: Left -> Root -> Right
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal: Root -> Left -> Right
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal: Left -> Right -> Root
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to search for an element
void search(struct Node *root, int key) {
    if (root == NULL) {
        printf("NULL (NOT found)\n");
        return;
    }

    if (root->data == key) {
        printf("Found.\n");
        return;
    }
    
    // If key is less than root's data, search left
    if (key < root->data) {
        search(root->left, key);
    }
    // If key is greater than root's data, search right
    else {
        search(root->right, key);
    }
}

int main() {
    struct Node *root = NULL;
    int n, value, key, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d node values: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        // Insert node and update the root
        root = insert(root, value);
    }

    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    printf("\nEnter element to search: ");
    scanf("%d", &key);
    search(root, key);

    return 0;
}