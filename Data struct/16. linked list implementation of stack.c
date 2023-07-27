#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* top=NULL;

void Push(int x)  //不用特別管是不是空的
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node*));
    temp->data=x;
    temp->next=top;  //接到後面的節點
    top=temp;    //更新top
}

void Pop()
{
    struct Node* temp;
    if(top==NULL) return;   //判斷是不是空的
    temp=top;
    top=top->next;   //把top更新到後一個
    free(temp);  //釋放~~
}

void Print()
{
    struct Node* temp=top;
    printf("Stack is: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    Push(2); Print();
    Push(4); Print();
    Push(5); Print();
    Pop(); Print();
    Push(10); Print();
    return 0;
}
