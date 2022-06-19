#include<stdio.h>
int main()
{
    long long a,b,temp,ans;
    while(scanf("%lld%lld",&a,&b)!=EOF)//判斷測資結束了沒
    {
        if(b>a)
        {
            temp=b;
            b=a;
            a=temp;
        }
        ans=a-b;
        printf("%lld\n",ans);
    }
    return 0;
}
