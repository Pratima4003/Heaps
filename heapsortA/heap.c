//REQUIRED HEADER FILES AND #DEFINES
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"heap.h"
#define SIZE 10

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
void adjust(heap *H, char flag){
  if(!H)
    return;
  int p,q;
  if(flag == 'X' || flag == 'x'){
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
void heapyfy(heap *H, char flag){
  int l,r;
  for(int i = 0; i <= H->rear; i++){
    l = 2 * i + 1;
    r = 2 * i + 2;
    if(flag == 'X'){
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



/****************************************************************/

//HEAP FUNCTIONS

//initH() is to initialize the heap
void initH(heap *H){
  H->A = (int*)malloc(sizeof(int) * SIZE);
  H->s = SIZE;
  for(int i = 0; i < SIZE; i++)
    H->A[i] = -1;   //initialize all the elements of the array to -1
  H->rear = -1;
  return;
}

//insertH() adds the element to the heap
void insertH(heap *H, int key, char flag){
  if(H->A[0] == -1){
    H->A[0] = key;
    H->rear++;
    return;
  }
  for(int i = 0; i < SIZE; i++){
    if(key == H->A[i])
      return;
  }
  H->rear++;
  if(H->rear < SIZE){
    H->A[H->rear] = key;
    adjust(H, flag);
  }
  else{
    printf("\nSPACE INSUFFICIENT\n");
    return;
  }
  return;
}

//preorder function to check the heap
void display(heap H){
  for(int i = 0; i <= H.rear; i++){
    if(H.A[i] != -1)
      printf("%d\t",H.A[i]);
  }
  return;
}

//deleteH() function always deletes the zeroth index element from the heap
int deleteH(heap *H, char flag){
  int e = INT_MIN;
  if(H->A[0] == -1)
    return e;
  e = H->A[0];
  H->A[0] = H->A[H->rear];
  H->rear--;
  heapyfy(H, flag);
  return e;
}
