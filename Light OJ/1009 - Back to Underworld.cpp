
//M M Mehedi Hasan
//From BUBT
#include <bits/stdc++.h>

#define pii              pair <int,int>
#define pll              pair <long long,long long>
#define sc               scanf
#define pf               printf
#define Pi               2*acos(0.0)
#define ms(a,b)          memset(a, b, sizeof(a))
#define pb(a)            push_back(a)
#define MP               make_pair
#define db               double
#define ll               long long
#define ull               unsigned long long
#define EPS              10E-10
#define ff               first
#define ss               second
#define sqr(x)           (x)*(x)
#define D(x)             cout<<#x " = "<<(x)<<endl
#define VI               vector <int>
#define DBG              pf("Hi\n")
#define MOD              1000000007
#define CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define stlloop(v)       for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define loop(i,n)        for(int i=0;i<n;i++)
#define loop1(i,n)       for(int i=1;i<=n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define TEST_CASE(t)     for(int z=1;z<=t;z++)
#define PRINT_CASE       printf("Case %d:\n",z)
#define CASE_PRINT       cout<<"Case "<<z<<":"<<endl
#define all(a)           a.begin(),a.end()
#define intlim           2147483648
#define infinity         (1<<28)
#define ull              unsigned long long
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))
#define maxl 100010

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
/*------------------------------------------------*/

vector<int>g[maxl];
bool sign[maxl];
int color[maxl];
long long maxi=0;

void bfs(int u)
{
    queue<int>q;
    q.push(u);
    sign[u]=false;
    color[u]=2;
    while( !q.empty() )
    {
        int u1=q.front();
    //    cout<<"U1  "<<u1<<"  "<<node<<endl;
        q.pop();
        for(int i=0; i<(int)g[u1].size(); i++)
        {
            int v=g[u1][i];
           // cout<<"V  "<<v<<endl;
            if(sign[v])
            {
                sign[v]=false;
                if(color[u1]==2) color[v]=1;
                else color[v]=2;
                q.push(v);
            }
        }
    }

}
int one1=0,two1=0;
int bfs1(int u)
{
    queue<int>q;
    q.push(u);
    sign[u]=false;
    while( !q.empty() )
    {
        int u1=q.front();
        if(color[u1]==1) one1++;
        else two1++;
        //cout<<"U1  "<<u1<<"  "<<color[u1]<<"  "<<one1<<" "<<two1<<endl;
        q.pop();
        for(int i=0; i<(int)g[u1].size(); i++)
        {
            int v=g[u1][i];
           // cout<<"V  "<<v<<endl;
            if(sign[v])
            {
                sign[v]=false;
                q.push(v);
            }
        }
    }
    //cout<<"B  "<<one1<<"  "<<two1<<endl;
    return max(one1,two1);

}

int main()
{
    int t,cas=1;
    sf(t);

    while(t--)
    {
        memset(sign,true,sizeof sign);
        memset(color,0,sizeof color);
        map<int,int>mp;
        int n;
        sf(n);
        vector<int>node;
        for(int i=0; i<n; i++)
        {
            int u,v;
            sff(u,v);
      //      cout<<"U  "<<u<<"  "<<v<<endl;
            g[u].push_back(v);
            g[v].push_back(u);
            if(mp[u]==0) node.push_back(u);
            if(mp[v]==0) node.push_back(v);
            mp[u]=mp[v]=1;
        }

        for(int i=0; i<(int)node.size(); i++)
        {
            int nn=node[i];
            if(sign[nn]) bfs(nn);
        }
        memset(sign,true,sizeof sign);
        int ans=0;
        for(int i=0; i<(int)node.size(); i++)
        {
            one1=0,two1=0;
           if(sign[node[i]])
           {
               ans += bfs1(node[i]);
           }
        }
        printf("Case %d: %d\n",cas++,ans);
        for(int i=0; i<(int) node.size(); i++) g[node[i]].clear();

    }
    return 0;
}
