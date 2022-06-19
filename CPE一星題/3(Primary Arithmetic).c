//第三題(Primary Arithmetic)

#include<stdio.h>
int main()
{
    int y,z;
    while(scanf("%d%d",&y,&z)!=0)
    {
        if(y==0&&z==0)//判斷測資是否結束
        {
            return 0;
        }
        int a[10]={0};
        int b[10]={0};
        int h=1,i,x,time=0;
        for(i=0;i<10;i++,h=h*10)//拆分第一個數字
        {
            x=(y/h)%10;
            a[i]=x;
        }
        h=1;
        for(i=0;i<10;i++,h=h*10)//拆分第二個數字
        {
            x=(z/h)%10;
            b[i]=x;
        }
        for(i=0;i<10;i++)//加起來看進位
        {
            if(a[i]+b[i]>=10)
            {
                time++;
                a[i+1]=a[i+1]+1;
            }
        }
        if(time==1)
        {
            printf("1 carry operation.");//沒有s,所以單獨寫
        }
        else if(time==0)
        {
            printf("No carry operation.");
        }
        else
        {
            printf("%d carry operations.",time);
        }
        printf("\n");

    }
}
