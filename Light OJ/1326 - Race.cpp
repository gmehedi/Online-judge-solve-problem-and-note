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
#define MOD              10056
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
#define maxl 1001
#define psz 20
using namespace std;
ll pascal[maxl+2][maxl+2];

void Pascal()
{
    pascal[0][0]=1;
    pascal[1][0]=1,pascal[1][1]=1;
    for(int i=2; i<=maxl; i++)
    {
        for(int j=0; j<=maxl; j++)
        {
            if(j == 0){ pascal[i][j]=1; continue; }
            pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j]%MOD;
            if(j == i)
            {
                pascal[i][j]=1;
                break;
            }
        }
    }

   // for(int i=0; i<12; i++) { for(int j=0; j<12; j++) cout<<pascal[i][j]<<"   "; cout<<endl; }

}
ll dp[maxl+2];

ll Solve(ll n)
{
    if(n == 0LL) return 1LL;
    if(dp[n] != -1) return dp[n];
    ll sum=0;
    for(int i=1; i<=n; i++)
    {
         sum= (sum+pascal[n][i]*Solve(n-i)%MOD)%MOD;
    }
    return dp[n]=sum;
}
int main()
{
    Pascal();
    memset(dp,-1,sizeof dp);
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;

        scanf("%d",&n);
        printf("Case %d: %lld\n",cas++,Solve(n));

    }

    return 0;
}
