
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxl 2
using namespace std;
ll mod = 0;

struct Matrix
{
    ll a[maxl][maxl];

    Matrix()
    {
        memset(a,0,sizeof a);
    }

    void init()
    {
        a[0][0]=1, a[0][1]=1;
        a[1][0]=1, a[1][1]=0;
    }
    Matrix operator* ( Matrix temp )
    {
        Matrix res;
        for(int i=0; i<maxl; i++)
        {
            for(int j=0; j<maxl; j++)
            {
                res.a[i][j]=0;
                for(int k=0; k<maxl; k++)
                {
                    res.a[i][j] = ( res.a[i][j]+(temp.a[i][k]*a[k][j]) ) %mod;
                }
            }
        }
        return res;
    }

};

Matrix Power(Matrix temp, ll n)
{
    if(n == 1) return temp;

    Matrix res=Power(temp,n/2);
    res = (res*res);
//cout<<"R  "<<res.a[0][0]<<endl;
    if(n%2 == 1) res = (res*temp);

    return res;
}

ll MatrixExpo(Matrix temp, ll n)
{
    Matrix res= Power(temp,n);
    return res.a[0][0]%mod;
}

int main()
{
    ll n,m;
    struct Matrix temp;
    temp.init();

    while( scanf("%lld %lld",&n,&m) != EOF )
    {
        if(n <= 1)
        {
            if(n == 0) printf("0\n");
            else printf("1\n");
            continue;
        }
        mod=powl(2,m);
      //  cout<<"M  "<<mod<<"  "<<n<<"  "<<m<<endl;
        printf("%lld\n",MatrixExpo(temp,n-1));
    }
    return 0;
}
