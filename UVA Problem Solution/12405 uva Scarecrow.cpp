

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        getchar();
        string s;
        getline(cin,s);
        long long cnt=0;
        for(int i=0; i<n; i++) if(s[i]=='.') cnt++, i+=2;
        printf("Case %d: %lld\n",cas++,cnt);
    }
    return 0;
}
