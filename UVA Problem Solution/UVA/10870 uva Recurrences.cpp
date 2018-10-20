
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

ll mod = 10007,maxl=0,val[20],fuc[20];

struct Matrix
{
    ll a[20][20];

    Matrix()
    {
        memset(a,0,sizeof a);
    }

    void init(ll val[20])
    {
        for(int i=0; i<maxl; i++)
        {
            for(int j=0; j<maxl; j++)
            {
                if(i == 0) a[i][j]=val[j];
                else
                {
                    if(j == (i-1)) a[i][j]=1;
                }
            }
        }

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
                {//cout<<"FFFF    "<<temp.a[i][k]<<"   "<<a[k][j]<<endl;
                    res.a[i][j] = ( res.a[i][j]+(temp.a[i][k]*a[k][j])%mod ) %mod;
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

Matrix MatrixExpo(Matrix temp, ll n)
{
    Matrix res= Power(temp,n);
    return  res;
}

int main()
{
    ll n,d,m;
    bool b=false;

    while( scanf("%lld %lld %lld",&d,&n,&m) != EOF )
    {
        if(d == 0 && n == 0 && m == 0) break;

        struct Matrix temp;
        ll fun[20],val[20];
        mod=m, maxl=d;

        for(int i=0; i<d; i++) scanf("%lld",&val[i]);
        for(int i=0; i<d; i++) scanf("%lld",&fun[i]);


        if(n<=d) { printf("%lld\n",fun[n-1]% mod); continue; }
        temp.init(val);
        Matrix res = MatrixExpo(temp,n-d);

        ll ans=0;
        int j=d-1;
    //    for(int i=0; i<d; i++) cout<<"F  "<<"  "<<val[i]<<"   "<<fun[i]<<"   "<<res.a[0][i]<<endl;
        for(int i=0; i<d; i++,j--) ans = ( ans+(fun[j]*res.a[0][i])%mod )%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
