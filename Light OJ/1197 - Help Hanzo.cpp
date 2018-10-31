

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxi 50000
#define mod 1000
using namespace std;

bitset<maxi+2>b;
int prime[maxi+2];
int k=0;
void Prime()
{
    b[0]=true;
    for(int i=2; i*i<=maxi; i++) if(!b[i]) for(int j=i*i; j<=maxi; j=j+i )b[j]=true;
    k=0;
    for(int i=2; i<=maxi; i++)if(!b[i] ) prime[k++]=i;
}
bool sign[100010];
ll Segmented_Sieve(ll u, ll v)
{
    ll cnt=0;
    memset(sign,true,sizeof sign);

    for(int i=0; i<k; i++)
    {
        ll base = (u/prime[i])*prime[i];

        if(base<u) base+=prime[i];
        for(int j=base; j<=v; j+=prime[i])
        {
            sign[j-u]=false;
        }
        if(base == prime[i]) sign[base-u]=true;
    }

    for(int i=u; i<=v; i++)
    {
        if(sign[i-u] && i != 1) cnt++;
    }
    return cnt;
}
int main()
{
    int t,cas=1;
    Prime();
    scanf("%d",&t);
    while(t--)
    {
        ll u,v;
        scanf("%lld %lld",&u,&v);
        printf("Case %d: %lld\n",cas++,Segmented_Sieve(u,v) );
    }
    return 0;
}
