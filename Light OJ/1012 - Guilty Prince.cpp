
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
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
bool sign[22][22];
int n,k;
int flat_feel(string s[22],int x, int y)
{
    int cnt=1;
    memset(sign,true,sizeof sign);
    queue< pair<int,int> >q;
    q.push(make_pair(x,y));

    while( !q.empty() )
    {
        int x1=q.front().ff;
        int y1=q.front().ss;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int x2=x1+fx[i], y2=y1+fy[i];
            if( x2>=0 && x2<n && y2>=0 && y2<k )
            {
                if(sign[x2][y2] && s[x2][y2]=='.')
                {
                    cnt++;
                    q.push(make_pair(x2,y2));
                    sign[x2][y2]=false;
                }
            }
        }
    }
    return cnt;

}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&k,&n);
        cin.ignore();
        string s[22];
        for(int i=0; i<n; i++) cin>>s[i];
      //  cout<<s[0]<<endl;
        int i,j;
        bool sign2=false;
      //  cout<<"N "<<n<<" "<<k<<endl;
        for( i=0; i<n; i++)
        {
            for( j=0; j<k; j++)
            {
              //  cout<<"R "<<i<<"  "<<j<<"  "<<s[i][j]<<endl;
                if(s[i][j]=='@'){  sign2=true;  break; }
            }
          //  cout<<"B "<<n<<" "<<i<<"  "<<j<<"  "<<sign[i][j]<<endl;
            if(sign2) break;
        }
      //  cout<<"I  "<<i<<" "<<j<<endl;
        printf("Case %d: %d\n",cas++,flat_feel(s,i,j));
    }
}
