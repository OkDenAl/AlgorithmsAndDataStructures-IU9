#include <stdio.h>
#pragma warning (disable: 4996)
int main()
{
	long long x0,res=0,resp=0,a,c,n;
	scanf("%lld %lld", &n,&x0);
	c = n;
	for (long long i = 0; i < n; i++) {
		scanf("%lld", &a);
		if (i==0) res = a * x0;
        else res = (res + a) * x0;
        if (i!=(n-1)){
		if (i==0) resp = c*a * x0;
        else resp = (resp + c*a) * x0;
        }
		c -= 1;
	}
	resp = resp+a;
	scanf("%lld", &a);
	res += a;
	printf("%lld\n%lld", res, resp);

	return 0;
}
