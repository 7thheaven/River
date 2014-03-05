#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        int len=num.size(),j,k,temp;
        if(len<3)
            return res;
        sort(num.begin(),num.end());
        for(int i=0;i<len-2;++i)
        {
            if(i>0 && num[i]==num[i-1])
                continue;
            j=i+1;
            k=len-1;
            while(j<k)
            {
                while(j<k && j>i+1 && num[j]==num[j-1])
                    ++j;
                while(k>j && k<len-1 && num[k]==num[k+1])
                    --k;
                if(j>=k)
                    break;
                temp=num[i]+num[j]+num[k];
                if(temp>0)
                    --k;
                else if(temp<0)
                    ++j;
                else
                {
                    vector<int> ans;
                    ans.push_back(num[i]);
                    ans.push_back(num[j]);
                    ans.push_back(num[k]);
                    res.push_back(ans);
                    //cout<<i<<" "<<j<<" "<<k<<endl;
                    ++j;
                    --k;
                }
            }
        }
        return res;
    }

int main()
{
    vector<int> abc;
    abc.push_back(-2);
    abc.push_back(0);
    abc.push_back(0);
    abc.push_back(2);
    abc.push_back(2);
    vector<vector<int> > ans=threeSum(abc);
    int len=ans.size();
    cout<<len<<endl;
    for(int i=0;i<len;++i)
    {for(int j=0;j<3;++j)
    cout<<threeSum(abc)[i][j]<<" ";cout<<endl;}
    return 0;
}
