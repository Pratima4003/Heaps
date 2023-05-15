//REQUIRED HEADER FILES AND #DEFINES
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"heap.h"
#include"heapsort.h"

/* UTILITY FUNCTIONS */

//swap() function which is required for swap and heapyfy
void swapN(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
  return;
}

//This function sort heapifies the heap as min heap
void heapifysort(heap *h, int index){
    int i = 0;
    int imin = 0;
    while (i < index){
        if(2 * i + 1 > index - 1)
            break;
        
        if(h->A[2 * i + 1] < h->A[2 * i + 2])
            imin = 2 * i + 1;
        
        else
            imin = 2 * i + 2;
        
        if(h->A[i] > h->A[imin]){
            swapN(&h->A[i], &h->A[imin]);
            i=imin;
        }
        
        else
            break;
    }
}

/*************************************************************************************/

/* HEAP SORT */

void heapSort(heap *h, char order){
    int nodes = h->rear + 1;
    int index = h->rear;

    for(int j = 0; j < nodes; j++){
        int data = h->A[0];
        int i = 0;
        
        swapN(&h->A[i], &h->A[index]);
        index--;
        // h->rear--;
        heapifysort(h, index);
    }
    if(h->A[0] > h->A[1])
      swapN(&h->A[0], &h->A[1]);
  
    if(order == 'A' || order == 'a')
        return;
    else{
        int s = 0, e = h->rear;
        while(s < e){
            swapN(&h->A[s], &h->A[e]);
            s++;
            e--;
        }
    }
    return;
}
