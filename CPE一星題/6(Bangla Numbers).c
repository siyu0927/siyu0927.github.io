//第六題(Bangla Numbers)

#include<stdio.h>

void f(long long a)
{
    if(a/10000000)
    {
        f(a/10000000);//回呼
        printf(" kuti");
        a=a%10000000;
        if(a>0) printf(" ");
    }
    if(a/100000)
    {
        printf("%lld lakh",a/100000);
        a=a%100000;
        if(a>0) printf(" ");
    }
    if(a/1000)
    {
        printf("%lld hajar",a/1000);
        a=a%1000;
        if(a>0) printf(" ");
    }
    if(a/100)
    {
        printf("%lld shata",a/100);
        a=a%100;
        if(a>0) printf(" ");
    }
    if(a!=0) printf("%lld",a);
}

int main()
{
    int i=1;
    long long a;

    while(scanf("%lld",&a)!=EOF)
    {
        printf("%d. ",i);
        if(a==0)
        {
            printf("%lld",a);
        }
        else f(a);
        printf("\n");
        i++;
    }
}
