

#include<bits/stdc++.h>
#define maxl 2
#define ll long long
#define ull unsigned long long
using namespace std;

struct matrix
{
    ull a[maxl][maxl];
    matrix()
    {
        memset(a,0,sizeof a);
    }
    void init(ull p, ull q)
    {
        a[0][0]=p, a[0][1]=-q;
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
                    res.a[i][j] = res.a[i][j]+ (temp.a[i][k]*a[k][j]);
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
    ull n,t,p,q;
    int cas=1;
    struct matrix mat;

    scanf("%llu",&t);

    while(  t-- )
    {
        scanf("%llu %llu %llu",&p,&q,&n);

        mat.init(p,q);
        ll f1=p,f2=(p*p)-(2*q);
        ll func[]={ 2,f1,f2 };

        if(n<=2)
        {
            if(n == 0) printf("Case %d: %llu\n",cas++,func[0]);
            else if(n == 1)printf("Case %d: %llu\n",cas++,func[1]);
            else printf("Case %d: %llu\n",cas++,func[2]);
            continue;
        }

        matrix res = Power(mat,n-2);

        ull ans = (res.a[0][0]*func[2]) + (res.a[0][1]*func[1]);
        printf("Case %d: %llu\n",cas++,ans);

    }

    return 0;
}
