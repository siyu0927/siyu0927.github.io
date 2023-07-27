//只能處理+-*/,個位數字
#include <stdio.h>
#include <stack>
#include <string.h>

int postfix(char *C, int n)
{
    std::stack<int> S;  //建stack
    for (int i = 0; i < n; i++)
    {
        if (C[i] >= '0' && C[i] <= '9')  //是數字的話
        {
            S.push(C[i] - '0');  //我們輸入時是char,要轉成int
        }
        else if (C[i] == '+' || C[i] == '-' || C[i] == '*' || C[i] == '/')  //是運算子的話
        {
            int op2 = S.top();   //取出最上面的數字
            S.pop();
            int op1 = S.top();   
            S.pop();
            int result;
            switch (C[i])  //對取出的數字進行運算
            {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
            }
            S.push(result);   //把結果push回去
        }
    }
    return S.top();   //最後的答案會是最上面的數字
}

int main()
{
    char C[51];
    printf("Enter a postfix expression: ");
    scanf("%s", C);  //輸入不用空格
    int result = postfix(C, strlen(C));
    printf("Result = %d\n", result);
    return 0;
}
