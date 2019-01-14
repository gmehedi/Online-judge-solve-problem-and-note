
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
#define maxl 1
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
/*

struct str
{
    string x;
    int y;
};
bool compare(str x1, str y1)
{
    return x1.y>y1.y;
}
*/
/*------------------------------------------------*/

using namespace std;

vector<ull>v;
vector<ull>res;

void Generate1(ull sum, int pos)
{
    if( sum > (ull) 1e12 || sum <= 0 ) return;
    if(sum != 1)res.push_back(sum);
    for(int i=pos; i<(int)v.size(); i++)
    {
        if(sum*v[i] >= (ull)1e12 || sum <= 0) break;
        Generate1(sum*v[i],i);
    }
}

void Generate(ull sum)
{
    if(sum > (ull)1e12) return;
    if(sum != 0) v.push_back(sum);

    Generate((sum*10ULL)+4ULL);
    Generate((sum*10ULL)+7ULL);
}

int main()
{
    int t,cas=1;

    Generate(0ULL);
    sort(v.begin(),v.end());
    Generate1(1ULL,0);
    sort(res.begin(),res.end());
    res.erase( unique(res.begin(),res.end()),res.end() );

    scanf("%d",&t);
    while(t--)
    {
        ll a,b;
        scanf("%lld %lld",&a,&b);
        ll t1=upper_bound(res.begin(),res.end(),b)-res.begin();
        ll t2=(lower_bound(res.begin(),res.end(),a)-res.begin());
        printf("Case %d: %lld\n",cas++,t1-t2);
    }
    v.clear();
    res.clear();
    return 0;
}
