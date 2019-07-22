
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
     vector<int>v;
    while( scanf("%d",&n) != EOF)
    {
        v.push_back(n);
        int si = v.size();
        sort(v.begin(),v.end());
        if(si % 2==0)printf("%d\n",(v[ (si/2)-1 ]+v[si/2])/2);
        else printf("%d\n",v[si/2]);
    }


    return 0;
}
