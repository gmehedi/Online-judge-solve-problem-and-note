#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        long long a[4];
        scanf("%lld %lld %lld",&a[0],&a[1],&a[2]);
        sort(a,a+3);
        if( (long long) (powl(a[0],2)+powl(a[1],2)) == (long long)powl(a[2],2) ) printf("Case %d: yes\n",cas++);
        else printf("Case %d: no\n",cas++);
    }
    return 0;
}
