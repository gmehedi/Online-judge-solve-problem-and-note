
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
    int val;
    int flag;
}
tree[(maxl*3)+2];
void Build(int node, int s, int e)
{
    if(s == e){ tree[node].val=st[s-1]-'0'; tree[node].flag=0; return; }
    int left=node*2;
    int right=left+1;
    int mid=(s+e)/2;
    Build(left,s,mid);
    Build(right,mid+1,e);
    tree[node].flag=0;
}
void Update(int node, int s, int e, int i, int j)
{
    if(s>j || e<i) return;
    if(s>=i && e<=j)
    {
        tree[node].flag ^= 1;
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(s+e)/2;
    Update(left,s,mid,i,j);
    Update(right,mid+1,e,i,j);
}
int ans=0;
void Quary(int node, int s, int e, int ind)
{
    if(ind>e || ind<s) return;
    if(ind<=s && ind>=e)
    {
        ans=tree[node].val;
        if(tree[node].flag) ans^=1;
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(s+e)/2;
    Quary(left,s,mid,ind);
    Quary(right,mid+1,e,ind);
    if(tree[node].flag) ans^=1;
}
void init()
{
    char tt[maxl];
    swap(st,tt);
    for(int i=1; i<=maxl; i++) tree[i].val=0,tree[i].flag=0;
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    getchar();

    while(t--)
    {
        init();
        scanf("%s",st);
        n=strlen(st);
        Build(1,1,n);

        int q;
        scanf("%d",&q);
        printf("Case %d:\n",cas++);
        while(q--)
        {
            char chos;
            scanf(" %c",&chos);
            if(chos == 'Q')
            {
                int node;
                scanf("%d",&node);
                Quary(1,1,n,node);
                printf("%d\n",ans);
            }
            else
            {
                int l,r;
                scanf("%d %d",&l,&r);
                Update(1,1,n,l,r);
            }
        }
    }

    return 0;
}
