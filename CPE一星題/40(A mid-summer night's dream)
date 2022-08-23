//第四題(A mid-summer night's dream)

#include<stdio.h>
#include<stdlib.h>
int sort(const void *a,const void *b)//省時間的sort
{
    return(*(int*)a-*(int*)b);
}
int main()
{
    int k;
    while(scanf("%d",&k)!=EOF)
{
    int i,change,j;
    int mid,b,count=0;

    int a[1000000];
    for(i=0;i<k;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,k,sizeof(int),sort);
    mid=(k-1)/2;
    printf("%d ",a[mid]);//中位數
    j=0;
    b=a[k/2];
    for(i=0;i<k;i++)
    {
        if(a[i]==a[mid]||a[i]==b)//符合中位數
        {
            j++;
        }
    }
    printf("%d ",j);

    printf("%d\n",b-a[mid]+1);
}
return 0;
}
