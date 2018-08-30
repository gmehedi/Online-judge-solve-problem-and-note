#include<bits/stdc++.h>
using namespace std;
long long f[50];
void store()
{
    f[0]=1;
    for(int i=1; ; i++)
    {
        if(f[i-1]*i>1e18) break;
        f[i]=f[i-1]*i;
    }
   // cout<<f[19]<<"   "<<f[20]<<endl;
}
int main()
{
    store();
    int cas;
    cin>>cas;
    for(int c=1; c<=cas; c++)
    {
        long long n;
        scanf("%lld",&n);
        int j=19;
        while(n<f[j]) j--;
     //   cout<<"J  "<<j<<"  "<<f[j]<<endl;
        if(n==f[j])
        {
            printf("Case %d: %d!\n",c,j);
            continue;
        }
        else
        {
            bool sign=false;
            for(int i=j; i>=0; i--)
            {
                vector<int>v;
                v.push_back(i);
                long long sum=f[i];
                for(int k=i-1; k>=0; k--)
                {
                    if(sum+f[k]>n) continue;
                    sum+=f[k];
                    v.push_back(k);
                    if(sum==n)
                    {
                        reverse(v.begin(),v.end());
                        printf("Case %d: ",c);
                        for(int h=0; h<(int)v.size()-1; h++)cout<<v[h]<<"!+";
                        cout<<v[v.size()-1]<<"!"<<endl;
                       sign=true;
                        break;
                    }
                }
                if(sign) break;
            }
            if(!sign)
            {
                printf("Case %d: impossible\n",c);
            }
        }

    }
    return 0;
}
