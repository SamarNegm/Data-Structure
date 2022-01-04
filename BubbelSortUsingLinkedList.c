
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    int Data;
    Node *Prev, *Next;
};

Node *head = NULL, *tail = NULL;

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
Node* GetNodeByData(int data)
{
    Node *current = head;

    while(current != NULL)
    {

        if(data == current->Data)
            return current;

        current = current->Next;
    }

    return NULL;
}
int Remove(int data)
{

    Node *node = GetNodeByData(data);
    if(node == NULL)
        return 0;

    if(node == head)
    {
        if(node == tail)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->Next;
            head->Prev = NULL;
        }
    }
    else if(node == tail)
    {
        tail = tail->Prev;
        tail->Next = NULL;
    }
    else
    {
        node->Prev->Next = node->Next;
        node->Next->Prev = node->Prev;
    }

    free(node);
    return 1;
}



void InsertAfter(int data, int afterData)
{
    Node *afterNode = GetNodeByData(afterData);
    Node *dataNode = Create(data);

    if(afterNode==tail)
    {
        dataNode->Next=NULL;


    }
    else
    {
        dataNode->Next=afterNode->Next;
        afterNode->Next->Prev=dataNode;
    }
    afterNode->Next=dataNode;
    dataNode->Prev=afterNode;
    Display();
};



void InsertBefore(int data, int beforeData)
{

    Node *beforNode = GetNodeByData(beforeData);
    Node *dataNode = Create(data);

    if(beforNode==head)
    {
        head=dataNode;

    }
    else
    {
        dataNode->Prev=beforNode->Prev;
        beforNode->Prev->Next=dataNode;
    }
    dataNode->Next=beforNode;
    beforNode->Prev=dataNode;
    Display();
};



int GetDataByIndex(int index)
{
    Node *current = head;
    int i;
    for( i=0; i<index; i++)
    {
        current=current->Next;

    }
    return current->Data;


};

int GetLengthOfLinkedList()
{
    Node *current = head;
    int i=1;
    while(current->Next!=NULL)
    {
        i++;
        current=current->Next;
    }
    return i;


};


void BubbleSort()
{
    Node *OuterCurr =head;
    while(OuterCurr->Next!=NULL)
    {

        Node *InnerCurr =head;
        while(InnerCurr->Next!=NULL)
        {
            if((InnerCurr->Data)>(InnerCurr->Next->Data))
            {
                swap((InnerCurr),(InnerCurr->Next));

            }

            InnerCurr=InnerCurr->Next;
        }
        OuterCurr=OuterCurr->Next;
    }
}
void swap(struct Node *a, struct Node *b)
{
    int temp = a->Data;
    a->Data = b->Data;
    b->Data = temp;
}
int BianrySearch(int num)
{
    int l=0;
    int r=GetLengthOfLinkedList();
    while(l<=r)
    {
        int mid=(l+r)/2;
        int curr=GetDataByIndex(mid);
       // printf(" curr %d\n",curr);
        if(GetDataByIndex(mid)==num)
        {
            printf(" find it ");
            return mid;
        }
        if(GetDataByIndex(mid)<num)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }

    }
}

int main()
{
    Add(9);
    Add(5);
    Add(1);
    Add(12);
    Add(7);
    Add(9);
    Add(11);
    BubbleSort();
    Display();
    BianrySearch(9);

    return 0;
}

