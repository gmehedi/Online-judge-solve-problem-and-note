#include <bits/stdc++.h>
using namespace std;
vector<int>graph;
vector<bool>sign;
 vector<int>dp;
int solve(int u)
{
    sign[u]=false;
    int total=0;
    if(sign[ graph[u] ] && graph[u] != -1)
    {
        total =1+solve(graph[u]);
    }
    sign[u]=true;
    return dp[u]=total;
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        dp.assign(n+2,-1);
        sign.assign(n+2,true);
        graph.assign(n+2,-1);
        for(int i=0; i<n; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            graph[x]=y;
        }
        int res=0, maxi=0;
        for(int i=1; i<=n; i++)
        {
            if(dp[i]==-1)solve(i);
            if(maxi<dp[i])
            {
                maxi=dp[i];
                res=i;
            }
        }
        printf("Case %d: %d\n",cas++,res);
       // for(int i=1; i<=n; i++) graph[i].clear();
    }
    return 0;
}
