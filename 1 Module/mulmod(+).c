#include <stdio.h>
#include <stdlib.h>
#include <math.h>



char checkbit (long long x, long long num)
{
        long long one=1;
    return ((x & (one << num))!=0);

}


int checklength(long long x)
{
    if (x==0) return 1;
        else
        return  (int)floorl(log2l(x + 0.5));
}
int main()
{
     long long a=0, b=0, k=0;
     unsigned long long sum=0;
    int i;
    scanf("%lld%lld%lld", &a, &b, &k);


    for (i = checklength(b); i >= 0; i--)
    {
        sum = (sum % k) * 2 + (a % k) * checkbit(b,i);
    }

    sum = sum % k;
    printf("%llu\n", sum);
    return 0;
}
