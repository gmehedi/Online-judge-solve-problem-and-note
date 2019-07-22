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

int n,m,q,ms,md,mc,mu,mv,mw,cost[1100][110],p[1010];
vector<pii>g[1010];
bool sign[1001][101];

struct str{

    int nodes,hass,tots;
    bool operator <(const str& temp) const{
        return tots > temp.tots;
    }
};

void Diajkstra(int s, int d, int c){
//cout<<"TTT"<<"  "<<s<<"  "<<d<<"  "<<c<<endl;
    for(int i = 0; i <= 1000; i++)
        for(int j = 0; j <= 100; j++) 
            cost[i][j] = INT_MAX, sign[i][j] = false;

    cost[s][0] = 0;
  // cout<<"FFF"<<endl; 
    priority_queue<str>q;
    q.push({s,0,0});
//cout<<"FDSFSFDSF"<<endl;

    while(!q.empty()){

        int u = q.top().nodes;
        int has = q.top().hass;
        int tot = q.top().tots;

      //  if(u == d) return;
        q.pop();
        if(sign[u][has]) continue;
        sign[u][has] = true;
     //   cout<<"U  "<<u<<endl;

        for(auto v : g[u]){

            int v1 = v.f;
            int w1 = v.s;

            if(w1 <= has && cost[u][has] < cost[v1][has-w1]){
                cost[v1][has-w1] = cost[u][has]; 
                q.push({v1,has-w1,cost[v1][has-w1]});
            }
           
        }

        if(has < c && (cost[u][has]+p[u]) < cost[u][has+1] ){
            cost[u][has+1] = cost[u][has]+p[u];
            q.push({u,has+1,cost[u][has+1]});
        }
    }
    return;
}
int main(){

   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);

    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++) scanf("%d",&p[i]);

    while(m--){
        scanf("%d%d%d",&mu,&mv,&mw);
        g[mu].pb(mk(mv,mw));
        g[mv].pb(mk(mu,mw));
    }
    scanf("%d",&q);

    while(q--){
        scanf("%d%d%d",&mc,&ms,&md);
        Diajkstra(ms,md,mc);
        if(cost[md][0] == INT_MAX) printf("impossible\n");
        else printf("%d\n",cost[md][0]);
    }
    return 0;

}