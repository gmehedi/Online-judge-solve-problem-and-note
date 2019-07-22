#include <iostream>


using namespace std;

int main(){
    int n,f,i,j,a,b,c;
    long long sum=0;
    while(cin >> n)
    {
        for(i=0; i<n; i++)
        {
           cin >> f;
           for(j=0; j<f; j++)
           {
            cin >> a >> b >> c;
            sum+=a*c;
           }

           cout << sum << endl;
        }

    }

 return 0;
}


