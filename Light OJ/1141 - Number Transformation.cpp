
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxl 1010
using namespace std;

vector<int>factor[1010];

void Factor(int u)
{
    int temp=u;
    if(temp%2 == 0)
    {
        if(2 != u) factor[u].push_back(2);
        while(temp%2 ==0) temp/=2;
    }
    for(int i=3; i*i<=u; i+=2)
    {
        if(temp%i == 0)
        {
            if(i != u) factor[u].push_back(i);
            while(temp%i == 0) temp/=i;
        }
        if(temp<i) break;
    }
    if(temp>1 && temp != u) factor[u].push_back(temp);
}
bool sign[1010];
int u,v;
int Bfs()
{
    queue< pair<int,int> >q;
    q.push(make_pair(u,0));

    while( !q.empty() )
    {
        int tot1=q.front().first;
        int cnt=q.front().second;
        q.pop();

        if(tot1 == v) return cnt;
        for(int i=0; i<factor[tot1].size(); i++)
        {
            int tot=tot1+factor[tot1][i];
            if(tot <= v && sign[tot]) q.push(make_pair(tot,cnt+1)), sign[tot]=false;
        }
    }
    return -1;
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    for(int i=1; i<=1000; i++) Factor(i);

    while(t--)
    {
        memset(sign,true,sizeof sign);
        scanf("%d %d",&u,&v);
        printf("Case %d: %d\n",cas++,Bfs());
    }
    return 0;
}
