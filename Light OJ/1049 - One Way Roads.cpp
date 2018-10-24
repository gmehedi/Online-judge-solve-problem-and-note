
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;
int have[110][110];
vector< pair<int,int> >g[110];
bool sign[110];

long long ans1=0,ans2=0;
int last=0;

void Dfs(int u)
{
    sign[u]=false;
    last=u;

    for(int i=0; i<(int)g[u].size(); i++)
    {
        int v=g[u][i].first;
        int c=g[u][i].second;
        if(sign[v])
        {
            if(have[u][v] == 0) ans1+=c;
            else ans2+=c;
            sign[v]=false;
            Dfs(v);
        }
    }
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        memset(have,0,sizeof have);
        memset(sign,true, sizeof sign);
        ans1=ans2=last=0;

        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            int x,y,c;
            scanf("%d %d %d",&x,&y,&c);
            have[y][x]=c;
            g[x].push_back(make_pair(y,c));
            g[y].push_back(make_pair(x,c));
        }

        Dfs(1);
        if(have[last][1] == 0) ans1+= have[1][last];
        else ans2+= have[last][1];

        printf("Case %d: %lld\n",cas++,min(ans1,ans2));

        for(int i=1; i<=n; i++) g[i].clear();
    }
    return 0;
}
