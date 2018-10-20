
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;
ll mod = 10007,maxl=4,val[20],fuc[20];

struct Matrix
{
    ll a[20][20];

    Matrix()
    {
        memset(a,0,sizeof a);
    }

    void init(ll x, ll y)
    {
        a[0][0]=x, a[0][2]=y, a[0][3]=1;
        a[1][0]=1, a[2][1]=1, a[3][3]=1;
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
    ll n,t;
    int cas=1;

    scanf("%lld",&t);
    while( t-- )
    {
        struct Matrix temp;
        ll x,y,c;
        scanf("%lld %lld %lld %lld",&n,&x,&y,&c);

        if(n<=2) { printf("Case %d: 0\n",cas++); continue; }

        temp.init(x,y);

        Matrix res = MatrixExpo(temp,n-2);
        ll ans = res.a[0][3];
        ans = (ans*c) %mod;

        printf("Case %d: %lld\n",cas++,ans);
    }
    return 0;
}
