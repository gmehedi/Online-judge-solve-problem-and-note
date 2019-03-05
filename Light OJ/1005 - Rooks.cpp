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
#define MOD              1000000007
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
#define maxl 100001
#define psz 20
using namespace std;

ll df,ans;

ll Fac(ll from, ll to, ll to2)
{
    for(ll i=from; i<=to ;i++)
    {
        ans=ans*i;
        while(ans%df == 0 && df<=to2) ans/=df, df++;
    }
    while(ans%df == 0 && df<=to2) ans/=df, df++;
   // cout<<"A  "<<ans<<"  "<<df<<endl;
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);

    while(t--)
    {
        ll n,k;
        scanf("%lld %lld",&n,&k);
        if(n<k)
        {
            printf("Case %d: 0\n",cas++);
            continue;
        }
     
        df=2LL;
        ans=1LL;

        Fac(n-k+1,n,k);
        Fac(n-k+1,n,k);

        printf("Case %d: %lld\n",cas++,ans);

    }

    return 0;
}
