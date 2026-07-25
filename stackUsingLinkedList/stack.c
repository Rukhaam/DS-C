#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
   struct Node *next; 
};
struct Node *top= NULL;


struct Node *insert(int data){
         
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

           if(top==NULL) return;
           newNode->data = data;
           newNode->next = top;
           top =newNode;

           return top;
}


struct Node *pop()
{
    struct Node *temp;
    
    if(top==NULL) return;

         temp=top;
         top = top->next;

    int data = temp->data;
    printf("element deleted sucess %d",data);
    free(temp);

         return top; 

};


void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct Node *ptr = top;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
