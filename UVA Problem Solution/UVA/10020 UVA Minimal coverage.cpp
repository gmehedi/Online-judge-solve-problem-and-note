
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
#define maxl 1
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
struct str
{
    int sl;
    int sr;
};

bool compare(str x, str y)
{
    return (x.sl<y.sl);
}

vector<str>v;

int main()
{
    int t;
    scanf("%d",&t);
    bool sign=false;
    while(t--)
    {
        int m;
        if(sign) printf("\n");
        sign=true;
        scanf("%d",&m);
        int l,r;

        while(true)
        {
            scanf("%d %d",&l,&r);
            if(l == 0 && r== 0) break;
            v.push_back({l,r});
        }
        sort(v.begin(),v.end(),compare);
     //   for(int i=0; i<v.size(); i++) cout<<v[i].sl<<"  "<<v[i].sr<<endl;
        if(v[0].sl > 0)
        {
            printf("0\n");
            continue;
        }
        vector<str>res;
        bool flag=false;
        for(int i=0; i<v.size(); i++)
        {
         //   cout<<"V  "<<v[i].sl<<"  "<<v[i].sr<<endl;
            if(v[i].sl <=0 )
            {
                if(res.size() == 0)
                {
                    res.push_back({v[i].sl,v[i].sr});
                    if(v[i].sr >= m)
                    {
                        flag=true;
                        break;
                    }
                }
                else if(res[res.size()-1].sr < v[i].sr)
                { //cout<<"GG"<<endl;
                    res.pop_back();
                  //  cout<<"R  "<<res.size()<<"  "<<v[i].sl<<"  "<<v[i].sr<<endl;
                    res.push_back({v[i].sl,v[i].sr});
                    if(v[i].sr >= m)
                    {
                        flag=true;
                        break;
                    }
                }
            }
            else
            {
                if(res.size() == 0)
                {
                    flag=false;
                    printf("0\n");
                    break;
                }
                if(res.size() == 1 && res[0].sr >= v[i].sl && res[0].sr < v[i].sr  )
                { // cout<<"FGG"<<endl;
                    res.push_back({v[i].sl,v[i].sr});
                    if(m <= v[i].sr)
                    {
                        flag=1;
                        break;
                    }
                    else continue;
                }

                else
                {

                    if(res[res.size()-1].sr < v[i].sr && res[res.size()-2].sr >= v[i].sl )
                    { // cout<<"TTTTT"<<endl;
                        res.pop_back(), res.push_back({v[i].sl,v[i].sr});
                        if(v[i].sr >= m)
                        {
                            flag=true;
                            break;
                        }
                    }
                    else if(res[res.size()-1].sr >= v[i].sl && res[res.size()-1].sr < v[i].sr )
                    {//cout<<"SSSSS"<<endl;
                        res.push_back({v[i].sl,v[i].sr});
                        if(v[i].sr >= m)
                        {
                            flag=true;
                            break;
                        }
                    }
                }
            }
        }

        if(flag)
        {
            printf("%d\n",res.size());
            for(int i=0; i<res.size(); i++) printf("%d %d\n",res[i].sl,res[i].sr);
        }
        else printf("0\n");

        v.clear();
    }

    return 0;
}
