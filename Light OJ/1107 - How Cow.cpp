#include<bits/stdc++.h>
#define phi acos(-1)
using namespace std;
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        x1=min(x1,x2);
        x2=max(x1,x2);
        y1=min(y1,y2);
        y2=max(y1,y2);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",cas++);
        while(q--)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            if(x>=x1 && y>=y1 && x<=x2 && y<=y2 ) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
