
#include <bits/stdc++.h>
#define maxi 1004
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
    while( scanf("%d %d",&n,&m) ==2 )
    {
        if(n==0 && m==0) break;
        for(int i=0; i<m; i++)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            v.push_back(make_pair(w,make_pair(x,y)));
        }
        sort(v.begin(),v.end());
        initialize();
        vector<int>res;
        bool sign=false;
        for(int i=0; i<(int)v.size(); i++)
        {
            int x=v[i].second.first, y=v[i].second.second, z=v[i].first;
            if( !unioon(x,y) ) sign=true, res.push_back(z);
        }
        if(sign)
        {
            for(int i=0; i<(int)res.size(); i++)
            {
                if(i==0) { printf("%d",res[i]); continue; }
                printf(" %d",res[i]);
            }
        }
        else printf("forest");
        printf("\n");

        v.clear();
        mp.clear();
    }
    return 0;
}
