#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        int len=num.size(),j,k,l,temp;
        if(len<4)
            return res;
        sort(num.begin(),num.end());
        for(int i=0;i<len-3;++i)
        {
            if(i>0 && num[i]==num[i-1])
                continue;
            for(int l=i+1;l<len-2;++l) {
                if(l>i+1 && num[l]==num[l-1])
                    continue;
            j=l+1;
            k=len-1;
            while(j<k)
            {
                while(j<k && j>l+1 && num[j]==num[j-1])
                    ++j;
                while(k>j && k<len-1 && num[k]==num[k+1])
                    --k;
                if(j>=k)
                    break;
                temp=num[i]+num[l]+num[j]+num[k];
                if(temp>target)
                    --k;
                else if(temp<target)
                    ++j;
                else
                {
                    vector<int> ans;
                    ans.push_back(num[i]);
                    ans.push_back(num[l]);
                    ans.push_back(num[j]);
                    ans.push_back(num[k]);
                    res.push_back(ans);
                    ++j;
                    --k;
                }
            }
            }
        }
        return res;
    }

int main()
{
    vector<int> abc;
    abc.push_back(1);
    abc.push_back(0);
    abc.push_back(-1);
    abc.push_back(0);
    abc.push_back(-2);
    abc.push_back(2);
    vector<vector<int> > ans=fourSum(abc,0);
    int len=ans.size();
    cout<<len<<endl;
    for(int i=0;i<len;++i)
    {for(int j=0;j<4;++j)
    cout<<ans[i][j]<<" ";cout<<endl;}
    return 0;
}
