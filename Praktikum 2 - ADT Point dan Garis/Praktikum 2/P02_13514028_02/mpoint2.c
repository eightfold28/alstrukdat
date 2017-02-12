/*NIM/ Nama = 13514028/ Dharma Kurnia Septialoka
 * Nama File= P02_13514028_mpoint2.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "point2.h"


int main()
{
	POINT p;
    POINT p1;
    int x;
    float r, delta;
	boolean SbX;
	
    BacaPoint(&p);
    BacaPoint(&p1);
    scanf("%f", &r);
    scanf("%d", &x);
    if (x==1)
    {
		SbX = true;
	}
	if (x==0)
	{
		SbX = false;
	}
	
    scanf("%f", &delta);
    
    if (DalamRange(p,p1,r) == true)
    {
		printf("1\n");
	}
    else 
    {
		printf("0\n");
	}
	GlideReflection(&p, SbX, delta);
	TulisPoint(p);
    
	return 0;
}
