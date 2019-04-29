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
#define maxl 100000
#define psz 20
/*
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
*/
using namespace std;

ll dp[10001],val[110],n,k;

ll Dp()
{
    dp[0]=1;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            if(j-val[i]>=0) dp[j]+=dp[j-val[i]];
            dp[j]%=MOD;
        }
    }
    return dp[k];
}


int main()
{
    int t,cas=1;
    scanf("%d",&t);

    while(t--)
    {
        memset(dp,0,sizeof dp);

        scanf("%lld %lld",&n,&k);
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&val[i]);
        }
        printf("Case %d: %lld\n",cas++,Dp());
    }
    return 0;
}
