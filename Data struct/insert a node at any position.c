#include<stdlib.h>
#include<stdio.h>
struct Node{  //定義node的格式,包含資料和指標next
    int data;
    struct Node* next;
};
struct Node* head;  //建立一個代表頭的node

void Insert(int data,int n)  //temp1用來當插入的,temp2用來當標位置的
{
     struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
     temp1->data=data;
     temp1->next=NULL;
     if(n==1)   //如果是加在開頭的話要設定head
     {
         temp1->next=head;
         head=temp1;
         return;
     }
     struct Node* temp2=head;
     int i;
     for(i=0;i<n-2;i++)   //n-2是因為這裡設i從0開始,所以-1,然後插入地點是上一個節點,所以-2
     {
         temp2 = temp2->next;
     }
     temp1->next=temp2->next;  //把後面的箭頭連接
     temp2->next=temp1;         //把前面連起來
}

void Print()
{
    struct Node* temp=head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void FreeList()  //用了malloc要記得用free釋放內存(鍾誠說不然可能會出現奇怪bug)
{
    struct Node* current=head;   //創一個新的Node用來traversal,不會動到head
    struct Node* temp;    //用來釋放的
    while(current != NULL)
    {
        temp=current;     //釋放current這個node
        current=current->next;  //下一個
        free(temp);
    }
}
int main()
{
    head=NULL;
    Insert(2,1);  //List:2
    Insert(3,2);  //List:2,3
    Insert(4,1);  //List:4,2,3
    Insert(5,2);  //List:4,5,2,3
    Print();
    FreeList();
    return 0;
}
