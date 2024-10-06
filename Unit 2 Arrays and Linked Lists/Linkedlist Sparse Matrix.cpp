#include <iostream>

//Sparse Matrix using linked list

// Node structure for LinkedList
struct Node {
    int row;
    int col;
    int value;
    Node* next;
};

// LinkedList class for Sparse Matrix
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Insert a new node at the end of the LinkedList
    void insert(int row, int col, int value) {
        Node* newNode = new Node;
        newNode->row = row;
        newNode->col = col;
        newNode->value = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Display the LinkedList
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            std::cout << "Row: " << temp->row << ", Column: " << temp->col << ", Value: " << temp->value << std::endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;

    // Inserting nodes into the LinkedList
    list.insert(0, 0, 5);
    list.insert(1, 2, 7);
    list.insert(2, 1, 3);

    // Displaying the LinkedList
    list.display();

    return 0;
}
