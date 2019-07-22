
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

vector<ll>fib;
void Store()
{
    fib.push_back(0);
    fib.push_back(1);
    fib.push_back(2);
    int n=3;
   while( 1 )
   {
       ll temp=fib[n-1]+fib[n-2];
       if(temp> (ll) 1e8) break;
       n++;
       fib.push_back(temp);
   }
   //cout<<"B "<<fib.size()<<endl;
}

string solve(int n)
{
    string s;

    int i= upper_bound(fib.begin(),fib.end(),n)-fib.begin();
    i--;
   // cout<<"I  "<<i<<"  "<<fib[i]<<endl;
    if(fib[i] == (ll)n)
    {
        s+='1';
        for(int j=i-1; j>0; j--) s+='0';
        return s;
    }

    ll sum=0;
    while(i>0)
    {
        if((sum+fib[i]) <= n)
        {
            sum+=fib[i],s+='1';
            //cout<<"H "<<fib[i]<<"  "<<n<<"  "<<sum<<"  "<<s<<"  "<<i<<endl;
            if(i != 1) s+='0';
             i-=2;

        }
        else s+='0', i--;
     //    cout<<"HGFDHGF"<<"  "<<sum<<"  "<<fib[i]<<endl<<endl;
        if(sum == n)
        {//cout<<"I  "<<i<<"  "<<s<<endl;
            while(i>0) s+='0', i--;
            return s;
        }
    }

}
int main()
{
    int t;
    Store();
    scanf("%d",&t);
    while(t--)
    {
        int i=0,n;
        scanf("%d",&n);
        string ans=solve(n);
        char res[100];

        for( i=0; i< (int)ans.size(); i++)
        {
            res[i]=ans[i];
        }
        res[i]='\0';

        printf("%d = %s (fib)\n",n,res);
    }
    return 0;
}

