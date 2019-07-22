
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,cnt;
    while(scanf("%d",&n) != EOF)
    {
        cnt=1;
        int value=1;
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        else if(n==1)
        {
            printf("1\n");
            continue;
        }
        while(value!=0)
        {
            cout <<"V           "<<value<<endl;
            value = (value*10+1)%n;
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
