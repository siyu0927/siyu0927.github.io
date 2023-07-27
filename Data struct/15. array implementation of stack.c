#include<stdio.h>
#define MAX_SIZE 101   //因為是全域變數,不能用表達式寫(int MAX_SIZE=101;)
int A[MAX_SIZE];
int top=-1;

void Push(int x)   //插入
{
    if(top==MAX_SIZE -1)  //考量到堆疊塞不下的問題
    {
        printf("Error: stack overflow\n");
        return;
    }
    A[++top]=x;   //輸入值
}

int Top()  //沒有用到,但就一起寫了
{
    return A[top];
}
void Pop()  //這裡的移除不是真的移除,只是將top往前,之後push時資料會蓋過去
{
    if(top==-1)  //考量到空stack的問題
    {
        printf("Error: No element to pop\n");
        return;
    }
    top--;
}

void Print()  
{
    int i;
    printf("Stack:");
    for(i=0;i<=top;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

int main()
{
    Push(2);  Print();
    Push(5);  Print();
    Push(10); Print();
    Pop();    Print();
    Push(12); Print();
    return 0;
}
