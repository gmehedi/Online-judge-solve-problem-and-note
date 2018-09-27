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
char s1[35],s2[35];
int dp[35][35];
ll dp1[35][35][35];

int Lcs(int i, int j)
{
    if(i<0 || j<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j])  dp[i][j]= 1+Lcs(i-1,j-1);
    else
    {
        dp[i][j]= max( Lcs(i-1,j),Lcs(i,j-1) );
    }
    return dp[i][j];
}

ll Unique(int l1, int l2, int l)
{
    if(l1 == 0 && l2 == 0 && l == 0 ) return 1;
    if(l1 == 0 && l2 == 0 && l != 0 ) return 0;
    if(l1 != 0 and l2 == 0)  return Unique(l1-1,l2,l-1);
    if( l1 == 0 and l2 != 0)  return Unique(l1,l2-1,l-1);

    if(dp1[l1][l2][l] != -1) return dp1[l1][l2][l];

    if(s1[l1-1] == s2[l2-1]) return Unique(l1-1,l2-1,l-1);
    else
    {
        return dp1[l1][l2][l] = Unique(l1-1,l2,l-1) + Unique(l1,l2-1,l-1);
    }

    return dp1[l1][l2][l];
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %s",&s1,&s2);
        memset(dp,-1,sizeof dp);
        int l1=strlen(s1), l2=strlen(s2);
        int length = Lcs(l1-1,l2-1);

        int ans1=l1+l2-length;
        memset(dp1,-1,sizeof dp1);
        ll ans2=Unique(l1,l2,ans1);

        printf("Case %d: %d %lld\n",cas++,ans1,ans2);
    }
}

