
#include<bits/stdc++.h>
using namespace std;
#define MOD 100000007
int  dp[52][1010],ans=0, p[55],v[55],n,k;
int recur(int taken,int pos)
{
   // cout <<"FF11"<<endl;
    if(taken == k)return 1;
    if( taken > k || pos == n)return 0;
    if(dp[pos][taken] != -1)return dp[pos][taken];

          int takc =0,ans=0;
         //cout <<"S!!"<<endl;
        for(int i=0; i<p[pos]; ++i)
        {
             takc+= v[pos];
             ans += recur( takc+taken, pos+1);
             ans  %= MOD;
        }

      ans += recur( taken, pos+1);
      ans  %= MOD;



    return dp[pos][taken] = ans;

}
int main()
{
    int t,Case=0;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        for(int i=0; i<n; i++)   scanf("%d", &v[i]);
        for(int i=0; i<n; i++)   scanf("%d", &p[i]);
        memset( dp,-1,sizeof dp );
        printf("Case %d: %d\n", ++Case, recur(0, 0));



    }



    return 0;
}
