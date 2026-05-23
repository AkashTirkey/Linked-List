// Structure for a node in the linked list
#include <iostream>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};

// Each node contains:

// value
// address of next node

// 10 20 30 40 50
// 10 is the head and 50 is the tail, 50 is pointing to NULL

// Core operations on linked list
// 1. Traversal-
void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

// 2. Insertion- at head
ListNode *insertAtHead(ListNode *head, int val)
{
    ListNode *newNode = new ListNode(val); // dynamically allocate memory for new node
    newNode->next = head;                  // point new node's next to current head
    return head;                           // update head to new node
}

// 2. Insertion- at tail
ListNode *insertAtTail(ListNode *head, int val)
{
    ListNode *newNode = new ListNode(val); // dynamically allocate memory for new node
    if (head == NULL)
    {
        return newNode; // if the list is empty, new node becomes the head
    }

    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next; // traverse to the end of the list
    }
    temp->next = newNode; // point the last node's next to the new node
    return head;          // return the unchanged head pointer
}

// 3.Deletion- at head
ListNode *deleteAtHead(ListNode *head)
{
    if (head == NULL)
    {
        return NULL; // if the list is empty, return NULL
    }

    ListNode *temp = head; // store the current head in a temporary variable
    head = head->next;     // update head to the next node
    delete temp;           // free the memory of the old head node
    return head;           // return the new head pointer
}

// 4. Deletion- at tail
ListNode *deleteAtTail(ListNode *head)
{
    // Empty list case
    if (head == NULL)
    {
        return NULL; // if the list is empty, return NULL
    }

    // single node case
    if (head->next == NULL)
    {
        delete head; // free the memory of the single node
        return NULL; // return NULL as the list is now empty
    }

    ListNode *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next; // traverse to the end of the list
    }

    delete temp->next; // free the memory of the last node
    temp->next = NULL; // set the second last node's next to NULL
    return head;       // return the unchanged head pointer
}
