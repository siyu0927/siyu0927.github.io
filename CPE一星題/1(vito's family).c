//第一題 vito's family
#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    while(num--)
    {

        int i,j,temp,r,mid,ans=0;
        int a[500]={0};
        scanf("%d",&r);
        for(i=0;i<r;i++)//讀入陣列中
        {
            scanf("%d",&a[i]);
        }

        for(i=0;i<r-1;i++)//r從0開始,所以要-1
        {
            for(j=0;j<r-1-i;j++)
        {
                if(a[j]>a[j+1])
                {
                    temp=a[j+1];
                    a[j+1]=a[j];
                    a[j]=temp;
                }
            }
        }
        mid=r/2;//mid是中位數
        for(i=0;i<r;i++)
        {
            if(a[mid]-a[i]>=0)
            {
            ans+=a[mid]-a[i];
            }
            else ans=ans+(-(a[mid]-a[i]));
        }
        printf("%d\n",ans);//最短距離和
    }
return 0;
}
