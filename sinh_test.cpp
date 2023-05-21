#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e6+7;
#define randomize mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count())
randomize;
int main()
{
    freopen("test.inp","w",stdout);
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=M;j++)
        {
            int value=mt()%M;
            cout<<value<<" ";
        }
        cout<<endl;
    }
}
