#include<bits/stdc++.h>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    int q;
    while(scanf("%d",&q)==1)
    {
        vector<int>v1;
        vector<int >v2;

        for(int i=0; i<q; i++)
        {
            int v;
            scanf("%d",&v);
            v1.push_back(v);
            v2.push_back(0);
        }
        v2[0]=1;
        for(int i=0; i<q-1; i++)
        {
            int ab=abs(v1[i+1]-v1[i]);
            if(ab>0 && ab<q)v2[ab]=1;
        }
        vector<int> :: iterator it;
        it = find(v2.begin(),v2.end(),0);
        if(it != v2.end())printf("Not jolly\n");
        else printf("Jolly\n");

    }

    return 0;
}
