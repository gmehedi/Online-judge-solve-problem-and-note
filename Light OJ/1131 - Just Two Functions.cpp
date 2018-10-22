

#include<bits/stdc++.h>
#define maxl 6
#define ll long long
#define ull unsigned long long
using namespace std;

ull a1,b1,c1,a2,b2,c2,g0,g1,g2,f0,f1,f2,q,mod,cas=1,n,t;

struct matrix
{
    ull a[maxl][maxl];
    matrix()
    {
        memset(a,0,sizeof a);
    }
    void init()
    {
        a[0][0]=a1, a[0][1]=b1, a[0][2]=0, a[0][3]=0, a[0][4]=0, a[0][5]=c1,
        a[1][0]=1, a[1][1]=0, a[1][2]=0, a[1][3]=0, a[1][4]=0, a[1][5]=0,
        a[2][0]=0, a[2][1]=1, a[2][2]=0, a[2][3]=0, a[2][4]=0, a[2][5]=0,
        a[3][0]=0, a[3][1]=0, a[3][2]=c2, a[3][3]=a2, a[3][4]=b2, a[3][5]=0,
        a[4][0]=0, a[4][1]=0, a[4][2]=0, a[4][3]=1, a[4][4]=0, a[4][5]=0,
        a[5][0]=0, a[5][1]=0, a[5][2]=0, a[5][3]=0, a[5][4]=1, a[5][5]=0;

    }

    matrix operator* ( matrix temp )
    {
        matrix res;
        for(int i=0; i<maxl; i++)
        {
            for(int j=0; j<maxl; j++)
            {
                res.a[i][j]=0;
                for(int k=0; k<maxl; k++)
                {//cout<<"Ttt  "<<temp.a[i][k]<<"  "<<a[k][j]<<endl;
                    res.a[i][j] = res.a[i][j]+ (temp.a[i][k]*a[k][j]%mod);
                }
            }
        }
        return res;
    }

};

matrix Power(matrix mat, ull n)
{
    if(n == 1) return mat;

    matrix res = Power(mat,n/2);
    res = res*res;
    if( (n%2) == 1 ) res= res*mat;

    return res;
}

matrix Matrix_Expo(matrix mat, ull n)
{
    matrix res = Power(mat,n);
    return res;
}

int main()
{
    struct matrix mat;

    scanf("%llu",&t);

    while(  t-- )
    {

        scanf("%llu %llu %llu",&a1,&b1,&c1);
        scanf("%llu %llu %llu",&a2,&b2,&c2);
        scanf("%llu %llu %llu",&f0,&f1,&f2);
        scanf("%llu %llu %llu",&g0,&g1,&g2);
        scanf("%llu",&mod);

        mat.init();

        scanf("%llu",&q);
        printf("Case %llu:\n",cas++);

        while( q-- )
        {
            scanf("%llu",&n);
            if(n<=2)
            {
                if(n == 0) printf("%llu %llu\n",f0%mod, g0%mod);
                else if(n == 1) printf("%llu %llu\n",f1%mod, g1%mod);
                else printf("%llu %llu\n",f2%mod, g2%mod);
                continue;
            }

            matrix res = Matrix_Expo(mat,n-2);

            ull fn = ( (f2*res.a[0][0] %mod) + (f1*res.a[0][1] %mod) + (f0*res.a[0][2] %mod) ) %mod;
            fn += ( (g2*res.a[0][3] %mod) + (g1*res.a[0][4] %mod) + (g0*res.a[0][5] %mod) ) %mod;

            ull gn= ( (f2*res.a[3][0] %mod) + (f1*res.a[3][1] %mod) +(f0*res.a[3][2] %mod) ) %mod;
            gn += ( (g2*res.a[3][3] %mod) + (g1*res.a[3][4] %mod) +(g0*res.a[3][5] %mod) ) %mod;

            printf("%llu %llu\n",fn%mod,gn%mod);
        }

    }

    return 0;
}
