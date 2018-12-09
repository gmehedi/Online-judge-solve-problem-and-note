
#include <bits/stdc++.h>
#define pii              pair <int,int>
#define pll              pair <long long,long long>
#define sc               scanf
#define pf               printf
#define Pi               2*acos(0.0)
#define ms(a,b)         memset(a, b, sizeof(a))
#define pb(a)            push_back(a)
#define MP               make_pair
#define db               double
#define ll               long long
#define ull               unsigned long long
#define f               first
#define s              second
#define sqr(x)           (x)*(x)
#define VI               vector <int>
#define DBG              pf("Hi\n")
#define MOD              1000000007
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define loop(i,n)        for(int i=0;i<n;i++)
#define loop1(i,n)       for(int i=1;i<=n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define intlim           2147483648
#define ull              unsigned long long
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))
#define mk(x1,y1) make_pair(x1, y1)
#define maxl 1000010

using namespace std;


/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdin);
/*------------------------------------------------*/
using namespace std;
bool sign[50010];
vector<int>g[50010];
int path[50010];
vector<int> res;

void Take_path(int u, int v)
{ //cout<<"T  "<<v<<"  "<<u<<endl;
    if(v == u) return;
    Take_path(u,path[v]);
    //cout<<"V  "<<v<<endl;
    res.push_back(v);
}
void Bfs(int u, int v)
{
    queue<int>q;
    q.push(u);
    sign[u]=false;

    while(!q.empty())
    {
        int  u1=q.front();
        q.pop();
        sort(g[u1].begin(),g[u1].end());

        for(int i=0; i<(int)g[u1].size(); i++)
        {
            int v1=g[u1][i];
            if(sign[v1])
            {
                sign[v1]=false;
                q.push(v1);
                path[v1]=u1;
                if(v1 == v) { res.push_back(u); Take_path(u,v); return; }
            }
        }
    }
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n+2];
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            if(i>0) g[a[i-1]].push_back(a[i]), g[a[i]].push_back(a[i-1]);
        }
        int source=a[0];
        int des=a[n-1];
        memset(sign,true,sizeof sign);
        memset(path,0,sizeof path);

        Bfs(source,des);

        printf("Case %d:\n",cas++);
        for(int i=0; i<(int)res.size(); i++)
        {
            if(i == 0) printf("%d",res[i]);
            else printf(" %d",res[i]);
        }
        printf("\n");
        vector<int>g1[50010];
        swap(g1,g);
        res.clear();
    }
    return 0;
}
/*

2
6
1 2 3 4 1 3
5
4 2 6 3 1

*/
