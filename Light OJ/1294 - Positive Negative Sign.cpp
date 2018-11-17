
#include<bits/stdc++.h>
#define ll long long
#define maxl 10000010
using namespace std;


ll Solve(ll n, ll m)
{
    ll first=m*(m+1)/2;
    ll dif=(m*((2*m)+1))-first-first;

  //  cout<<"F  "<<first<<"  "<<dif<<endl;
    n=n/m;
    ll minu=(n/2)+(n%2);
    ll plu=n/2;

    ll totalpl=0,totalmi=0;

    totalmi+=(first*minu);

    totalpl+=(first*plu);
    minu--;

    ll temp=0,temp1=0;
    temp=plu*plu;
   // cout<<"M "<<minu<<endl;
    if(minu > 0)temp1=(((minu*2)+2)/2)-1;
    temp1= (temp1*(temp1+1));

   // cout<<"T  "<<temp<<" "<<dif<<"  "<<temp1<<endl;
    totalmi += (temp1*dif);
    totalpl += temp*dif;
  //  cout<<"T1  "<<totalpl<<"  "<<totalmi<<" "<<dif<<endl;
    return (-1*totalmi)+(totalpl);
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);

    while(t--)
    {
        ll n,m;
        scanf("%lld %lld",&n,&m);
        printf("Case %d: %lld\n",cas++,Solve(n,m));
    }

    return 0;
}
