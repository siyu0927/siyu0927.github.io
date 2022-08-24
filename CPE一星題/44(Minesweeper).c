//第44題(Minesweeper)
#include<stdio.h>
void count(char a[][102],int n,int m);
int main()
{
    int n,m,i,j,c,z=1;

    char a[102][102];
    while(scanf("%d%d",&n,&m))
{
    if(n==0&&m==0)
    {
        break;
    }
    for(i=0;i<=n+1;i++)//地圖歸0
    {
        for(j=0;j<=m+1;j++)
        {
            a[i][j]='0';
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
           c=getchar();
           if(c=='\n')
           {
               c=getchar();
           }
           if(c=='*')
           {
               a[i][j]='*';
               count(a,i,j);
           }
        }
    }
printf("Field #%d:\n",z);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
           printf("%c",a[i][j]);
        }
        printf("\n");
    }
    z++;
    printf("\n");
}
return 0;
}
void count(char a[][102],int n,int m)//九宮格+1
{
    int i,j;
    for(i=n-1;i<=n+1;i++)
    {
        for(j=m-1;j<=m+1;j++)
        {
            if(a[i][j]!='*')
            {
                a[i][j]++;
            }
        }
    }
}
