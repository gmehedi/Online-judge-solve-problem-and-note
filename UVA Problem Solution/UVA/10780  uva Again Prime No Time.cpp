
#include<bits/stdc++.h>
using namespace  std;
int mini=INT_MAX;
bool number_of_power_n(int n,int mode,int cnt)
{//cout<<"F  "<<n<<"  "<<mode<<"  "<<cnt<<endl;
    int cnt2=0;
    int k=mode;
    while(k<=n)cnt2+=n/k,k*=mode;
   //cout<<"C@   "<<cnt2<<"   "<<cnt<<endl;
    if(cnt2>=cnt){ mini = min(mini,cnt2/cnt);  return true; }
    else return false;

}

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&m,&n);
        int temp=m,cnt=0;
        mini=INT_MAX;
        bool b=true;
        printf("Case %d:\n",cas++);
        for(int i=2; i<=m; i++)
        {
            cnt=0;
            if(temp%i==0)
            {
                while(temp%i==0)cnt++,temp/=i;
                if( !number_of_power_n(n,i,cnt) )
                {
                    printf("Impossible to divide\n"); b=false;
                    break;
                }
            }
        }
        if(b)printf("%d\n",mini);
    }
        return 0;
}
