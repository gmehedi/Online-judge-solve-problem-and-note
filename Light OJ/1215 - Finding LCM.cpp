
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxi 1000000
#define mod 1000000007
using namespace std;

ll Bigmod(ll base, ll power)
{
    if(power == 0) return 1;
    ll x= Bigmod(base,power/2);
    x=x*x;
    if(power%2 == 1) x = base*x;
    return x;
}
bitset<maxi>b;
int prime[maxi];
int k=0;
void Prime()
{
    b[0]=true;
    for(int i=2; i*i<=maxi; i++) if(!b[i]) for(int j=i*i; j<=maxi; j=j+i )b[j]=true;
    k=0;
    for(int i=2; i<=maxi; i++)if(!b[i] ) prime[k++]=i;
}

map<int,int>mp,mp1;

void Factor(ll n, ll m)
{
    for(int i=0; i<k; i++)
    {
        if(n%prime[i] == 0) while(n%prime[i] == 0) mp[prime[i]]++, n/=prime[i];
        if(m%prime[i] == 0) while(m%prime[i] == 0) mp1[prime[i]]++, m/=prime[i];
        if(m ==0 && n==0) break;
    }
    if(n>1) mp[n]++;
    if(m>1) mp1[m]++;
 }
int main()
{
    int t,cas=1;
    Prime();
    scanf("%d",&t);

    while(t--)
    {
        ll a,b,lcm;
        scanf("%lld %lld %lld",&a,&b,&lcm);

        ll temp = (a*b)/__gcd(a,b);
        if(lcm % temp != 0) printf("Case %d: impossible\n",cas++);
        else
        {
            Factor(lcm,temp);
            map<int,int> :: iterator it;
            map<int,int> res;
            ll ans=1;
            for(it =mp.begin(); it != mp.end(); it++)
            {
                    if ( it->second > mp1[it->first] ) res[it->first]= it->second;
            }
            for(it =res.begin(); it != res.end(); it++)
            {
                ans =ans*Bigmod(it->first,it->second);
            }
            printf("Case %d: %lld\n",cas++,ans);

        }
        mp.clear();
        mp1.clear();
    }
    return 0;
}
