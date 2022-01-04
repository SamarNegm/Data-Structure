
#include <stdio.h>
#include <stdlib.h>
#define maxSize 10
int Queue[maxSize];
int isempty=1;
int front=-1,rare=-1;

int dequeue(int *num)
{
    if(rare<0)
        return 0;
   int i;
   *num=Queue[front];
   for(i=1;i<=rare;i++)
   {
       Queue[i-1]=Queue[i];
   }
   rare--;
return 1;

}

void enqueue(int data)
{

if(front==maxSize)
    return 0;
    if(isempty)
    {
        isempty=0;
        front++;
        rare++;

    }
    else{
        rare++;
    }
 Queue[rare]=data;



}




void Display()
{
    int i;
    for(i=front;i<rare+1;i++)
    {
           printf("%d \t", Queue[i%maxSize]);
    }

    printf("\n");
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



