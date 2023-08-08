#include <iostream>
using namespace std;

const int maxsize = 10;
int n;
int a[maxsize]; 

void create() {
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void del() {
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;
    if (pos >= n) {
        cout << "Invalid position\n";
    } else {
        for (int i = pos; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        n--;
        cout << "Element deleted\n";
    }
}

void insert() {
    int pos, data;
    cout << "Enter position to insert: ";
    cin >> pos;
    if (pos > n) {
        cout << "Invalid position\n";
    } else {
        cout << "Enter data to insert: ";
        cin >> data;
        for (int i = n; i >=pos; i--) {
            a[i] = a[i - 1];
        }
        a[pos] = data;
        n++;
        cout << "Element inserted\n";
    }
}

int main() {
    create();
    del();
    insert();
    cout << "Array elements:\n";
    for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
    }
    return 0;
}
