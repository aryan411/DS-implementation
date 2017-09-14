#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
  struct Node* prev;
};

typedef struct Node* node;
node head,tail;

void insertAtHead(int value){
  node temp = (node)malloc(sizeof(node));
  temp->data = value;
  temp->next = head;
  temp->prev = NULL;
  head = temp;
}

void insertAtTail(int value){
  node temp1 = head;
  if(head == NULL){
    // printf("List is empty\n");
    insertAtHead(value);
    return;
  }
  
  while(temp1->next != NULL) temp1 = temp1->next;
  node temp2 = (node)malloc(sizeof(node));
  temp2->next = NULL;
  temp2->prev = temp1;
  temp2->data = value;
  temp1->next = temp2;
}

void deleteAtBeginning(){
  node temp = head;
  temp  = temp->next;
  temp->prev = NULL;
  free(head);
  head = temp;
}

void deleteAtEnd(){
  node temp1 = head;
  while(temp1->next != NULL){
    temp1 = temp1->next;
  }
  node temp2;
  temp2 = temp1->prev;
  temp2->next = NULL;
  free(temp1);
}

void print(){
  node temp = head;
  while(temp != NULL){
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}
int getSize(){
  node temp = head;
  int count=0;
  while(temp != NULL){
    temp = temp->next;
    count++;
  }
  return count;
}
int main(){
  head = NULL;
  tail = NULL;
  // int t,n,m;
  // scanf("%d",&t);
  // while(t--){
    // scanf("%d",&n);
    int n = 10;
    insertAtTail(n++);
    insertAtTail(n++);
    insertAtTail(n++);
    insertAtTail(n++);
    insertAtTail(n++);
    insertAtHead(n--);
    insertAtHead(n--);
    insertAtHead(n--);

  // }
  print();
  // printf("Wanna move forward?\n");
  // scanf("%d",&m);
  // if(m==1){
  // for(int i=1; i<=t; i++){
  //     if(i%2==0){ 
  //       deleteAtEnd();
  //       print();
  //     }
  //     else{ 
  //       deleteAtBeginning();
  //       print();
  //     }
  //   }
    deleteAtEnd();
    print();
    deleteAtBeginning();
    print();
  // }
  return 0;
}
