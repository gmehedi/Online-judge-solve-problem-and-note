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
#define ff               first
#define ss               second
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

vector<ull>fib;
void Store()
{
    fib.push_back(0);
    fib.push_back(1);
    fib.push_back(2);
    ull n=3;
   while( 1 )
   {
       ull temp=fib[n-1]+fib[n-2];
       if(temp> (ll) 5e18) break;
       n++;
       fib.push_back(temp);
   }
   //cout<<"B "<<fib.size()<<endl;
}

vector<pll> solve(ull n)
{
    vector<pll>res;
    int i= upper_bound(fib.begin(),fib.end(),n)-fib.begin();
    ull total=0;
    i--;
    while(i>0)
    {
        if( total+fib[i]<= n)
        {
            res.push_back( make_pair(i,fib[i]) );
            total+=fib[i];
        }
        i--;
        if(total == n) return res;
    }
}

int main()
{

    ll n;
    Store();
    bool sign=false;
    while( scanf("%llu",&n) != EOF )
    {
        vector<pll>res;
  //      if(n == 0){ printf("0\n0\n0\n"); continue; }
        res=solve(n);
        printf("%llu\n",n);
        int len=res.size();
      //  cout<<"L  "<<len<<endl;
        for(int i=0; i<len; i++)
        {
             printf("%lld ",res[i].first);
        }
        printf("\n");

        for(int i=0; i<len; i++)
        {
            printf("%lld ",res[i].second);
        }
        printf("\n\n");
    }
    return 0;
}

