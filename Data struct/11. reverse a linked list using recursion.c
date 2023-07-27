#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* head;

struct Node* Insert(struct Node* head,int data)  //有回傳所以不能用void
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    if(head ==NULL) head=temp;  //list是空的狀態
    else
    {
        struct Node* temp1=head;
        while(temp1->next !=NULL) temp1=temp1->next;
        temp1->next=temp;
    }
    return head;
}

void Print(struct Node* p)  //recursion的方式,正著印
{
    if(p==NULL)    //判斷是不是最後一個
    {
        printf("\n");
        return;
    }
    printf("%d ",p->data);     //印資料
    Print(p->next);   //後recursion
}

void Reverse(struct Node* p)
{
    if(p->next==NULL)    //先把最後一個設成head
    {
        head=p;    
        return;
    }
    Reverse(p->next);   //recursion
    struct Node* q =p->next;     //q會是還沒轉方向的最後一個,p世上一個
    q->next=p;    //箭頭往回指
    p->next=NULL;    //表示結束
}

int main()
{
    head=NULL;
    head=Insert(head,2);
    head=Insert(head,4);
    head=Insert(head,6);
    head=Insert(head,5);
    printf("List is: ");
    Print(head);
    printf("Reverse List is: ");
    Reverse(head);
    Print(head);
    printf("\n");
    return 0;
}
