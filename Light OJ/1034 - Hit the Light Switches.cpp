
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
#define maxl 5000001
#define maxi 10010

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

bitset<maxi>sign;
vector<int>graph[maxi];

void Creat(int t1, int t2)
{
    graph[t1].push_back(t2);
}

stack<int>stackk;

void dfs(int u)
{
    sign[u]=true;

    for(int i=0; i<(int)graph[u].size(); i++)
    {
        int v=graph[u][i];
        if( !sign[v] ) dfs(v);
    }
    stackk.push(u);
}

void dfs1(int u)
{
    sign[u]=true;

    for(int i=0; i<(int)graph[u].size(); i++)
    {
        int v=graph[u][i];
        if( !sign[v] ) dfs(v);
    }
}


int main()
{
    int n,m,t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; i++)
        {
            int t1,t2;
            cin>>t1>>t2;
            Creat(t1,t2);
        }
        sign.reset();
        for(int i=1; i<=n; i++)
        {
            if( !sign[i] ) dfs(i);
        }
        sign.reset();
        int ans=0;
        while( !stackk.empty() )
        {
            int u=stackk.top();
            stackk.pop();
            if( !sign[u] )
            {
                ans++;
                dfs1(u);
            }
        }
        printf("Case %d: %d\n",cas++,ans);

        for(int i=1; i<=n; i++) graph[i].clear();

    }
    return 0;
}
