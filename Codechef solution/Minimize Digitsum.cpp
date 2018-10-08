
#include <bits/stdc++.h>
#define ll long long
#define ull long long
#define maxl 10000
using namespace std;

ull n,d;

ull ansNum=999,ansCnt=0;

ull digit_sum(ull nn)
{
    ull temp=0;
    while(nn) temp+=(nn%10), nn/=10;
    return temp;
}

void bfs()
{
    queue<pair<ull,ull> >q;
    q.push( make_pair(n,0) );
    ull step = 0;
    while( !q.empty() )
    {
        ull num=q.front().first;
        ull tm=q.front().second;
        q.pop();
        if(num<10)
        {
            if(ansNum>num && num>0)
            {
                ansNum=num;
                ansCnt=tm;
            }
        }
        q.push(make_pair(num+d,tm+1));
        q.push(make_pair(digit_sum(num),tm+1));
        step++;
        if(step>1e5) break;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&d);
        ansNum=999,ansCnt=0;
        bfs();
        printf("%lld %lld\n",ansNum,ansCnt);
    }
    return 0;
}
