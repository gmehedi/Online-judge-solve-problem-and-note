
 
//#include <bits/stdc++.h>
#include <string>
#include <stack>
#include <bitset>
#include <queue>
#include <cstdio>
#include <cmath>
#include <iostream>
 
 
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
#define maxl 100000
#define psz 20
#define Fin      freopen("input.txt","r",stdin)
#define Fout     freopen("output.txt","w",stdout)
 
 
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
//freopen("out.txt","w",stdout);
//ios_base::sync_with_stdio(false);
 //cin.tie(NULL);

using namespace std;

bool sign[maxl + 2], test[maxl + 3];
vector<int>prime;
int a[maxl + 3], pos[maxl + 5];
bitset<1230>ttt;
vector<bitset<1230>>v;

void Prime(){
    for(int i = 0; i <= 1e4; i++) sign[i] =  true;
    prime.pb(2);
    
    pos[0] = 2;

    for(int i = 3; i * i <= 1e4; i += 2){
        if(sign[i]){
            for(int j = i * i; j <= 1e4; j += (i * 2)) sign[j] = false;
        }
    }
    int p = 1;
    for(int i = 3; i <= 1e4; i += 2){
        if(sign[i]) prime.pb(i), pos[i] = p, p++;
    }
}

bitset<1230> Factorization(int num){

    int temp = num,res = 1;
    bitset<1230>test;

    for(int i=0; i < prime.size() && prime[i] * prime[i] <= temp; i++){
        if(prime[i] > temp) break;
        int ans=0;
        while(temp % prime[i] == 0) temp /= prime[i], ans++;
        if(ans % 2 > 0){
           // cout<<"P   "<<pos[prime[i]]<<endl;
            test[pos[prime[i]]] = true;
        }
    }

    if(temp>1) test[pos[temp]] = true;

    return test;

}

///////////////////////////////////////////////////////////////////////////////////////

struct str{
    bitset<1230>sum;
   // bitset<1230>prop;
}
tree[maxl * 4 + 2];


void Build(int node, int s, int e){
    if(s == e) { tree[node].sum = v[a[s]]; return; }
    int mid = (s+e)/2;

    Build(node*2,s,mid);
    Build((node*2)+1,mid+1,e);
    tree[node].sum = tree[node*2].sum ^ tree[(node*2)+1].sum;
   // tree[node].sum.clear() , tree[node].prop.clear();
}

void Update(ll node, ll s, ll e, ll i, ll j, bitset<1230> &prop){
   
    if(s>j || e<i) return;
    if(s>=i && e<=j){

        tree[node].sum = prop;
        return;
    }
    ll mid = (e+s)/2;
    Update(node*2,s,mid,i,j,prop);
    Update((node*2)+1,mid+1,e,i,j,prop);
    tree[node].sum = tree[node*2].sum ^ tree[(node*2)+1].sum;
}


bitset<1230> Qry(int node, int s, int e, int i, int j)
{
    if(s>j || e<i) return ttt;
    if(s>=i && e<=j){
        return tree[node].sum;
    }
    int mid = (e+s)/2;
    bitset<1230> p1 = Qry(node*2,s,mid,i,j);
    bitset<1230> p2 = Qry((node*2)+1,mid+1,e,i,j);
   // tree[node].sum = tree[node*2LL].sum+tree[(node*2LL)+1LL].sum;
    tree[node].sum = tree[node*2LL].sum ^ tree[(node*2LL)+1LL].sum;

    return p1 ^ p2;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int  main(){

    int t,cas=1;
    Prime();

    v.pb(ttt);
    v.pb(ttt);
    for(int i = 2; i <= 1e4; i++){
        v.pb(Factorization(i));
    }
    //cout<<"EEE "<<endl;
    scanf("%d",&t);

    while(t--){

        int n,c,l,r;
        scanf("%d%d",&n,&c);

        for(int i = 1; i <= n; i++){
            scanf("%d",&a[i]);
        }
        Build(1,1,n);

        printf("Case %d:\n", cas++);
        while(c--){

            int types;
            scanf("%d",&types);
           // l++,r++;
            if(types == 1)
            {   // cout<<"L  "<<l<<"  "<<r<<endl;
                scanf("%d%d",&l,&r);

                bitset<1230> res = Qry(1,1,n,l,r);

                if(res.count() == 0){
                    printf("YES\n");
                }
                else printf("NO\n");
            }
            else
            {
                scanf("%d%d",&l,&r);
                Update(1,1,n,l,l,v[r]);
            }
        }
    }
    return 0;
}

/*

1
5 6
1 2 3 4 5
1 1 3
2 5 6
1 2 5
2 4 6
1 4 5
1 1 5

*/
