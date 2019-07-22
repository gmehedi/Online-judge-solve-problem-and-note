
#include<bits/stdc++.h>
#define maxi 50000
using namespace  std;

int main()
{
    long long n;
  //  cout<<sqrt(2025)<<"  "<<45*45;
    while( scanf("%lld",&n),n )
    {
        long long temp=n;
        bool b=true;
        if(n<0) temp=n*-1;//cout<<"H  "<<n*-1<<endl;
        int t=sqrt(temp);
      //  cout<<"tt   "<<t<<endl;
        for(int i=2; i<=t; i++)
        {
            temp=abs(n);
            map<int,int>mp;
            if( temp%i==0) while(temp%i==0) mp[i]++ ,temp/=i;
            if(temp>1)mp[temp]++;
            if((int)mp.size() ==1 && temp==1 && n>=0|| (n<0 && (int)mp[i]%2) ) { printf("%d\n",mp[i]); b=false; break; }
        }
        if(b) printf("1\n");
    }
        return 0;
}
