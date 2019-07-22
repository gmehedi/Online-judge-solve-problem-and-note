#include<bits/stdc++.h>
#define maxi 10000005
using namespace std;
bool b[maxi+2];
int prime[maxi];
int k=0;
void Prime()
{
    for(int i=2; i*i<=maxi; i++) if(b[i]) for(int j=i+i; j<=maxi; j=j+i )b[j]=false;
    k=0;
    for(int i=2; i<=maxi; i++)if(b[i] ) prime[k++]=i;
    prime[k++]=INT_MAX;
   // cout<<"K  "<<k<<endl;
}

bool Check(int temp)
{
    for(int i=0; i<k; i++)
    {
        if(temp-prime[i]<=0)break;
        if(b[ temp-prime[i] ]) { cout<<prime[i]<<" "<<temp-prime[i]; return 1; }
    }
    return 0;
}

int main()
{
    memset(b,true,sizeof b);
    Prime();
    int n;
    while( scanf("%d",&n) != EOF)
    {
        if(n<8)cout<<"Impossible."<<endl;
        else
        {
            if( Check(n-4) )
            {
                cout<<" "<<2<<" "<<2<<endl;
            }
            else
            {
                Check(n-5);
                cout<<" "<<2<<" "<<3<<endl;
            }
        }
    }
    return 0;
}

