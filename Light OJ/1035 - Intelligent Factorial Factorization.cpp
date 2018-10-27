
#include<bits/stdc++.h>
#define ll long long
#define maxl 101
using namespace std;

int factor[110][110]={0};
void Store( )
{
    for(int i=2; i<=100; i++)
    {
        int temp=i,cnt=0;
        while(temp%2 ==0) temp/=2, cnt++;
        if(cnt>0) factor[i][2] = cnt;

        for(int j=3; j<=100; j+=2)
        {
            cnt=0;
            if(temp<j) break;
            while(temp%j == 0) temp/=j, cnt++;
            if(cnt > 0) factor[i][j] = cnt;
        }
        if(temp > 1) factor[i][temp] = 1;
    }

    for(int i=2; i<=100; i++) for(int j=2; j<=100; j++) factor[i][j] += factor[i-1][j];

}
int main()
{
    int t,cas=1;
    Store();

    scanf("%d",&t);
    while(t--)
    {
       int n;
       scanf("%d",&n);
     //   Case 2: 3 = 2 (1) * 3 (1)
       printf("Case %d: %d = ",cas++,n);

       bool sign=false;
       int num=n;

       for(int i=2; i<=n; i++)
       {
          int tot=factor[n][i];
          if(tot == 0) continue;

          if( sign ) printf(" * %d (%d)",i,tot);
          else printf("%d (%d)",i,tot), sign=true;
       }
       printf("\n");
    }
    return 0;
}
