
#include <bits/stdc++.h>
#define N 5010
using namespace std;
typedef pair<int,int>p;

vector<p>graph[N];
int dist[N][3],n,m,flag;
void initialize()
{
    for(int i=1; i<=n; i++)
    {
        dist[i][0]=dist[i][1]=INT_MAX;
    }
}

bool diakstra(int s, int d)
{
    priority_queue<p,vector<p>,greater<p> >pq;
    pq.push(make_pair(0,s));
    initialize();
    dist[1][0]=0;
    flag=0;
    while( !pq.empty() )
    {
        int u=pq.top().second;
        int wf=pq.top().first;
        pq.pop();
        for( int i=0; i<(int)graph[u].size(); i++ )
        {
            int v=graph[u][i].first;
            int w=graph[u][i].second;
            if(w+wf<dist[v][0])
            {
                dist[v][1]=dist[v][0];
                dist[v][0]=w+wf;
                pq.push(make_pair( dist[v][0],v ));
                //cout<<"F  "<<w+dist[v][0]<<"  "<<w<<"  "<<u<<endl;
                pq.push(make_pair( dist[v][0]+w,u));

            }
            else if( dist[v][0] != w+wf and w+wf<dist[v][1] )
            {
                dist[v][1]=w+wf;
                pq.push( make_pair(dist[v][1],v) );
            }
           // cout<<"V  "<<dist[v][0]<<"  "<<dist[v][1]<<"    "<<dist[u][0]<<"    "<<dist[u][1]<<endl;
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
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            graph[x].push_back( make_pair(y,z) );
            graph[y].push_back(make_pair(x,z));
        }
        diakstra(1,n);
        printf("Case %d: %d\n",cas++,dist[n][1]);
        for(int i=0; i<=n; i++) graph[i].clear();
    }

    return 0;
}
