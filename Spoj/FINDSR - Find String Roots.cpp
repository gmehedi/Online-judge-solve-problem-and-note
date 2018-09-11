#include<bits/stdc++.h>
#define maxi 100010
using namespace std;
int phi[maxi];
int prefix_func(char s[maxi],int &len)
{
    int j=0;
    phi[0]=0;
    int ans=0;
    for(int i=1; i<len; i++)
    {
        while(j>0 && s[i] != s[j]) j=phi[j-1];

        if(s[i]==s[j]) j++;
        phi[i]=j;
    }

    return 0;
}
int main()
{
        char s[maxi];

        while( scanf("%s",s) ==1 )
        {
            if(s[0]=='*') break;
            memset(phi,0,sizeof phi);

            int len=strlen(s);
            prefix_func(s,len);
            int divi=0;
            phi[len]=1e9;
            for(int i=0; i<len; i++)
            {
                if(phi[i]==0 || phi[i]==phi[i+1]) divi=i+1;
            }
            if(len%divi==0)cout<<len/divi<<endl;
            else cout<<1<<endl;
        }
        return 0;
}
