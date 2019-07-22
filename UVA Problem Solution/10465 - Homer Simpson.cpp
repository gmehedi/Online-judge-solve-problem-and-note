#include<bits/stdc++.h>
#define N 10100
using namespace std;
int n,m,mini=123456,temp=0;
int dp[N];

int Dp(int t)
{
    if(t==0)
    {
         return dp[t]=0;
    }

    if(t<0)
    {
        mini=min(mini,temp);
        return -123456;
    }
    if(dp[t] != -1)return dp[t];
    temp=t;
    int r1=Dp(t-m)+1;
    int r2=Dp(t-n)+1;

    return dp[t]=max(r1,r2);
}

int main()
{
    int t;
    while( scanf("%d%d%d",&m,&n,&t) !=EOF )
    {
        memset(dp,-1,sizeof dp);
        temp=0;
        mini=123456;
        int res=Dp(t);

        if(res>=0)
        cout<<res<<endl;
        else
        {  // cout<<"M     "<<mini<<"              "<<t<<endl;
            int t2=mini;
            memset(dp,-1,sizeof dp);
            cout<<Dp(t-mini)<<" "<<t2<<endl;

        }

    }
    return 0;
}
