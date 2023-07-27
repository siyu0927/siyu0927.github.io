//C++
#include <stdio.h>
#include <stack>
#include <string.h>   //有用到strlen,所以要加

bool Balance(char *C,int n)  //判斷平衡
{
    std::stack<char> S;   //建stack
    for(int i=0;i<n;i++)  
    {
        if(C[i]=='('||C[i]=='['||C[i]=='{')    //把字串內括號開口放入
            {

                S.push(C[i]);
            }
        else if(C[i]==')'||C[i]=='}'||C[i]==']')  //處理關閉括號
            {
                if(S.empty())  //代表只有關閉符號,沒有開始,所以false
                {
                    return false;
                }
                char z =S.top();   //標示最上面的是哪種括號
                S.pop();    //先移除(反正有z存了)
                if((C[i]==')'&& z !='(')||(C[i]==']'&& z !='[')||(C[i]=='}'&& z !='{'))   //跟z判斷是不是同一種括號
                    {
                        return false;
                    }

            }
    }
    return S.empty(); //都處理完後應該要是空的,所以可以直接回傳empty()
}
int main()
{
    char C[51];
    printf("Enter a string: ");
    scanf("%s", C);
    if (Balance(C, strlen(C)))
    {
        printf("Balanced\n");
    }
    else
    {
        printf("Not Balanced\n");
    }
    return 0;
}
