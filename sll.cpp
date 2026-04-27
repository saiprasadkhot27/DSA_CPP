#include <iostream>
using namespace std;

class Node {
public:
int data;
Node* next;


Node(int val) {
    data = val;
    next = NULL;
}

};

class SLL {
Node* head;

public:
SLL() {
head = NULL;
}


// Insert at beginning
void insertAtBeginning(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
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
}

// Delete a node
void deleteNode(int val) {
    if (head == NULL) return;

    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next == NULL) return;

    Node* del = temp->next;
    temp->next = temp->next->next;
    delete del;
}

// Display
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


};

int main() {
SLL list;


list.insertAtBeginning(10);
list.insertAtBeginning(5);
list.insertAtEnd(20);
list.insertAtEnd(30);

cout << "SLL: ";
list.display();

list.deleteNode(20);
cout << "After deletion: ";
list.display();

return 0;


}
