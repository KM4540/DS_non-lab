#include <iostream>
using namespace std;
struct Node {
    int info;
    Node* next;
};

Node* start = nullptr;

void create() {
    Node* temp = new Node;
    if (temp == nullptr) {
        cout << "Out of Memory Space\n";
        exit(0);
    }
    cout << "Enter the data value for the node: ";
    cin >> temp->info;
    temp->next = nullptr;
    if (start == nullptr) {
        start = temp;
    } else {
        Node* ptr = start;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void display() {
    if (start == nullptr) {
        cout << "List is empty\n";
        return;
    } else {
        Node* ptr = start;
        cout << "The List elements are:\n";
        while (ptr != nullptr) {
            cout << ptr->info << "\t";
            ptr = ptr->next;
        }
        cout << "\n";
    }
}

void insert_begin() {
    Node* temp = new Node;
    if (temp == nullptr) {
        cout << "Out of Memory Space\n";
        return;
    }
    cout << "Enter the data value for the node: ";
    cin >> temp->info;
    temp->next = nullptr;
    if (start == nullptr) {
        start = temp;
    } else {
        temp->next = start;
        start = temp;
    }
}

void insert_end() {
    Node* temp = new Node;
    if (temp == nullptr) {
        cout << "Out of Memory Space\n";
        return;
    }
    cout << "Enter the data value for the node: ";
    cin >> temp->info;
    temp->next = nullptr;
    if (start == nullptr) {
        start = temp;
    } else {
        Node* ptr = start;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void insert_pos() {
    Node* temp = new Node;
    if (temp == nullptr) {
        cout << "Out of Memory Space\n";
        return;
    }
    int pos;
    cout << "Enter the position for the new node to be inserted: ";
    cin >> pos;
    cout << "Enter the data value of the node: ";
    cin >> temp->info;
    temp->next = nullptr;

    if (pos == 0) {
        temp->next = start;
        start = temp;
    } else {
        Node* ptr = start;
        for (int i = 0; i < pos - 1; i++) {
            ptr = ptr->next;
            if (ptr == nullptr) {
                cout << "Position not found: [Handle with care]\n";
                return;
            }
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void delete_begin() {
    if (start == nullptr) {
        cout << "List is Empty\n";
        return;
    } else {
        Node* ptr = start;
        start = start->next;
        cout << "The deleted element is: " << ptr->info << "\n";
        delete ptr;
    }
}

void delete_end() {
    if (start == nullptr) {
        cout << "List is Empty\n";
        exit(0);
    } else if (start->next == nullptr) {
        Node* ptr = start;
        start = nullptr;
        cout << "The deleted element is: " << ptr->info << "\n";
        delete ptr;
    } else {
        Node* ptr = start;
        Node* temp = nullptr;
        while (ptr->next != nullptr) {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = nullptr;
        cout << "The deleted element is: " << ptr->info << "\n";
        delete ptr;
    }
}

void delete_pos() {
    int pos;
    if (start == nullptr) {
        cout << "The List is Empty\n";
        exit(0);
    } else {
        cout << "Enter the position of the node to be deleted: ";
        cin >> pos;
        if (pos == 0) {
            Node* ptr = start;
            start = start->next;
            cout << "The deleted element is: " << ptr->info << "\n";
            delete ptr;
        } else {
            Node* ptr = start;
            Node* temp = nullptr;
            for (int i = 0; i < pos; i++) {
                temp = ptr;
                ptr = ptr->next;
                if (ptr == nullptr) {
                    cout << "Position not Found\n";
                    return;
                }
            }
            temp->next = ptr->next;
            cout << "The deleted element is: " << ptr->info << "\n";
            delete ptr;
        }
    }
}

int main() {
    int choice;
    while (true) {
        cout << "1: Create\n2: Display\n3: Insert at the beginning\n4: Insert at the end\n5: Insert at a specific position\n6: Delete from the beginning\n7: Delete from the end\n8: Delete from a specific position\n9: Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_begin();
                break;
            case 4:
                insert_end();
                break;
            case 5:
                insert_pos();
                break;
            case 6:
                delete_begin();
                break;
            case 8:
                delete_pos();
                break;
            case 9:
                exit(0);
                break;
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}
