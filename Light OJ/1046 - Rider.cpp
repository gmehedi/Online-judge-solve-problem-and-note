
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
#define maxl 1000010

using namespace std;


/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdin);
/*------------------------------------------------*/
using namespace std;

int res[110][11][11],n,m;
int occur[12][12];
int svalue[110],state;
bool sign[11][11];
char s[20][20];

struct str
{
    pii pos;
};

bool Check(int x, int y)
{
    if(x>=0 && y>=0 && x<n && y<m) return true;
    return false;
}

void Bfs(int x, int y, int who)
{

    queue<str>q;
    q.push( {pii(x,y)} );

    sign[x][y]=false;
    occur[x][y]++;
  // cout<<"F  "<<x<<"  "<<y<<"    "<<occur[x][y]<<endl;
    while( !q.empty() )
    {
        str temp=q.front();
        q.pop();
        for(int i=0; i<8; i++)
        {
            int x1=temp.pos.f+fx[i];
            int y1=temp.pos.s+fy[i];
            if(Check(x1,y1) && sign[x1][y1])
            {
                sign[x1][y1]=false;
                res[who][x1][y1]=res[who][temp.pos.f][temp.pos.s]+1;
                occur[x1][y1]++;
                q.push({pii(x1,y1)});
            //    cout<<"R  "<<res[who][x1][y1]<<"    "<<occur[x1][y1]<<"     "<<x1<<" "<<y1<<endl;
            }
        }
    }
}

int Min(int x, int y)
{
    int mini=0;
    for(int i=1; i<=state; i++)
    {
        int k=svalue[i];
        mini += (res[i][x][y]/k);
        if(res[i][x][y]%k != 0) mini++;
      //  cout<<"I  "<<i<<"  "<<x<<" "<<y<<"      "<<res[i][x][y]<<endl;
    }
   // cout<<"M  "<<mini<<"   "<<endl;
    return mini;
}
int Check2()
{
    bool sign1=true;
    int mini=123456789;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            //cout<<"O  "<<occur[i][j]<<endl;
            if(occur[i][j] == state)
            {
                 mini= min(mini,Min(i,j));
                 sign1=false;
            }
        }
    }
    if(!sign1) return mini;
    return -1;
}

void Clear()
{
    char temp[20][20];
    swap(temp,s);
    memset(res,0,sizeof res);
    memset(occur,0,sizeof occur);
    memset(svalue,0,sizeof svalue);
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);

    while(t--)
    {
        Clear();
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++) scanf("%s",s[i]);
        state=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(s[i][j] != '.')
                {
                    memset(sign,true,sizeof sign);
                    int k = s[i][j]-'0';
                    Bfs(i,j,++state);
                    svalue[state]=k;
                }
            }
        }
        printf("Case %d: %d\n",cas++,Check2());
    }

    return 0;
}
