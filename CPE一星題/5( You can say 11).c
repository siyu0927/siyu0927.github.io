//第五題( You can say 11)

#include<stdio.h>
#include<string.h>//記得加
int main(){

    char a[1000]={0};//整數不夠用,所以用陣列

    while(1)
    {
        scanf("%s",&a);
        if(*a=='0'&&strlen(a)==1)//用指標表示,注意是字元
        {
            break;
        }
        else
        {
            int i,x=0,y=0,z=0;
            for(i=0;i<strlen(a);i++)
            {
                if(i%2==0)//奇數位的
                {
                    x=x+(a[i]-'0');
                }
                else//偶數位
                {
                    y=y+(a[i]-'0');
                }
            }

            z=x-y;
            if(z==0||z%11==0)
            {
                printf("%s is a multiple of 11.\n",a);
            }
            else
            {
                printf("%s is not a multiple of 11.\n",a);
            }
        }
    }
    return 0;
}
