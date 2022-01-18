#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable: 4996)

char* concat(char** s, int n) {
	int len = 0;
	for (int i = 0; i < n; i++) {
		len += strlen(s[i]);
	}
	char *str = (char*)malloc(len+1);
	int res_ind = 0;
	for (int i = 0; i < n; i++) {
		int j = 0;
		while (s[i][j] != '\0') {
			str[res_ind] = s[i][j];
			res_ind++;
			j++;
		}
	}
	return str;
}

int main() {
	int n;
	scanf("%d ", &n);
	char* s[n];
	for (int i = 0; i < n; i++) {
		s[i] = (char*)malloc(256);
	}
	for (int i = 0; i < n; i++) {
		gets(s[i]);
	}
	char* res = concat(s, n);
	puts(res);
	free(res);
	for (int i = 0; i < n; ++i) {
		free(s[i]);
	}
	free(s);
	return 0;
}
