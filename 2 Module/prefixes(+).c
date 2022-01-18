#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable: 4996)

void pref_foo(char* str, int* pref) {
    pref[0] = 0;
    for (int i = 1; i < strlen(str); i++) {
        int j = pref[i - 1];
        while (j > 0 && str[i] != str[j]) j = pref[j - 1];
        if (str[i] == str[j]) j++;
        pref[i] = j;
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        return 0;
    }
    char* s = argv[1];
    int* pref = (int*)malloc(strlen(s) * sizeof(int));
    pref_foo(s, pref);
    for (int i = 1; i < strlen(s); i++) {
        if ((pref[i] > 0) && ((i+1) % ((i+1)- pref[i])==0))
                printf("%d %d\n", i + 1, (i + 1) / ((i + 1) - pref[i]));
        }

    free(pref);
    return 0;
}
