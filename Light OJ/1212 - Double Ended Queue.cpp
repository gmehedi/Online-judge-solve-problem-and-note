
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        cin.ignore();
        int sz=0;
        deque<int>q;
        printf("Case %d:\n",cas++);
        for(int i=1; i<=m; i++)
        {
            string s;
            cin>>s;
        //    cout<<"S            "<<s<<"           "<<i<<"     "<<m<<endl;
            if(s[1]=='u')
            {
                 int temp;
                 cin>>temp;
                if(sz>=n)
                {
                    printf("The queue is full\n");
                }
                else
                {
                    if(s[4]=='L') q.push_front(temp), printf("Pushed in left: %d\n",temp);
                    else q.push_back(temp), printf("Pushed in right: %d\n",temp);
                    sz++;
                }
            }
            else if(s[1]=='o')
            {
                if(sz<=0)
                {
                    printf("The queue is empty\n");
                }
                else
                {
                    if(s[3]=='L')  printf("Popped from left: %d\n",q.front()), q.pop_front();
                    else printf("Popped from right: %d\n",q.back()), q.pop_back();
                    sz--;
                }
            }
        }
    }
    return 0;
}
