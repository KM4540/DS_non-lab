
#include <bits/stdc++.h>
using namespace std;

char tree[10];

int root(char key) {
    if (tree[0] != '\0')
        cout << "Tree already has a root";
    else
        tree[0] = key;
    return 0;
}

int set_left(char key, int parent) {
    if (tree[parent] == '\0')
        cout << "\nCan't set child at " << (parent * 2) + 1 << ", no parent found";
    else
        tree[(parent * 2) + 1] = key;
    return 0;
}

int set_right(char key, int parent) {
    if (tree[parent] == '\0')
        cout << "\nCan't set child at " << (parent * 2) + 2 << ", no parent found";
    else
        tree[(parent * 2) + 2] = key;
    return 0;
}

void print_tree(int index, int level) {
    if (tree[index] == '\0')
        return;

    print_tree((index * 2) + 2, level + 1); // Right subtree

    for (int i = 0; i < level; i++)
        cout << "   "; // Indent based on the level

    cout << tree[index] << endl; // Print the current node

    print_tree((index * 2) + 1, level + 1); // Left subtree
}

int main() {
    root('A');
    set_left('B', 0);
    set_right('C', 0);
    set_left('D', 1);
    set_right('E', 1);
    set_right('F', 2);

    cout << "Binary Tree Representation:" << endl;
    print_tree(0, 0);

    return 0;
}
