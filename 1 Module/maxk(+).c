#include <stdio.h>
#pragma warning (disable: 4996)

int main() {
    int n, k, sum = 0, max_sum;
    scanf("%d", &n);
    int Arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &Arr[i]);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        sum += Arr[i];
    }
    max_sum = sum;
    int j = 0;
    while (k < n) {
        sum -= Arr[j++];
        sum += Arr[k++];
        if (sum > max_sum)
            max_sum = sum;
    }
    printf("%d", max_sum);
    return 0;
}