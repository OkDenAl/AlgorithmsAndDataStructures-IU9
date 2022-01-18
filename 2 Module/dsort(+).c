#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void directionsort(char *a, unsigned long n)
    {
        long i,j,count[26]={0};
        char b[n];
        char k;
        for (i=0;i<n;i++)
        {
            k = a[i] - 97;
            count[(int)k]++;
        }

        for (i=1;i<26;i++)
            count[i]=count[i]+count[i-1];
        i = n - 1;
        while (i>=0)
        {
            k = a[i] - 97;
            j = count[k] - 1;
            count[k] = j;
            b[j]=a[i];
            i--;
        }

        for (i=0;i<n;i++)
            putchar(b[i]);


    }

int main()
{
    char a[1000000];
    unsigned long n;
    gets(a);
    n = strlen(a);
    directionsort(a , n);




}
