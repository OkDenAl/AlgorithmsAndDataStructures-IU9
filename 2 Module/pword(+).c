#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int kmpsubst(char *s, int *pi, char *t)
{
        int q = 0, k = 0, tn, sn;
        tn = strlen(t);
	sn = strlen(s);
	//printf("%s\n", s);
	while (k < tn) {
		while ((q > 0) && (s[q] != t[k]))
			q = pi[q-1];
		if (s[q] == t[k])
			q++;
		if (q == 0)
			return 0;
		k++;
	}
	return 1;
}

void prefix(char *s, int *pi)
{
	int t = 0, i = 1, sn = strlen(s);
	pi[0] = 0;
        while (i < sn) {
		while ((t > 0) && (s[t] != s[i]))
			t = pi[t-1];
		if (s[t] == s[i])
			t++;
		pi[i] = t;
		i++;
	}
}
int main(int argc, char **argv)
{
	int sn, tn, i;
	sn = strlen(argv[1]);
	tn = strlen(argv[2]);
	//char s[sn+1], t[tn];
	//strcpy(s, argv[1]);
	//strcpy(t, argv[2]);
	//for(i = 0; i < sn; i++)
	//	s[i] = argv[1][i];
	//printf("%s - %d\n", argv[1], sn);
	int pi[sn];
	prefix(argv[1], pi);
	//for (i = 0; i < sn; i++)
	//	printf("%d ", pi[i]);
	//printf("\n");
	//printf("%s %s\n", s, t);
	if (kmpsubst(argv[1], pi, argv[2]) == 1)
		printf("yes\n");
	else
		printf("no\n");

	return 0;
}
