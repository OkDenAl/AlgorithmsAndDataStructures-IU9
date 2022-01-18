#include <stdlib.h>
#include <stdio.h>

int *array;

int compare(int i, int j)
{
        if (array[i] == array[j]) return 0;
        return array[i] < array[j] ? -1 : 1;
}

void swap(int i, int j)
{
        int t = array[i];
        array[i] = array[j];
        array[j] = t;
}

void selectSort(int l, int r)
{
  int j,k,i;
  for (j=r;j>l;j--) {
    k=j;
    i=j-1;
    while (i>=l) {
      if (compare(k,i)<0)
        k=i;
      i=i-1;
    }
    swap(j,k);
  }
}

int partition(int l, int r, int (*compare)(int i, int j),
	  void (*swap)(int i, int j))
{
  int i=l,j;
  for(j=l;j<r;j++) {
    if (compare(j,r)<0) {
      swap(i,j);
      i++;
    }
  }
  swap(i,r);
  return i;
}

void qqsort(int m, int l, int r, int (*compare)(int i, int j),
        void (*swap)(int i, int j))
{
  int q;
  while (((r-l+1)>=m) && (l<r)) {
      q=partition(l,r,compare,swap);
      qqsort(m,l,q-1,compare,swap);
      l=q+1;
  }
  selectSort(l,r);
}

int main(int argc, char **argv)
{
	int i, n, m;
        scanf("%d", &n);
	scanf("%d",&m);

        array = (int*)malloc(n * sizeof(int));
        for (i = 0; i < n; i++) scanf("%d", array+i);

        qqsort(m, 0, n-1, compare, swap);
        for (i = 0; i < n; i++) printf("%d ", array[i]);

        free(array);
        return 0;
}
