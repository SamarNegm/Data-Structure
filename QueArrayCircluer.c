#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define maxSize 6
int Queue[maxSize];
int isempty=1;
int front=-1,rare=-1;

int dequeue(int *num)
{
    if(rare==-1)
        return 0;
    if(rare==front)
    {
        //empty
        isempty=1;
        *num=Queue[front%maxSize];
        front=-1;
        rare=-1;
        int i;
    }
    else
    {
        int i;
        *num=Queue[front%maxSize];
        front++;
        front=front%maxSize;
        return 1;
    }
}

void enqueue(int data)
{
    if((rare==maxSize-1&&front==0)||(rare+1==front))
    {
//full
        return ;
    }
    if(isempty)
    {
        isempty=0;
        front++;
    }
    rare++;
    rare=rare%maxSize;
    Queue[rare%maxSize]=data;

}

void Display()
{
    if(front==-1)
        return;
    int i,e;
    if(rare<front)
    {

        for(i=front; i<maxSize-1; i++)
            printf("%d \t", Queue[i]);

        for(i=0; i<=rare; i++)
            printf("%d \t", Queue[i]);

    }
    else
        for(i=front; i<=rare; i++)
        {
            printf("%d \t", Queue[i]);
        }

    printf("\n");
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(2);
    enqueue(6);
    Display();

    int p1;
    if( dequeue(&p1))
    {

        printf("\n\n dequeue %d  \n",p1);
        Display();


    }
    printf("\n\nenqueue %d  \n",7);
    enqueue(7);
    Display();

    int p2;
    if(dequeue(&p2))
    {

        printf("\n\ndequeue %d  \n",p2);
        Display();
    }
    int p3;
    if(dequeue(&p3))
    {
        printf("\n\ndequeue %d  \n",p3);
        Display();
    }
    printf("\n\nenqueue %d  \n",8);
    enqueue(8);
    Display();
    int p4;
    if( dequeue(&p4))
    {

        printf("\n\ndequeue %d  \n",p4);
        Display();

    }
    int p5;
    if( dequeue(&p5))
    {
        printf("\n\ndequeue %d  \n",p5);
        Display();

    }

    int p6;
    if( dequeue(&p6))
    {
        printf("\n\ndequeue %d  \n",p6);
        Display();

    }
    else
    {
        printf("Queue is Empty");
    }

    int p7;
    if( dequeue(&p7))
    {
        printf("\n\ndequeue %d  \n",p7);
        Display();

    }
    else
    {
        printf("Queue is Empty");
    }

    int p8;
    if( dequeue(&p8))
    {
        printf("\n\ndequeue %d  \n",p8);
        Display();

    }
    else
    {
        printf("Queue is Empty");
    }
    return 0;
}




