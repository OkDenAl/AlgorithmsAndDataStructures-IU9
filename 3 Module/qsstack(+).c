#include <stdio.h>
#include <stdlib.h>

typedef struct stack1 Stack;
typedef struct Task Task;

struct Task {
    int low, high;
};

struct stack1 {
    struct Task data[100000];
    int cap;
    int top;
};


Stack *initstack(int n) {
    Stack *s;
    s = (Stack*) malloc(sizeof(Stack));
    //s->data = (Task*) malloc(sizeof(Task) * (n+1));
    s->cap = n;
    s->top = 0;
    return s;
}

int checkempy(Stack *s)
{
    if (s->top==0)
        return 1;
    return 0;
}

void push(Stack *s,int left,int right) {
    s->data[s->top].low=left;
    s->data[s->top].high=right;
    s->top++;

}

Task pop(Stack *s) {
    struct Task x;

    s->top--;
    x=s->data[s->top];
    return x;
}

void swap(int* a, int* b)
{
    int buffer;
    buffer = *a;
    *a = *b;
    *b = buffer;
}

int part(Stack *s,int *a, int l, int r) {
    int mid = a[(l + r) / 2], i = l , k = r , tmp;
    while (1) {
        while (a[k] > mid)
            k--;
        while (a[i] < mid)
            i++;
        if (i >= k)
            break;
        tmp = a[i];
        a[i] = a[k];
        a[k] = tmp;
    }

    if (i<(l+r)/2) {
        if (i<r) {
            push(s,i,r);
        }
        r=k;
    }
    else {
        if (k>l)  {
            push(s,l, k);
        }
        l=i;
    }


    return k;
}

void quicksort(int *arr, int n) {
    int mid = 0,left=0,right=0,help;
    Stack *s = initstack(100000);
    Task t = { 0, n - 1};
    push(s, 0,n-1);
    while (!(checkempy(s)))  {
        t =pop(s);
        while (t.low<t.high)  {
            mid=(t.low+t.high)/2;
            left=t.low;
            right=t.high;
            help=arr[mid];
            do  {
                while (arr[left]<help)
                    left++;
                while (arr[right]>help)
                    right--;
                if (left<=right) {
                    swap(&arr[left], &arr[right]);
                    left++;
                    right--;
                }

            }  while (left<=right);

            if (left<mid) {
                if (left<t.high) {
                    push(s,left,t.high);
                }
                t.high=right;
            }
            else {
                if (right>t.low)  {
                    push(s,t.low, right);
                }
                t.low=left;
            }

        }
    }


    free(s);

}

int main()
{
    int i,n,m;
    scanf("%d", &n);
    int *a;
    a = (int *)malloc((n+1)*sizeof(int));

    for (i=0;i<n;i++)
        scanf("%d", &a[i]);
    quicksort(a,n);

    for (i=0;i<n;i++)
        printf("%d ", a[i]);


    free(a);

}
