#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll NumberOfSqrt(ll n)
{
    ll sqr= sqrt(n);
    return sqr;
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        ll ans =NumberOfSqrt(n);
        ans += NumberOfSqrt(n/2);

        printf("Case %d: %lld\n",cas++,n-ans);
    }
    return 0;
}

