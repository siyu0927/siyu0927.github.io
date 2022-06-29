//第14題(Doom's Day Algorithm)
#include<stdio.h>
int main()
{
    int i,j=5,open=1,n;;
    int month,day;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&month,&day);
        if(month<=7&&month>=1)//1-7月
        {
            j=5;
            open=1;
            for(i=1;i<month;i++)
            {
                j=j+30+open;//31.30輪流加

                if(open==0)
                {
                    open=1;
                }
                else open=0;
            }
            if(month>2) j=j-2;//2月只有28天

            j=j+day;

        }
        if(month<=12&&month>=8)//8-12月
        {
            open=1;
            j=217;//8月前總天數
            for(i=0;i<month-8;i++)
            {
                j=j+30+open;
                if(open==0)
                {
                    open=1;
                }
                else open=0;

            }
            j=j+day;

        }
        if(j%7==1) printf("Monday");
        if(j%7==2) printf("Tuesday");
        if(j%7==3) printf("Wednesday");
        if(j%7==4) printf("Thursday");
        if(j%7==5) printf("Friday");
        if(j%7==6) printf("Saturday");
        if(j%7==0) printf("Sunday");
        printf("\n");
    }
    return 0;
}
