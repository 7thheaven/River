#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s) {
        int len=s.length();
        if(!len)
            return 0;
        int res=0,temp=0;
        bool has;
        for(int i=0;i<len;++i)
        {
            has=false;
            for(int j=0;j<temp;++j)
            {
                if(s[i-j-1]==s[i])
                {
                    if(res<temp)
                        res=temp;
                    temp=j+1;
                    has=true;
                    break;
                }
            }
            if(!has)
                ++temp;
        }
        if(temp>res)
            res=temp;
        return res;
    }

int main()
{
    string a="wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
    cout<<lengthOfLongestSubstring(a)<<endl;
    return 0;
}
