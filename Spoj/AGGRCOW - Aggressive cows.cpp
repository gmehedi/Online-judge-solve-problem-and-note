
#include <bits/stdc++.h>
using namespace std;
int n,cow;
bool func(int a[], int value)
{
    int cnt=1;
    int sit=a[0];
  //  cout<<"V  "<<value<<endl;
    for(int i=1; i<n; i++)
    {
        if(abs(a[i]-sit)>=value)cnt++,sit=a[i];
        if(cnt==cow) return true;
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>cow;
        int a[n+2];
        for(int i=0; i<n; i++)cin>>a[i];
        sort(a,a+n);
        int left=0,right=1000000000,maxi=0;
        while(left<=right)
        {
           // cout<<left<<"  "<<right<<endl;
            int mid=(left+right)/2;
            if( func(a,mid) )
            {//cout<<"M "<<mid<<endl;
              //  cout<<"G "<<mid<<endl;
                maxi=max(maxi,mid);
                left=mid+1;
            }
            else right=mid-1;
         //   cout<<"N "<<left<<"  "<<right<<endl;

        }
        printf("%d\n",maxi);
    }
    return 0;
}
