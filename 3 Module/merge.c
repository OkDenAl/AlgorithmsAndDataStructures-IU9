#include<stdio.h>
#include<stdlib.h>

struct key {
  int a,number;
};

struct key InitKey(arr,number){
  struct key helper;
  helper.a=arr;
  helper.number=number;
  return helper;
}

struct ptr {
 int index;
 struct key key;
 int value;
};

struct ptr InitPtr(int index,int arr,int i,int value)
{
  struct ptr helper;
  helper.index=index;
  struct key key;
  key=InitKey(arr,i);
  helper.key=key;
  helper.value=value;
  return helper;
}

struct Queue{
  struct ptr *heap;
  int cap,count;
};

struct Queue InitQueue(int n)
{
  struct Queue helper;
  helper.heap=malloc(n*sizeof(struct ptr));
  helper.cap=n;
  helper.count=0;
  return helper;
}

struct ptr Minimum(struct Queue *q)
{
  if (q->count==0) printf("Pusto");
  return q->heap[0];
}

int QueueEmpty(struct Queue *q)
{
  return (q->count==0)? 1:0;
}

void swap(struct Queue *q,int i,int j)
{
  struct ptr t;
  t=q->heap[i];
  q->heap[i]=q->heap[j];
  q->heap[j]=t;
}

void Insert(struct Queue *q, struct ptr ptr)
{
  int i=q->count;
  if (i==q->cap) printf("perepolnenie");
  else {
    q->count=i+1;
    q->heap[i]=ptr;
    while (i>0 && (q->heap[(i-1)/2].value > q->heap[i].value)) {
      swap(q,i,(i-1)/2);
      q->heap[i].index=i;
      i=(i-1)/2;
    }
    q->heap[i].index=i;
  }
}

void Heapify(struct Queue *q,int i, int n)
{
  int l,r,j;
  while (1==1) {
    l=2*i+1;
    r=l+1;
    j=i;
    if (l<n && q->heap[i].value > q->heap[l].value)
      i=l;
    if (r<n && q->heap[i].value > q->heap[r].value)
      i=r;
    if (i==j)
      break;
    swap(q,i,j);
    q->heap[i].index=i;
    q->heap[j].index=j;
  }
}

struct ptr ExtractMin(struct Queue *q)
{
  struct ptr ptr;
  if (q->count==0) printf("Pusto");
  else {
    ptr=q->heap[0];
    q->count--;
    if (q->count>0) {
      q->heap[0]=q->heap[q->count];
      q->heap[0].index=0;
      Heapify(q,0,q->count);
    }
  }
}

int main()
{
  int n,i;
  struct ptr ptr;
  scanf("%d",&n);
  int* sizes=malloc(n*sizeof(int));
  for (i=0;i<n;i++)
    scanf("%d",sizes+i);
  int j;
  int **arr=malloc(n*sizeof(int *));
  struct Queue q;
  q=InitQueue(n);
  for (i=0;i<n;i++){
    arr[i]=malloc(sizes[i]*sizeof(int));
    for (j=0;j<sizes[i];j++) {
      scanf("%d",&arr[i][j]);
      if (j==0 && sizes[i]) {
        ptr=InitPtr(q.count,i,0,arr[i][0]);
        Insert(&q,ptr);
      }
    }
  }
  while (q.count) {
    ptr=Minimum(&q);
    ExtractMin(&q);
    printf("%d ",ptr.value);
    if (ptr.key.number==sizes[ptr.key.a]-1) continue;
    else {
      ptr=InitPtr(q.count,ptr.key.a,ptr.key.number+1,arr[ptr.key.a][ptr.key.number+1]);
      Insert(&q,ptr);
    }
  }
    for (i=0;i<n;i++)
      free(arr[i]);
    free(arr);
    free(q.heap);
    free(sizes);
  return 0;
}
