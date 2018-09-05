//M M Mehedi Hasan
//From BUBT
#include <bits/stdc++.h>
#define N 510
#define maxp 12
using namespace std;

int n,q,a[N][N];
int stable[N][16][N];

void build_table()
{
    for( int p=1; p<=maxp; p++)
    {
        for(int i=0; i+(1<<p)<=n; i++)
        {
            for(int j=0; j+(1<<p)<=n; j++)
            {
                int t1= max( stable[i][p-1][j],stable[i][p-1][j+(1<<p-1)] );
                int t2= max( stable[i+(1<<p-1)][p-1][j],stable[i+(1<<p-1)][p-1][j+(1<<p-1)] );
                stable[i][p][j]= max(t1,t2);
            }
        }
    }
}

int main()
{   //cout<<log2(500)<<endl;
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++) scanf("%d",&a[i][j]), stable[i][0][j]=a[i][j];
        }

        build_table();

        printf("Case %d:\n",cas++);
        for(int i=0; i<q; i++)
        {
            int l,r,s;
            scanf("%d %d %d",&l,&r,&s);
            l--;
            r--;
            int p=log2(s);
            int hp=(1<<p);
            int max1= max(stable[l][p][r],stable[l][p][r+s-hp]);
            int max2 =max(stable[l+s-hp][p][r],stable[l+s-hp][p][r+s-hp]);
            printf("%d\n",max( max1,max2 ) );

        }
    }
    return 0;
}
