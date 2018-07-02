#include<bits/stdc++.h>
using namespace std;
map<long long,int>mp;
int main()
{
    int n,t;
     scanf("%d",&t);
     while(t--)
     {
          scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            long long temp;
            scanf("%lld",&temp);
            mp[temp]++;
        }
        int dif=mp.size();
        auto it=mp.end();
        it--;
        int maxi=(*it).second;

      //  cout<<dif<<"   "<<(*it).second<<endl;
        if(maxi>dif)
        {
            printf("%d\n",maxi-dif);
        }
        else printf("%d\n",dif);

        mp.clear();

     }





    return 0;
}
