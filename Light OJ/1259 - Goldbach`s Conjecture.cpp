
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxi 10000000
#define mod 1000000007
using namespace std;
bitset<maxi+2>b;
vector<int>prime,res;
int k=0;
void Prime()
{
    b[0]=true;
    for(int i=2; i*i<=maxi; i++) if(!b[i]) for(int j=i*i; j<=maxi; j=j+i )b[j]=true;
    k=0;
    for(int i=2; i<=maxi; i++)if(!b[i] ) prime.push_back(i),k++;
}



int main()
{
    int t,cas=1;
    Prime();
    scanf("%d",&t);

    while(t--)
    {
        int n,ans=0;
        scanf("%d",&n);
        int half=n/2;
        for(int i=0; prime[i]<=half && i<k; i++)
        {
            if(!b[n-prime[i]] ) ans++;
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
