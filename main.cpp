#include <iostream>

using namespace std;

struct Node {
    Node(int val) {
        this->val = val;
        next = nullptr;
    }
    int val;
    Node* next;
};

class LinkedList {
public:

    LinkedList() {
        head = new Node(0);
    }

    void push(int val) {
        Node* newNode = new Node(val);

        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    void reverse() {
        Node* curr = head->next;
        Node* prev = nullptr;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head->next = prev;
    }

    void print() {
        Node* curr = head->next;
        while (curr != nullptr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }

private:
    Node* head;
};

int main() {
    LinkedList myList;

    for (int i = 1; i < 11; i++) {
        myList.push(i);
    }
    myList.print();
    myList.reverse();
    myList.print();
}
