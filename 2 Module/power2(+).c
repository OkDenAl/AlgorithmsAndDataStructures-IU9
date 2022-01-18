#include <stdio.h>
#pragma warning (disable: 4996)


int power2_count(int* arr, int n, int curn, int cursum) {
    int c;
    cursum += arr[curn];
    if ((cursum > 0) && ((cursum & (~cursum + 1)) == cursum))
        c = 1;
    else c = 0;
    for (int i = curn + 1; i < n; i++) {
        c += power2_count(arr, n, i, cursum);
    }
    return c;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += power2_count(arr, n, i, 0);
    }
    printf("%d", ans);
    return 0;
}