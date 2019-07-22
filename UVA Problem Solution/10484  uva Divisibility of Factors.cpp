#include<bits/stdc++.h>
using namespace std;

int prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29 ,31, 37, 41, 43,
47, 53, 59, 61, 67, 71, 73, 79, 83 ,89, 97, 101, 103, 107};
int countt[120];

void factor_of_n(int n)
{
    for(int i=0; prime[i]<=n; i++)
    {
        int k=prime[i],cnt=0;
        while( k<=n )cnt+=n/k,k*=prime[i];
        countt[prime[i]]+=cnt;
    }
}
int factor_of_d(int d)
{
    int k=d;
    for(int i=0; prime[i]<=100 && prime[i]*prime[i]<=d; i++)
    {
        int cnt=0;
        if(!(d%prime[i]) )
        {
            while( !(d%prime[i]) ) cnt++,d/=prime[i];
            countt[prime[i]]-=cnt;
        }
    }
    if(d>100)return 1;
    if(d>1)countt[d]-=1;
    return 0;
}
int main()
{
    int n,d;
    while(scanf("%d %d",&n,&d) )
    {
        if(n==0 && d==0) break;

        if(n==0)
        if(d==1) { printf("1\n"); continue; }
        else { printf("0\n"); continue; }

        memset(countt,0,sizeof countt);
        bool b=true;
        long long ans=1;
        factor_of_n(n);
      //  cout<<"G"<<endl;
        int check = factor_of_d(d);
    //   cout<<"FFF"<<endl;
        if(check) { printf("0\n"); continue; }
        for(int i=0; prime[i]<=100; i++)
        {
            if( countt[ prime[i]]<0 ) { printf("0\n"); b=false; break; }
            if(countt[ prime[i] ]>0) ans *= (countt[prime[i]]+1);
        }
        if(b)printf("%lld\n",ans);
    }
    return 0;
}
