#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* head;

void Insert(int x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    if(head ==NULL) head=temp;
    else
    {
        struct Node* current=head;
        while(current->next !=NULL)
        {
            current=current->next;
        }
        current->next=temp;
    }
}

void Print()
{
    struct Node* temp=head;
    printf("List is: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void Reverse()  //前後反轉
{
    struct Node *current,*prev,*next;   //需要記上一個,下一個跟現在的
    current=head;
    prev=NULL;    //這樣可以把頭變成尾巴
    while(current!=NULL)   
    {
        next=current->next;   //設next是下一個node
        current->next=prev;   //把線接到上一個(一開始是NULL)
        prev=current;  //pre往前一個node 
        current=next;  //current往前一個node
    }
    head=prev;    //最後記得把head重設(print才能正常印)
}

int main()
{
    head=NULL;
    Insert(2);
    Insert(4);
    Insert(5);
    Insert(6);
    Print();
    Reverse();
    Print();
    return 0;
}
