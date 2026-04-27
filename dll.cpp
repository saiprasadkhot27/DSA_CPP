#include <iostream>
using namespace std;

class Node {
public:
int data;
Node* prev;
Node* next;


Node(int val) {
    data = val;
    prev = NULL;
    next = NULL;
}


};

class DLL {
Node* head;

public:
DLL() {
head = NULL;
}


// Insert at beginning
void insertAtBeginning(int val) {
    Node* newNode = new Node(val);
    if (head != NULL) {
        head->prev = newNode;
        newNode->next = head;
    }
    head = newNode;
}

// Insert at end
void insertAtEnd(int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete node
void deleteNode(int val) {
    if (head == NULL) return;

    Node* temp = head;

    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

// Display forward
void displayForward() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


};

int main() {
DLL list;


list.insertAtBeginning(10);
list.insertAtBeginning(5);
list.insertAtEnd(20);
list.insertAtEnd(30);

cout << "DLL: ";
list.displayForward();

list.deleteNode(20);
cout << "After deletion: ";
list.displayForward();

return 0;

}
