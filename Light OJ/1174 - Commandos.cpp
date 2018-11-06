
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxl 110
using namespace std;

vector<int>g[maxl];
int dp[110];
bool sign[110];
int n,m,s,d,ans;

int Bfs(int u)
{
    queue<pair<int,int> >q;
    q.push(make_pair(u,0));
    sign[u]=false;

    while(!q.empty())
    {
        int u1=q.front().first;
        int cnt=q.front().second;
        q.pop();

        dp[u1]+=cnt;
        for(int i=0; i<(int)g[u1].size(); i++)
        {
            int v1=g[u1][i];
            if(sign[v1]) q.push(make_pair(v1,cnt+1)), sign[v1]=false;
        }
    }
}

int main()
{
    int t,cas=1,u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        scanf("%d %d",&s,&d);
        memset(sign,true,sizeof sign);
        memset(dp,0,sizeof dp);
        ans=0;
        Bfs(s);
        memset(sign,true,sizeof sign);
        Bfs(d);
        for(int i=0; i<n; i++) ans=max(ans,dp[i]);

        printf("Case %d: %d\n",cas++,ans);
        for(int i=0; i<=n; i++) g[i].clear();
    }
    return 0;
}
