#include <bits/stdc++.h>
#define maxi 150
using namespace std;
typedef pair<int,int>p;
bool b[maxi][maxi];
vector< pair<int,p> >v;
vector<int>graph[maxi];
int group[maxi];
int cas=1;
bool sign[maxi];

int dfs(int u)
{
    sign[u]=false;
    for(int i=0; i<(int)graph[u].size(); i++)
    {
        int v=graph[u][i];
        if(sign[v]) dfs(v);
    }
}

void initialize(int n)
{
    for(int i=0; i<=n+1; i++)group[i]=i;
    memset(b,false,sizeof b);
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

bool check(int n)
{
    memset(sign,true,sizeof sign);
    dfs(1);
    for(int i=0; i<=n; i++) graph[i].clear();
    for(int i=1; i<=n; i++) if(sign[i]) return true;
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        initialize(n);
        vector< pair<int,p> >v1;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                int temp;
                scanf("%d",&temp);
                if(temp==0)continue;
                v.push_back(make_pair(temp,make_pair(i,j)));
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }

        if(check(n)) { printf("Case %d: -1\n",cas++); swap(v1,v); continue; }

        sort(v.begin(),v.end());
        long long total=0;
        for(int i=0; i<(int)v.size(); i++)
        {
            int t1=v[i].second.first, t2=v[i].second.second, t3= v[i].first;
            if(!unioon(t1,t2))total+=t3;
        }
         printf("Case %d: %lld\n",cas++,total);
         swap(v1,v);
    }

    return 0;
}
