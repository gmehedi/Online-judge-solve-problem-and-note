
#include <bits/stdc++.h>
using namespace std;
vector<int>v[110];
void Creat(int x, int y)
{
    v[x].push_back(y);
}
int n,m;
void Topological_sort()
{
    int indigree[110]={0};
    for(int i=1; i<=n; i++)
    {
        for(auto j=v[i].begin(); j != v[i].end(); j++)
        {
            indigree[*j]++;
        }
    }
    queue<int>q;
    vector<int>res;
    for(int i=1; i<=n; i++) if(indigree[i]==0)q.push(i);
    int cnt=0;
    while( !q.empty() )
    {
        int f=q.front();
      //  cout<<"F  "<<f<<endl;
        res.push_back(f);
        q.pop();
        for(auto k=v[f].begin(); k != v[f].end(); k++)
        {
            if(--indigree[*k]==0)q.push(*k);
        }
        cnt++;
    }
    if(cnt!=n){ cout<<"Sycle"<<endl; }
    for(int i=0; i<(int)res.size(); i++) if(i==0)cout<<res[i]; else cout<<" "<<res[i];
    cout<<endl;
}
int main()
{
    while( cin>>n>>m )
    {
        if(m==0 && m == n)break;
        for(int i=0; i<m; i++)
        {
            int x,y;
            cin>>x>>y;
            Creat(x,y);
        }
        Topological_sort();
        for(int i=0; i<=n; i++)v[i].clear();
    }
    return 0;
}

