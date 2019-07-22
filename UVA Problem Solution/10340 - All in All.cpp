
#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[1000000],t[1000000];
    while(scanf("%s%s",s,t) ==2 )
    {
        int sz=(int)strlen(t),k=0,c=(int)strlen(s);
        bool b= false;
        for(int i=0; i<sz && k<c; i++)
        {
            if(s[k]==t[i])
            {
                k++;
            }
            if(k== c)
            {
                cout <<"Yes"<<endl;
                b=true;
                break;

            }
        }
        if(!b)
        cout <<"No"<<endl;
    }


    return 0;
}
