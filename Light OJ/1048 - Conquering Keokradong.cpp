
#include <bits/stdc++.h>
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
int n,k,len;
int a[1010];

bool Possible(ll mid)
{
  //  cout<<mid<<" : ";
    ll sum=0,cnt=0;
    for(int i=0; i<=n; i++)
    {
        if(mid<a[i]) return false;
        if(sum+a[i]>mid)
        {
            cnt++, sum=0;
        }
        sum =+ a[i];
        //cout<<a[i]<<" ";
    }
  //  cout<<endl;
   // cout<<"M  "<<mid<<  "  "<<cnt<<"  "<<k<<endl;
    if(cnt<=k) return true;

    return false;
}

bool Possible1(ll avrg)
{
       ll sum=0,tot=0;
        for(int i=0; i<=n; i++)
        {
            if(sum+a[i] > avrg && sum != 0) sum=0, tot++;
            sum += a[i];
            if(tot == k+1) break;
        }
        if(sum != 0 ) tot++;
        if(tot >= k+1) return true;
        return false;
        //cout<<"A "<<ans<<endl;
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);

    while(t--)
    {

        scanf("%d %d",&n,&k);
        ll l=0,r=0,ans=0,k1=0;

        for(int i=0; i<=n; i++)
        {
            scanf("%d",&a[i]);
            r += a[i];
        }
        k1=r;
//cout<<"R  "<<r<<endl;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if( Possible(mid) )
            {
                r=mid-1;
                ans=mid;
            }
            else l=mid+1;
        }
        printf("Case %d: %d\n",cas++,ans);
        l=0,r=k1;

        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(Possible1(mid)) l=mid+1, ans=mid;
            else r=mid-1;
        }

    //    cout<<"AA  "<<ans<<endl;
        ll avrg=ans,sum=0;
        vector<ll>res;
        int i;
        for( i=n; i>=0; i--)
        {
            if(sum+a[i] > ans && sum != 0) res.pb(sum), sum=0;
            sum += a[i];
            if(res.size() == k) break;
        }
        i--;
        while(i>=0) sum+=a[i], i--;
        if(sum != 0 ) res.pb(sum);

        for(int i=res.size()-1; i>=0; i--) printf("%lld\n",res[i]);
        //cout<<"A "<<ans<<endl;
    }
    return 0;
}
