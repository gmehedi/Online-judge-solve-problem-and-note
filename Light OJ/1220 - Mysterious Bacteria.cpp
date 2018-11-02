
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxi 6
using namespace std;

inline ll Log(ll n, ll i)
{
    ll cnt=0, tt=1;
    while(1)
    {
        tt *= i;
        if(tt > n) return cnt;
        cnt++;
    }
}
bool sign =false;
inline ll Bigmod(ll base, ll power)
{
    if(power == 0) return 1;
    ll x = Bigmod(base,power/2);
    x = (x*x);
    if(power%2 == 1 ) x= (x*base);
    return x;
}

ll Max(ll n)
{
    ll temp=sqrt(n);

    for(ll i=2; i<=temp; i++)
    {
        if(n%i == 0)
        {
            ll power = Log(n,i);
         //   cout<<"I  "<<i<<" "<<power<<endl;
            if(Bigmod(i,power) != n) continue;
            else if(!sign || power%2 == 1) return power;
        }
    }
    return 1;
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);

    while(t--)
    {
        ll n;
        sign=false;
        scanf("%lld",&n);
        if(n<0) n = abs(n), sign=true;

        if(n == 0) printf("Case %d: 0\n",cas++);
        else printf("Case %d: %lld\n", cas++, Max(n));
    }
    return 0;
}
