

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxi 1000000
#define mod 1000
using namespace std;

ll Bigmod(ll base, ll power)
{
    if(power == 0) return 1;
    ll x= Bigmod(base,power/2);
    x= (x*x)% mod;
    if(power%2 == 1) x= (base*x)% mod;
    return x% mod;
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);

    while(t--)
    {
        ll n,k;
        scanf("%lld %lld",&n,&k);

        double log=log10(n);
        log=log*k;
        log= fmod(log,1);
        log=powl(10.0,log);
        ll first = (ll) (log*100);

        printf("Case %d: %lld",cas++,first);
        ll last=Bigmod(n,k);
        if( last == 0 ) printf(" 000\n");
        else
        {
            if(last <10)  printf(" 00%lld\n",last);
            else if(last <100)  printf(" 0%lld\n",last);
            else printf(" %lld\n",last);
        }
    }
    return 0;
}
