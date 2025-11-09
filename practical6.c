#include <stdio.h>
#include <stdlib.h>

// Node structure for the Binary Search Tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // Ignore duplicate values in a typical BST implementation
    return root;
}

// Function to search for an element in the BST
void search(struct node* root, int key) {
    if (root == NULL) {
        printf("NULL\n");
        return;
    }

    if (root->data == key) {
        printf("Found\n");
        return;
    } else if (key < root->data) {
        search(root->left, key);
    } else {
        search(root->right, key);
    }
}

// Function to delete a leaf node with the given key
struct node* deleteLeaf(struct node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->data) {
        root->left = deleteLeaf(root->left, key);
    } else if (key > root->data) {
        root->right = deleteLeaf(root->right, key);
    } else {
        // key == root->data, check if it's a leaf node
        if (root->left == NULL && root->right == NULL) {
            // It is a leaf node
            free(root);
            printf("Leaf node deleted successfully!\n");
            return NULL; // Parent's pointer is set to NULL
        } else {
            // Not a leaf node! (Has one or two children)
            printf("Not a leaf node! Cannot delete.\n");
            return root; // Return the node without deleting
        }
    }
    return root;
}

// Inorder Traversal (Used here to check the tree after operations)
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n---- Binary Search Tree Menu ----\n");
        printf("1. Search an element\n");
        printf("2. Insert an element\n");
        printf("3. Delete leaf element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &value);
                search(root, value);
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Enter leaf element to delete: ");
                scanf("%d", &value);
                root = deleteLeaf(root, value);
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}