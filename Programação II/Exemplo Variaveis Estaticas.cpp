#include <stdio.h>

void imprime ( float a )
{
static int n = 1;
printf ( " %f ", a);
if ( ( n % 5 ) == 0 ){
 
	printf( "\n “ );
n++;
}
}
