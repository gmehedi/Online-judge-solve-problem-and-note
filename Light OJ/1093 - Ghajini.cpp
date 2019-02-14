
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
int n,d;
struct str
{
    int maxv;
    int minv;
}
tree[(maxl*3)+2];
int a[maxl+2];
void Build(int node, int s, int e)
{
    if(s == e){ tree[node].maxv=a[s]; tree[node].minv=a[s]; return; }
    int left=node*2;
    int right=left+1;
    int mid=(s+e)/2;
    Build(left,s,mid);
    Build(right,mid+1,e);
    tree[node].maxv=max(tree[left].maxv,tree[right].maxv);
    tree[node].minv=min(tree[left].minv,tree[right].minv);
}

int MAX(int node, int s, int e, int i, int j)
{
    if(s>j || i>e) return 0;
    if(s>=i && e<=j)
    {
      //  cout<<"R  "<<i<<" "<<j<<" "<<tree[node].maxv<<endl;
        return tree[node].maxv;
    }
    int left=node*2;
    int right=left+1;
    int mid=(s+e)/2;
    int t1=MAX(left,s,mid,i,j);
    int t2=MAX(right,mid+1,e,i,j);

    return max(t1,t2);
}
int MIN(int node, int s, int e, int i, int j)
{
    if(s>j || i>e) return 1e9;
    if(s>=i && e<=j)
    {
        return tree[node].minv;
    }
    int left=node*2;
    int right=left+1;
    int mid=(s+e)/2;
    int t1=MIN(left,s,mid,i,j);
    int t2=MIN(right,mid+1,e,i,j);

    return min(t1,t2);
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&d);
        for(int i=1; i<=n; i++) scanf("%d",&a[i]);
        Build(1,1,n);
        int ans=0;
        for(int i=1; i<=n-d+1; i++)
        {
            int res=abs(MAX(1,1,n,i,i+d-1)-MIN(1,1,n,i,i+d-1));
            ans=max(ans,res);
        }
        printf("Case %d: %d\n",cas++,ans);
    }

    return 0;
}
