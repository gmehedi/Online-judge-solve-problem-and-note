
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
#define maxl 20

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
using namespace std;
bool sign[maxl][maxl];
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
string s[maxl];
int n;
char source,des;

struct str
{
    char ch;
    int x;
    int y;
};

bool compare(str x, str y)
{
    return x.ch<y.ch;
}

bool Check(int i, int j)
{
    if(i>=0 && i<n && j>=0 && j<n)
    {
        if( (s[i][j] == '.' || s[i][j] <= des) && s[i][j] != '#') return true;
    }
    return false;
}

int Bfs(int x, int y, int x1, int y1)
{
    queue< pair<int, pair<int,int> > >q;
    q.push( mk(0, mk(x,y) ) );
    source=s[x][y], des=s[x1][y1];
    sign[x][y]=false;

    while( !q.empty() )
    {
        int cnt1=q.front().f;
        int i1=q.front().s.f;
        int j1=q.front().s.s;
        q.pop();

        if(s[i1][j1] == des) return cnt1;

        for(int i=0; i<4; i++)
        {
            int i2=i1+fx[i];
            int j2=j1+fy[i];
            if( Check(i2,j2) && sign[i2][j2] )
            {
               // cout<<"T  "<<i2<<"  "<<j2<<"  "<<sign[i2][j2]<<"   "<<s[i2][j2]<<endl;
                sign[i2][j2]=false;
                q.push(mk(cnt1+1,mk(i2,j2)));
            }
        }
    }

    return -1;
}
int main()
{
    int t,cas=1;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            char temp[maxl];
            scanf("%s",temp);
            s[i]=(string) temp;
        }
        vector< str >v;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(s[i][j] >= 'A' && s[i][j] <= 'Z')
                {
                    v.push_back( {s[i][j],i,j} );
                }
            }
        }

        sort(v.begin(),v.end(),compare);

        int len= (int)v.size();
        int res=0;
        int total=0;

        for(int i=0; i<len-1; i++)
        {
            memset(sign,true,sizeof sign);
            res=Bfs( v[i].x, v[i].y, v[i+1].x, v[i+1].y );
            if(res == -1) { total=-1; break; }
            else total+=res;
        }

        if(total != -1)printf("Case %d: %d\n",cas++,total);
        else printf("Case %d: Impossible\n",cas++);
        string temps[maxl];
        swap(temps,s);
    }
    return 0;
}
