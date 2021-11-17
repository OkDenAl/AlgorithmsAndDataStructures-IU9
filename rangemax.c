#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

void Segment_Tree_Build(int* arr,int i, int a, int b, int*T) {
	if (a == b) {
		T[i] = arr[a];
	}
	else {
		int mid = b - ((b - a + 1) / 2);
		Segment_Tree_Build(arr, 2 * i + 1, a, mid,T);
		Segment_Tree_Build(arr, 2 * i + 2, mid+1, b, T);
		T[i] = max(T[2 * i + 1], T[2 * i + 2]);
	}
}

int Segment_Tree_Query(int l, int r, int* T, int i, int a, int b) {
	if (l == a && r==b) {
		return T[i];
	}
	else {
		int mid = b - ((b - a + 1) / 2);
		if (r <= mid) {
			return Segment_Tree_Query(l, r, T, 2 * i + 1, a, mid);
		}
		else if (l > mid) {
			return Segment_Tree_Query(l, r, T, 2 * i + 2, mid + 1, b);
		}
		else {
			return max(Segment_Tree_Query(l, mid, T, 2 * i + 1, a, mid), 
				Segment_Tree_Query(mid + 1, r, T, 2 * i + 2, mid + 1, b));
		}
	}
}

void Segment_Tree_UPD(int Update_i, int i, int NewValue, int a, int b, int* T) {
	if (a == b) {
		T[i] = NewValue;
	}
	else {
		int mid = b - ((b - a + 1) / 2);
		if (Update_i <= mid) {
			Segment_Tree_UPD(Update_i, i * 2 + 1, NewValue, a, mid, T);
		}
		else {
			Segment_Tree_UPD(Update_i, i * 2 + 2, NewValue, mid+1, b, T);
		}
		T[i] = max(T[2 * i + 1], T[2 * i + 2]);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int* T = (int*)malloc(n * 4 * sizeof(int));
	Segment_Tree_Build(arr, 0, 0, n - 1, T);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int res;
		char cond[4];
		int l, r;
		scanf("%s %d %d", &cond, &l, &r);
		if (strcmp(cond, "MAX") == 0) {
			res = Segment_Tree_Query(l, r, T, 0,0,n-1);
			printf("%d\n", res);
		}
		else if (strcmp(cond, "UPD") == 0) {
			Segment_Tree_UPD(l, 0, r, 0, n - 1, T);
		}
	}
	free(arr);
	return 0;
}
