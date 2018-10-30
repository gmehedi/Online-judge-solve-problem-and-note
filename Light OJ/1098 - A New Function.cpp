
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxi 50000
#define mod 1000000007
using namespace std;
ll Sod(ll n)
{
    ll ans=0;
    for(ll i=2; i*i<=n; i++)
    {
        ll tot=n/i;
        ans += (tot+i)*(tot-i+1)/2;
        ans += i*(tot-i);
    }
    return ans;
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);

    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        printf("Case %d: %lld\n",cas++,Sod(n));
    }
    return 0;
}
