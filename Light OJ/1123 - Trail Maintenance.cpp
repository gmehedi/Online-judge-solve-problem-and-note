
#include <bits/stdc++.h>
#define maxi 60010
using namespace std;
typedef pair<int,int>p;
vector< pair<int,p> >v;
vector<pair<int,int> >graph[maxi];
int group[maxi],sz[maxi];
int cas=1,n,m;

void initialize()
{
    for(int i=0; i<=n+1; i++)group[i]=i,sz[i]=1;
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

bool check()
{
    int t=root(1);
    for(int i=2; i<=n; i++)
    {
        if(root(i) != t) return false;
    }
    return true;
}

void remain()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<graph[i].size(); j++)
        {
            int v1=graph[i][j].first, w=graph[i][j].second;
            v.push_back(make_pair(w,make_pair(i,v1)));
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        long long total=0;
        printf("Case %d:\n",cas++);
        for(int i=0; i<m; i++)
        {
            int x,y,w;
            //cout<<"FF                        "<<v.size()<<endl;
            scanf("%d%d%d",&x,&y,&w);

            v.push_back(make_pair(w,make_pair(x,y)));
            sort(v.begin(),v.end());
            initialize();
            total=0;
            for(int i=1; i<=n; i++)graph[i].clear();
            for(int i=0; i<(int)v.size(); i++)
            {
                int x=v[i].second.first, y= v[i].second.second, z=v[i].first;
                if(unioon(x,y))
                {
                    graph[x].push_back(make_pair(y,z));
                    graph[y].push_back(make_pair(x,z));
                    total+=z;
                }
            }
            if(check())
            {
                printf("%lld\n",total);
                v.clear();
                remain();
            }
            else printf("-1\n");
        }

        vector< pair<int,p> >v1;
        vector<pair<int,int> >g[maxi];
        swap(v,v1);
        swap(g,graph);
    }
    return 0;
}
