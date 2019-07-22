
#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>v;
int dp[10010][110];
int Dp(int pos, int mod)
{//cout<<"M  "<<mod<<endl;
    if(pos>=n) if(mod==0)  return 1;else return 0;
    if( dp[pos][mod] != -1 ) return dp[pos][mod];
    int check=Dp( pos+1, ( ( (v[pos]+mod) % k)+k) %k );
    check|=Dp( pos+1, ( ( (v[pos]-mod) % k)+k) %k );
    return dp[pos][mod]=check;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int temp;
        memset(dp,-1,sizeof dp);
        scanf("%d%d",&n,&k);
        for(int i=0; i<n; i++) scanf("%d",&temp),v.push_back(temp);
       if( Dp(0,k) )printf("Divisible\n");
       else printf("Not divisible\n");
        v.clear();
    }
    return 0;
}
