#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;

    MyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    int get(int index) {
        Node* temp = head;
        int i = 0;
        while (temp != NULL) {
            if (i == index) return temp->val;
            temp = temp->next;
            i++;
        }
        return -1; // not found
    }

    void addAtHead(int val) {
        Node* newnode = new Node(val);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    void addAtTail(int val) {
        Node* newnode = new Node(val);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node* temp = head;
        for (int i = 0; temp != NULL && i < index - 1; i++) {
            temp = temp->next;
        }
        if (temp == NULL) return; // invalid index
        Node* newnode = new Node(val);
        newnode->next = temp->next;
        temp->next = newnode;
        if (newnode->next == NULL) tail = newnode;
    }

    void deleteAtIndex(int index) {
        if (head == NULL) return;
        if (index == 0) {
            Node* toDelete = head;
            head = head->next;
            if (head == NULL) tail = NULL;
            delete toDelete;
            return;
        }
        Node* temp = head;
        for (int i = 0; temp != NULL && i < index - 1; i++) {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) return; // invalid index
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        if (temp->next == NULL) tail = temp;
        delete toDelete;
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
