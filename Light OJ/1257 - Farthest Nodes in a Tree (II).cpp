
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define pii              pair <int,int>
#define pll              pair <long long,long long>
#define sc               scanf
#define pf               printf
#define Pi               2*acos(0.0)
#define ms(a,b)         memset(a, b, sizeof(a))
#define pb(a)            push_back(a)
#define MP               make_pair
#define db               double
#define ll               long long
#define ull               unsigned long long
#define f               first
#define s              second
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
#define maxl 30010

using namespace std;


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
//freopen("out.txt","w",stdin);
/*------------------------------------------------*/
using namespace std;

vector<pii>g[maxl];
ll dp[maxl],maxi=0,dp1[maxl];
bool sign[maxl];
int node=0;

void Dfs(int u)
{
    sign[u]=false;
    if(maxi<dp[u]) maxi=dp[u], node=u;

    for(int i=0; i<(int)g[u].size(); i++)
    {
        int v=g[u][i].f;
        int cost1=g[u][i].s;
     //   cout<<"U  "<<u<<"  "<<v<<endl;
        if(sign[v])
        {
            sign[v]=false;//cout<<"D "<<dp[u]<<"  "<<dp[v]<<endl;
            if(dp[v]<(dp[u]+cost1)) dp[v]=cost1+dp[u];
            Dfs(v);
        }
    }
}
int main()
{
    int t,cas=1;

//    freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdin);
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<n; i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back(mk(v,w));
            g[v].push_back(mk(u,w));
        }
        maxi=0;
        memset(sign,true,sizeof sign);
        memset(dp,0,sizeof dp);
        Dfs(0);
        int node1=node;
       // cout<<"N  "<<node1<<endl;
        maxi=0;
        memset(dp,0,sizeof dp);
        memset(sign,true,sizeof sign);
        Dfs(node1);
        for(int i=0; i<n; i++) dp1[i]=dp[i];

        memset(sign,true,sizeof sign);
        memset(dp,0,sizeof dp);
        int node2=node;
     //   cout<<"N2  "<<node2<<endl;
        Dfs(node2);
      //  for(int i=0; i<n; i++) cout<<dp[i]<<"  "<<dp1[i]<<endl;
     //   cout<<endl;
        printf("Case %d:\n",cas++);
        for(int i=0; i<n; i++) printf("%lld\n",max(dp[i],dp1[i]));

        for(int i=0; i<=n; i++) g[i].clear();
    }
    return 0;
}

/*

12
7
0 1 100
1 2 2
2 3 3
3 6 100
3 5 9
2 4 8
*/
