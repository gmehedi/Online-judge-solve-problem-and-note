
#include<bits/stdc++.h>
#define mod 131071
using namespace std;
int main()
{
    char ch;
    while(cin>>ch)
    {
        long long m=0;
        m=( (2*m)+(ch-'0'));
        while(cin>>ch)
        {
            if(ch=='#')break;
            m= ( (2*m)+(ch-'0' ) )%mod;
          //  cout<<"M  "<<m<<endl;
        }
        m%=mod;
        if(m!=0)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        m=0;
    }
    return 0;
}
