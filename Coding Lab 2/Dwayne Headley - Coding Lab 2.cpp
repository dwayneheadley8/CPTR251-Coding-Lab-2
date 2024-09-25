#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to search for a value in a linked list recursively
bool searchLinkedList(Node* head, int value) {
    // Base case: if the current node is null, return false (value not found)
    if (head == nullptr) {
        return false;
    }

    // If the current node's data matches the value, return true
    if (head->data == value) {
        return true;
    }

    // Recursively call the function with the next node in the list
    return searchLinkedList(head->next, value);
}

// Function to print the linked list
void printLinkedList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Linked List: ";
    printLinkedList(head);

    int searchValue;
    std::cout << "Enter a value to search in the linked list: ";
    std::cin >> searchValue;

    if (searchLinkedList(head, searchValue)) {
        std::cout << "Value found in the linked list." << std::endl;
    } else {
        std::cout << "Value not found in the linked list." << std::endl;
    }

    // Clean up allocated memory (freeing the linked list)
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
