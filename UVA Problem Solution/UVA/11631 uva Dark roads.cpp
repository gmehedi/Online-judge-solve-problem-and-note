
#include <bits/stdc++.h>
#define maxi 200010
using namespace std;
vector< pair<int,pair<int,int> > >v;
int group[maxi],n,m,sz[maxi];
int  root(int i)
{
    while(i != group[i]) i=group[group[i]];
    return i;
}

bool unioon(int a, int b)
{
    int ra=root(a), rb=root(b);
    if(ra==rb) return false;
    if(sz[rb]>sz[ra]) group[ra]=group[rb], sz[rb]+=sz[ra];
    else group[rb]=group[ra], sz[ra]+=sz[rb];
 //   cout<<"A  "<<a<<"  "<<b<<endl;
    return true;
}

void initialize()
{
    for(int i=0; i<=n; i++) group[i]=i, sz[i]=1;
}
int main()
{
    while( scanf("%d %d",&n,&m)==2 )
    {
        if(n==0 && m==0) break;
        long long total=0;
        for(int i=0; i<m; i++)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            total+=z;
            v.push_back(make_pair(z,make_pair(x,y)));
        }
        sort(v.begin(),v.end());
        long long w=0;
        initialize();
        for(int i=0; i<(int)v.size(); i++)
        {
            int x=v[i].second.first, y=v[i].second.second, z=v[i].first;
            if(unioon(x,y)) w+=z, junc++;
        }
        printf("%lld\n",total-w);
        v.clear();
    }
    return 0;
}
