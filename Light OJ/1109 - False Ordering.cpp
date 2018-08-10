#include<bits/stdc++.h>
using namespace std;
struct str
{
    int n1;
    int t;
};

bool compare(str x, str y)
{
    if(x.t==y.t && x.n1>y.n1) return x.n1>y.n1;
    return x.t<y.t;
}

vector<str>v;
void store()
{
    for(int i=1; i<=1000; i++)
    {
        int cnt=0;
        for(int j=1; j*j<=i; j++)
        {
            if(i%j==0)
            {
                if( (i/j) != j) cnt+=2;
                else cnt++;
            }
        }
        v.push_back( {i,cnt} );
    }
}
int main()
{
    int t,cas=1;
    store();
    sort(v.begin(),v.end(),compare);
    //for(int i=0; i<100; i++)cout<<"F    "<<v[i].n1<<"  "<<v[i].t<<endl;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: %d\n",cas++,v[n-1].n1);
    }
    return 0;
}
