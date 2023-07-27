//只能處理+-*/,個位數字
#include <stdio.h>
#include <stack>
#include <string.h>

int prefix(char *C, int n)
{
    std::stack<int> S;
    for (int i = n - 1; i >= 0; i--)
    {
        if (C[i] >= '0' && C[i] <= '9')
        {
            S.push(C[i] - '0');
        }
        else if (C[i] == '+' || C[i] == '-' || C[i] == '*' || C[i] == '/')
        {
            int op1 = S.top();
            S.pop();
            int op2 = S.top();
            S.pop();
            int result;
            switch (C[i])
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
            S.push(result);
        }
    }
    return S.top();
}

int main()
{
    char C[51];
    printf("Enter a prefix expression: ");
    scanf("%s", C);
    int result = prefix(C, strlen(C));
    printf("Result = %d\n", result);
    return 0;
}
