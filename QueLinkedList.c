
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

int dequeue(int *num)
{

if(isempty)
    return 0;
    if(head == tail)
    {
        printf("Queue is Empty");
        *num=head->Data;
        head = tail = NULL;
        isempty=1;
        return 1;
    }
    else if(!isempty)
    {
        *num=head->Data;

        head=head->Next;
        head->Prev=NULL;
        return 1;
    }


}

void enqueue(int data)
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
    enqueue(3);
    enqueue(5);
    enqueue(7);
    enqueue(9);
    enqueue(11);

    Display();
    int p1;
    if( dequeue(&p1))
    {

        printf("\n\n\n\n dequeue %d  \n",p1);
        Display();


    }
    int p2;
    if(dequeue(&p2))
    {

        printf("\n\n\n\n dequeue %d  \n",p2);
        Display();
    }
    int p3;
    if(dequeue(&p3))
    {


        printf("\n\n\n\ndequeue %d  \n",p3);
        Display();
    }

    int p4;
    if( dequeue(&p4))
    {

        printf("\n\n\n\ndequeue %d  \n",p4);
        Display();

    }
    int p5;
    if( dequeue(&p5))
    {
        printf("\n\n\n\ndequeue %d  \n",p5);
        Display();

    }

    int p6;
    if( dequeue(&p6))
    {
        printf("\n\n\n\ndequeue %d  \n",p6);
        Display();

    }
    else
    {
        printf("Queue is Empty");
    }


    return 0;
}


