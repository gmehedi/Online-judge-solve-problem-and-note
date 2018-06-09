#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000],cut[110],n;

int Dp(int i, int j)
{
    if(i+1==j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int  ans=INT_MAX;
    //cout<<"C  "<<cut[j]-cut[i]<<endl;
    for(int k=i+1; k<j; k++)
    ans=min(ans,cut[j]-cut[i]+Dp(i,k)+Dp(k,j));
    dp[i][j]=ans;
    return ans;

}
int main()
{
    int l;
    while(scanf("%d",&l)==1 && l)
    {
        scanf("%d",&n);
        memset(dp,-1,sizeof dp);
        cut[0]=0;
        for(int i=1; i<=n; i++) scanf("%d",&cut[i]);
        cut[n+1]=l;
        printf("The minimum cutting is %d.\n",Dp(0,n+1));

    }
}

