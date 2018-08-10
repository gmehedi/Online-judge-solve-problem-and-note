#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,temp;
        scanf("%d %d",&n,&m);
        long long a[n+3];
        int ind=n-1;
        for(int i=0; i<n; i++) scanf("%lld",&a[i]);

        int rev=1;
       // cin.ignore();
        char c;
        for(int i=0; i<m; i++)
        {
            cin>>c;
            if(c=='R') { rev++; continue; }
            cin>>temp;
            if(c=='S')
            {
                for(int i=0; i<n; i++) a[i]+=temp;
            }
            if(c=='M')
            {
                for(int i=0; i<n; i++) a[i]*=temp;
            }
            if(c=='D')
            {
                for(int i=0; i<n; i++) a[i]/=temp;
            }
            if(c=='P')
            {
                int j;
                scanf("%d",&j);
                if(rev%2 !=0) swap(a[temp],a[j]);
                else swap(a[ind-temp],a[ind-j]);
            }
        }
        printf("Case %d:\n",cas++);
        if(rev%2==1)
        {
            for(int i=0; i<n; i++)
            {
                if(i==0) printf("%lld",a[i]);
                else printf(" %lld",a[i]);
            }
            printf("\n");
        }
        else
        {
             for(int i=ind; i>=0; i--)
            {
                if(i==ind) printf("%lld",a[i]);
                else printf(" %lld",a[i]);
            }
            printf("\n");
        }
       // cout<<"T  "<<t<<endl;
    }
    return 0;
}
