#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p,q,r,s;
    while( scanf("%d %d %d %d",&p,&q,&r,&s) != EOF )
    {

        if(q>(p-q)) q=p-q;
        if(s>(r-s)) s=r-s;
        double result=1.0;
       // cout<<"F "<<s<<" "<<q<<endl;
       for (int i = 1; i <= q || i <= s; ++i)
        {
            if (i <= q) result = result * (p - q + i) / i;
            if (i <= s) result = (result / (r - s + i)) * i;
        }
        printf("%.5f\n",result);

    }



    return 0;

}
