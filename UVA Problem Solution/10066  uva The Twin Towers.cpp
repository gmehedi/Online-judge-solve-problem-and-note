
#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int n1,n2,dp[110][110];
int a1[110],a2[110];
int Dp(int i, int j)
{
    if( j>=n2 || i>=n1) return 0;
    if( dp[i][j] != -1 )return dp[i][j];
   // cout<<"cnt  "<<a1[i]<<"    "<<a2[i]<<endl;
    if( a1[i] == a2[j] )  return dp[i][j] = Dp(i+1,j+1)+1;
    int t1 = Dp(i+1,j);
    int t2 = Dp(i,j+1);
    return dp[i][j]=max(t1,t2);
}

int main()
{
    int cas=1;
    while(scanf("%d %d",&n1,&n2)==2 && n1 && n2)
    {
        memset(dp,-1,sizeof dp);
        for(int i=0; i<n1; i++)scanf("%d",&a1[i]);
        for(int i=0; i<n2; i++)scanf("%d",&a2[i]);
        printf("Twin Towers #%d\nNumber of Tiles : %d\n",cas++,Dp(0,0));
        printf("\n");
    }

  return 0;
}

