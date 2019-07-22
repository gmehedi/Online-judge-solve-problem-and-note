
#include<bits/stdc++.h>
#define N 100000
using namespace std;
bool b[N+1];
long long prime[10000];
int k=1;
void Prime(){
    for(int64_t i=3; i*i<=N; i+=2){
        if(b[i]){
            for(int64_t j=i*i; j<=N; j=j+(i*2) ){
                b[j]=false;
            }
        }//  if(b[i])cout<<i<<endl;
    }
    prime[0]=2;
    for(int64_t i=3; i<=N; i+=2)if(b[i])prime[k++]=i;//cout<<"K  "<<k<<endl;
}

int main()
{//cout<<7*(1-(1.00/7))<<endl;
    long long n;
    memset(b,true,sizeof b);
    Prime();
    while( scanf("%lld",&n)==1 && n !=0 ){
        if(n==1){
            printf("0\n");
            continue;
        }
        double ans=(double)n;
        for(int i=0; prime[i]*prime[i]<=n; i++){
            bool b=false;
            while(n%prime[i]==0){
                b=true;
                n/=prime[i];
            }
          //  cout<<"B "<<b<< "   "<<prime[i]<<endl;
            if(b)ans=ans*(1.00-(1.00/prime[i]));
        }
//cout<<"D "<<ans<<"   "<<n<<"    "<<(1-(1.00/(double)n))<< "  "<<ans*(1-(1.00/(double)n))<<endl;
        if(n>1) ans=ans*(1-(1.00/n));
        printf("%.0f\n",ans);

    }
    return 0;
}
