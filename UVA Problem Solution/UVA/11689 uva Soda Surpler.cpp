
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    long long cnt=0;
    for(int i=0; i<t; i++)
    {
        int a,b,c;
        cnt=0;
        cin>>a>>b>>c;
        cnt+=a/c;
        int r=(a%c)+a/c;
       // cout<<" R  "<<r<<endl;
        r+=b;
        while(1)
        {
            if(r/c==0) break;
            cnt+=r/c;
            r=(r%c)+r/c;
       //     cout<<"T  "<<r<<endl;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
