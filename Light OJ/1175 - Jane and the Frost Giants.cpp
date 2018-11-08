



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
#define maxl 210

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

const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
int n,m;
string s[maxl];
bool sign[maxl][maxl];
int f[maxl][maxl];
vector<pii>v;

int BfsF()
{
    queue< pair<int,pair<int,int> > >q;
    for(int i=0; i<(int)v.size(); i++)
    {
        q.push(mk(0,mk(v[i].f,v[i].s)));
        f[v[i].f][v[i].s]=0;
        sign[v[i].f][v[i].s]=false;
    }

    while( !q.empty() )
    {
        int i1=q.front().s.f;
        int j1=q.front().s.s;
        int cnt1=q.front().f;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int i2=i1+fx[i];
            int j2=j1+fy[i];
            if(i2>=0 && i2< n && j2>= 0 && j2<m && sign[i2][j2] )
            {
                sign[i2][j2]=false;
                if(s[i2][j2] != '#') f[i2][j2]=cnt1+1, q.push( mk(cnt1+1, mk(i2,j2) ) );
            }
        }
    }
}

int Bfs(int x, int y)
{
    queue< pair<int,pair<int,int> > >q;
    q.push(mk(0,mk(x,y)));

    while( !q.empty() )
    {
        int i1=q.front().s.f;
        int j1=q.front().s.s;
        int cnt1=q.front().f;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int i2=i1+fx[i];
            int j2=j1+fy[i];

            if(i2<0 || j2<0 || i2>=n || j2 >= m) return cnt1+1;
           // cout<<"I  "<<i2<<" "<<j2<<"            "<<f[i2][j2]<<"  "<<cnt1+1<<endl;
            if( sign[i2][j2] && s[i2][j2] != '#' && ( (cnt1+1) < f[i2][j2] ) )
            {
               sign[i2][j2]=false;
              // cout<<i2<<" "<<j2<<"        "<<cnt1<<"  "<<f[i2][j2]<<endl;
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
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++)
        {
            char temp[maxl];
            scanf("%s",temp);
            s[i]=(string) temp;
        }
        int fx=0,fy=0,jx=0,jy=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(s[i][j] == 'J') jx=i, jy=j;
                if(s[i][j] == 'F') v.push_back(mk(i,j));
            }
        }
        memset(sign,true,sizeof sign);
        memset(f,0,sizeof f);
        BfsF();
        memset(sign,true,sizeof sign);

        int ans=Bfs(jx,jy);
        if(ans == -1) printf("Case %d: IMPOSSIBLE\n",cas++);
        else printf("Case %d: %d\n",cas++,ans);

        string temps[maxl];
        swap(temps,s);
        v.clear();
    }
    return 0;
}
