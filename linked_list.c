#include <stdio.h>
#include <stdlib.h>//for malloc function to allocate to memory
//Node structure
typedef struct Node{
    int data;
    struct Node*next;//pointer to another struct node
}Node;

void *New_Node(int data){
    Node*result = malloc(sizeof(Node));
    result->data = data;
    result->next = NULL;
    return result; 
}

void print_Node(Node*head){
    Node*temp = head;
    while(temp!= NULL){
        printf("%d -->",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Node*head = NULL;
    Node *tmp;
    for(int i = 0;i<=25;i++){
        tmp = New_Node(i);
        tmp->next = head;
        head = tmp;
    }
    print_Node(head);
}
    