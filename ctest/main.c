#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int a=10;
    int *p = (int *) &a;
    *p=20;
    printf("%d %d\n",a,*p);
    return 0;
}
