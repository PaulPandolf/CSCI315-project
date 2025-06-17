#include "../include/doublyLinkedList.h"

int main()
{
  doublyLinkedList<int> list;

  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4);
  list.insert(5);
  list.insert(6);

  list.print();

  return 0;
}