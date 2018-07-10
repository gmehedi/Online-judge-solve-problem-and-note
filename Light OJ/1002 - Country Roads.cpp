#include <bits/stdc++.h>
using namespace std;
vector<int>graph[510];
int cost[510][510];
int group[510];
int cas=1;
int res[510];
struct str
{
    int x;
    int y;
    int z;
};
vector<str>v;
bool compare(str a, str b)
{
    return a.z<b.z;
}
bool sign[510];
int flag=0;

int bfs(int u)
{
    queue<int>q;
    q.push(u);
    sign[u]=false;
    res[u]=0;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        for(int i=0; i<(int)graph[f].size(); i++)
        {
            int v=graph[f][i];
            int c=cost[f][v];
           // cout<<"F  "<<f<<"   "<<v<<  "   "<<cost[f][v]<<endl;
            if(sign[v])
            {
                sign[v]=false;
                q.push(v);
              //  cout<<"W                                   "<<res[v]<<"   "<<cost[u][v]<<endl;
                res[v]=max(res[f],cost[f][v]);
            }
        }
    }
}

int find_root(int n)
{
    while( n != group[n]) group[n]=group[group[n]], n=group[n];
}

void initialize(int n)
{
    for(int i=0; i<n; i++)group[i]=i;
}

void minimum_spannig_tree(int ra, int rb)
{
    group[ra]=group[rb];
}

void graph_build(int x, int y, int w)
{
  //  cout<<"GGG     "<<x<<"    "<<y<<endl;
    graph[x].push_back(y);
    graph[y].push_back(x);
    cost[x][y]=w;
    cost[y][x]=w;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0; i<m; i++)
        {
            int t1,t2,w;
            scanf("%d%d%d",&t1,&t2,&w);
            v.push_back({t1,t2,w});
          //  cout<<"H "<<i<<"    "<<m<<endl;
        }
        int destination;
        scanf("%d",&destination);
        sort(v.begin(),v.end(),compare);
        initialize(n);
        for(int i=0; i<(int)v.size(); i++)
        {
            int t1=0,t2=0,w=0;
            t1=v[i].x, t2=v[i].y, w=v[i].z;
            int ra=find_root(t1);
            int rb=find_root(t2);
            if(ra==rb) continue;
            else { minimum_spannig_tree(ra,rb); graph_build(t1,t2,w); }
        }
        printf("Case %d:\n",cas++);

        for(int i=0; i<=n; i++)res[i]=-1;
        memset(sign,true,sizeof sign);

        bfs(destination);

       for(int i=0; i<n; i++)
       {
           if(res[i]==-1) printf("Impossible\n");
           else printf("%d\n",res[i]);
       }

       v.clear();
        for(int i=0; i<n; i++) graph[i].clear();
        memset(cost,-1,sizeof cost);
    }
    return 0;
}
