//第三十題(Hartals)
#include<stdio.h>
#include<string.h>
int main()
{
    int w=0;
    scanf("%d",&w);
    while(w--)
    {
        int n=0;//多少天
        int p=0;//幾場派對
        int i=0,j=0,ans=0;
        int a[101]={0},day[3651]={0};
        scanf("%d",&n);
        scanf("%d",&p);
        for(i=0;i<p;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<p;i++)
        {
            for(j=0+a[i];j<n+1;j=j+a[i])
            {
                 if(day[j]<=n)
                 {
                     day[j]=1;
                 }
            }
        }
        for(i=1;i<n+1;i++)
        {
            if(day[i]==1)
            {
                if(i%7!=6&&i%7!=0)
                {
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
}
