#include "smok.h"
#include <stdio.h>

struct smok_stat jedzenie(struct smok_stat smok)
{
	if (smok.spi == 0)
	{
		if (smok.glod < smok.glod_max)
			smok.glod++;
		else
			printf_s("Smok jest juz najedzony");
	}
	else
		printf_s("Smok spi nie mozesz go nakarmic");
	czekaj();
	return smok;
}