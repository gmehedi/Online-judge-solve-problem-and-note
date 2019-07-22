
#include<bits/stdc++.h>
using namespace std;
char year[1000000];

long long rem(int n)
{
    int t=0;
    for(int i=0; i<(int)strlen(year); i++)
    {
        t=(t*10+(year[i]-48) )%n;
    }

    return t;
}
int main()
{
    bool sign=true;
    while( scanf("%s",&year) != EOF)
    {
         if(sign)
        {
            sign=false;
        }
        else
        printf("\n");
        bool l=false,b=false,h=false;
        if( rem(400)%400==0||(rem(4)%4==0 && rem(100)%100 !=0) )
        {
            cout<<"This is leap year."<<endl;
            l=true;
        }
        if(rem(15)%15==0)
        {
            cout<<"This is huluculu festival year."<<endl;
            h=true;
        }
       if(rem(55)%55==0 && l )
        {
            cout<<"This is bulukulu festival year."<<endl;
            b=true;
        }
       if(!l && !b && !h)
        cout<<"This is an ordinary year."<<endl;

    }
    return 0;
}
