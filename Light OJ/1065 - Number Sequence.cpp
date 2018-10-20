
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;
ll mod = 0,maxl=0,val[20],fuc[20];

struct Matrix
{
    ll a[20][20];

    Matrix()
    {
        memset(a,0,sizeof a);
    }

    void init()
    {
        for(int i=0; i<maxl; i++)
        {
            for(int j=0; j<maxl; j++)
            {
                if(i == 0) { a[i][j]=val[maxl-j-1]; continue; }
                if(j == (i-1)) { a[i][j]=1; break;  }
            }
        }
        cout<<"TT "<<endl;
        for(int i=0; i<maxl; i++)
        {
            for(int j=0; j<maxl; j++)
            {
                cout<<a[i][j]<<"  ";
            }
            printf("\n");
        }
        cout<<"EE"<<endl;
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
    ll n,m,d;


    while( scanf("%lld %lld %lld",&d,&n,&m) != EOF )
    {
        struct Matrix temp;
        maxl=d, mod=m;

        for(int i=0; i<d; i++) scanf("%lld",&val[i]);
        for(int i=0; i<d; i++) scanf("%lld",&fuc[i]);

        temp.init();
        if(n <= d)
        {
            printf("A   %lld\n",val[n-1]%mod);
            continue;
        }
        Matrix res=MatrixExpo(temp,n-1);
        ll ans= res.a[0][0];
        printf("A   %lld\n",ans);
    }
    return 0;
}
