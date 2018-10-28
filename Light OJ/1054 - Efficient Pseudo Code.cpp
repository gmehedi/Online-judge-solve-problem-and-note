
#include<bits/stdc++.h>
#define ll long long
#define maxi 50000
#define mod 1000000007
using namespace std;

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
// sod=( (p1^cnt+1 - 1)/(p1-1) )*( (p2^cnt+1 - 1)/(p2-1) )

ll Big_mod(ll base, ll power)
{
    if(power == 0) return 1;

    ll x= Big_mod(base,power/2);
    x=(x*x) %mod;
    if(power%2 == 1) x=(x*base) %mod;

    return x%mod;
}

ll Modular_inverse(ll base, ll power)
{
    return Big_mod(base,power)%mod;
}

ll Factorization(ll num, ll m)
{
    ll temp=num;
    ll ans=1;

    for(int i=0; prime[i]*prime[i]<=num && i<k; i++)
    {
        int cnt=0;
        if(prime[i] > temp) break;

        while(temp%prime[i] == 0) temp/=prime[i],cnt++;

        if(cnt>0)
        {
            ll totp=(cnt*m)+1;
            ll temp1 =( (Big_mod(prime[i],totp) -1 )+mod ) %mod;
            ans=(ans*temp1)%mod;
            ans= ( ans*Modular_inverse(prime[i]-1,mod-2) ) %mod;
        }
    }
    if(temp>1)
    {
         ll temp1 =( (Big_mod(temp,m+1) -1 )+mod ) %mod;
         ans=(ans*temp1)%mod;
         ans= ( ans*Modular_inverse(temp-1,mod-2) ) %mod;
    }
    return ans%mod;
}


int main()
{
    int t,cas=1;
    Prime();
    scanf("%d",&t);
    while(t--)
    {
        ll n,m;
        scanf("%lld %lld",&n,&m);
         printf("Case %d: %lld\n",cas++,Factorization(n,m) );
    }

    return 0;
}
