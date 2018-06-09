
#include<bits/stdc++.h>
#define maxi 1000000
using namespace std;
bitset<maxi>b;
int prime[maxi];
int k=0;
void Prime()
{
    b[0]=true;
    for(int i=2; i*i<=maxi; i++) if(!b[i]) for(int j=i*i; j<=maxi; j=j+i )b[j]=true;
    k=0;
    for(int i=2; i<=maxi; i++)if(!b[i] ) prime[k++]=i;//cout<<"I  "<<i<<endl;
    prime[k++]=INT_MAX;
}

int main()
{
    Prime();
    long long n,t=0;
    while( scanf("%lld",&n)==1 && n>0 )
    {
        t=n;
        for(int i=0; i<k && (long long) prime[i]*prime[i]<=t; i++)
        {
            while( !(n%prime[i]) )
            {
                printf("    %d\n",prime[i]);
                n/=prime[i];
            }
        }
        if( n>1 )printf("    %lld\n",n);
        printf("\n");
    }
    return 0;
}
