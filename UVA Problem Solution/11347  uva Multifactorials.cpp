
#include<bits/stdc++.h>
using namespace  std;

int main()
{
    int t,cas=1;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        int number=0,k=0,cnt[1010];
        memset(cnt,0,sizeof cnt);
        for(int i=0; i<(int)s.size(); i++) if(s[i]>='0' && s[i]<='9')number= number*10+(s[i]-'0'); else k++;
       // cout<<"N  "<<number<<"   "<<k<<endl;
        for(int i=number; i>0; i-=k)
        {
            int f=i;
            for(int j=2; j*j<=f; j++)
            {
                if(f%j==0) while(f%j==0) cnt[j]++,f/=j;
            }
            if(f>1)cnt[f]++;
        }
        long long ans=1;
        double digit=0;
        for(int i=2; i<=1000; i++)
        {
            if(cnt[i]>0) digit+=log10(cnt[i]+1), ans*=(cnt[i]+1);
        }
        digit=floor(digit);
        //cout<<"D    "<<digit<<endl;
        digit++;
        if(digit>18)printf("Case %d: Infinity\n",cas++);
        else printf("Case %d: %lld\n",cas++,ans);

    }
        return 0;
}
