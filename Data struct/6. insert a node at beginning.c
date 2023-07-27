#include<stdlib.h>
#include<stdio.h>
struct Node{  //定義node的格式,包含資料和指標next
    int data;
    struct Node* next;
};
struct Node* head; //建立一個代表頭的node

void Insert(int x)    //插入函式
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));    //建立一個叫temp的node,分配空間給他,記得轉換指標類型(防止出錯)
    temp->data=x;   //temp的資料是x,也能寫成(*temp).data=x;
    temp->next=NULL;   //temp指向NULL,也能寫成(*temp).next=NULL;
    if(head != NULL) temp->next=head;  //如果head不直接指到NULL的話要指到head
    head=temp;   //把head更新成temp(才能知道下一個要加入到哪邊)
}

void Print()
{
    struct Node* temp=head;  //創造一個Node用來traversal,防止直接動到list的指標
    printf("List is: ");
    while(temp != NULL)  //直到temp指到NULL為止
    {
        printf(" %d",temp->data);  //印data
        temp=temp->next;    //繼續指到下一個node
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
    head=NULL;   //讓這個list先是一個empty狀態
    printf("How many numbers?\n");
    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)  //一個一個插
    {
        printf("Enter the number \n");
        scanf("%d",&x);
        Insert(x);
        Print();
    }
    FreeList();
    return 0;
}
