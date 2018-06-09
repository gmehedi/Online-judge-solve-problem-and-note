
#include<bits/stdc++.h>
using namespace std;
int main()
{
   // cout<<ceil(5.10)<<"  "<<floor(5.10)<<endl;
    long long n;
    while(scanf("%lld",&n)==1 && n!=0 )
    {
        double d=sqrt(n);
        int t1=ceil(d);
        int t2=floor(d);
        if(t1==t2 || n ==1)
        {
            cout<<"yes"<<endl;
        }
        else cout<<"no"<<endl;

    }
    return 0;
}
