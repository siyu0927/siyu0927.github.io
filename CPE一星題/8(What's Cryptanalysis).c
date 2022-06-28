//第八題(What's Cryptanalysis)
#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    int count[999]={0};
    int i,m;
    char j='A';
    char str[999]={0};
    while(n--)
    {
    gets(str);

    for(i=0;i<=strlen(str);i++)//轉大寫
    {
        if(str[i]>='a'&&str[i]<='z')
        {
            str[i]=str[i]-32;
        }
    }

    for(i=0;i<strlen(str);i++)//算次數
    {
        for(m=0;m<26;j++)
        {
            if(str[i]==j)
            {
                count[m]++;
            }
            else if(str[i]!=j)
            {
                m++;
            }
        }
        j='A';

    }

    }

        j='A';
        for(m = sizeof(str); m >= 1; m--)
        {
            for(i=0;i<26;i++,j++)
            {
                if(count[i] == m)
                {
                    printf("%c %d\n", j,count[i]);
                }
            }
            j='A';
        }
}
