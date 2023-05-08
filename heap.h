#include<stdlib.h>

//structure of heap
typedef struct heap{
  int *A;
  int s;
  int rear;
}heap;

//functions
void initH(heap *H);
void insertH(heap *H, int key, char flag);
int deleteH(heap *H, char flag);
void preorder(heap H);
