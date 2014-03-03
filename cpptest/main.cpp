#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

int numDecodings(string s) {
        int len=s.length();
        if(!len)
            return 0;
        int dp[len];
        if(s[len-1]=='0')
            dp[len-1]=0;
        else
            dp[len-1]=1;
        for(int i=len-2;i>=0;--i)
        {
            if(s[i]=='0')
            {
                if(s[i+1]=='0')
                    return 0;
                if(i-1<0 || s[i-1]=='0' || s[i-1]>'2')
                    return 0;
                dp[i]=0;
            }
            else if(s[i]>'2')
                dp[i]=dp[i+1];
            else if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))
            {
                dp[i]=dp[i+1];
                if(i+2<len)
                    dp[i]+=dp[i+2];
                else
                    ++dp[i];
            }
            else
                dp[i]=dp[i+1];
        }
        return dp[0];
    }

int main()
{
    cout<<numDecodings("27")<<endl;
    return 0;
}
