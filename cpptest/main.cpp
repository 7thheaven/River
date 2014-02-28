#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int x=1;
    vector<vector<int> > a;
    for(int i=0;i<10;++i)
    {
        vector<int> b;
        b.push_back(x);
        a.push_back(b);
    }
    cout<<x<<" "<<a[2][0]<<" "<<a.size()<<" "<<a[7].size()<<endl;
    return 0;
}
