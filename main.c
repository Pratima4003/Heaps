#include<stdio.h>
#include<stdlib.h>
#include"heapsort.h"

int main(){
  heap H;
  
  int flag;
  printf("ENTER 1 FOR MAX AND 0 FOR MIN HEAP:");
  scanf("%d",&flag);
  if(flag != 1 && flag != 0){
    printf("PLEASE ENTER VALID DATA!!\n");
    return 0;
  }
  initH(&H, flag);
  insertH(&H, 12);
  //preorder(H);
  //printf("\n");
  
  insertH(&H, 1);
  //preorder(H);
  //printf("\n");
  
  insertH(&H, 13);
  //preorder(H);
  //printf("\n");
  
  insertH(&H, 121);
  //preorder(H);
  //printf("\n");
  
  insertH(&H, 98);
  //preorder(H);
  //printf("\n");
  
  insertH(&H, 17);
  //preorder(H);
  //printf("\n");
  
  insertH(&H, 15);
  //preorder(H);
  //printf("\n");
  
  insertH(&H, 45);
  //preorder(H);
  //printf("\n");
  
  insertH(&H, 3);
  //preorder(H);
  //printf("\n");
  
  insertH(&H, 23);
  
  insertH(&H, 43);
  insertH(&H, 563);
  insertH(&H, 27);
  preorder(H);
  printf("\n");
  
  printf("DELETED ELEMENT: %d\n",deleteH(&H));
  preorder(H);
  printf("\n");
  heapSort(&H);
  preorder(H);
  printf("\n");
  return 0;
}  
  
