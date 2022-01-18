#include <stdio.h>
#include <limits.h>
#pragma warning (disable: 4996)

int const N = 8;

void fill_array(int* arr) {
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
}

int main() {
	int A[N],B[N];
	fill_array(A);
	fill_array(B);
	int f=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i] == B[j]) {
				f += 1;
				B[j] = INT_MAX;
				break;
			}
		}
	}
	if (f == N)
		printf("yes");
	else
		printf("no");
	return 0;

}