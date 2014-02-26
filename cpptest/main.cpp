#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
bool fin;
int findkinA(int A[],int m,int B[],int n,int k)
    {
        fin=false;
        int low=0,high=m-1,mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(k-mid-2<n && (k-mid-2<0 || A[mid]>=B[k-mid-2]))
            {
                if(k-mid-1<0)
                {
                    if(A[mid]<=B[0])
                    {
                        fin=true;
                        return mid;
                    }
                    else
                        high=mid-1;
                }
                if(k-mid-1>=n || A[mid]<=B[k-mid-1])
                {
                    fin=true;
                    return mid;
                }
                else
                    high=mid-1;
            }
            else
                low=mid+1;
        }
        return 0;
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if(!m)
        {
            if(n%2==0)
                return (B[n/2-1]+B[n/2])/2.0;
            else
                return B[n/2];
        }
        if(!n)
        {
            if(m%2==0)
                return (A[m/2-1]+A[m/2])/2.0;
            else
                return A[m/2];
        }
        double res;
        int k;
        if((m+n)%2)
        {
            res=A[findkinA(A,m,B,n,(m+n)/2+1)];
            if(fin)
                return res;
            res=B[findkinA(B,n,A,m,(m+n)/2+1)];
            return res;
        }
        else
        {
            k=findkinA(A,m,B,n,(m+n)/2);
            if(fin)
            {
                res=A[k];
                k=findkinA(A,m,B,n,(m+n)/2+1);
                if(fin)
                    return (res+A[k])/2.0;
                k=findkinA(B,n,A,m,(m+n)/2+1);
                return (res+B[k])/2.0;
            }
            k=findkinA(B,n,A,m,(m+n)/2);
            res=B[k];
            k=findkinA(A,m,B,n,(m+n)/2+1);
            if(fin)
                return (res+A[k])/2.0;
            k=findkinA(B,n,A,m,(m+n)/2+1);
            return (res+B[k])/2.0;
        }
    }

int main()
{
    int a[]={1,3,5,7,9},b[]={2,4,6,8,10};
    cout<<findMedianSortedArrays(a,5,b,5)<<endl;
    return 0;
}
