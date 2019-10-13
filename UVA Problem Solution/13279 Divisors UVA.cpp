
#include <bits/stdc++.h>
#include <string>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <iostream>
#define vpii vector< pair<int,int> >
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
#define maxl 5000000
#define psz 20
#define Fin      freopen("in.txt","r",stdin)
#define Fout     freopen("out.txt","w",stdout)


/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
//ios_base::sync_with_stdio(false);
 //cin.tie(NULL);

using namespace std;
bool sign[maxl + 2];
vector<ll>prime;
ll n;

void Prime()
{
    memset(sign, true, sizeof sign);
    prime.pb(2LL);
    for(ll i = 3LL; i * i <= maxl; i += 2LL){
        if(sign[i]){
            for(ll j = i * i; j <= maxl; j += (i * 2LL)) sign[j] = false;
        }
    }
    for(ll i = 3LL; i <= maxl; i += 2LL){
        if(sign[i]) prime.pb(i);
    }
}



int main(){

    Prime();

    while( scanf("%lld", &n) != EOF && n){

        ll ans = 1LL;

        for(int i = 0; i < prime.size() && prime[i] <= n; i++){

            ll temp = prime[i], n1 = n;
            ll tot = 0LL;

            while(n1 / temp){

                ll tt = n1 / temp;

                ll rr = (n1 % temp) + 1LL;

                ll tot1 =  ( ( (tt * (tt - 1LL)) / 2LL) * temp );

                tot = ( tot + (rr * tt) + tot1 );

                temp *= prime[i];
            }
            tot = ( 1LL + tot) % MOD;
            ans = (ans * tot) % MOD;
        }

        printf("%lld\n", ans);
    }

    return 0;
}
