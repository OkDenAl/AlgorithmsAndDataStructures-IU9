#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable: 4996)
int strdiff(char* a, char* b) {
	int c = 0;
	int N;
	if (strlen(a) >= strlen(b)) N = strlen(a);
	else N = strlen(b);
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < 8; i++) {
			if ((a[j] & (1 << i)) == ((b[j]) & (1 << i))) {
				c++;
			}
			else {
				return c+1;
			}
		}
	}
	return -1;
}
int main() {
	printf("%d", strdiff("T", "The quick brown fox jumps over the lazy dog"));
	return 0;
}
