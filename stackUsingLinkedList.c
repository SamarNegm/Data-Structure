
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
    int Data;
    Node *Prev, *Next;
};

Node *head = NULL, *tail = NULL;
int isempty=1;

int peek()
{
    return tail->Data;
}

int pop(int *num)
{

if(isempty)
    return 0;
    if(head == tail)
    {
        printf("Stack is Empty");
        *num=tail->Data;
        head = tail = NULL;
        isempty=1;
        return 1;
    }
    else if(!isempty)
    {
        *num=tail->Data;

        tail=tail->Prev;
        tail->Next=NULL;
        return 1;
    }


}

void push(int data)
{

    isempty=0;

    Add(data);


}
Node* Create(int data)
{
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->Data = data;
    newNode->Prev = newNode->Next = NULL;

    return newNode;
}

void Add(int data)
{
    Node *newNode = Create(data);

    if(head == NULL) // empty LinkedList
    {
        head = tail = newNode;
    }
    else
    {
        newNode->Prev = tail;
        tail->Next = newNode;
        tail = newNode;

    }

}

void Display()
{
    Node *current = head;

    while(current != NULL)
    {
        printf("%d \t", current->Data);
        current = current->Next;
    }
    printf("\n\n");
}

int main()
{
    push(3);
    push(5);
    push(7);
    push(9);
    push(11);

    Display();
    int p1;
    if( pop(&p1))
    {

        printf("\n\n\n\npop %d  \n",p1);
        Display();


    }
    int p2;
    if(pop(&p2))
    {

        printf("\n\n\n\n pop %d  \n",p2);
        Display();
    }
    int p3;
    if(pop(&p3))
    {


        printf("\n\n\n\npop %d  \n",p3);
        Display();
    }

    int p4;
    if( pop(&p4))
    {

        printf("\n\n\n\npop %d  \n",p4);
        Display();

    }
    int p5;
    if( pop(&p5))
    {
        printf("\n\n\n\npop %d  \n",p5);
        Display();

    }

    int p6;
    if( pop(&p6))
    {
        printf("\n\n\n\npop %d  \n",p6);
        Display();

    }
    else
    {
        printf("Stack is Empty");
    }


    return 0;
}

