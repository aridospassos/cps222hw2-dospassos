// C program to merge a linked list into another at 
// alternate positions 
#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
using namespace std; 
  
// A nexted list node 
struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
  
/* Function to insert a node at the beginning */
void push(struct Node ** headr, int ndata) 
{ 
    struct Node* new_node =  
           (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = ndata; 
    new_node->next = (*headr); 
    (*headr)  = new_node; 
} 
  
/* Utility function to print a singly linked list */
void printList(struct Node *head) 
{ 
    struct Node *temp = head; 
    while (temp != NULL) 
    { 
        cout<< temp->data; 
        temp = temp->next; 
    } 
    cout<<endl; 
} 
  
// Main function that inserts nodes of linked list q into p at  
void merge(struct Node *p, struct Node **q) 
{ 
     struct Node *p_now = p, *q_now = *q; 
     struct Node *p_next, *q_next; 
  
     // While therre are avialable positions in p 
     while (p_now != NULL && q_now != NULL) 
     { 
         // Save next pointers 
         p_next = p_now->next; 
         q_next = q_now->next; 
  
         // Make q_curr as next of p_curr 
         q_now->next = p_next;  // Change next pointer of q_curr 
         p_now->next = q_now;  // Change next pointer of p_curr 
  
         // Update current pointers for next iteration 
         p_now = p_next; 
         q_now = q_next; 
    } 
  
    *q = q_now; // Update head pointer of second list 
} 
  
// Driver program to test above functions 
int main() 
{ 
     struct Node *p = NULL, *q = NULL; 
     push(&p, 3); 
     push(&p, 2); 
     push(&p, 1);
     push(&q, 8); 
     push(&q, 7); 
     push(&q, 6); 
     push(&q, 5); 
     push(&q, 4); 
  
     merge(p, &q); 
  
     cout<<"Merged First Linked List:"<< endl; 
     printList(p); 
  
     cout<<"Merged Second Linked List:"<<endl; 
     printList(q); 
  
     getchar(); 
     return 0; 
} 