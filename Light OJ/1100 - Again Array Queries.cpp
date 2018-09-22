// M M Mehedi Hasan
// From BUBT
#include<bits/stdc++.h>
#define p1 31
#define maxl 3100
#define maxp 3100
#define ull unsigned long long
using namespace std;

int main()
{
    int t,n,q,cas=1,cnt[1010];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        int a[n+3];
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        printf("Case %d:\n",cas++);
        for(int i=0; i<q; i++)
        {
            int l,r;
            scanf("%d %d",&l,&r);
            memset(cnt,0,sizeof cnt);
            bool sign=false;
            for(int i=l; i<=r; i++)
            {
                cnt[a[i]]++;
                if(cnt[a[i]]>=2){ sign=true; break;}
            }
            if(sign){ printf("0\n"); continue; }
      //      cout<<"HGFDSAGFDS"<<endl;
            int ans=12345,previ=1001;
            for(int j=1; j<=1000; j++)
            {//cout<<"F  "<<j<<"  "<<previ<<"  "<<cnt[j]<<endl;
                if(cnt[j]>=1)
                {
                    if(previ==1001) { previ=j; continue; }

                    ans=min(ans,j-previ);
                    previ=j;
                }
            }
            printf("%d\n",ans);
        }
    }
}

