//第七題(List of Conquests)

#include<stdio.h>
#include<string.h>
int main()
{
    char a[2001][76]={0};
    char b[76]={0};
    char temp[76]={0};
    int i,j,n,count=0,open=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",a[i]);
        gets(b);//把國名後的人名吃掉

    }
    for(i=0;i<n-1;i++)//bubble sort
    {
        for(j=0;j<n-1-i;j++)
        {
            if(strcmp(a[j],a[j+1])>0)
            {
                strcpy(temp,a[j]);
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1],temp);
            }
        }
    }
    i=0;
    while(i<n)
    {
            if(open==0)//管他一不一樣先印就對
            {
                printf("%s",a[i]);
                count++;
                open=1;
            }
            else if(open==1)
            {
                if(strcmp(a[i],a[i+1])==0)//國名一樣
                {
                    count++;
                }
                else//國名不一樣
                {
                    printf(" %d\n",count);
                    open=0;
                    count=0;
                }
                i++;
            }
    }
    return 0;

}
