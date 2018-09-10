

#include<bits/stdc++.h>
#define maxi 1000010
using namespace std;
int phi[maxi];
void prefix_func(string &temp,int &len)
{
    int j=0;
    phi[0]=0;
    for(int i=1; i<len; i++)
    {
        while(j>0 && temp[i] != temp[j]) j=phi[j-1];

        if(temp[i]==temp[j]) j++;
        phi[i]=j;
    }
}
int cas=1;
int match[100] = {0};
int kmp(string &s, int &len)
{
     int maxx=0,j=0;
     string temp=s;
     reverse(temp.begin(),temp.end());
     prefix_func(temp,len);
    for(int i=0; i<len; i++)
    {
        while(j>0 && s[i] != temp[j] )
        {
            j=phi[j-1];
        }
        if(s[i] == temp[j])
        {
            j++;
        }
    }
    return j;
}
int main()
{
       string s;

        while( getline(cin,s) )
        {
            memset(phi,0,sizeof phi);
            int len=s.size();
            int length= (len- kmp(s,len) );
            string res="\0";
            res=s.substr(0,length);
            if(res!="\0") reverse(res.begin(),res.end()), s+=res;
            cout<<s<<endl;

        }
        return 0;
}


