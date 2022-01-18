#include <stdlib.h>
#include <stdio.h>

int *a;
int *p;

int compare(unsigned long i, unsigned long j)
{
        if (abs(a[i]) == abs(a[j])) return 0;
        return abs(a[i]) < abs(a[j]) ? -1 : 1;
}

void swap(unsigned long i, unsigned long j)
{
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
}

void vstavka(unsigned long low, unsigned long high,
             int (*compare)(unsigned long i, unsigned long j),
	     void (*swap)(unsigned long i, unsigned long j))
{
  int i,loc;
  for (i=(low+1);i<(high+1);i++) {
    loc=i-1;
    if (loc>=0) {
      while ((loc>=low)&&(compare(loc,loc+1)>0)) {
	swap(loc,(loc+1));
	loc--;
	if (loc==(-1)) break;
      }
    }
  }
}

void merge(unsigned long low, unsigned long high,
	   int (*compare)(unsigned long i, unsigned long j),
	   void (*swap)(unsigned long i, unsigned long j))
{
  int h,i,j,med;
  med=(low+high)/2;
  int * temp = (int *)malloc((high-low+1)*sizeof(int));
  i=low;
  j=med+1;
  for (h = 0; h < (high-low+1);h++) {
    if ((j<=high) && ((i==med+1) || (compare(j,i)<0))) {
      temp[h]=a[j];
      j++;
    }
    else {
     temp[h]=a[i];
     i++;
    }
  }
  for (i=low,j=0;i<(high+1),j<h;i++,j++)
    a[i]=temp[j];
  free(temp);
}


void mergerec(unsigned long low,unsigned long high,
	      int (*compare)(unsigned long i, unsigned long j),
	      void (*swap)(unsigned long i, unsigned long j))
{
  unsigned long med,i,j,h,k,l,loc;
  if ((high-low)!=0){
      if ((high-low)>4) {
	med=(high+low)/2;
	mergerec(low, med, compare, swap);
	mergerec((med+1), high, compare, swap);
	merge(low,high,compare,swap);
      }
      else vstavka(low,high,compare,swap);
  }
}

int main(int argc, char **argv)
{
        int i, n;
        scanf("%d", &n);
        a = (int*)malloc(n * sizeof(int));
        for (i = 0; i < n; i++) scanf("%d", a+i);
        mergerec(0,(n-1), compare, swap);
        for (i = 0; i < n; i++) printf("%d ", a[i]);
        free(a);
        return 0;
}
