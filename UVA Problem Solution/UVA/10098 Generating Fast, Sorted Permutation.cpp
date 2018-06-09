#include<bits/stdc++.h>
using namespace std;
char s[1000];
set<string>sett;
int main()
{
    int t;
    scanf("%d ",&t);
    while(t--)
    {

        gets(s);
        int l=strlen(s);
        sort(s,s+l);
        do
        {
            printf("%s\n",s);
        }
        while(next_permutation(s,s+l));
        printf("\n");
    }
    return 0;
}
