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

struct str
{
    int r;
    int g;
    int b;
}
val[30];

int n,t,cas=1;
int dp[25][20010][2][2][2];

int Dp(int pos, int tot, bool b1, bool b2, bool b3)
{
    if(pos == n)
    {
        return tot;
    }
   
    if(dp[pos][tot][b1][b2][b3] != -1) return dp[pos][tot][b1][b2][b3];
    int ans1=1e9,ans2=1e9,ans3=1e9;

   
    if(b1)
    {
       // cout<<"B1   "<<val[pos].r<<"      "<<tot+val[pos].r<<endl;
        ans1=Dp(pos+1,tot+val[pos].r,false,true,true);
    }

    if(b2)
    {
       // cout<<"B2   "<<val[pos].g<<"    "<<tot+val[pos].g<<endl;
        ans2=Dp(pos+1,tot+val[pos].g,true,false,true);
    }

    if(b3)
    {
      // if(tot == 42) cout<<"B3   "<<val[pos].b<<"   "<<tot+val[pos].b<<endl;
        ans3=Dp(pos+1,tot+val[pos].b,true,true,false);
    }
    return dp[pos][tot][b1][b2][b3]=min(ans1,min(ans2,ans3));

}
int main()
{
   // freopen("in.txt","w",stdout);
    scanf("%d",&t);

    while(t--)
    {
        memset(dp,-1,sizeof dp);
        scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            scanf("%d %d %d",&val[i].r,&val[i].g,&val[i].b);
        }
        int ans=Dp(0,0,true,true,true);
        if(ans == 1e9) ans=0;

        printf("Case %d: %d\n",cas++,ans);
    }

    return 0;
}