void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
if (nel<=1)
        return;
  unsigned long t,bound1,bound2,i;
  t=0;
  bound2=nel-1;
  bound1=0;
  while (t<bound2) {
    i=bound1;
    t=bound1;
    while (i<bound2) {
      if (compare(i,i+1)>0) {
        swap(i,i+1);
        t=i;
      }
       i++;}

      bound2=t;
      i=bound2;
      t=bound2;

    while (i>bound1) {
      if (compare(i-1,i)>0) {
	swap(i-1,i);
	t=i;
	}
      i--;}

      bound1=t;
    }
}
