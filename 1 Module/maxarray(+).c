#include <stdio.h>
#pragma warning (disable: 4996)

int compare(void* a, void* b) {
    return *((int*) a) > *((int*) b);
}

int maxarray(void* base, size_t nel, size_t width,
    int (*compare)(void* a, void* b)) {
    int i_max = 0;
    unsigned char *max_el = ((unsigned char*)base);
    for (int i = 0; i < nel; i++) {
        if (compare(((unsigned char*)base + i * width), max_el)>0)
        {
            max_el = ((unsigned char*)base + i * width);
            i_max = i;
        }
    }
    return i_max;
}

int main() {
    long arr[5]={100000,2000000000,9000000,5000,400};
    int max_i = maxarray(arr, 5, sizeof(long), compare);
    printf("%d", max_i);
    return 0;
}
