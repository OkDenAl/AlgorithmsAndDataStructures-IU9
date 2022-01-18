#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable: 4996)

char* fibstr(int n) {
	if (n == 0)return 0;
	int f1 = 1, f2 = 1, sum = 1;
	char* strf1 = (char*)(calloc(2, sizeof(char)));
	char* strf2 = (char*)(calloc(2, sizeof(char)));
	strcpy(strf1, "a");
	strcpy(strf2, "b");
	if (n == 1) {
		free(strf2);
		return strf1;
	}
	for (int i = 3; i <= n; i++) {
		sum = f1 + f2;
		f1 = f2;
		f2 = sum;
		strf1 = (char*)realloc(strf1, sum + 1);
		strcat(strf1, strf2);
		char* tmp = strf2;
		strf2 = strf1;
		strf1 = tmp;
	}
	
	free(strf1);
	return strf2;

}

int main() {
	int n;
	scanf("%d", &n);
	char* res = fibstr(n);
	puts(res);
	free(res);
	return 0;
}