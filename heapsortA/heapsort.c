//REQUIRED HEADER FILES AND #DEFINES
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"heapsort.h"
#define SIZE 100

/* UTILITY FUNCTIONS */

//swap() function which is required for swap and heapyfy
void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
  return;
}

//following functions adjusts the binary tree
//after insertion to satisfy the definition of max or min heap
//if flag == 'X', do adjustment for max heap
//else if flag == 'N' do adjustment for min heap
//else dont do anything
void adjust(heap *H){
  if(!H)
    return;
  int p,q;
  if(H->type == 1){
    for(int i = H->rear; i >= 0; i--){
      p = (i - 1) / 2;
      if(p >= 0){
        if(H->A[i] > H->A[p])
          swap(&H->A[i] , &H->A[p]);
      }
    }
  }
  
  else{
    for (int j = H->rear; j >= 0; j--){
      q = (j - 1) / 2;
      if(q >= 0){
        if(H->A[j] < H->A[q])
          swap(&H->A[j], &H->A[q]);
      }
    }
  }
  //printf("\nHEAP ADJUSTED\n");
  return;
}

//following function adjusts the binary tree
//after deletion to satisfy the definition of max heap
//if flag == 'X', do heapyfy for max heap
//else if flag == 'N' do heapyfy for min heap
void heapyfy(heap *H){
  int l,r;
  for(int i = 0; i <= H->rear; i++){
    l = 2 * i + 1;
    r = 2 * i + 2;
    if(H->type == 1){
      if(l < H->rear && r < H->rear){
        if(H->A[l] > H->A[r] && H->A[l] > H->A[i])
          swap(&H->A[i], &H->A[l]);
        
        else if(H->A[l] < H->A[r] && H->A[r] > H->A[i])
          swap(&H->A[i], &H->A[r]);
      }
    }
    else{
      if(l <= H->rear && r <= H->rear){
        if(H->A[l] < H->A[r] && H->A[l] < H->A[i])
          swap(&H->A[i], &H->A[l]);
        
        else if(H->A[l] > H->A[r] && H->A[r] < H->A[i])
          swap(&H->A[i], &H->A[r]);
      }
    }
  }
  return;
}



/****************************************************************************************/

//HEAP FUNCTIONS

//initH() is to initialize the heap
void initH(heap *H, int type){
  H->A = (int*)malloc(sizeof(int) * SIZE);
  H->s = SIZE;
  //for(int i = 0; i < SIZE; i++)
    //H->A[i] = -1;   //initialize all the elements of the array to -1
  H->rear = -1;
  H->type = type;
  return;
}

//insertH() adds the element to the heap
void insertH(heap *H, int key){
  if(H->rear == -1){
    H->rear++;
    H->A[H->rear] = key;
    return;
  }
  /*for(int i = 0; i < SIZE; i++){
    if(key == H->A[i])
      return;
  }*/
  H->rear++;
  if(H->rear < SIZE){
    H->A[H->rear] = key;
    adjust(H);
  }
  else{
    printf("\nSPACE INSUFFICIENT\n");
    return;
  }
  return;
}

//preorder function to check the heap
void preorder(heap H){
  for(int i = 0; i <= H.rear; i++){
    if(H.A[i] != -1)
      printf("%d\t",H.A[i]);
  }
  return;
}

//deleteH() function always deletes the zeroth index element from the heap
int deleteH(heap *H){
  int e = INT_MIN;
  if(H->rear == -1)
    return e;
  e = H->A[0];
  H->A[0] = H->A[H->rear];
  H->rear--;
  heapyfy(H);
  return e;
}

/*************************************************************************************/

//HEAP SORT

void heapifysort(heap *h, int index){
    int i=0;
    int imax=0;
    while (i<index){
        if(2*i+1>index-1){
            break;
        }
        if(h->A[2*i+1]>h->A[2*i+2]){
            imax=2*i+1;
        }else{
            imax=2*i+2;
        }

        if(h->A[i]<h->A[imax]){
            swap(&h->A[i],&h->A[imax]);
            i=imax;
        }else{
            break;
        }
    }
}

void heapSort(heap *h){
    int nodes=h->rear+1;
    int index=h->rear;

    for(int j = 0; j < nodes; j++){
        int data = h->A[0];
        int i=0;
        
        swap(&h->A[i],&h->A[index]);
        index--;
        // h->c--;
        heapifysort(h, index);
    }
    if(h->A[0] > h->A[1])
      swap(&h->A[0], &h->A[1]);
    return;
}
