#include <stdio.h>

char tree[10]; // An array to represent the binary tree

// Function to set the root of the binary tree
int root(char key) {
    if (tree[0] != '\0')
        printf("Tree already has a root");
    else
        tree[0] = key;
    return 0;
}

// Function to set the left child of a given parent node
int set_left(char key, int parent) {
    if (tree[parent] == '\0')
        printf("\nCan't set child at %d, no parent found", (parent * 2) + 1);
    else
        tree[(parent * 2) + 1] = key;
    return 0;
}

// Function to set the right child of a given parent node
int set_right(char key, int parent) {
    if (tree[parent] == '\0')
        printf("\nCan't set child at %d, no parent found", (parent * 2) + 2);
    else
        tree[(parent * 2) + 2] = key;
    return 0;
}

// Function to print the binary tree in a readable format
void print_tree(int index, int level) {
    if (tree[index] == '\0')
        return;

    // Print the right subtree
    print_tree((index * 2) + 2, level + 1);

    // Indent based on the level
    for (int i = 0; i < level; i++)
        printf("   ");

    // Print the current node
    printf("%c\n", tree[index]);

    // Print the left subtree
    print_tree((index * 2) + 1, level + 1);
}

int main() {
    char rootKey, leftKey, rightKey;

    printf("Enter the root key: ");
    scanf(" %c", &rootKey);
    root(rootKey);

    // Left subtree of the root
    printf("Enter the left child key for %c: ", rootKey);
    scanf(" %c", &leftKey);
    set_left(leftKey, 0);

    // Left branch of the left subtree
    printf("Enter the left child key for %c: ", leftKey);
    scanf(" %c", &leftKey);
    set_left(leftKey, (0 * 2) + 1);

    // Right branch of the left subtree
    printf("Enter the right child key for %c: ", leftKey);
    scanf(" %c", &rightKey);
    set_right(rightKey, (0 * 2) + 1);

    // Right subtree of the root
    printf("Enter the right child key for %c: ", rootKey);
    scanf(" %c", &rightKey);
    set_right(rightKey, 0);

    // Left branch of the right subtree
    printf("Enter the left child key for %c: ", rightKey);
    scanf(" %c", &leftKey);
    set_left(leftKey, (0 * 2) + 2);

    // Right branch of the right subtree
    printf("Enter the right child key for %c: ", rightKey);
    scanf(" %c", &rightKey);
    set_right(rightKey, (0 * 2) + 2);

    printf("\nBinary Tree Representation:\n");
    print_tree(0, 0);

    return 0;
}
