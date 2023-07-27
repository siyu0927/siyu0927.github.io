//環狀queue
#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 10  //全域變數要用define

int A[MAX_SIZE];
int front = -1;
int rear = -1;

bool IsEmpty()  //判斷是不是空的
{
    return (front == -1 && rear == -1);
}

int Front()   //判斷front端的第一個是甚麼
{
    if (IsEmpty())
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return A[front];
}

void Enqueue(int x)  //插入
{
    if ((rear + 1) % MAX_SIZE == front)  //因為是環狀,所以判斷要用(rear+1)%MAX_SIZE
    {
        printf("Queue is full. Cannot enqueue %d.\n", x);
        return;
    }
    else if (IsEmpty())   //設定第一個
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX_SIZE;
    }
    A[rear] = x;
}

void Dequeue()  //這裡的刪除不是真正的移除,只是把front往後移而已
{
    if (IsEmpty())   //處理空queue的狀態
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    else if (front == rear) //queue剩一個時
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX_SIZE;   //front往後移
    }
}

int main()
{
    Enqueue(1); Enqueue(2); Enqueue(3);
    printf("Front element: %d\n", Front()); 
    Dequeue();
    printf("Front element after dequeue: %d\n", Front()); 
    Enqueue(4); Enqueue(5); Enqueue(6);
    printf("Queue elements: ");
    int current = front;
    while (current != rear) //印出所有的
    {
        printf("%d ", A[current]);
        current = (current + 1) % MAX_SIZE;
    }
    printf("%d\n", A[current]);
    return 0;
}
