#include <bits/stdc++.h>
#define maxi 450
using namespace std;
vector< pair<int,pair<int,int> > >v;
map<string,int>mp;
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

bool check(string s)
{
    int t=mp[s];
    int r=root(t);
    for(int i=0; i<n; i++) if(r != root(i)) return false;

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
        int cnt=0;
        if(n==0 && m==0) break;
        getchar();
        string s;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            if(mp[s]==0)mp[s]=cnt, cnt++;
        }
        string s1,s2;
        int w;
        for(int i=0; i<m; i++)
        {
            cin>>s1>>s2>>w;
            int x=mp[s1], y=mp[s2];
            v.push_back( make_pair(w,make_pair(x,y)) );
        }
        string des;
        cin>>des;

        sort(v.begin(),v.end());

        long long total=0;
        initialize();
        for(int i=0; i<(int)v.size(); i++)
        {
            int x=v[i].second.first, y=v[i].second.second, z=v[i].first;
            if(unioon(x,y)) total+=z;
        }
        if(check(des))
        {
            printf("%lld\n",total);
        }
        else printf("Impossible\n");
        v.clear();
        mp.clear();
    }
    return 0;
}

