#include <iostream>
using namespace std;

typedef struct Node
{
  unsignede int data;
  struct Node *next;
}Node;

void TraverseLinkedList(Node *root)
{
  Node *temp = root;
  while(NULL != temp)
  {
    std::cout << "item: " << temp->data << std::endl;
    temp = temp->next;
  }
}
