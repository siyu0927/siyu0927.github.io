#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* front=NULL;  //刪除端
struct Node* rear=NULL;   //輸入端

void Enqueue(int x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node*));
    temp->data=x;
    temp->next=NULL;
    if(front==NULL&&rear==NULL)    //空queue的狀態
    {
        front=temp;    //front跟rear都設成temp
        rear=temp;
        return;
    }
    rear->next=temp;   //連接到新節點
    rear=temp;   //把rear更新到最後一個
}
void Dequeue()
{
    struct Node* temp=front;
    if(front==NULL) return;   //空queue的狀況
    if(front==rear)    //剩一個元素時
    {
        front=NULL;
        rear=NULL;
    }
    else
    {
        front=front->next;   //前進front
    }
    free(temp);   //釋放掉刪除的
}
void Print()
{
    struct Node* temp=front;
    printf("Queue is: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    Enqueue(2); Print();
    Enqueue(3); Print();
    Enqueue(4); Print();
    Dequeue();  Print();
    Enqueue(5); Print();
    Enqueue(6); Print();
    Dequeue();  Print();
    return;
}
