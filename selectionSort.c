static int selectMax (void **ar, int left, int right,
int (*cmp)(const void *,const void *)) {
int maxPos = left;
int i = left;
while (++i <= right) {
if (cmp(ar[i], ar[maxPos])> 0) {
maxPos = i;
}
}
return maxPos;
}
void sortPointers (void **ar, int n,
int(*cmp)(const void *,const void *)) {
int i;
/* repeatedly select max in A[0,i] and swap with proper position */
for (i = n-1; i >=1; i--) {
int maxPos = selectMax (ar, 0, i, cmp);
if (maxPos != i) {
void *tmp = ar[i];
ar[i] = ar[maxPos];
ar[maxPos] = tmp;
}
}
}