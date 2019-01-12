
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
#define maxl 100001
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
int a[100],n,n1;
ll k;
vector<ll>v1,v2;

void Dp(ll tot, int pos, int flag)
{
    if(tot > k) return ;
    //cout<<"P  "<<pos<<"   "<<n1<<endl;
    if(pos >= n1)
    {
        if(flag) v1.pb(tot);
        else v2.pb(tot);
        return ;
    }
    Dp(tot+a[pos],pos+1,flag);
    Dp(tot,pos+1,flag);
}
int main()
{
    int q,cas=1;
    cin>>q;
    while(q--)
    {
        scanf("%d %lld",&n,&k);
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        n1=(n/2)+1;
        Dp(0LL,0LL,1);
        n1=n;
        Dp(0LL,(n/2)+1,0);
        sort(v1.begin(),v1.end());

        ll ans=0;
        for(int i=0; i<(int)v2.size(); i++)
        {
            if( k-v2[i] < v1[0]) continue;
            int tt= upper_bound(v1.begin(),v1.end(),k-v2[i])-v1.begin();
            ans +=tt;
        }
        printf("Case %d: %lld\n",cas++,ans);
        v1.clear();
        v2.clear();
    }
    return 0;
}
