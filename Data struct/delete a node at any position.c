#include<stdlib.h>
#include<stdio.h>
struct Node{  //定義node的格式,包含資料和指標next
    int data;
    struct Node* next;
};
struct Node* head;  //建立一個代表頭的node

void Insert(int x)    //插入函式,往後插入
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));    //建立一個叫temp的node,分配空間給他,記得轉換指標類型(防止出錯)
    temp->data=x;   //temp的資料是x,也能寫成(*temp).data=x;
    temp->next=NULL;   //temp指向NULL,也能寫成(*temp).next=NULL;
    if (head == NULL) {    //記得設定head在哪
        head = temp;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}

void Print()
{
    struct Node* temp=head;
    printf("List is : ");
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void Delete(int n)   //temp2是要釋放的,temp1做標記
{
    struct Node* temp1=head;
    if(n==1)  //刪頭要設定下一個頭
    {
        head=temp1->next;        
        free(temp1);   //釋放掉才算真正刪除
        return;
    }
    int i;
    for(i=0;i<n-2;i++)
    {
        temp1=temp1->next;  
    }
    struct Node* temp2=temp1->next;    //創一個temp2指到要刪除的
    temp1->next=temp2->next;     //連線
    free(temp2);
}
int main()
{
    head=NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    Print();
    int n;
    printf("Enter a position to delete\n");  //是看位置刪
    scanf("%d",&n);
    Delete(n);
    Print();
    return 0;
}
