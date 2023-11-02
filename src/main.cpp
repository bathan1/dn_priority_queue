#include <iostream>
#include <BinaryHeapPriorityQueue.hpp>

int main() {
  BinaryHeapPriorityQueue<int>* my_heap = new BinaryHeapPriorityQueue<int>();
  
  my_heap->insert(10);
  my_heap->insert(5);
  my_heap->insert(8);
  my_heap->insert(1);
  my_heap->insert(14);
  my_heap->remove();
  my_heap->insert(12);
  my_heap->insert(3);
  my_heap->insert(7);
  my_heap->remove();
  my_heap->print_heap();
  return 0;
}
