#include<bits/stdc++.h>
#define N 100010
using namespace std;
int t,n,q;
int a[N];
int64_t tree[N*3];
int Build(int node, int s, int e)
{
    if(s==e)
    {
        return tree[node]=a[s];
    }
    int mid = (s+e)/2;
    int left=2*node,right=2*node+1;
    Build(left,s,mid);
    Build(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
 //  tree[node]=tree[left]+tree[right];

    return tree[node];
}

int Quary(int node, int s,int e,int i,int j)
{
    if(i>e || j<s) return INT_MAX;
    if(s>=i && e<=j)
    {
        return tree[node];
        //cout <<"T "<<tree[node];
    }
    int mid=(s+e)/2;
    int left=2*node,right=2*node+1;

   int p1= Quary(left,s,mid,i,j);
   int p2=Quary(right,mid+1,e,i,j);
  // cout <<"P  "<<p1<<"   "<<p2<<endl;
   return min(p1,p2);



}
int main()
{

    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
      //  printf("\n");
        scanf("%d %d",&n,&q);

        for(int i=1; i<=n; i++) scanf("%d",&a[i]);
        Build(1,1,n);
        printf("Case %d:\n",++cas);
        for(int h=1; h<=q; h++)
        {
            int i,j;
            scanf("%d%d",&i,&j);
            printf("%d\n",Quary(1,1,n,i,j));
        }

    }
    return 0;
}
