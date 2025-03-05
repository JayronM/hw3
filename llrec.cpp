#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void pivHelper(Node* head, Node*& smaller,Node*& larger, int pivot){
  if(!head){//base case
    smaller = nullptr;
    larger = nullptr;
    return;
  }
  Node* nextNode = head->next;

  if (head->val <= pivot){
    smaller = head; // current node is smaller
     pivHelper(nextNode, smaller->next, larger, pivot); //recursive for next
  } else{
    larger = head;//curent node is larger
     pivHelper(nextNode, smaller, larger->next, pivot); //recursive for next
  }
}

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot){
  pivHelper(head, smaller, larger, pivot);
  head = nullptr; //used up orignal list
}