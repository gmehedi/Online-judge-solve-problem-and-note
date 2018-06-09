#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int r;
    scanf("%d",&r);
       while(r--)
       {
          int s;
          scanf("%d",&s);
           vector<int>v;

           for(int i=0; i<s; i++)
           {
               int temp;
               scanf("%d",&temp);
                   v.push_back(temp);

           }
            sort(v.begin(),v.end());

            int middle=v[s/2];
            int ans=0;
            for(int i=0; i<s; i++)
            {
                ans+=abs(middle-v[i]);
            }
            printf("%d\n",ans);


    }

    return 0;
}
