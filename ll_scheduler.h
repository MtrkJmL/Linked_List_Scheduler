#ifndef LL_SCHEDULER_H
#define LL_SCHEDULER_H

class Node {
public:
    Node();
    Node(int n);
    Node(int processID, int arrivalTime, int runTime, int priority);
    int arrivalTime;
    int priority;
    int runTime;
    int processID;
    Node* left;
    Node* right;
};

void ll_insert(Node** head, Node* new_node, int* count);
Node* ll_getPrev(Node** head, int* count);

#endif // LL_SCHEDULER_H
