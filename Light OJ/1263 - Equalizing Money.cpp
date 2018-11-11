
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
#define maxl 1010

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

vector<int>g[maxl];
int dp[maxl];
bool sign[maxl];
int cnt=0;

ll Bfs(int u)
{
    ll tot=0;
    queue<int>q;
    q.push(u);
    sign[u]=false;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        tot= tot+dp[u];
      //  cout<<"D  "<<tot<<" "<<dp[u]<<"  "<<u<<endl;
        cnt++;

        for(int i=0; i<(int)g[u].size(); i++)
        {
            int v=g[u][i];
            if(sign[v]) q.push(v), sign[v]=false;
        }
    }
//cout<<"TT  "<<tot<<endl;
    return tot;
}
int main()
{
    int t,cas=1;
//  freopen("in.txt","r",stdin);
//  freopen("out.txt","w",stdin);
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=1; i<=n; i++) scanf("%d",&dp[i] );

        for(int i=1; i<=m; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        memset(sign,true,sizeof sign);
        unordered_set<int>sett;
        bool yes=true;
        for(int i=1; i<=n; i++)
        {
            cnt=0;
            if(sign[i])
            {
                ll tot = Bfs(i);
             //   cout<<"T  "<<tot<<"  "<<cnt<<endl;
                if(tot%cnt == 0) sett.insert( (tot/cnt) );
                else { yes=false; break; }
            }
        }
        if((int)sett.size() > 1) yes=false;
        if(yes) printf("Case %d: Yes\n",cas++);
        else printf("Case %d: No\n",cas++);

        for(int i=0; i<=n; i++) g[i].clear();
    }
    return 0;
}
