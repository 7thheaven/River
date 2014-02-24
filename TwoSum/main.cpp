#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
int partition(int *a,int p,int r)
{
    int x=a[r];
    int i=p-1;
    int temp;
    for(int j=p;j<r;++j)
    {
        if(a[j]<=x)
        {
            ++i;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;
    return i+1;
}

void quicksort(int *a,int p,int r)
{
    if(p<r)
    {
        int q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}

int binarysearch(int *a,int begin,int end,int target)
{
    int low=begin,high=end,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==target)
            return mid;
        else if(a[mid]<target)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}

    vector<int> twoSum(vector<int> &numbers, int target) {
        int aim,a=0,b=0,len=numbers.size(),c,first=0,second=0;
        int temp[len];
        vector<int>::iterator iter;
        for(iter=numbers.begin();iter!=numbers.end();++b,++iter)
            temp[b]=(*iter);
        quicksort(temp,0,len);
        vector<int> res;
        for(;a<len;++a)
        {
            aim=target-temp[a];
            b=binarysearch(temp,a,len,aim);
            //cout<<temp[a]<<" "<<aim<<" "<<b<<endl;
            if(b!=-1)
            {
                //for(iter=numbers.begin();iter!=numbers.end();++b,++iter) cout<<(*iter)<<endl;
                for(c=0;c<len;++c)
                {
                    if(numbers[c]==temp[a] && first==0)
                    {
                        //cout<<"first "<<c<<" "<<numbers[c]<<" "<<temp[a]<<endl;
                        first=c;
                        continue;
                    }
                    if(numbers[c]==aim)
                    {
                        //cout<<"second "<<c<<" "<<numbers[c]<<" "<<aim<<endl;
                        second=c;
                        continue;
                    }
                    if(first!=0 && second!=0)
                        break;
                }
                if(first>second)
                {
                    c=first;
                    first=second;
                    second=c;
                }
                res.push_back(first+1);
                res.push_back(second+1);
                break;
            }
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> p,b;
    p.push_back(2);
    p.push_back(1);
    p.push_back(9);
    p.push_back(4);
    p.push_back(4);
    p.push_back(56);
    p.push_back(90);
    p.push_back(3);
    b=a.twoSum(p,8);
    vector<int>::iterator iter;
    for(iter=b.begin();iter!=b.end();++iter)
        cout<<(*iter)<<endl;
    return 0;
}
