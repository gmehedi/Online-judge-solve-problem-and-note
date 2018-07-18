
#include <bits/stdc++.h>
#define M 110
using namespace std;
typedef pair<int,int>p;
int n,m;

vector<p>graph[M];
int dist[M],path[M];

void initialize()
{
    for(int i=0; i<=n+1; i++) dist[i]=INT_MAX, path[i]=-1;
}

bool diakstra(int source)
{
    initialize();
    priority_queue< p,vector<p>, greater<p> >pq;
    dist[1]=0;
    pq.push(make_pair(0,source) );
    while( !pq.empty() )
    {
        int u=pq.top().second;
        int w=pq.top().first;
        pq.pop();
        if(u==n) return true;
        for( int i=0; i<(int)graph[u].size(); i++)
        {
            int v=graph[u][i].first, w=graph[u][i].second;
            //cout<<"D  "<<dist[u]<<"   "<<dist[v]<<"  "<<w<<endl;
            if( dist[u]+w < dist[v] )
            {
                dist[v]=dist[u]+w;
                pq.push( make_pair(dist[v],v) );
                path[v]=u;
            }

        }
    }

    return false;
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0; i<m; i++)
        {
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
            graph[x].push_back( make_pair(y,w) );
            graph[y].push_back( make_pair(x,w) );
        }
        if( diakstra(1) )
        {
            printf("Case %d: %d\n",cas++,dist[n]);
        }
        else printf("Case %d: Impossible\n",cas++);
        for(int i=0; i<=n; i++) graph[i].clear();
    }

    return 0;
}

