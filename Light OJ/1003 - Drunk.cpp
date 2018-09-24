
// M M Mehedi Hasan
// From BUBT
#include<bits/stdc++.h>
#define p1 31
#define maxl 3100
#define maxp 3100
#define ull unsigned long long
using namespace std;
vector<int>g[10010];
vector<int>v;
int ind[10100],state;

bool top()
{
    queue<int>q;
    for(int i=0; i<(int)v.size(); i++)
    {
        int t1=v[i];
        if(ind[t1]==0) q.push(t1);
    }
    int cnt=0;
    while( !q.empty() )
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<(int)g[u].size(); i++)
        {
            int v1=g[u][i];
            if(--ind[v1]==0) q.push(v1);
        }
        cnt++;
    }
    if( cnt != state) return false;

    return true;
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);

    while(t--)
    {
        string s1,s2;
        state=0;
        map<string, int>mp;
        int n;
        cin>>n;
        cin.ignore();
        memset(ind,0,sizeof ind);
        for(int i=0; i<n; i++)
        {
            cin>>s1>>s2;
            if(mp[s1]==0) mp[s1]= ++state, v.push_back(state);
            if(mp[s2]==0) mp[s2]= ++state, v.push_back(state);
            g[mp[s1]].push_back(mp[s2]);
            ind[mp[s2]]++;
        }
        if(!top()) printf("Case %d: No\n",cas++);
        else printf("Case %d: Yes\n",cas++);
        for(int i=0; i<=n; i++) g[i].clear();
        v.clear();
    }
    return 0;
}
