#include<stdlib.h>
#define MAX 1
#define MIN 0
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
void preorder(heap H);
void heapSort(heap *h);
