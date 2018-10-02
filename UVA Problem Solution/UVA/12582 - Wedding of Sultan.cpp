

#include<bits/stdc++.h>
#define maxl 500010
using namespace std;

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    int n,m;
    char s[10000];
    while(t--)
    {
        stack<char>stackk;
        map<char,int>mp;
        scanf("%s",s);
        stackk.push(s[0]);
        for(int i=1; i<(int)strlen(s); i++)
        {
            if(stackk.top() == s[i]) stackk.pop();
            else
            {
                mp[stackk.top()]++;
                mp[s[i]]++;
                stackk.push(s[i]);
            }
        }
        printf("Case %d\n",cas++);
        for(auto i=mp.begin(); i != mp.end(); i++)
        {
            printf("%c = %d\n",i->first,i->second);
        }
    }
    return 0;
}
