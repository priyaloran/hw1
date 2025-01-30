/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

// Adding a helper function to continue or discontinue the recursion
// based on if we at the end of the list
void splitHelper(Node* splitHead, Node*& odds, Node*& evens);

void split(Node*& in, Node*& odds, Node*& evens)
{
  Node* splitHead = in;
  // Right away we just set original list to NULL and follow with a temp pointer
  in = nullptr;
  // Check two cases: if the original list is empty vs if it is filled
  // If it is empty, we don't need our helper function
  // We are not told to assume it is not empty
  if  (splitHead == nullptr)  {
    return;
  }
  // Now call the helper
  splitHelper(splitHead, odds, evens);

}

void splitHelper(Node* splitHead, Node*& odds, Node*& evens) {
  // This is the base case
  if (splitHead == nullptr) {
    // List is empty so stop recursing
    return;
  }
  // This is the recursive function
  Node* temp = splitHead->next;
    // The value in the linked list is even
  if (splitHead->value % 2 == 0)  {
    // The ensures we don't allocate new memory but just change pointers
    splitHead->next = evens;
    evens = splitHead;
    }
  // The value in the linked list is odd
  else {
    splitHead->next = odds;
    odds = splitHead;
  }
  // Recurse with the next node in the original list
  // and pass odd and even lists to add to them
  splitHelper(temp, odds, evens);
}
