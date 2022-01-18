#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void FenwickTreeUpdate(int i, int delta, int n, int * T)
{
  while (i<n) {
    T[i]^=delta;
    i=i|(i+1);
  }
}

int build(char *stroka,int l,int r,int * T,int n)
{
  int m,sum=0;
  int bound=((r<n)? r:n);
  while (l<bound) {
    m=(l+r)/2;
    sum^=build(stroka,l,m,T,n);
    l=m+1;
  }
  if (r<n) {
    sum^=1<<(((int)stroka[r])-97);
    T[r]=sum;
  }
  return sum;
}

int query(int * T,int i)
{
  int v=0;
  while (i>=0) {
    v^=T[i];
    i=(i&(i+1))-1;
  }
  return v;
}


void FenwickTreeBuild (char * stroka, int * T,int n)
{
    int r = 1;
    while(r < n) r*=2;

    build(stroka, 0, r - 1, T, n);
}

int FenwickTreeQuery(int * T, int l, int r)
{
  int v;
  v=query(T,r)^query(T,(l-1));
  return v;
}

int main()
{
  char * stroka=(char*)malloc(1000001*sizeof(char));
  char st[3];
  fgets(stroka,1000001,stdin);
  int m;
  scanf("%d",&m);
  int n,i,j,k,v,l,r;
  n=strlen(stroka);
  int * T=(int*)malloc(n*sizeof(int));
  FenwickTreeBuild(stroka,T,n);
  for (k=0;k<m;k++) {
    scanf("%s",st);
    if (st[0]=='H') {
      scanf("%d %d",&l,&r);
      v= FenwickTreeQuery(T,l,r);
      if (((!((r-l+1)%2))&&(!v))||(((r-l+1)%2)&&(!(v&(v-1))))) printf("YES\n");
      else printf("NO\n");
    }
    else {
      int delta=0,c;
      char * stro=(char*)malloc(1000001*sizeof(char));
      scanf("%d %s",&c,stro);
      int len=strlen(stro);
      delta^=1<<(((int)stroka[c])-97);
      for (i=0;i<len;i++,c++) {
        delta=(1<<((int)stro[i]-97))^(1<<(((int)stroka[c])-97));
	FenwickTreeUpdate(c,delta,n,T);
	stroka[c]=stro[i];
      }
      free(stro);
    }
  }
  free(stroka);
  free(T);
  return 0;
}
