
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxl 10000000
using namespace std;

int n,um,vm,wm,node=0;
ll maxi=0;
vector< pair<int,int> >g[30010];
bool sign[30005];

int Dfs(int u, ll cost)
{
    sign[u]=false;
    if(maxi <cost) maxi = cost, node = u;
    for(int i=0; i< (int)g[u].size(); i++)
    {
        int v = g[u][i].first, w = g[u][i].second;
        if(sign[v]) Dfs(v,cost+w);
    }
    sign[u]=true;
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        maxi=0, memset(sign,true,sizeof sign);
        for(int i=0; i<n-1; i++)
        {
            scanf("%d %d %d",&um,&vm,&wm);
            g[um].push_back( make_pair(vm,wm) );
            g[vm].push_back( make_pair(um,wm) );
        }

        Dfs(0,0);
        Dfs(node,0);

        printf("Case %d: %lld\n",cas++,maxi);
        for(int i=0; i<=n; i++) g[i].clear();
    }
    return 0;
}
