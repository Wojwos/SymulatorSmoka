#include "smok.h"
#include <stdio.h>

struct smok_stat picie(struct smok_stat smok)
{
	if (smok.spi == 0)
	{
		if (smok.pragnienie < smok.pragnienie_max)
			smok.pragnienie++;
		else
			printf_s("Smok nie chce juz pic");
	}
	else
		printf_s("Smok spi nie mozesz dac mu pic");
	czekaj();
	return smok;
}