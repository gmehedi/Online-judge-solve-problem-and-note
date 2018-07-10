#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int>p;
vector< p >graph[510];
bool sign[510];
int res[510],group[510],cas=1;

int bfs(int u)
{
    sign[u]=false;
    res[u]=0;
    queue<int>q;
    q.push(u);

    while( ! q.empty() )
    {
        int f=q.front();
        q.pop();
        for(int i=0; i<(int)graph[f].size(); i++)
        {
            int v=graph[f][i].first;
            int ww=graph[f][i].second;

            if(sign[v])
            {
                res[v]=max(res[f],ww);
                q.push(v);
                sign[v]=false;
            }

        }
    }
}

void  print(int n)
{
    printf("Case %d:\n",cas++);
    for(int i=0; i<n; i++)
    {
        if( res[i]==INT_MAX ) printf("Impossible\n");
        else printf("%d\n",res[i]);
    }
}
void initialize()
{
    memset(sign,true,sizeof sign);
    for(int i=0; i<501; i++) group[i]=i,res[i]=INT_MAX;
}

int root(int i)
{
    while(i != group[i] )group[i]=group[group[i]], i=group[i];
    return i;
}

bool unioon(int a, int b)
{
    int ra=root(a);
    int rb=root(b);
   // cout<<"RRR               "<<a<<"  "<<b<<"  "<<ra<<"  "<<rb<<endl;
    if(ra==rb) return false;
    group[ra]=group[rb];
  //  cout<<group[ra]<<"  "<<group[rb]<<endl;
    return true;
}

void build(int x,int y, int w)
{
    graph[x].push_back( make_pair(y,w) );
    graph[y].push_back( make_pair(x,w) );
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        vector< pair<int,p > >v;
        scanf("%d%d",&n,&m);
        initialize();
        for(int i=0; i<m; i++)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            v.push_back( make_pair( w,make_pair(x,y) ) );
        }
        sort(v.begin(),v.end());
        for(int i=0; i<(int)v.size(); i++)
        {
            int t1,t2,t3;
            t1=v[i].second.first, t2=v[i].second.second, t3=v[i].first;
          //  cout<<"T  "<<t1<<" "<<t2<<endl;
            bool check=unioon(t1,t2);
            if( check ) build(t1,t2,t3);
        }
        int t;
        scanf("%d",&t);
        //for(int i=0; i<n; i++)cout<<"R  "<<res[i]<<endl;
        bfs(t);
        print(n);
       // for(int i=0; i<m; i++)   cout<<v[i].first<<"  "<<v[i].second.first<<"  "<<v[i].second.second<<endl;
       for(int i=0; i<n; i++)graph[i].clear();
    }
    return 0;
}
