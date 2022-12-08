#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
int EnterBid (int b,int money){
	do{
	printf ("Enter bid:");
	scanf ("%d", &b);
	if (b>money)
	{
	printf ("---------WARNING---------\n");
	printf ("Not enough money on your account\n");

	}
	else{
	if (b<1){
	printf ("---------WARNING---------\n");
	printf ("Bid must be more than 1$\n");
	}
	}
} while (b>money || b<1);
return b; 
}