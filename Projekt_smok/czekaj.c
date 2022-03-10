#include "smok.h"
#include <stdio.h>
#include <time.h>

void czekaj()  //Czas po którym program wykona ponownie polecenia
{
	clock_t a;
	a = clock() + 1 * CLOCKS_PER_SEC;
	while (clock() < a) {}
}