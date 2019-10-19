 
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
#define maxl 10000
#define psz 20
#define Fin      freopen("input.txt","r",stdin)
#define Fout     freopen("output.txt","w",stdout)
 
 
/*----------------------Graph Moves----------------*/
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
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
 
bool sign[1000000 + 2];
vector<ll>prime;
vector<int>p[1000000 + 3];
vector<int>g[1000000 + 3];

void Prime()
{
    memset(sign, true, sizeof sign);
    prime.pb(2);
    for(ll i = 3; i * i <= maxl; i += 2){
        if(sign[i]){
            for(ll j = i * i; j <= maxl; j += (i * 2LL)) sign[j] = false;
        }
    }
    for(ll i = 3; i <= maxl; i += 2LL){
        if(sign[i]) prime.pb(i);
    }
}

void Fac(int n, int pos){

    for(int i = 0; i < prime.size() && prime[i] * prime[i] <= n; i++){

        if(n % prime[i] == 0){

            p[prime[i]].pb(pos);

            while(n % prime[i] == 0) n /= prime[i];
        }
    }

    if(n > 1) p[n].pb(pos);
}

void Dfs(int u){

    sign[u] = false;

    for(auto v : g[u]){

        if(sign[v]) Dfs(v);
    }
}

int main(){

   // Fout;

    Prime();
    
    int t, n, cas = 1;
    scanf("%d",&t);


    while(t--){

        scanf("%d",&n);

        for(int i = 0; i < n; i++){
            int temp;
            scanf("%d", &temp);
            Fac(temp, i);
        }

        for(int i = 0; i  <  1000000; i++){

            for(int j = 0; j < int(p[i].size()) - 1; j ++){

                g[ p[i][j] ].pb(p[i][j + 1]);
                g[ p[i][j + 1] ].pb(p[i][j]);

            }
        }

        int ans = 0;
        memset(sign, true, sizeof sign);

        for(int i = 0; i < n; i++){

            if(sign[i]){
                Dfs(i);
                ans++;

              //  cout<<"W.  "<<i<<".  "<<ans<<endl;
            }
        }

        printf("Case %d: %d\n", cas++, ans);
        for(int i = 0; i <= 1000000; i++) g[i].clear(), p[i].clear();

    }

    
    return 0;
}
