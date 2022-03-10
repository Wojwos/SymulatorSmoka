#include "smok.h"
#include <stdio.h>

struct smok_stat leczenie(struct smok_stat smok)
{
	if (smok.spi == 0)
	{
		if (smok.leczenie == 1)
			printf_s("Smok jest juz leczony");
		else
		{
			if (smok.zdrowie == smok.zdrowie_max)
				printf_s("Smok jest zdrowy, nie potrzebuje ziol");
			else
				smok.leczenie = 1;
		}
	}
	else
		printf_s("Smok spi nie mozesz dac mu ziol");
	czekaj();
	return smok;
}