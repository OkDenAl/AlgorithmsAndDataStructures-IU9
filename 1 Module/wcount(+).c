#include<stdio.h>

int wcount(char *s)
{
  int i,k=0;
  for (i=0;s[i];i++) {
    if (((s[i+1]==' ')||(s[i+1]=='\0'))&&(s[i]!=' ')) k++;
  }
  return (k);

}
main()
{
  int wcount(char *s);
  int i;
  char s[100];
  gets(s);
  printf("%d",wcount(s));
}
