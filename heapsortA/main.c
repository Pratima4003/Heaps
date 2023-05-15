#include<stdio.h>
#include<stdlib.h>
#include"heap.h"
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
  FILE *fp;
  int n;
  fp = fopen("coco.txt", "r");
  for(int i = 0; i < 10; i++){
    fscanf(fp, "%d", &n);
    insertH(&H, n);
  }
  displayH(H);
  printf("\n");
  
  char order;
  printf("Enter A for acending or D for descending:");
  if(order != 'A' || order != 'a' || order != 'D' || order != 'd'){
    printf("PLEASE ENTER VALID DATA!!\n");
    exit(0);
  }
  heapSort(&H, order);
  displayH(H);
  printf("\n");
  return 0;
}  
  
