
/////// SOLVE 1
#include <bits/stdc++.h>
#define maxi 10010
using namespace std;
typedef pair<int,int>p;
vector< pair<int,p> >v;
vector<pair<int,int> >graph[maxi];
int group[maxi];
bool sign[maxi];
int cas=1,n,m,cost,air;

void initialize()
{
    for(int i=0; i<=n+1; i++)group[i]=i;
}

int root(int i)
{
    while(i != group[i]) group[i]=group[group[i]], i=group[i];
    return i;
}
bool unioon(int a, int b)
{
    int ra=root(a);
    int rb=root(b);
    if(ra==rb) return false;
    group[ra]=group[rb];
    return true;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&cost);
        for(int i=0; i<m; i++)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            v.push_back(make_pair(w,make_pair(x,y)));
        }
        initialize();
        sort(v.begin(),v.end());
        long long total=0;
        air=0;
        for(int i=0; i<(int)v.size(); i++)
        {
            int x=v[i].second.first, y= v[i].second.second, z=v[i].first;
            if(z>=cost) break;
            if(unioon(x,y) )
            {
                total+=z;
            }
        }
        int len=0;
        for(int i=1; i<=n; i++)
        {
            if(group[i]==i) len++;
        }
        printf("Case %d: %lld %d\n",cas++,total+(len*cost),len);
        vector< pair<int,p> >v1;
        vector<pair<int,int> >g[maxi];
        swap(v,v1);
        swap(g,graph);
    }
    return 0;
}

/*
SOLVE2

#include <bits/stdc++.h>
#define maxi 10010
using namespace std;
typedef pair<int,int>p;
vector< pair<int,p> >v;
vector<pair<int,int> >graph[maxi];
int group[maxi];
bool sign[maxi];
int cas=1,n,m,cost,air;
long long tot=0,total;
long long dfs1(int u)
{
    sign[u]=false;

    for(int i=0; i<(int)graph[u].size(); i++)
    {
        int v=graph[u][i].first;
        int w=graph[u][i].second;
        if(sign[v])  tot+=w,dfs1(v);
    }
}

int dfs()
{
    memset(sign,true,sizeof sign);
    air=0;
    total=0;
    for(int i=1; i<=n; i++)
    {
        tot=0;
        if(sign[i]) { air++; dfs1(i); total+=tot+cost; }
    }
    return air;
}
void initialize()
{
    for(int i=0; i<=n+1; i++)group[i]=i;
}

int root(int i)
{
    while(i != group[i]) group[i]=group[group[i]], i=group[i];
    return i;
}
bool unioon(int a, int b)
{
    int ra=root(a);
    int rb=root(b);
    if(ra==rb) return false;
    group[ra]=group[rb];
    return true;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&cost);
        for(int i=0; i<m; i++)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            v.push_back(make_pair(w,make_pair(x,y)));
        }
        initialize();
        sort(v.begin(),v.end());
        for(int i=0; i<(int)v.size(); i++)
        {
            int x=v[i].second.first, y= v[i].second.second, z=v[i].first;
         //   cout<<"W  "<<unioon(x,y)<<"    "<<cost<<"   "<<z<<endl;
            if(unioon(x,y) && cost>z)
            {
              //  cout<<"X "<<x<<" "<<y<<"   "<<z<<endl;
                graph[x].push_back(make_pair(y,z));
                graph[y].push_back(make_pair(x,z));
            }
        }
        int l=dfs();
        printf("Case %d: %lld %d\n",cas++,total,l);
        vector< pair<int,p> >v1;
        vector<pair<int,int> >g[maxi];
        swap(v,v1);
        swap(g,graph);
    }
    return 0;
}
*/
