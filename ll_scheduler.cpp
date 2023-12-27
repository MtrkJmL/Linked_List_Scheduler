// ll_scheduler.cpp
#include "ll_scheduler.h"

// Implementation of the Node class constructor
Node::Node() : arrivalTime(0), priority(0), runTime(0), processID(0), left(nullptr), right(nullptr) {}

Node::Node(int n) : arrivalTime(0), priority(n), runTime(0), processID(0), left(nullptr), right(nullptr) {}

Node::Node(int processID, int arrivalTime, int runTime, int priority)
    : arrivalTime(arrivalTime), priority(priority), runTime(runTime), processID(processID), left(nullptr), right(nullptr) {}

// Implementation of ll_insert function
void ll_insert(Node** head, Node* new_node, int* count) {
    (*count)++;
    if (*head == nullptr) {
        *head = new_node; // if linked list is empty, make new node head of the list
    } else {
        Node* curr = (*head)->right, *prev = *head;
        if (prev->priority > new_node->priority) {
            new_node->right = prev;
            *head = new_node;
        } else {
            (*count)++;
            while (curr != nullptr && curr->priority < new_node->priority) {
                (*count)++;
                prev = curr;
                curr = curr->right;
            }
            prev->right = new_node;
            new_node->right = curr;
        }
    }
}

// Implementation of ll_getPrev function
Node* ll_getPrev(Node** head, int* count) {
    (*count)++;
    Node* prev = *head;
    *head = (*head)->right;
    return prev;
}