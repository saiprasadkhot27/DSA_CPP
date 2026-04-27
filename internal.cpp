#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void create() {
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Node* newnode = new Node;
        cout << "Enter value: ";
        cin >> val;

        newnode->data = val;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

void insertAtPosition() {
    int pos, val;
    cout << "Enter position: ";
    cin >> pos;
    cout << "Enter element: ";
    cin >> val;

    Node* newnode = new Node;
    newnode->data = val;

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            cout << "Invalid position\n";
            return;
        }
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteAtPosition() {
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    if (pos == 1) {
        head = temp->next;
        delete temp;
        return;
    }

    for (int i = 1; i < pos - 1; i++) {
        if (temp->next == NULL) {
            cout << "Invalid position\n";
            return;
        }
        temp = temp->next;
    }

    Node* delNode = temp->next;
    if (delNode == NULL) {
        cout << "Invalid position\n";
        return;
    }

    temp->next = delNode->next;
    delete delNode;
}

void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    cout << "List: ";

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice;

    do {
        cout << "\n1.Create\n2.Insert\n3.Delete\n4.Display\n5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: create(); break;
            case 2: insertAtPosition(); break;
            case 3: deleteAtPosition(); break;
            case 4: display(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
