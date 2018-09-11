#include<bits/stdc++.h>
#define maxi 1000005
using namespace std;
long long phi[maxi];
void prefix_func(char s[maxi+3],long long len)
{
    long long j=0;
    phi[0]=0;

    for(long long i=1; i<len; i++)
    {
        while(j>0 && s[i] != s[j]) j=phi[j-1];

        if(s[i]==s[j]) j++;
        phi[i]=j;
    }

}

int main()
{
        while( 1 )
        {
            char s[maxi+3];
            scanf("%s",&s);
            if(s[0]=='.' && s[1] == '\0') break;
            memset(phi,0,sizeof phi);
            long long len= (int) strlen(s);
            prefix_func(s,len);
            long long not_match=len-phi[len-1];
            if( len%not_match==0 ) printf("%lld\n",(len/not_match));
            else printf("1\n");
        }
        return 0;
}
