//C++寫法
#include <stdio.h>
#include <stack>
#include <string.h>   //有用到strlen,所以要加

void Reverse(char *C, int n)  //陣列的傳入要用指標傳
{
    std::stack<char> S;    //創建一個叫S的Stack,格式是char
    for (int i = 0; i < n; i++)  //把字母全部放入堆疊
    {
        S.push(C[i]);
    }
    for (int i = 0; i < n; i++)
    {
        C[i] = S.top();   //讓top往後移
        S.pop();   //取出堆疊
    }
}

int main()
{
    char C[51];
    printf("Enter a string: ");
    scanf("%s", C);
    Reverse(C, strlen(C));  
    printf("Output = %s", C);
    return 0;
}
