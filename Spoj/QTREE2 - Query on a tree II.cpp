
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
#define maxl 10010
#define psz 15
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

vector< pair<int,ll> >g[maxl+2];
int level[maxl+2],parent[maxl+2],lcat[maxl+2][psz+2];
bool sign[maxl+2];
ll total[maxl];
int n;

struct str
{
    int su;
    int sl;
    ll stot;
};
void BFS()
{
   queue< str >q;
   q.push({1,1,0LL});
   sign[1]=false;

   while(!q.empty())
   {
       int u=q.front().su;
       ll tot=q.front().stot;
       int lev=q.front().sl;
       level[u]=lev;
       total[u]=tot;
       q.pop();

       for(int i=0; i<g[u].size(); i++)
       {
           int v=g[u][i].f;
           ll tot1=g[u][i].s;
           if(sign[v])
           {
               sign[v]=false;
               q.push({v,lev+1,tot1+tot});
               parent[v]=u;
           }
       }
   }
}

void Gen_table()
{
    for(int p=0; p<=psz; p++)
    {
        for(int i=1; i<=n; i++)
        {
            if(p == 0)
                lcat[i][p]=parent[i];// cout<<"I "<<i<<"  "<<lcat[i][0]<<endl;
            else
            {
                if(lcat[i][p-1] != -1)
                {
                    int t1=lcat[i][p-1];
                    lcat[i][p]=lcat[t1][p-1];
                }
            }
        }
    }


}

int LCA(int x, int y)
{
    if(level[x] > level[y]) swap(x,y);

    for(int p=psz; p>=0; p--)
    {
        int temp=lcat[y][p];
        if(level[temp] == level[x])
        {
            y=temp; break;
        }
        if(level[temp] > level[x] ) y=temp;
    }
    if(x == y) return x;

    for(int i=psz; i>=0; i--)
    {
        int x1=lcat[x][i],y1=lcat[y][i];
        if(x1 != y1) x=x1,y=y1;
    }
    return parent[x];
}

int Print(int k, int start)
{
    bitset<psz>bit(k);
    for(int i=0; i<=psz; i++)
    {
        if(bit[i]) start=lcat[start][i];
    }
    return start;
}
void init()
{
    for(int i=0; i<=maxl; i++)g[i].clear();
    memset(sign,true,sizeof sign);
    memset(lcat,0,sizeof lcat);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d",&n);
        for(int i=1; i<n; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            g[u].pb(make_pair(v,w));
            g[v].pb(make_pair(u,w));
        }

        BFS();
    //    for(int i=1; i<=n; i++) cout<<total[i]<<endl;
        Gen_table();

        while(true)
        {
            int u,v,k;
            char s[120];

            scanf(" %s",s);
            if(strcmp(s,"DONE") == 0) break;

            scanf("%d%d",&u,&v);
            int lca=LCA(u,v);
            ll dist=(total[u]+total[v])-(2LL*total[lca]);

            if(strcmp(s,"DIST") == 0)
            {
                printf("%lld\n",dist);
                continue;
            }
            scanf("%d",&k);
            k--;
            int dist1=level[u]-level[lca];

            if(k<=dist1)
            {
                printf("%d\n",Print(k,u));
            }
            else
            {
                dist1=k-dist1;
                k=(level[v]-level[lca])-dist1;
                printf("%d\n",Print(k,v));
            }
        }
        printf("\n");
    }
    return 0;
}

/*
1
8
1 2 1
1 3 2
2 4 1
2 5 2
3 6 1
3 7 3
7 8 1

*/



