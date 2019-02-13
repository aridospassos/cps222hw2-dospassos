#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
using namespace std;
// referenced code from https://codeforwin.org/2018/06/c-program-to-count-nodes-in-circular-linked-list.html
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
/* Function to insert a node at the begining 
   of a Circular linked list */
void push(struct Node** beg_ref, int data) 
{ 
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node)); 
    struct Node* sub = *beg_ref; 
    ptr->data = data; 
    ptr->next = *beg_ref; 
  
    if (*beg_ref != NULL) { 
        while (sub->next != *beg_ref) 
            sub = sub->next; 
        sub->next = ptr; 
    } else
        ptr->next = ptr; 
  
    *beg_ref = ptr; 
} 