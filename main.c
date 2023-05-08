#include<stdio.h>
#include<stdlib.h>
#include"heap.h"

int main(){
  heap H;
  initH(&H);
  char flag;
  printf("ENTER X FOR MAX AND N FOR MIN HEAP:");
  scanf("%c",&flag);
  if(flag != 'X' && flag != 'n' && flag != 'x' && flag != 'N'){
    printf("PLEASE ENTER VALID DATA!!\n");
    return 0;
  }
  insertH(&H, 12, flag);
  //preorder(H);
  //printf("\n");
  
  insertH(&H, 1, flag);
  //preorder(H);
  //printf("\n");
  
  insertH(&H, 13, flag);
  //preorder(H);
  //printf("\n");
  
  insertH(&H, 121, flag);
  //preorder(H);
  //printf("\n");
  
  insertH(&H, 98, flag);
  //preorder(H);
  //printf("\n");
  
  insertH(&H, 17, flag);
  //preorder(H);
  //printf("\n");
  
  insertH(&H, 15, flag);
  //preorder(H);
  //printf("\n");
  
  insertH(&H, 45, flag);
  //preorder(H);
  //printf("\n");
  
  insertH(&H, 3, flag);
  //preorder(H);
  //printf("\n");
  
  insertH(&H, 23, flag);
  preorder(H);
  printf("\n");
  
  printf("DELETED ELEMENT: %d\n",deleteH(&H, flag));
  preorder(H);
  printf("\n");
  return 0;
}  
  
