#include<bits/stdc++.h>
using namespace std;
int n,store[210][210],dp[210][210],k=0;
int banana(int i, int j)
{
        if( i>=2*n-1 ) return 0;

        if(dp[i][j] != -1)return dp[i][j];
           if(store[i][j]==0)return 0;
          int p1=-1;
         //  cout <<"P    "<<p1<<endl;
           p1=max(p1,banana(i+1,j)+store[i][j]);
           if(i<n-1)
           p1 = max(p1,store[i][j]+banana(i+1,j+1));
           else p1= max(p1,store[i][j]+banana(i+1,j-1));

            dp[i][j]=p1;
            return dp[i][j];

}

int main()
{
    int t,cas=1;
    cin >>t;
   // memset(store,0,sizeof store);
    while(t--)
    {
         memset(store,0,sizeof store);
        memset(dp,-1,sizeof dp);
        cin >>n;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=i; j++)cin >>store[i][j];
          //  cout <<"I"<<endl;
        }
        k=n-1;
        for(int i=n; i<2*n-1; i++,k--)
        {
            for(int j=0; j<k; j++)cin >>store[i][j];
        }


          printf("Case %d: %d\n",cas++,banana(0,0));

    }


}


