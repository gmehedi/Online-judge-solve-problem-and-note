
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        long long num,temp=0;
        scanf("%lld",&num);
        temp=num;
        int cnt=0;
        while(temp%2==0) temp/=2 ,cnt++;
        long long even=1,t=0;
        bool sign=false;
        for(int i=0; i<cnt; i++)
        {
            even*=2;
            t=(num/even);
            if( t%2 != 0) { sign=true; break; }
        }
        if(sign) printf("Case %d: %lld %lld\n",cas++,t,even);
        else printf("Case %d: Impossible\n",cas++);

    }
    return 0;
}
