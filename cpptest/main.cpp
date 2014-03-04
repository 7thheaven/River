#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        if(!n)
        return m;
        if(!m)
        return n;
        int c[n+1][m+1];
        for(int i=0;i<=n;++i)
        c[i][0]=i;
        for(int i=0;i<=m;++i)
        c[0][i]=i;
        for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            if(word1[i-1]==word2[j-1])
                c[i][j]=c[i-1][j-1];
            else
            {
                c[i][j]=c[i-1][j];
                if(c[i][j]>c[i][j-1])
                    c[i][j]=c[i][j-1];
                if(c[i][j]>c[i-1][j-1])
                    c[i][j]=c[i-1][j-1];
                ++c[i][j];
            }
            cout<<i<<" "<<j<<" "<<c[i][j]<<endl;
            cout<<c[i-1][j]<<" "<<c[i][j-1]<<" "<<c[i-1][j-1]<<endl;
        }
        return c[n][m];
    }

int main()
{
    cout<<minDistance("a","ab")<<endl;
    return 0;
}
