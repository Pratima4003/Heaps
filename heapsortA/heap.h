#ifndef HEAP_H
#define HEAP_H

#include<stdlib.h>

//structure of heap
typedef struct heap{
  int *A;
  int s;
  int rear;
  int type;
}heap;

//functions
void initH(heap *H, int type);
void insertH(heap *H, int key);
int deleteH(heap *H);
void display(heap H);

#endif
