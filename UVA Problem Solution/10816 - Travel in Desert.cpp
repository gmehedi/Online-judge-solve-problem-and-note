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


int n,e,s,d,u1,v1;

double t,d1;
double costt[110];
int path[110];

struct str1{
    int nodes1;
    double cnts1;
    double temps1;
};

vector<str1>g[101];
bool sign[101];

struct str{

    int nodes;
    double temps;
    bool operator <(const str& temp) const{
        return temps > temp.temps;
    }
    
};

vector<int>v;

void Path(int d) { 
    while(d != -1) v.pb(d), d = path[d]; 
}

void Diajkstra(int s, int d){

    priority_queue<str>q;

    for(int i=0; i<=n; i++) costt[i] = double(100000000.00);

    q.push({s,0.0});
    
    costt[s] = 0.0;
    while(!q.empty()){

        int u1 = q.top().nodes;
        double temp1 = q.top().temps;
        q.pop();

        for(auto tt : g[u1]){

            int v2 = tt.nodes1;
            double temp2 = tt.temps1;

            if(max(temp1,temp2) < costt[v2]){
                costt[v2] = max(temp1,temp2);
                q.push({v2,costt[v2]});
            }
        }
    }
}


void Diajkstra1(int s, int d, double tmp){

    priority_queue<str>q;

    for(int i=0; i<=n; i++) costt[i] = double(100000000.00), path[i] = -1;

    q.push({s,0.0});
    
    costt[s] = 0.0;
    while(!q.empty()){

        int u1 = q.top().nodes;
        double cnt1 = q.top().temps;
        q.pop();

        for(auto tt : g[u1]){

            int v2 = tt.nodes1;
            double temp2 = tt.temps1;
            double cnt2 = tt.cnts1;
            if(temp2 > tmp) continue;

            if(costt[u1]+cnt2 < costt[v2]){
                path[v2] = u1; 
                costt[v2] = costt[u1]+cnt2;
                q.push({v2,costt[v2]});
            }

        }
    }
}

void CLR(){

    for(int i=0; i<=100; i++) g[i].clear();
    v.clear();
}
int main(){

   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);

    while( scanf("%d%d%d%d",&n,&e,&s,&d) == 4){
        for(int i=0; i<e; i++){
            scanf("%d%d",&u1,&v1);
            scanf("%lf%lf",&t,&d1);
            g[u1].push_back({v1,d1,t});
            g[v1].push_back({u1,d1,t});
        }

        Diajkstra(s,d);
        double tmp = costt[d];
        Diajkstra1(s,d,tmp);

        Path(d);
        reverse(v.begin(),v.end());
        for(int i=0; i<int(v.size()); i++){
            if(i == 0) printf("%d",v[i]);
            else printf(" %d",v[i]);
        }

        printf("\n%.1f %.1f\n",costt[d],tmp);
        CLR();
    }
    return 0;
}