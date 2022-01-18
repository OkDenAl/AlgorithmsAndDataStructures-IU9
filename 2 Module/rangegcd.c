#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int gcd(int a, int b)
{
  if (a&&b) {
    if (abs(a)>abs(b)) gcd(a%b,b);
    else gcd(a,b%a);
  }
  else {
    if (a) return abs(a);
    else return abs(b);
  }
}

void SparseTableBuild(int*V, int**ST,int n,int m)
{
  int i,j;
  for (i=0;i<n;i++) ST[i][0]=V[i];
  j=1;
  while (j<m) {
    i=0;
    while (i<=(n-(1<<j))) {
      ST[i][j]=gcd(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
      i++;
    }
    j++;
  }
}

int main()
{
  int n,i,j,l,r,o;
  scanf("%d",&n);
  int m=log2(n)+1;
  int *V=calloc(n,sizeof(int));
  int **ST=malloc(2*n*sizeof(int*));
  for (i=0;i<n;scanf("%d", &V[i]),i++)
     ST[i]=malloc((2*m)*sizeof(int));
  SparseTableBuild(V,ST,n,m);
  scanf("%d",&o);
  for (i=0;i<o;i++) {
    scanf("%d %d",&l,&r);
    j=log2(r-l+1);
    printf("%d\n",gcd(ST[l][j],ST[r-(1<<j)+1][j]));
  }
  for (i=0;i<n;i++)
    free(ST[i]);
  free(ST);
  free(V);
}
