#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        long long n;
        scanf("%lld",&n);
        double sq=sqrt(n);
        long  long s=(long long)sq;
        if( fmod(sq,1)==0 )
        {
            if(s%2==0)printf("Case %d: %lld %d\n",cas++,s,1);
            else printf("Case %d: %d %lld\n",cas++,1,s);
        }
        else
        {
            s++;
            long long start=(s-1)*(s-1)+1,r=0,c=0;
            if(s%2 != 0)
            {
                r=s,c=1;
            //    cout<<"N  "<<n<<"  "<<start<<endl;
                if(s+start-1<n) r-=n-(start+s-1), c=s;
                else c=n-start+1;
                printf("Case %d: %lld %lld\n",cas++,r,c);
            }
            else
            {
                c=s, r=1;
                if(s+start-1<n) c-=n-(start+s-1), r=s;
                else r=n-start+1;
                printf("Case %d: %lld %lld\n",cas++,r,c);
            }
        }
    }
    return 0;
}
