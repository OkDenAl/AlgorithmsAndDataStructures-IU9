#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable: 4996)


typedef struct {
    int Day;
    int Month;
    int Year;
} Date;

void count_sort_Day(Date * arr, int n) {
    int counter[32] = {};
    for (int i = 0; i < n; i++) {
        counter[arr[i].Day]++;
    }
    for (int i = 1; i < 32; i++)
        counter[i] += counter[i - 1];
    Date helper[n];
    for (int i = n - 1; i >= 0; --i) {
        helper[--counter[arr[i].Day]] = arr[i];
    }
    for (int i = 0; i < n; i++)
        arr[i] = helper[i];
}

void count_sort_Month(Date* arr, int n) {
    int counter[13] = {};
    for (int i = 0; i < n; i++) {
        counter[arr[i].Month]++;
    }
    for (int i = 1; i < 13; i++)
        counter[i] += counter[i - 1];
     Date helper[n];
    for (int i = n - 1; i >= 0; --i) {
        helper[--counter[arr[i].Month]] = arr[i];
    }
    for (int i = 0; i < n; i++)
        arr[i] = helper[i];
}

void count_sort_Year(Date* arr, int n) {
    int counter[62] = {};
    for (int i = 0; i < n; i++) {
        counter[arr[i].Year-1970]++;
    }
    for (int i = 1; i < 62; i++)
        counter[i] += counter[i - 1];
    Date helper[n];
    for (int i = n - 1; i >= 0; --i) {
        helper[--counter[arr[i].Year - 1970]] = arr[i];
    }
    for (int i = 0; i < n; i++)
        arr[i] = helper[i];
}

int main() {
    int n;
    scanf("%d", &n);
    Date arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &arr[i].Year, &arr[i].Month, &arr[i].Day);
    }
    count_sort_Day(arr,n);
    count_sort_Month(arr, n);
    count_sort_Year(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d %02d %02d\n", arr[i].Year, arr[i].Month, arr[i].Day);
    }
    return 0;
}
