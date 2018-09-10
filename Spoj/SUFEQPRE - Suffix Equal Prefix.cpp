

#include<bits/stdc++.h>
#define maxi 1000010
using namespace std;
int phi[maxi];
void prefix_func(char s[maxi],int &len)
{
    int j=0;
    phi[0]=0;
    for(int i=1; i<len; i++)
    {
        while(j>0 && s[i] != s[j]) j=phi[j-1];

        if(s[i]==s[j]) j++;
        phi[i]=j;
    }
}
int cas=1;
int kmp(char s[maxi], int &len)
{
    prefix_func(s,len);
    int cnt=0,i=len-1;
    while(1)
    {
        if(phi[i]>0)
        {
            cnt++;
            i=phi[i]-1;
        }
        else break;
    }
    return cnt;
}
int main()
{
        int n,cas=1;
        scanf("%d",&n);
        getchar();
        for(int i=0; i<n; i++)
        {
            char s[maxi];
            scanf("%s",s);
            memset(phi,0,sizeof phi);
            int len=strlen(s);
            printf("Case %d: %d\n",cas++,kmp(s,len));
        }
        return 0;
}
