#include <stdio.h>
#include "point2.h"

int main()
{
	//KAMUS
	float r, delta;
	POINT p,p1;
	int dummy;
	boolean SbX;

	//Algoritma

	BacaPoint(&p);
	BacaPoint(&p1);


	scanf("%f",&r);
	scanf("%d",&dummy);
	if (dummy==1)
		SbX = true;
	else
		SbX = false;
	scanf("%f",&delta);


	//OUTPUT

	if (DalamRange(p,p1,r)==true)
		printf("1\n");
	else
		printf("0\n");

	GlideReflection (&p,SbX,delta);

	TulisPoint(p);


	return 0;
}
