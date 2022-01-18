#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Queue
{
  int * data;
  unsigned long count, head,tail,cap;
};

struct Queue InitQueue()
{
  struct Queue helper;
  helper.data=malloc(4*sizeof(int));
  helper.count=0;
  helper.head=0;
  helper.tail=0;
  helper.cap=4;
  return helper;
}

int main()
{
  unsigned long n,i,j,k,temp;
  scanf("%lu",&n);
  char str[6];
  struct Queue queue;
  queue = InitQueue();
  for (i=0;i<n;i++) {
    scanf("%s",str);
    if (!(strcmp(str,"ENQ")))  {
      if (queue.count==queue.cap) {
        queue.data=realloc(queue.data,2*queue.cap*sizeof(int));
	for (j=0;j<queue.tail;j++) queue.data[queue.cap+j]=queue.data[j];
	queue.tail=queue.cap+j;
	queue.cap*=2;
      }
      scanf("%lu",&temp);
      queue.data[queue.tail]=temp;
      ++queue.tail;
      ++queue.count;
      if (queue.tail==queue.cap) queue.tail=0;
    }
    if (!(strcmp(str,"DEQ"))) {
      printf("%d\n",queue.data[queue.head]);
      ++queue.head;
      queue.count--;
      if (queue.head==queue.cap) queue.head=0;
    }
    if (!(strcmp(str,"EMPTY"))) if (queue.count==0) printf("true\n"); else printf("false\n");
  }
  free(queue.data);
  return 0;
}
