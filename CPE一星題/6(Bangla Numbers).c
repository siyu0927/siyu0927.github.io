//第六題(Bangla Numbers)

#include<stdio.h>
int main()
{
    int count=1;
    long long n;
    while(scanf("%lld",&n)!=EOF)
    {
        printf("%d. ",count);
        if(n==0)
        {
            printf("%d",n);
        }
        else
        {
            function(n);
        }
        count++;
        printf("\n");
    }

}
void function(long long n)
{
    if(n/10000000>0)
    {
        function(n/10000000);
        printf(" kuti");
        n=n%10000000;
        if(n>0) printf(" ");
    }
    if(n/100000>0)
    {

        printf("%lld lakh",n/100000);
        n=n%100000;
        if(n>0) printf(" ");
    }
    if(n/1000>0)
    {

        printf("%lld hajar",n/1000);
        n=n%1000;
        if(n>0) printf(" ");
    }
    if(n/100>0)
    {

        printf("%lld shata",n/100);
        n=n%100;
        if(n>0) printf(" ");
    }
    if(n!=0)
    {
        printf("%lld",n);
    }
}


/*錯誤寫法,zero judge 錯在輸入460000000009040
正確答案是 2. 4 kuti 60 lakh kuti 9 hajar 40
我的答案是 2. 4 kuti 60 lakh 9 hajar 40
少一個kuti(但我從題目也看不出來需要寫這個啊,煩欸
*/

//錯誤寫法
/*#include<stdio.h>
int main(){
    long long x=0,i=1;
    while(scanf("%lld",&x)!=EOF)
    {
        long long one=0,two=0,three=0,four=0;
        long long a=0,b=0,c=0,d=0,e=0,z=0,f=0,g=0;
        a=x;
        z=(a%10000000000000000)/1000000000000;
        if(z>=10)
        {
            f=(z%100);
            g=(z/100);
        }
        z=(a%1000000000000000)/100000;
        if(z>=100)
        {
            c=(z%10000)/100;
            d=(z%100000)/10000;
            e=(z%10000000)/100000;
        }
        one=a%100;
        two=(a%1000)/100;
        three=(a%100000)/1000;
        four=(a%10000000)/100000;
        z=(a%1000000000000000)/100000;
        printf("%lld.",i);
        if(g!=0) printf(" %lld kuti",g);
        if(f!=0) printf(" %lld lakh",f);
        if(e!=0) printf(" %lld hajar",e);
        if(d!=0) printf(" %lld shata",d);
        if(c!=0) printf(" %lld kuti",c);
        if(four!=0) printf("% lld lakh",four);
        if(three!=0) printf(" %lld hajar",three);
        if(two!=0) printf(" %lld shata",two);
        if(one!=0) printf(" %lld\n",one);
        i++;
    }
}
*/
