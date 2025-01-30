/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

int main(int argc, char* argv[])
{
  
  Node* testLL = new Node(1, nullptr);
  testLL->next = new Node(3, nullptr);
  testLL->next->next = new Node(4, nullptr);
  testLL->next->next->next = new Node(6, nullptr);
  testLL->next->next->next->next = new Node(7, nullptr);
  testLL->next->next->next->next->next = new Node(10, nullptr);
  Node* oddLL = nullptr;
  Node* evenLL = nullptr;
  split(testLL, oddLL, evenLL);

  // Print and deallocate each linked list
  Node* Ehead = evenLL;
  while (Ehead != NULL) {
    Node* Etemp = Ehead;
    std::cout << Ehead->value << " ";
    Ehead = Ehead->next;
    delete Etemp;
  }
  Node* Ohead = oddLL;
  while (Ohead != NULL) {
    Node* Otemp = Ohead;
    std::cout << Ohead->value << " ";
    Ohead = Ohead->next;
    delete Otemp;
  }

}
