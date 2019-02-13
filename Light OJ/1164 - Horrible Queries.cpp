
#include <bits/stdc++.h>
#define pii              pair <ull,int>
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
#define maxl 100110
#define psz 20
using namespace std;
int n;
char st[maxl];
struct str
{
    ll val;
    ll inc;
}
tree[(maxl*3)+2];
void Build(int node, int s, int e)
{
    if(s == e){ tree[node].val=0; tree[node].inc=0; return; }
    int left=node*2;
    int right=left+1;
    int mid=(s+e)/2;
    Build(left,s,mid);
    Build(right,mid+1,e);
    tree[node].inc=0;
    tree[node].val =0;
}
void Update(int node, int s, int e, int i, int j, int val1)
{
    if(s>j || e<i) return;
    if(s>=i && e<=j)
    {
        tree[node].inc += val1;
        tree[node].val += (val1*((e-s)+1));
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(s+e)/2;
    Update(left,s,mid,i,j,val1);
    Update(right,mid+1,e,i,j,val1);
    tree[node].val=tree[left].val+tree[right].val+(((e-s)+1)*tree[node].inc);
}

ll Query(int node, int s, int e, int i, int j, ll carry)
{
    if(i>e || j<s) return 0LL;
    if(i<=s && j>=e)
    {
        return tree[node].val+((e-s)+1)*carry;

    }
    int left=node*2;
    int right=left+1;
    int mid=(s+e)/2;
    ll t1=Query(left,s,mid,i,j,carry+tree[node].inc);
    ll t2=Query(right,mid+1,e,i,j,carry+tree[node].inc);

    return t1+t2;
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);

    while(t--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        Build(1,1,n);
        printf("Case %d:\n",cas++);

        while(q--)
        {
            int go;
            scanf("%d",&go);
            //cout<<"FF"<<endl;
            if(!go)
            {
                int l,r,val1;
                scanf("%d %d %d",&l,&r,&val1);
                Update(1,1,n,l+1,r+1,val1);
            }
            else
            {
                int l,r;
                scanf("%d%d",&l,&r);
                printf("%lld\n",Query(1,1,n,l+1,r+1,0LL));
            }
        }
        //cout<<"FFFFFFFFFFFFFFFFF"<<endl;
    }

    return 0;
}
