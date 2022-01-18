#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Pair
{
  long value;
  long key;
};

struct Stack
{
  struct Pair *data;
  int top1;
  int top2;
  int cap;
};

struct Stack InitDoubleStack(int n)
{
  struct Stack helper;
  helper.data=malloc(n*sizeof(struct Pair));
  helper.cap=n;
  helper.top1=0;
  helper.top2=n-1;
  return helper;
}

long Pop1(struct Stack *s)
{
  s->top1--;
  struct Pair x=s->data[s->top1];

  return x.value;
}

long Pop2(struct Stack *s)
{
  s->top2++;
  struct Pair x=s->data[s->top2];

  return x.value;
}

long max(long a, long b)
{
  return (a<b)? b:a;
}

void Push1(struct Stack *s, long x)
{
  if (s->top1>s->top2) printf("perepolnenie");
  else {
    s->data[s->top1].value=x;
    if (s->top1 != 0)
      s->data[s->top1].key = max(s->data[s->top1 - 1].key, x);
    else
      s->data[s->top1].key = x;

    s->top1++;

  }
}

void Push2(struct Stack *s, long x)
{
  if (s->top2<s->top1) printf("perepolnenie");
  else {
    s->data[s->top2].value=x;
    if (s->top2 != s->cap - 1)
      s->data[s->top2].key = max(s->data[s->top2 + 1].key, x);
    else
      s->data[s->top2].key = x;

    s->top2--;
  }
}

void Enqueue(struct Stack *s, long x)
{
  Push1(s, x);
}

long Dequeue(struct Stack *s)
{
  if (s->top2==(s->cap-1))
    while (s->top1)
      Push2(s,Pop1(s));
  long x=Pop2(s);
  return x;
}

int QueueEmpty(struct Stack *s)
{
  return (!(s->top1) && (s->top2==s->cap-1))? 1:0;
}

long Maximum(struct Stack *s)
{
  if (s->top1==0)
    return s->data[s->top2+1].key;
  else if (s->top2==s->cap-1)
    return s->data[s->top1-1].key;
  else {
    long a=s->data[s->top1-1].key;
    long b=s->data[s->top2+1].key;
    return (a>b)? a:b;
  }
}

int main()
{
  int n,i;
  char str[6];
  scanf("%d", &n);
  long x;
  struct Stack s;
  s=InitDoubleStack(n);
  for (i=0;i<n;i++) {
    scanf("%s",str);
    if (str[1]=='N') {
      scanf("%ld",&x);
      Enqueue(&s,x);
    }
    if (str[1]=='E')
      printf("%ld\n",Dequeue(&s));
    if (str[1]=='A')
      printf("%ld\n",Maximum(&s));
    if (str[1]=='M') (QueueEmpty(&s))? printf("true\n"):printf("false\n");
  }
  free(s.data);
  return 0;
}
