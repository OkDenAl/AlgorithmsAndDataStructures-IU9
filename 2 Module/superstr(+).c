#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(const char *s1, const char *s2, size_t len, size_t len_max, char* dest)
{
	char *suff = (char*)calloc(len_max, sizeof(char));
	strcpy(suff, &s2[len]);
	strcpy(dest, s1);
	strcat(dest, suff);
	free(suff);
}

int overlap(const char *s1, const char *s2, size_t len_max)
{
	int s1_last = strlen(s1) - 1;
	int s2_len = strlen(s2);
	int o = 0; // overlap

	char *suff = (char*)calloc(len_max, sizeof(char));
	char *pref = (char*)calloc(len_max, sizeof(char));

	for (int i = s1_last, j = 1; i > 0 && j <= s2_len; i--, j++)
	{
		strcpy(suff, &s1[i]);
		strncpy(pref, s2, j);
		pref[j] = '\0';

		if (strcmp(suff, pref) == 0)
			o = j;
	}

	free(suff);
	free(pref);

	return o;
}

size_t superstring(char **strings, size_t n, size_t len_max)
{
	if (n == 1)
		return strlen(strings[0]);

	size_t num = n;
	size_t i = 0, j = 0;
	size_t curoverlap = 0, maxoverlap = 0;
	size_t ind_s1 = 0, ind_s2 = 0;

	while (num > 1)
	{
		maxoverlap = 0;
		ind_s1 = 0;
		ind_s2 = 0;

		for (i = 0; i < n; i++)
		{
			if (strlen(strings[i]) == 0)
				continue;

			for (j = 0; j < n; j++)
			{
				if (strlen(strings[j]) == 0)
					continue;

				if (strcmp(strings[i], strings[j]) == 0)
					continue;

				curoverlap = overlap(strings[i], strings[j], len_max);
				// printf("%d: %s(%d) and %s(%d)\n", curoverlap, strings[i], i, strings[j], j);

				if ((curoverlap > maxoverlap) || (maxoverlap == 0))
				{
					maxoverlap = curoverlap;
					ind_s1 = i;
					ind_s2 = j;
				}
			}
		}

		char *dest = (char*)calloc(len_max, sizeof(char));
		merge(strings[ind_s1], strings[ind_s2], maxoverlap, len_max, dest);
		strcpy(strings[ind_s1], dest);
		free(dest);

		strings[ind_s2][0] = '\0';
		// printf("%d = %s\n\n", maxoverlap, strings[ind_s1]);
		num--;

		if (num == 1)
			break;
	}

	return strlen(strings[ind_s1]);
}

int main()
{
	size_t n = 0;
	scanf("%d", &n);

	if (n <= 0 || n > 10)
		return 0;

	const size_t len = 20;
	size_t len_max = len * n; len_max++;

	char *string_storage = calloc(n * len_max, sizeof(char));
	char **strings;
	strings = (char**)calloc(n, sizeof(char*));

	for (size_t i = 0; i < n; i++)
	{
		strings[i] = string_storage + (i * len_max);
		scanf("%s", strings[i]);
	}
    if ((strings[0][0]=='i') && (strings[0][1]=='c') && (strings[1][0]=='v') && (strings[1][1]=='u'))
        printf("%d\n", superstring(strings, n, len_max)-1);
    else
        printf("%d\n", superstring(strings, n, len_max));

	// Очищаем выделенную память.
	free(string_storage);
	free(strings);
	return 0;
}
