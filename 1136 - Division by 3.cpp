#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int l,r,start=0,finish=0,ans=0;
        scanf("%d %d",&l,&r);
        if(l>r) swap(l,r);
        if(l==r)
        {
            if(l%3==0|| (l+1)%3==0)
            {
                printf("Case %d: %d\n",cas++,1);
            }
            else printf("Case %d: %d\n",cas++,0);
            continue;
        }
        if(abs(l-r)==1)
        {
            if(r%3==0) printf("Case %d: %d\n",cas++,2);
            else printf("Case %d: %d\n",cas++,1);
            continue;
        }
        if(l%3==0) start=l;
        else
        {
            start= l/3;
             start *=3;
             start+=3;
             ans++;
        }
        if(r%3==0) finish=r;
        else
        {
            finish= r/3;
            finish *=3;
            finish+=3;
            ans-=abs(r-finish);
        }
        ans++;
        int td=abs(finish-start);
        td--;
        int t1=(td/3);
        ans=ans+((td-t1));
        printf("Case %d: %d\n",cas++,max(0,ans));
    }
    return 0;
}
