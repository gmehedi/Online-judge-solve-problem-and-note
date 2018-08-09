#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int r,c;
        scanf("%d %d",&r,&c);
        int t1=0,t2=0,t3=0,t4=0;
        t1=r/2, t2=r/2+1, t3=c/2, t4=c/2+1;
        long long ans=0;
        if(r==1 || c==1  || (c==2 && r==2)) ans=c*r;
        else if(r==2 || c==2)
        {
            int k=max(r,c);

            if(k%4==0) ans=(k/4)*4;
            else if(k%4==1) ans=(k/4)*4+2;
            else if(k%4==2 || k%4==3) ans=(k/4+1)*4;

            else ans=(k-(k/2))*4+2;
        }
        else if(c%2 !=0 && r%2 !=0)
        {
            ans+= t4*t2+t3*t1;
        }
        else if(c%2 ==0 && r%2==0)
        {
            ans = t4*t1+t3*(t1)-r/2;
        }
        else if(c%2 !=0 && r%2==0)
        {
            ans = t4*t1+t3*(t1);
        }
        else ans=(t4*t2+t3*t1)-(r/2+1);//cout<<"T  "<<t1<<"   "<<t2<<"   "<<t3<<"  "<<t4<<endl;

        printf("Case %d: %lld\n",cas++,ans);
    }
    return 0;
}
