
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
#define maxl 100001
#define psz 20
using namespace std;
int n,q;

struct str
{
    ll sum;
    ll prop;
}
tree[maxl*4+2];

void Build(int node, int s, int e)
{//cout<<"S  "<<s<<"  "<<e<<endl;
    if(s == e)
    {
        tree[node].sum=0LL;
        tree[node].prop=-1LL;
        return;
    }
    int mid=(s+e)/2;
    int left=node*2;
    int right=left+1;
    Build(left,s,mid);
    Build(right,mid+1,e);

    tree[node].sum=0LL, tree[node].prop=-1LL;
}
void Go_front(int node, int s, int e, int p)
{   //cout<<"SSS  "<<s<<"  "<<e<<endl;
    if(s == e)
    {
       // cout<<"Q  "<<node<<"  "<<p<<endl;
        tree[node].sum=p;
        tree[node].prop=p;
        return;
    }

    int mid=(s+e)/2;
    int left=node*2;
    int right=left+1;
//cout<<"GO  "<<tree[node].prop<<" "<<left<<"  "<<right<<endl;
    tree[left].prop=p;
    tree[left].sum=p*(mid-s+1);

    tree[right].prop=p;
    tree[right].sum=p*(e-mid);

    tree[node].prop=-1LL;

    tree[node].sum = tree[left].sum+tree[right].sum;

    return;
}
void Update(int node, int s, int e, int i, int j, int p)
{
    if(i>e || j<s) return;
    if(s>=i && e<=j)
    {
     //   cout<<"BB  "<<node<<endl;
        Go_front(node,s,e,p);
        return;
    }
    int mid=(s+e)/2;
    int left=node*2;
    int right=left+1;
    if(tree[node].prop != -1LL) Go_front(node,s,e,tree[node].prop);

    Update(left,s,mid,i,j,p);
    Update(right,mid+1,e,i,j,p);

    tree[node].sum=tree[left].sum+tree[right].sum;
    //cout<<"Node  "<<tree[node].sum<<" "<<s<<" "<<e<<endl;
    //cout<<"L  "<<tree[left].sum<<"  "<<left<<endl;
    //cout<<"R   "<<tree[right].sum<<"  "<<right<<endl;
}

ll Querie(int node, int s, int e, int i, int j)
{
    if(i>e || j<s) return 0LL;
    if(s>=i && e<=j)
    {
       // cout<<"T  "<<tree[node].sum<<"  "<<s<<"  "<<e<<endl;
        return tree[node].sum;
    }
    int mid=(s+e)/2;
    int left=node*2;
    int right=left+1;

    if(tree[node].prop != -1LL) Go_front(node,s,e,tree[node].prop);
    ll t2=Querie(left,s,mid,i,j);
    ll t1=Querie(right,mid+1,e,i,j);

    return t1+t2;
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        Build(1,1,n);
        printf("Case %d:\n",cas++);

        while(q--)
        {
            int choose;
            scanf("%d",&choose);
            if(choose == 1)
            {
                int l,r,v;
                scanf("%d%d%d",&l,&r,&v);
                l++, r++;
                Update(1,1,n,l,r,v);
            }
            else
            {
                int l,r;
                scanf("%d %d",&l,&r);
                l++, r++;
                ll tot=Querie(1,1,n,l,r);
                ll nt=r-l+1;
              //  cout<<"R  "<<tot<<"  "<<nt<<endl;
                if(tot%nt == 0) printf("%lld\n",tot/nt);
                else
                {
                    ll gcd=__gcd(tot,nt);
                //    cout<<"G  "<<gcd<<"  "<<nt<<"  "<<nt/gcd<<endl;
                    ll tt1=tot/gcd, tt2=nt/gcd;
                    printf("%lld/%lld\n",tt1,tt2);
                }
               // cout<<"R  "<<tot<<"  "<<nt<<endl;
            }
        }
    }
    return 0;
}





