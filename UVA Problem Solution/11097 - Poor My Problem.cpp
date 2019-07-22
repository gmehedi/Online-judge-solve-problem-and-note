
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
#define maxl 1000000
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


ll totn[610];

struct str{
    ll nodes, cnts, costs;
    bool operator < (const str& temp) const {
        return ( costs > temp.costs );
    }
};
vector< pair<ll,ll> >g[610];
ll cost[610][1010];

void Diajkstra(ll s){

    priority_queue<str>q;

    for(int i = 0; i <= 600; i++) 
        for(int j = 0; j <= 1000; j++) cost[i][j] = 1e17;

    q.push({s,0,0});
    cost[s][0] = 0;

    while(!q.empty()){

        ll u1 = q.top().nodes;
        ll w1 = q.top().costs;
        ll cnt1 = q.top().cnts;
        q.pop();

        for(auto tg : g[u1]){

            ll v2 = tg.f;
            ll w2 = tg.s;
         //  cout<<"U "<<u1<<"  "<<v2<<"  "<<cost[u1][cnt1]+w2<<"  "<<cost[v2][cnt1+1]<<endl;
            if( (cost[u1][cnt1] + w2) < cost[v2][cnt1 + 1]){
                cost[v2][cnt1 + 1] = cost[u1][cnt1] + w2;
                q.push({v2,cnt1 + 1,cost[v2][cnt1 + 1]});
            }
        }
    }
}


void CLR(){
    for(int i=0; i<=600; i++) g[i].clear();
}
int main(){

   // freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    ll n,e,u1,v1,w1,s;
    while( scanf("%lld%lld%lld",&n,&e,&s) == 3){
        for(int i=0; i<e; i++){
            scanf("%lld%lld%lld",&u1,&v1,&w1);
            g[u1].push_back(mk(v1,w1));
          //  g[v1].push_back(mk(u1,w1));
       //     cout<<"F "<<u1<<endl;
        }
      //  cout<<"SS"<<endl;
        Diajkstra(s);
      //  cout<<"DD"<<endl;
        int q;
        scanf("%d",&q);
        while(q--){
            int go, cnt = 0;
            scanf("%d",&go);

    
            double ans = 1e18;
            for(int i = 0; i <= 1000; i++){
                if(go == s) { ans = 0.0; break; }
                if(cost[go][i] == 1e17) continue;

                if(ans > ( double(cost[go][i]) / double(i) )){
                    ans = ( double(cost[go][i]) / double(i) );
                    cnt = i;
                }
            }
            if(ans == 1e18) printf("No Path\n");
            else printf("%.4f %d\n",ans,cnt);

            CLR();
        }
        printf("\n");
    }
    return 0;
}