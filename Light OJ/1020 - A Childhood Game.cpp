
#include<bits/stdc++.h>
#define sf(a)            scanf("%d",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define x first
#define y second
using namespace std;

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        char s[10];
        scanf("%d %s",&n,s);
        printf("Case %d: ",cas++);
        n=n%3;
        if(s[0]=='A')
        {
           if(n != 1) printf("Alice\n");
            else printf("Bob\n");
        }
        else
        {
            if(n == 1 || n == 2)  printf("Bob\n");
            else printf("Alice\n");
        }

    }
   return 0;
}
