
#include <bits/stdc++.h>
#define ll long long
#define maxl 100020
using namespace std;

ll n,m,num[maxl+2],balun[maxl+2],cost[maxl+2],ans=0;

bool Possible(ll x, ll have)
{
    int i=0;
  //  cout<<"X  "<<x<<"  "<<have<<endl;
    ll r[n+2];
    memset(r,0,sizeof r);
    for( i=0; i<n; i++)
    {
        if(cost[i]==0) continue;
        if(have == 0) break;
        if(x<cost[i])
        {
            r[i]=cost[i]-x;
           // cout<<"R  "<<r[i]<<"  "<<balun[i]<<endl;
            r[i]=  ceil( (double)r[i]/ (double)balun[i]  );
         //   cout<<"R2  "<<r[i]<<endl;
            if(r[i]>have) return false;
            have= have-r[i];
            //cout<<"T  "<<r<<"  "<<cost[i]<<" "<<have<<endl;
        }

    }
    ll maxi=0;
    for(int i=0; i<n; i++)
    {
        ll tt=cost[i]-(balun[i]*r[i]);
      //  cout<<"T "<<tt<<"  "<<balun[i]<<" "<<r[i]<<endl;
        if(tt>x) return false;
        maxi=max(maxi,tt);
    }

    ans=min(ans,maxi);
    return true;
}

int main()
{
    scanf("%lld %lld",&n,&m);
    for(int i=0; i<n; i++) scanf("%lld",&num[i]);
    for(int i=0; i<n; i++) scanf("%lld",&balun[i]), cost[i]=balun[i]*num[i], ans=max(ans,cost[i]);
    //cout<<"Y  "<<Possible(1,m);
    //return 0;
    ll left=0,right=ans,mid;

    for(int i=0; i<200; i++)
    {
        mid= (left+right)/2;
        bool iff =Possible(mid,m);
    //    cout<<"Igg  "<<iff<<"  "<<mid<<endl;
        if( iff )
        {
            right=mid-1;
        }
        else left=mid+1;
    }

    printf("%lld\n",ans);

    return 0;
}
