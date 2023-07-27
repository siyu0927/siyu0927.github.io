#include <stdio.h>
#include <string.h>

#define MAX_SIZE 51

struct Stack
{
    char data[MAX_SIZE];
    int top;
};

void Initialize(struct Stack *stack)  //用來初始化堆疊
{
    stack->top = -1;
}

void Push(struct Stack *stack, char value)
{
    if (stack->top == MAX_SIZE - 1)   //處理堆疊已滿的問題
    {
        printf("Error: stack overflow\n");
        return;
    }
    stack->top = stack->top + 1;  //top是要插入的地方,所以要先移到下一格
    stack->data[stack->top] = value;  //把值放入top的位置
}

char Pop(struct Stack *stack)
{
    if (stack->top == -1)  //處理沒東西的狀況
    {
        printf("Error: No element to pop\n");
        return '\0';
    }
    return stack->data[stack->top--];  //回傳top的下一個
}

void Reverse(char *C, int n)
{
    struct Stack S;
    Initialize(&S);   //初始化Stack
    for (int i = 0; i < n; i++)
    {
        Push(&S, C[i]);
    }
    for (int i = 0; i < n; i++)
    {
        C[i] = Pop(&S);
    }
}

int main()
{
    char C[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", C);
    Reverse(C, strlen(C));
    printf("Output = %s", C);
    return 0;
}
