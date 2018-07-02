

#include<bits/stdc++.h>
using namespace std;

bool compare(string s1, string s2)
{
    string s3= s1+s2;
    string s4=s2+s1;
  //  cout<<"B   "<<s3<<"   "<<s4<<endl;
    for(int i=0;i<(int)s3.size(); i++)
    {
        if( s3[i]!=s4[i])return (s3[i]>s4[i]);
    }

    return true;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        string s[n+2];
        cin.ignore();
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
        }
        int l1=0,l2=0;
        sort(s,s+n,compare);

        for(int i=0; i<n; i++)
        {
            cout<<s[i];
        }
        cout<<endl;
    }



    return 0;
}
