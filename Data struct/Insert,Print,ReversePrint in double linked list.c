#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head;

struct Node* GetNewNode(int x)  //單獨寫出來方便之後使用
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));   //不能用struct Node* newNode;因為結束後會被刪掉(不會一直在)
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
};

void InsertAtHead(int x)  //插入在head
{
    struct Node* newNode=GetNewNode(x);  //區域變數
    if(head==NULL)  //設定head
    {
        head=newNode;
        return;
    }
    head->prev=newNode;   //舊節點連接新的節點
    newNode->next=head;   //新節點連接舊節點
    head=newNode;  //設定head
}

void Print()
{
    struct Node* temp=head;
    printf("Forward: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void ReversePrint()
{
    struct Node* temp=head;
    if(temp==NULL) return;  //判斷有沒有traversal到最後了
    while(temp->next!=NULL)  //往前
    {
        temp=temp->next;
    }
    printf("Reverse: ");
    while(temp!=NULL)  
    {
        printf("%d ",temp->data);
        temp=temp->prev;   //倒著印回來
    }
    printf("\n");
}
int main()      //這樣寫比較整齊~~
{
    head=NULL;
    InsertAtHead(2); Print(); ReversePrint();  
    InsertAtHead(4); Print(); ReversePrint();
    InsertAtHead(6); Print(); ReversePrint();
    return 0;
}
