#include<bits/stdc++.h>
#define maxi 46345
using namespace std;
bitset<46346>b;
int prime[10000];
int k=1;
void Prime()
{
   // prime[0]=2;
    for(int i=2; i*i<=maxi; i++) if( !b[i]) for(int j=i+i; j<=maxi; j+=i ) b[j]=true;
    k=0;
    for(int i=2; i<=maxi; i++)if( !b[i] ) prime[k++]=i;//cout<<"I  "<<i<<endl;
    prime[k++]=INT_MAX;
}
vector<int>v;
map<int,int>cnt;

void Store(int temp)
{ //cout<<"T  "<<temp<<"  "<<prime[0]<<"  "<<prime[1]<<"  "<<INT_MAX<<endl;
    for(int i=0; prime[i]*prime[i]<=temp && i<k; i++)
    {//cout<<"H   "<<prime[i]<<endl;
        bool b=true;
        while(temp%prime[i]==0)
        {
            if(b)v.push_back(prime[i]),b=false;
            cnt[prime[i]]++;
            temp/=prime[i];
        }
    }
    if(temp>1) v.push_back(temp),cnt[temp]++;
}

int main()
{
    int n;
    Prime();
    while(scanf("%d",&n)==1,n)
    {
       // memset(cnt,0,sizeof cnt);
        long long tempn=0;
        int temp=powl(2,n)-1;
        tempn=temp;
        Store(temp);
        temp=powl(2,n-1);
        tempn=tempn*temp;
     //   cout<<"T  "<<tempn<<endl;
        Store(temp);
        long long ans=1;
        for(int i=0; i<(int)v.size(); i++)
        {   //cout<<"B "<<v[i]<<"     "<<cnt[v[i]]<<endl;
            int p=v[i],k=cnt[v[i]];
            if( cnt[v[i]]>0 ) ans*=( powl(p,(k+1))-1)/(p-1);//cout<<"A   "<<ans<<endl;
        }
       // cout<<"A  "<<ans<<" "<<tempn<<endl;
        if(ans/2 == (tempn)) printf("Perfect: %lld!\n",tempn);
        else if(!b[n]) printf("Given number is prime. But, NO perfect number is available.\n");
        else printf("Given number is NOT prime! NO perfect number is available.\n");
        v.clear();
        cnt.clear();

    }
    return 0;
}
