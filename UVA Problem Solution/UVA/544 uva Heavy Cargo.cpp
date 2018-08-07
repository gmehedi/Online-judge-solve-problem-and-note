
#include<bits/stdc++.h>
#define N 20000
using namespace std;
int n,m;
int sz[220];
int root[220];
vector< pair<int, pair<int,int> > >v;
int mini=123456789;

void initialize()
{
    mini=123456789;
    for(int i=0; i<=210; i++) root[i]=i, sz[i]=1;
    v.clear();
}

int find_root(int i)
{
    while(i != root[i] ) i=root[root[i]];
    return i;
}

bool unioon(int x, int y)
{
    int rx= find_root(x);
    int ry= find_root(y);
    if(rx != ry)
    {
        if(sz[rx]>sz[ry]) sz[rx]+=sz[ry], root[ry]=root[rx];
        else sz[ry]+=sz[rx], root[rx]=root[ry];
        return true;
    }
    return false;
}

int kruskal(int source, int dest)
{
    for(int i=0; i<(int)v.size(); i++)
    {
        int w=v[i].first, u=v[i].second.first, v1=v[i].second.second;
        if( unioon(u,v1) )
        {
            mini=min(mini,w);
            if( find_root(source)==find_root(dest) ) return mini;
        }
    }
}

int main()
{
   int cas=1;
   while(scanf("%d %d",&n,&m))
   {
       getchar();
       if(n==0 && m==0) break;
       initialize();
       int cnt=1;
       map<string,int>mp;
       for(int i=0; i<m; i++)
       {
           string s1,s2;
           int w;
           cin>>s1>>s2>>w;
           if(mp[s1]==0) mp[s1]=cnt, cnt++;
           if(mp[s2]==0) mp[s2]=cnt, cnt++;
           int t=mp[s1], t1=mp[s2];

           v.push_back( make_pair( w,make_pair(t,t1) ) );
           v.push_back( make_pair( w,make_pair(t1,t) ) );
        //   cout<<"U  "<<u1<<"  "<<v1<<endl;
       }
       getchar();
       string ss,ds;
       sort(v.rbegin(),v.rend());
       cin>>ss>>ds;
       int source=mp[ss], des=mp[ds];
       printf("Scenario #%d\n%d tons\n",cas++,kruskal(source,des));
       printf("\n");
   }
   return 0;
}
