
#include<bits/stdc++.h>
#define maxl 2
#define ll long long
using namespace std;

ll mod=0;
struct matrix
{
    ll a[maxl][maxl];
    matrix()
    {
        memset(a,0,sizeof a);
    }
    void init()
    {
        a[0][0]=1, a[0][1]=1;
        a[1][0]=1, a[1][1]=0;
       // cout<<"F "<<a[0][0]<<"  "<<a[0][1]<<endl;
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
                    res.a[i][j] =( res.a[i][j]+ (temp.a[i][k]*a[k][j]) )%mod;
                }
            }
        }
        return res;
    }

};

matrix Power(matrix mat, ll n)
{
    if(n == 1) return mat;

    matrix res = Power(mat,n/2);
    res = res*res;
    if( (n%2) == 1 ) res= res*mat;

    return res;
}

matrix Matrix_Expo(matrix mat, ll n)
{
    matrix res = Power(mat,n);
    return res;
}

int main()
{
    ll n,t;
    int cas=1;
    struct matrix mat;

    scanf("%lld",&t);
    mat.init();
    while(  t-- )
    {
        ll x,y,n,m;
        scanf("%lld %lld %lld %lld",&x,&y,&n,&m);
        mod=powl(10,m);

        if(n<=1)
        {
            if(n == 0) printf("Case %d: %lld\n",cas++,x%mod);
            else printf("Case %d: %lld\n",cas++,y%mod);
            continue;
        }

        matrix res = Power(mat,n-1);
        printf("Case %d: %lld\n",cas++, ( (res.a[0][0]*y) %mod + (res.a[0][1]*x) %mod) %mod );
    }
    return 0;
}
