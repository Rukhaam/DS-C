#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;


struct Node *insertAtBeginning(int data)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node *insertAtEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        newNode->data = data;
        newNode->next = NULL;
        head = newNode;
        return head;
    };

    newNode->data = data;
    struct Node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = NULL;
    return head;
}

void display(){
          struct Node *ptr= head;
          if(head  ==NULL) return;

          while(ptr!=NULL){
               printf("the element is %d", ptr->data);
               ptr = ptr->next;
          };

};

int main(){
       
      insertAtBeginning(10);
      insertAtBeginning(20);
      insertAtBeginning(30);
      insertAtBeginning(40);
      insertAtEnd(50);
      insertAtEnd(60);
      insertAtEnd(70);

      display();
      

}