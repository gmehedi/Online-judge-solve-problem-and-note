#include <bits/stdc++.h>
 
#define vpii vector< pair<int,int> >
#define vi vector<int>
 
#define for0(i,a) for(int i=0;i<a;i++)
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
#define ull              unsigned long long
#define f                first
#define s                second
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
#define maxl 100000
#define psz 20
using namespace std;
 
/*----------------------Graph Moves----------------*/
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
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
//freopen("out.txt","w",stdout);
//ios_base::sync_with_stdio(false);
 //cin.tie(NULL);
 
int main(){
 
    int t, cas = 1;
 
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
 
        int res,a[n+3],b[n+3];
 
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }
        for(int i=0; i<n; i++){
            scanf("%d",&b[i]);
        }

        res = abs(a[0]-b[0])-1;
 
       for(int i=1; i<n; i++){
 
          res ^= abs(a[i]-b[i])-1;
       }
 
       if(res != 0) printf("Case %d: white wins\n",cas++);
       else printf("Case %d: black wins\n",cas++);
 
 
    }
 
 
    return 0;
}