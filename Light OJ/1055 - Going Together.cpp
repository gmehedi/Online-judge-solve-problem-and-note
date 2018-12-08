
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
#define maxl 10000100
using namespace std;
/*----------------------Graph Moves----------------*/
const int fx[]= {+1,-1,+0,+0};
const int fy[]= {+0,+0,+1,-1};
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
bool sign[11][11][11][11][11][11];
map<pii,bool>mp;
int n;
string s[20];

struct str
{
    pii a,b,c;
    int cnt;
};

bool Check2(str temp)
{
    if(mp.find(temp.a) != mp.end() && mp.find(temp.b) != mp.end() && mp.find(temp.c) != mp.end() && temp.a != temp.b && temp.b != temp.c && temp.a != temp.c) return true;
    return false;
}
bool Check(pii temp)
{
    if( temp.f>=0 && temp.s>=0 && temp.f<n && temp.s<n && s[temp.f][temp.s] != '#') return true;
    return false;
}

int Bfs(str source)
{
    queue<str>q;
    q.push(source);
    sign[source.a.f][source.a.s][source.b.f][source.b.s][source.c.f][source.c.s]=false;

    int t1=0,t2=0;
    while( !q.empty() )
    {
        str temp=q.front();
        q.pop();

        str temp1;
        if(Check2(temp)) return temp.cnt;
        for(int i=0; i<4; i++)
        {
            t1=temp.a.f+fx[i];
            t2=temp.a.s+fy[i];
            temp1.a=pii(t1,t2);
            // cout<<"E1      "<<t1<<"  "<<t2<<endl;
            if(!Check(temp1.a)) temp1.a=temp.a;
            //cout<<"T "<<"  "<<temp1.a.f<<"  "<<temp1.a.s<<"  "<<t1<<"  "<<t2<<endl,
            t1=temp.b.f+fx[i];
            t2=temp.b.s+fy[i];
            temp1.b=pii(t1,t2);
            //    cout<<"E2     "<<t1<<"   "<<t2<<"   "<<temp1.b.f<<"   "<<temp1.b.s<<endl;
            if(!Check(temp1.b))  temp1.b=temp.b;

            t1=temp.c.f+fx[i];
            t2=temp.c.s+fy[i];
            temp1.c=pii(t1,t2);

            if(!Check(temp1.c)) temp1.c=temp.c;
        //    printf("A11 %d  %d   B  %d %d  C   %d %d\n",temp1.a.f,temp1.a.s,temp1.b.f,temp1.b.s,temp1.c.f,temp1.c.s);

            if(temp1.a == temp1.b)
            {
               // cout<<"R1   "<<temp1.a.f<<"   "<<temp1.a.s<<"   "<<temp1.b.f<<"   "<<temp1.b.s<<endl;
                temp1.a=temp.a, temp1.b=temp.b;
                if(temp1.c == temp1.b) temp1.c=temp.c;
            }
            if(temp1.a == temp1.c)
            {
               // cout<<"R2   "<<temp1.a.f<<"   "<<temp1.a.s<<"   "<<temp1.c.f<<"   "<<temp1.c.s<<endl;
                temp1.a=temp.a, temp1.c=temp.c;
                if(temp1.c == temp1.b) temp1.b=temp.b;
            }

            if(temp1.b == temp1.c)
            {
                //cout<<"R1   "<<temp1.b.f<<"   "<<temp1.b.s<<"   "<<temp1.b.f<<"   "<<temp1.b.s<<endl;
                temp1.b=temp.b, temp1.c=temp.c;
                if(temp1.a == temp1.b) temp1.a=temp.a;
            }

            if(sign[temp1.a.f][temp1.a.s][temp1.b.f][temp1.b.s][temp1.c.f][temp1.c.s])
            {
                temp1.cnt=temp.cnt+1;
                q.push(temp1);
                sign[temp1.a.f][temp1.a.s][temp1.b.f][temp1.b.s][temp1.c.f][temp1.c.s]=false;
              //  printf("IN %d  %d   B  %d %d  C   %d %d\n",temp1.a.f,temp1.a.s,temp.b.f,temp.b.s,temp1.c.f,temp1.c.s);
            }
        }
    }

    return -1;
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    str source;
    while(t--)
    {
        scanf("%d",&n);
        cin.ignore();
        for(int i=0; i<n; i++) cin>>s[i];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(s[i][j] == 'A') source.a=pii(i,j);
                if(s[i][j] == 'B') source.b=pii(i,j);
                if(s[i][j] == 'C') source.c=pii(i,j);

                if(s[i][j] == 'X') mp[pii(i,j)]= true;
            }
        }
        source.cnt=0;
        memset(sign,true,sizeof sign);
        int res=Bfs(source);

        if(res == -1) printf("Case %d: trapped\n",cas++);
        else printf("Case %d: %d\n",cas++,res);

        mp.clear();
        string stemp[20];
        swap(s,stemp);
    }

    return 0;
}
