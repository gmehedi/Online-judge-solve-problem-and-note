
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxl 1
using namespace std;

int n,m,k,um,vm,ocurr[1005];
ll maxi=0;
vector< int >g[1005];
bool sign[1005], signk=false;
int Dfs(int u)
{
    sign[u]=false;
    ocurr[u]++;

    if(ocurr[u] == k) maxi++;
    for(int i=0; i< (int)g[u].size(); i++)
    {
        int v = g[u][i];
        if(sign[v]) Dfs(v);
    }
  //  sign[u]=true;
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);

    while(t--)
    {
        maxi=0;
        memset(ocurr,0,sizeof ocurr);
        scanf("%d %d %d",&k,&n,&m);

        int person[k+2];
        for(int i=0; i<k; i++) scanf("%d",&person[i]);

        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&um,&vm);
            g[um].push_back( vm );
        }
        for(int i=0; i<k; i++)
        {
            memset(sign,true,sizeof sign);
            Dfs(person[i]);
        }

        printf("Case %d: %lld\n",cas++,maxi);
        for(int i=0; i<=n; i++) g[i].clear();
    }
    return 0;
}
