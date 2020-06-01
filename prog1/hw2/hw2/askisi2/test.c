#include <stdio.h>
 
int main ( void )
{
  int a[] = {1,2,3,4,5};
  int i;
 
  for ( i = 0; i < 20; i++ )
    printf ( "%d ", a[i % 5] );
 
  printf ( "\n" );
 
  return 0;
}xar[i]=myASCII[(j+key)%PRINTED];