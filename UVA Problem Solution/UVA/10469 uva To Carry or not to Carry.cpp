
#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n1,n2;
    while( scanf("%lld%lld",&n1,&n2) != EOF )
    {
        bitset<64>b1(n1);
        bitset<64>b2(n2);
        long long sum=0;
        b1=b1^b2;
        sum=b1.to_ullong();
        cout<<sum<<endl;
    }

    return 0;
}
