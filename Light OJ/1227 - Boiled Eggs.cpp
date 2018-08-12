
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,p,q;
        scanf("%d %d %d",&n,&p,&q);
        int a[n+2];
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        int cnt=0;
        long long sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=a[i];
            if(sum>q || cnt>=p) break;
            cnt++;
        }
        printf("Case %d: %d\n",cas++,cnt);
    }
    return 0;
}
