
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long z,i,m,l;
    bool b[1000000];
    int sign[100000];
    int cas=1;
    while(cin>>z>>i>>m>>l,z,i,m,l)
    {
        memset(b,true,sizeof b);
        int cnt=1;
        b[l]=false;
        sign[l]=0;
        int k=1;
        while(1)
        {
            l = ((z*l)+i)%m;
           // cout<<"L    "<<l<<endl;
            if(b[l])cnt++,b[l]=false,sign[l]=k;
            else
            {
                break;
            }
        }
        cout<<"Case "<<cas<<": "<<cnt-sign[l]<<endl;
        cas++;
    }
    return 0;
}
