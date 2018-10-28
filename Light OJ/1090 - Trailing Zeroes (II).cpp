
#include<bits/stdc++.h>
#define ll long long
#define maxi 50000
#define mod 1000000007
using namespace std;
ll ncrt[1000010],ncrf[1000010];
void NCR()
{
    for(int i=2; i<=1000000; i++)
    {
        int t=0,f=0;
        int temp=i;
        while(temp%2 == 0) temp/=2,t++;
        while(temp%5 == 0) temp/=5, f++;
        ncrt[i]= ncrt[i-1]+t;
        ncrf[i]= ncrf[i-1]+f;
    }
}
int main()
{
    int t,cas=1;
    NCR();
    scanf("%d",&t);
    while(t--)
    {
        ll n,r,p,q;
        scanf("%lld %lld %lld %lld",&n,&r,&p,&q);
        ll two=0,five=0;
        ll temp=p;

        while(temp%2 == 0) two++, temp/=2;
        while(temp%5 == 0) five++, temp/=5;

        two=two*q;
        five=five*q;

        two=two+ncrt[n]-ncrt[n-r]-ncrt[r];
        five=five+ncrf[n]-ncrf[n-r]-ncrf[r];

        printf("Case %d: %lld\n",cas++,min(two,five));
    }

    return 0;
}
