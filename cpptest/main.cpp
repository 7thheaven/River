#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>

using namespace std;

bool isPalindrome(int x) {
        if(x<0)
            return false;
        while(x)
        {
            if(x/int(pow(10,int(log10(x))))!=x%10)
                return false;
            if(int(log10(x)))
                x/=pow(10,int(log10(x))-int(log10(x-(x/int(pow(10,int(log10(x)))))*pow(10,int(log10(x))))));
            x-=(x/int(pow(10,int(log10(x)))))*int(pow(10,int(log10(x))));
        }
        return true;
    }

int main()
{
    int x=1;
    cout<<isPalindrome(x)<<endl;
    return 0;
}
