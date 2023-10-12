#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) {
        root = newNode(val);
    } else if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void display(struct Node* root) {
    if (root != NULL) {
        display(root->left);
        printf("%d -> ", root->data);
        display(root->right);
    }
}

struct Node* findMaximum(struct Node* node) {
    if (node == NULL)
        return node;
    if (node->right == NULL) {
        return node;
    } else {
        return findMaximum(node->right);
    }
}

struct Node* findMinimum(struct Node* node) {
    if (node == NULL)
        return node;
    if (node->left == NULL) {
        return node;
    } else {
        return findMinimum(node->left);
    }
}

void preorder(struct Node* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(struct Node* node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

void inorder(struct Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void levelorder(struct Node* node) {
    if (node == NULL)
        return;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = node;
    while (front < rear) {
        struct Node* frontNode = queue[front];
        printf("%d -> ", frontNode->data);
        if (frontNode->left != NULL)
            queue[rear++] = frontNode->left;
        if (frontNode->right != NULL)
            queue[rear++] = frontNode->right;
        front++;
    }
}

bool search(struct Node* root, int item) {
    if (root == NULL)
        return false;
    if (item == root->data) {
        return true;
    } else if (item < root->data) {
        return search(root->left, item);
    } else if (item > root->data) {
        return search(root->right, item);
    } else {
        return false;
    }
}

int findHeight(struct Node* node) {
    if (node == NULL) {
        return -1;
    } else {
        int leftheight = findHeight(node->left);
        int rightheight = findHeight(node->right);
        return (leftheight > rightheight) ? (leftheight + 1) : (rightheight + 1);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, item;

    do {
        printf("\n1. Insert\n");
        printf("2. Display\n");
        printf("3. Find Minimum and Maximum\n");
        printf("4. Find Height\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Inorder Traversal\n");
        printf("8. Level Order Traversal\n");
        printf("9. Search\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &item);
                root = insert(root, item);
                break;

            case 2:
                printf("Tree formed:\n");
                display(root);
                break;

            case 3:
                {
                    struct Node* min = findMinimum(root);
                    struct Node* max = findMaximum(root);
                    if (min == NULL) {
                        printf("Tree is empty\n");
                    } else {
                        printf("Maximum element is: %d\n", max->data);
                        printf("Minimum element is: %d\n", min->data);
                    }
                    break;
                }

            case 4:
                printf("Height of the tree: %d\n", findHeight(root));
                break;

            case 5:
                printf("Preorder traversal: ");
                preorder(root);
                break;

            case 6:
                printf("Postorder traversal: ");
                postorder(root);
                break;

            case 7:
                printf("Inorder traversal: ");
                inorder(root);
                break;

            case 8:
                printf("Level Order traversal: ");
                levelorder(root);
                break;

            case 9:
                printf("Enter the item to find: ");
                scanf("%d", &item);
                if (search(root, item)) {
                    printf("Found..\n");
                } else {
                    printf("Not Found!\n");
                }
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 0);

    return 0;
}
