#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* createNode(int data) {
  struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
  if(newNode==NULL) {
    printf("Memory allocation failed\n"); exit(1);
  }
  newNode->data=data;
  newNode->next=NULL; return newNode;
}

void insertEnd(struct Node** head_ref, int new_data) {
  struct Node* new_node=createNode(new_data);
  if(*head_ref==NULL) {
    *head_ref=new_node;
    new_node->next=*head_ref;
  }
  else {
    struct Node* temp=*head_ref;
    while(temp->next!=*head_ref) {
    temp=temp->next;
    }
    temp->next=new_node;
    new_node-<next=*head_ref;
  }
}


















