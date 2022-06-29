//第25題(An Easy Problem!)
#include <stdio.h>
#include <string.h>
int main(){
    char n[10001];
    int i,sum=0,all=1,ans=0;
    while (scanf("%s", n) !=EOF){
        sum=0;
        all=1;
        for (i=0; i<strlen(n); i++){
            ans=0;
             if(n[i]>='0'&&n[i]<='9')
            {
                ans=n[i]-'0';
            }
            else if(n[i]>='A'&&n[i]<='Z')
            {
                ans=n[i]-'A'+10;
            }
            else if(n[i]>='a'&&n[i]<='z')
            {
                ans=n[i]-'a'+36;
            }
            sum=sum+ans;
            if (ans > all)
            {
                all=ans;
            }
        }
        for (i=all; i<=62; i++)
        {
            if (sum%i == 0)
            {
                printf("%d\n", i+1);
                break;
            }
            else if (i == 62)
            {
                printf("such number is impossible!\n");
            }
        }
    }
    return 0;
}
