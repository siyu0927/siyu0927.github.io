//C++
#include <stdio.h>
#include <stack>
#include <string.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* top;
void Reverse()
{
    if(top==NULL) return;  //判斷是不是空的
    std::stack<struct Node*> S;  //創一個堆疊,格式是Node
    Node* temp=top;
    while(temp!=NULL)  //全部放進去
    {
        S.push(temp); 
        temp=temp->next;
    } 
    temp=S.top();
    top=temp;
    S.pop();  //先讓top變成上一個
    while(!S.empty())
    {
        temp->next=S.top();   //指到上一個
        S.pop();  //移出堆疊
        temp=temp->next;   //temp往下一個移動
    }
    temp->next=NULL;

}
void Push(int x)  //不用特別管是不是空的
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
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
    struct Node* temp = top;
    printf("Stack is: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
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
    printf("Reverse: ");
    Reverse();Print();
    return 0;
}
