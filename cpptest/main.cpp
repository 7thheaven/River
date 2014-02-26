#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

void merge(int A[], int m, int B[], int n) {
        if(!n)
            return;
        if(!m)
        {
            for(int i=0;i<n;++i)
                A[i]=B[i];
            return;
        }
        for(int i=m+n-1;i>n-1;--i)
            A[i]=A[i-n];
        int indexa=n,indexb=0,now=0;
        while(now<m+n)
        {
            if(indexa>=m+n)
            {
                while(indexb<n)
                    A[now++]=B[indexb++];
                return;
            }
            if(indexb>=n)
            {
                while(indexa<m+n)
                    A[now++]=A[indexa++];
                return;
            }
            cout<<A[indexa]<<" "<<B[indexb]<<endl;
            if(A[indexa]<B[indexb])
                A[now++]=A[indexa++];
            else
                A[now++]=B[indexb++];
            cout<<now<<" "<<indexa<<" "<<indexb<<endl;
        }
    }

int main()
{
    int a[]={1,2,4,5,6,0},b[]={3};
    merge(a,5,b,1);
    for(int i=0;i<6;++i)
    cout<<a[i]<<endl;
    return 0;
}
