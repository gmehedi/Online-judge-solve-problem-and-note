
#include <bits/stdc++.h>
using namespace std;
int cnt=0,group[100],sz[100],cas=1;
long long total=0;
struct str
{
    int a;
    int b;
    int c;
};
vector<str>v;
map<string,int>mp;

bool compare(str x, str y)
{
    return x.c<y.c;
}
void creat(string x, string y, int w)
{
    int t1=0,t2=0;
    if(mp[x]==0)cnt++,mp[x]=cnt;
    if(mp[y]==0)cnt++, mp[y]=cnt;
    v.push_back( {mp[x],mp[y],w} );

}

int find_root(int i)
{
    while( i != group[i] )
    {
        group[i]=group[group[i]];
        i=group[i];
    }
    return i;
}

int transfer_and_size(int ra, int rb, int a, int b)
{
    if(sz[ra]>=sz[rb])
    {
        sz[ra]+=sz[rb];
        group[ra]=group[rb];
    }
    else
    {
        sz[rb]+=sz[ra];
        group[rb]=group[ra];
    }
}

void initialize() { for(int i=1; i<=cnt; i++) sz[i]=1,group[i]=i; }

bool check()
{
    int temp=find_root(1);
    for(int i=2; i<=cnt; i++)
    {
        if(find_root(i) != temp) return false;
    }
    return true;
}

void mimnimum_spanning_tree()
{
    initialize();
    for(int i=0; i<(int)v.size(); i++)
    {
        int x=v[i].a, y=v[i].b, w=v[i].c;
        int ra= find_root(x);
        int rb=find_root(y);
        if(ra==rb) continue;
        else total+=w, transfer_and_size(ra,rb,x,y);
    }
    if( check() )
    {
        printf("Case %d: %lld\n",cas++,total);
    }
    else printf("Case %d: Impossible\n",cas++);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m;
        scanf("%d",&m);
        getchar();
        cnt=0,total=0;
        for(int i=0; i<m; i++)
        {
            string s1,s2;
            int w;
            cin>>s1>>s2>>w;
            creat(s1,s2,w);
        }
        sort(v.begin(),v.end(),compare);
        mimnimum_spanning_tree();
        //clear memory.
        vector<str>v1;
        map<string,int>mp1;
        swap(v1,v);
        swap(mp1,mp);
    }
    return 0;
}
