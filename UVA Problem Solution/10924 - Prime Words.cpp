

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool Is_prime(int n)
{
    if(n<=2)return true;
    for(int i=2; i<=sqrt(n); i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
int  main()
{
    char ch[100000];
    while( scanf("%s",ch ) != EOF)
    {
        int s=strlen(ch),t1=0;
        for(int i=0; i<s; i++)
        {

            if( ch[i]>='a' && ch[i]<='z' )
            {
                int d=(ch[i]-'a')+1;
                t1+=d;

            }
            else
            {
                t1+=(ch[i]-'A')+27;

            }


        }
        bool b=Is_prime(t1);
       // cout <<b<<endl;
        if(b)cout <<"It is a prime word."<<endl;
        else cout <<"It is not a prime word."<<endl;

    }
    return 0;
}
