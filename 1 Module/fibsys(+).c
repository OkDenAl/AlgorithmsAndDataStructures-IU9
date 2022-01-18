#include <stdio.h>
#pragma warning (disable: 4996)

const int SIZE = 100;

int main() {
	unsigned long long x;
	scanf("%lld", &x);
	unsigned long long fib[SIZE];
	fib[0] = 1;
	fib[1] = 2;
	for (int i = 2; i < SIZE; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	int index = 0;
	while (fib[index+1] <= x) {
		index++;
	}
	int max_index = index;
	int _x = x;
	char ans[SIZE];
	x -= fib[index];
	index--;
	ans[0] = '1';
	for (; index >= 0; index--) {
		if (fib[index] <= x) {
			x -= fib[index];
			ans[max_index - index] = '1';
		}
		else ans[max_index - index] = '0';
	}
	if (_x == 0) ans[0] = '0';
	ans[max_index + 1] = '\0';
	printf("%s\n", ans);

	return 0;
}
