

#include <bits/stdc++.h>
#include <string>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <iostream>
#define vpii vector< pair<ll,int> >
#define vi vector<int>

#define for0(i,a) for(int i=0;i<a;i++)
#define pii              pair <int,int>
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
#define maxl 1000
#define psz 20
#define Fin      freopen("input.txt","r",stdin)
#define Fout     freopen("output.txt","w",stdout)
using namespace std;

    ll dp[maxl + 2][maxl + 2];
    ll dpb[maxl + 2][maxl + 2];

    ll Bionomial(ll n, ll k)
    {
        if(n == k || k == 0) return 1LL;
        if(dpb[n][k] != -1) return dpb[n][k];

        return dpb[n][k] = Bionomial(n-1,k-1) + ( Bionomial(n-1,k) );
    }

    ll  Subfactorial(int n, int k)
    {
        if(n == 0 && k == 0) return 1LL;
        if(n == 1 && k == 0) return 0LL;
        if(dp[n][k] != -1) return dp[n][k];

        if(n>1 && k == 0)
        {
            return dp[n][k] = (n-1)*( Subfactorial(n-1,0)+( Subfactorial(n-2,0)) );
        }


        return dp[n][k] = dpb[n][k] * ( Subfactorial(n-k,0) );
    }


int main(){

      ll n, k;
      for(int i=0; i<=810; i++)
      {
          for(int j=0; j<=810; j++)
          {
              dp[i][j] = -1LL;
              dpb[i][j] = -1LL;
          }
      }

      while( scanf("%lld%lld",&n, &k) != EOF )
      {
         // cout<<"B  "<<Bionomial(n, k)<<endl;
          if(n == -1) break;
          printf("%lld\n",Subfactorial(n,k));
      }
      return 0;

}
