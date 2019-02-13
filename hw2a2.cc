#include <cstddef>
#include <iostream>
using namespace std;
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 

//Function to get the middle of the linked list
void findMiddle(struct Node *head) 
{ 
    struct Node *first_ptr = head; 
    struct Node *second_ptr = head; 
  
    if (head!=NULL) 
    { 
        while (first_ptr != NULL && second_ptr->next != NULL) 
        { 
            first_ptr = second_ptr->next->next; 
            second_ptr = second_ptr->next; 
        } 
        cout<<"The middle element is"<< second_ptr->data; 
    } 
} 