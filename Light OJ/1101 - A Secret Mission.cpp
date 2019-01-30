
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
#define maxl 50010
#define psz 16
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

vector< pair<int,int> >g[maxl+2];
int level[maxl+2],parent[maxl+2],lcat[maxl+2][psz+2],ans[maxl+2][psz+2];
bool sign[maxl+2];
int n,m;
//.............MST...............
int group[maxl+2],sz[maxl+2];
struct str1
{
    int a;
    int b;
    int c;
};
vector<str1>v;
bool compare(str1 x, str1 y)
{
    return x.c<y.c;
}
//.........MST......................
int find_root(int i)
{
    while( i != group[i] )
    {
        group[i]=group[group[i]];
        i=group[i];
    }
    return i;
}

int transfer_and_size(int ra, int rb, int a, int b)
{
    if(sz[ra]>=sz[rb])
    {
        sz[ra]+=sz[rb];
        group[ra]=group[rb];
    }
    else
    {
        sz[rb]+=sz[ra];
        group[rb]=group[ra];
    }
}

void initialize() { for(int i=1; i<=n; i++) sz[i]=1,group[i]=i; }

void MST()
{
    initialize();
    sort(v.begin(),v.end(),compare);
    for(int i=0; i<(int)v.size(); i++)
    {
        int x=v[i].a, y=v[i].b, w=v[i].c;
        int ra= find_root(x);
        int rb=find_root(y);
        if(ra==rb) continue;
        else
        {
            g[x].push_back(make_pair(y,w));
            g[y].push_back(make_pair(x,w));
            transfer_and_size(ra,rb,x,y);
        }
    }
}
//....................LCA...............
struct str
{
    int su;
    int sl;
};
void BFS()
{
    queue< str >q;
    q.push({1,1});
    sign[1]=false;

    while(!q.empty())
    {
        int u=q.front().su;
        int lev=q.front().sl;
        level[u]=lev;
        q.pop();

        for(int i=0; i<g[u].size(); i++)
        {
            int v=g[u][i].f;
            int tot1=g[u][i].s;
            if(sign[v])
            {
                sign[v]=false;
                q.push({v,lev+1});
                parent[v]=u;
                ans[v][0]=tot1;
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


    for(int p=1; p<=psz; p++)
    {
        for(int i=1; i<=n; i++)
        {
            if(lcat[i][p-1] != -1)
            {
                int t1=lcat[i][p-1];
                ans[i][p]=max(ans[i][p-1],ans[t1][p-1]);
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

int Max(int u, int len)
{
    bitset<psz>bit(len);
    int res=0;
    for(int i=0; i<=psz; i++)
    {
        if(bit[i]) res=max(res,ans[u][i]),u=lcat[u][i];
    }
    return res;
}
void init()
{
    for(int i=0; i<=maxl; i++) g[i].clear(),ans[i][0]=0;
    memset(sign,true,sizeof sign);
    memset(lcat,0,sizeof lcat);
    vector<str1>v1;
    swap(v1,v);
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; i++)
        {
            int u1,v1,w1;
            scanf("%d%d%d",&u1,&v1,&w1);
            v.push_back({u1,v1,w1});
            v.push_back({v1,u1,w1});
        }

        MST();
        BFS();
        Gen_table();

        int q;
        scanf("%d",&q);
        printf("Case %d:\n",cas++);
        while(q--)
        {
            int u1,v1;
            scanf("%d %d",&u1,&v1);
            int lca=LCA(u1,v1);
            int dist1=level[u1]-level[lca];
            int dist2=level[v1]-level[lca];
            printf("%d\n",max(Max(u1,dist1),Max(v1,dist2)));
        }

    }
    return 0;
}
