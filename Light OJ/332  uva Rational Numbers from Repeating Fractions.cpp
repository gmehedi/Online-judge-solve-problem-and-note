
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,cas=0;
    int din[15],p=0,q=0;
    din[0]=1;
    for(int i=1; i<=9; i++) din[i] = din[i-1]*10;
    while( scanf("%d",&n) && n>=0 )
    {
        string s;
        getline(cin,s);
        bool b=false;
        int f=0,k=0;
        for(int i=0; i<(int)s.size(); i++)
        {
            if( b ) f=(f*10)+(s[i]-'0'),k++; //cout<<s[i]<<"   "<<f<<endl;
            if( s[i]=='.' ) b=true;
        }
       // cout<<"F  "<<f<<"   "<<din[n]<<endl;
        k=k-n;
        if( n>0 ){ p = f - (f/din[n]), q=din[k+n]-din[k]; }
        else p=f,q=din[k+n];
        int gcd=__gcd(p,q);
        printf("Case %d: %d/%d\n", ++cas, p/gcd, q/gcd);

    }

}
