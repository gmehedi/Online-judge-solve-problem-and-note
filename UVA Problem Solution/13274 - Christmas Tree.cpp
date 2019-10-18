
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
#define maxl 2000
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


vector<int>g[maxl + 3];
int n, k;


int Dfs1(int p, int u, int k){
    if(g[u].size() < k) return 1;

    int t = 0, ans = 1;
    vector<int>a(g[u].size() + 2);

    for(auto v : g[u]){
       if(p == v) continue;
       a[t] = Dfs1(u, v, k);
   // cout<<"T  "<<t<<"  "<<a[t-1]<<endl;
       t++;
    }

    if(t < k) return 1;
    int j = 0;
    sort(a.begin(), a.begin() + t);
    for(int i = t - 1; j < k; j++, i--){
        ans += a[i];
    }
   // cout<<"A  "<<ans<<endl;
    return ans;
}

int main(){

   // Fout;
    int t, cas = 1;

    scanf("%d",&t);

    while(t--){
        scanf("%d%d",&n,&k);

        for(int i = 1; i < n; i++){
            int u, v;
            scanf("%d%d",&u, &v);
            g[u].pb(v);
            g[v].pb(u);
        }

        printf("Case %d: %d\n", cas++,Dfs1(0, 1, k));
        for(int i = 0; i <= n; i++){
            g[i].clear();
        }

    }

    return 0;
}


/*
3
6 2
1 2
1 3
2 4
3 5
3 6

6 3
1 2
1 3
1 4
4 5
4 6

6 4
1 2
1 3
1 4
4 5
4 6
*/
