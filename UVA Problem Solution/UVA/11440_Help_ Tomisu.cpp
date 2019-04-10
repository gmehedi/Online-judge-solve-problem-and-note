#include <bits/stdc++.h>
#define pii              pair <ull,int>
#define pll              pair <long long,long long>
#define sc               scanf
#define pf               printf
#define Pi               2*acos(0.0)
#define ms(a,b)          memset(a, b, sizeof(a))
#define pb(a)            push_back(a)
#define MP               make_pair
#define db               double
#define ll               long long
#define ull              unsigned long long
#define f                first
#define s                second
#define sqr(x)           (x)*(x)
#define VI               vector <int>
#define DBG              pf("Hi\n")
#define MOD              100000007
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define loop(i,n)        for(int i=0;i<n;i++)
#define loop1(i,n)       for(int i=1;i<=n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define intlim           2147483648
#define ull              unsigned long long
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))
#define mk(x1,y1) make_pair(x1, y1)
#define maxl 10000001
#define psz 20
using namespace std;

vector<ll>prime;
bool sign[maxl+2];
ll inv[maxl+2],pup[maxl+2],pdown[maxl+3];;

ll Big_mod(ll base, ll power)
{
    if(power == 0LL) return 1LL;

    ll ans=Big_mod(base,power/2LL);
    ans=(ans*ans)%MOD;

    if(power%2LL == 1LL) ans=(ans*base)%MOD;

    return ans;
}

void Prime()
{
    prime.pb(2LL);

    for(ll i=3; i*i<=maxl; i+=2LL)
    {
        if(sign[i])
        {
            for(ll j=i*i; j<=maxl; j+=(i*2LL)) sign[j]=false;
        }
    }
    for(ll i=3; i<=maxl; i+=2) if(sign[i]) prime.pb(i);
    
    pup[0]=1,pdown[0]=2;
    for(int i=1; i<(int)prime.size(); i++)
    {
         pdown[i]=(pdown[i-1]*prime[i])%MOD; // multiplication of prime
         pup[i]=(pup[i-1]*(prime[i]-1LL))%MOD; // multiplication of prime-1;
    }

}

ll f[maxl+2];
void Fac()
{
    f[0]=1LL;
    for(ll i=1LL; i<=maxl; i++) f[i]=(f[i-1]*i)%MOD;// cout<<"F  "<<f[i]<<endl;
}
int main()
{
    memset(sign,true,sizeof sign);
    Prime();
    Fac();

    ll n,m;
    while(scanf("%lld %lld",&n,&m) == 2)
    {
        if(n == 0 && m == 0) break;

        ll ans=f[n];
        ll low=upper_bound(prime.begin(),prime.end(),m)-prime.begin();
        if(prime[low]>m) low--;
        //cout<<"L  "<<low<<"  "<<prime[low]<<"  "<<pdown[low]<<"  "<<pdown[low]<<endl;
        ans = (ans*pup[low])%MOD;
        ans= (ans*Big_mod(pdown[low],MOD-2))%MOD;
        ans=ans-1;
        ans=(ans+MOD)%MOD;

        printf("%lld\n",ans);

    }
    return 0;
}