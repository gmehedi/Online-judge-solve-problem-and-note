
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,b,t;
    cin>>t;
    while(t--)
    {
        int k,choc;
        long long ans=1,res=0;
       cin>>n>>b;
        for(int i=0; i<b; i++)
        {
            cin>>k;
            int a[k+2];
            ans=1;
            for(int i=1; i<k; i++)cin>>a[i];
            cin>>choc;
            for(int i=1; i<k; i++) ans=(ans*a[i])%n;
            res+=ans*choc%n;//cout<<a[i]<<"   "<<ans<<endl;

        } //cout<<"E  "<<res<<"   "<<choc<<endl;
        cout<<res%n<<endl;
    }
    return 0;
}
