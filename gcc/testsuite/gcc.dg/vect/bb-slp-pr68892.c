/* { dg-do compile } */
/* { dg-additional-options "-fvect-cost-model=dynamic" } */
/* { dg-require-effective-target vect_double } */

double a[128][128];
double b[128];

void foo(void)
{
  b[0] = a[0][0];
  b[1] = a[1][0];
  b[2] = a[2][0];
  b[3] = a[3][0];
}

/* ???  Due to the gaps we fall back to scalar loads which makes the
   vectorization profitable.  */
/* { dg-final { scan-tree-dump "not profitable" "slp2" { xfail { ! aarch64*-*-* } } } } */
/* { dg-final { scan-tree-dump "BB vectorization with gaps at the end of a load is not supported" "slp2" } } */
/* { dg-final { scan-tree-dump-times "Basic block will be vectorized" 1 "slp2" { xfail aarch64*-*-* } } } */
