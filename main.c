#include <stdio.h>
#include <stdlib.h>
#include "lapacho.h"



double** array_to_matrix(double* m, size_t rows, size_t cols) {
  size_t  i,j;
 double** r;
  r = (double**)calloc(rows,sizeof(double*));
  for(i=0;i<rows;i++)
  {
    r[i] = (int*)calloc(cols,sizeof(double));
    for(j=0;j<cols;j++)
      r[i][j] =-m[i*cols+j];
  }
  return r;
}


int main()
{
size_t m=5,n=5;
int index_count;
long *rows = NULL, *cols = NULL;
rows = (long *)calloc(m, sizeof(long));
cols = (long *)calloc(n, sizeof(long));


double ta[]={5,5,4,6,8,4,5,4,7,8,5,5,4,6,8,4,5,4,7,8,1,1,1,1,1};


double **p=array_to_matrix(ta,m,n);

    /* Run the matching algorithm */
index_count = hungarian(p, m, n, rows, cols);

for (int i=0;i<index_count;i++)

{
printf("%ld\t",rows[i]);
printf("%ld\t",cols[i]);
printf("\n");
}


free(rows);
free(cols);


return index_count;

}
