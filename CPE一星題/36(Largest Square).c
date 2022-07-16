//第36題(Largest Square)
#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m,n,i,j;
        int x,y,ans;
        int open=1,a,b,q;
        scanf("%d%d%d",&m,&n,&q);
        char map[102][102]={0};
        getchar();
        for(i=0;i<m;i++)//輸入地圖
        {
           for(j=0;j<n+1;j++)
           {
              scanf("%c",&map[i][j]);
           }

        }
        printf("%d %d %d\n",m,n,q);
        //要找的中心點
        while(q--)
        {
            scanf("%d%d",&x,&y);
            ans=0;
             for(i=0;i<m||i<n;i++)//一圈一圈檢查
            {
                open=1;

                for(a=x-i;a<=x+i;a++)
                {
                    for(b=y-i;b<=y+i;b++)
                    {
                        if(a<0 || b<0 || a>=m || b>=n)
                        {
                            open=0;break;
                        }
                        if(map[a][b]!=map[x][y])
                        {
                            open=0;
                        }
                    }
                }
                if(open==1)
                {
                    ans=(i*2)+1;
                }
                else
                {
                    break;
                }
            }
            printf("%d\n",ans);
        }
    }

   return 0;
}
