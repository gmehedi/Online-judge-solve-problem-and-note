#include<bits/stdc++.h>
#define maxi 100
using namespace std;
vector<int>graph[maxi];
vector<int>revgraph[maxi];
vector<int>topsort;
bitset<maxi+10>sign;
int res[maxi];

struct str
{
  int node,value;
};
str v[maxi];
bool compare(str t1, str t2)
{
    return t1.value<t2.value;
}

int Dfs1(int u)
{
    sign[u]=true;
    for(int i=0; i<(int)graph[u].size(); i++)
    {
        int v=graph[u][i];
        if( !sign[v] ) Dfs1(v);
    }
    topsort.push_back(u);

}

int Dfs2(int u, int cnt)
{
    sign[u]=true;
    res[u]=cnt;
    for(int i=0; i<(int)revgraph[u].size(); i++)
    {
        int v=revgraph[u][i];
        if( !sign[v] ) Dfs2(v,cnt);
    }

}

int main()
{
    int n,m,cas=1;
    while( scanf("%d%d",&n,&m)==2 )
    {
        map<string,int>si;
        map<int,string>is;
        int num=1;
        if(n==0 && m==0) break;
        for(int i=1; i<=m; i++)
        {
            char s1[200],s2[200];
            int x,y;
            scanf("%s %s",s1,s2);
            if(si[s1]==0) si[s1]=num, is[num]=s1, num++;
            if(si[s2]==0) si[s2]=num, is[num]=s2, num++;
            x=si[s1], y=si[s2];
            graph[x].push_back(y);
            revgraph[y].push_back(x);
        }

        for(int i=1; i<=n; i++) if( !sign[i] )Dfs1(i);

        reverse(topsort.begin(),topsort.end());
        sign.reset();
        int cnt=1;

        for(int i=0; i<(int)topsort.size(); i++)
        {
            if( !sign[topsort[i]] ) Dfs2(topsort[i],cnt),cnt++;
        }

        for(int i=1; i<=n; i++)
        {
           // cout<<i<<"  ::  "<<res[i]<<"       IS   "<<is[i]<<endl;
           v[i-1].node=i, v[i-1].value=res[i];
        }

        sort(v,v+n,compare);
    //    for(int i=1; i<=n; i++)  cout<<i<<"  ::  "<<res[i]<<"       IS   "<<is[i]<<endl;

        printf("Calling circles for data set %d:\n",cas++);
        for(int i=0; i<n; i++)
        {
            if(i==0)cout<<is[v[i].node];
            else if(v[i].value==v[i-1].value)cout<<", "<<is[v[i].node];
            else cout<<endl<<is[v[i].node];
        }
        cout<<endl;
        for(int i=0; i<=n; i++)graph[i].clear(), revgraph[i].clear();
        memset(res,0,sizeof res);
        topsort.clear();
        is.clear();
        si.clear();
        sign.reset();
        str t[maxi];
        swap(t,v);

    }
    return 0;
}
