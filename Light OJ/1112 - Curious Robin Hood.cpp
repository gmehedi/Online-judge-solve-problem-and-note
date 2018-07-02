

#include<bits/stdc++.h>
#define N 100001
using namespace std;
int a[N],t,t1,n,q,cas=0;
int64_t tree[N*3];
int Build(int node, int s, int e)
{
    if(s==e)return tree[node]=a[s];
    int mid = (s+e)/2,left=node*2,right=node*2+1;
    Build(left,s,mid);
    Build(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
    return tree[node];

}

int Update(int node, int s, int e, int i,int value)
{
    if(e<i || s>i) return 0;
    if(i<=s && e<=i)
    {
        if(value==0)
        {
         //   cout <<"T  "<<tree[s]<<endl;
              t1=tree[node];
              tree[node]=0;
              return 0;
        }
        else
        {
            //cout <<"H  "<<value+tree[node]<<endl;
         return  tree[node]=tree[node]+value;
        }

    }

    int mid = (s+e)/2,left=node*2,right=node*2+1;
    Update(left,s,mid,i,value);
    Update(right,mid+1,e,i,value);
    tree[node]=tree[left]+tree[right];
    if(value==0) return t1;
}

int Quary(int node ,int s, int e, int i, int j)
{
    if(i>e || j<s) return 0;
    if(i<=s && j>=e) return tree[node];
    int mid = (s+e)/2;
    int left=node*2,right=node*2+1;
    int p1 = Quary(left,s,mid,i,j);
    int p2 = Quary(right,mid+1,e,i,j);

    return p1+p2;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(int i=0; i<n; i++) scanf("%d",&a[i]);

        Build(1,0,n-1);
        printf("Case %d:\n",++cas);

         for(int i=0; i<q; i++)
         {

             int temp;
             scanf("%d",&temp);
             if(temp==1)
             {
                 int index;
                 scanf("%d",&index);
                 printf("%d\n",Update(1,0,n-1,index,0));
             }
             else if(temp==2)
             {
                 int value,index;
                 scanf("%d%d",&index,&value);
                 Update(1,0,n-1,index,value);
             }
             else if(temp==3)
             {
                 int start,endd;
                 scanf("%d%d",&start,&endd);
                 printf("%d\n",Quary(1,0,n-1,start,endd));
             }

         }


    }


    return 0;
}
