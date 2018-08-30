
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int r1,r2,c1,c2;
        cin>>r1>>c1>>r2>>c2;
        int t1=abs(r1-r2);
        int t2=abs(c1-c2);
        int t3=t1%2;
        int t4=t2%2;
        if(t3 != t4)
        {
            printf("Case %d: impossible\n",cas++);
        }
        else
        {
            if(t1==t2)printf("Case %d: 1\n",cas++);
            else printf("Case %d: 2\n",cas++);
        }
    }
    return 0;
}
