#include <stdio.h>
#include <stdlib.h>

// Node structure for the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with a given key
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = key;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new key into BST
struct Node* insert(struct Node* root, int key) {
    // If the tree is empty, return a new node
    if (root == NULL)
        return newNode(key);

    // Otherwise, recur down the tree
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    // Return the (unchanged) node pointer
    return root;
}

// Function to print the tree
void printTree(struct Node* root, int space) {
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 5;

    // Process right child first
    printTree(root->right, space);

    // Print current node after space
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child
    printTree(root->left, space);
}

// Driver program to test the functions
int main() {
    // Creating an empty tree
    struct Node* root = NULL;

    int n, key;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &key);
        root = insert(root, key);
    }

    // Print the tree structure
    printf("\nBinary Search Tree:\n");
    printTree(root, 0);

    return 0;
}
