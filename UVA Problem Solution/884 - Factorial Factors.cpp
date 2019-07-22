
#include <bits/stdc++.h>
#define N 1000001
#define N1 2000
using namespace std;
int prime[1000],t=0,cnt=0,n;
int64_t total[N];
bool sign[N1];
void Seive()
{
    int k=1;
    prime[0]=2;
    for(int i=3; i<=N1; i+=2)
    {
        if(sign[i])
            for(int j=i*i; j<=N1; j+=i*2) sign[j]=false;
    }
    for(int i=3; i<=N1; i+=2)
    {
        if(sign[i]) prime[k++]=i;// cout <<"I "<<prime[k-1]<<endl;}
     }

}
vector<int>v;
void Cnt()
{
    v.push_back(1);
    v.push_back(1);
    for(int j=4; j<=N; j++)
    {
        cnt=0;
        int t=j;
  //cout <<j<<endl;
        for(int i=0; ( prime[i]*prime[i] ) <= t; i++)
        {
           // cout <<prime[i]<<endl;
            while( !(t%prime[i]) )
            {
                cnt++;
                t/=prime[i];
            }
        }
        if(t>1) cnt++;
        v.push_back(cnt);
    }

    total[2]=1;
    for(int i=3; i<N; i++)
    {
        total[i] = total[i-1]+v[i-2];
    }


}
int main()
{
    memset(sign,true,sizeof sign);
    Seive();
    Cnt();

    while(scanf("%d",&n) != EOF)
    {
        cout <<total[n]<<endl;
    }

    return 0;
}

