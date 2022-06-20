//第四題(The 3n + 1 problem)
#include<stdio.h>
int main()
{
    int i,j;
    while(scanf("%d%d",&i,&j)!=EOF)//判斷是否結束
    {
        int a,b,time=1,temp=0,ans=0;
        printf("%d %d",i,j);
        if(j>i)//i一定是大的
        {
            temp=j;
            j=i;
            i=temp;
        }


        for(i;i>=j;i--)//運算
        {
            a=i;
            while(a!=1)
            {
                if(a%2==1)
                {
                    a=(a*3)+1;
                }
                else
                {
                    a=a/2;
                }
                time++;
            }
            if(time>ans)//更新最大值
            {
                ans=time;
            }
            time=1;
        }
        printf(" %d\n",ans);
    }
}
