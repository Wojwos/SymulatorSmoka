#include "smok.h"
#include <stdio.h>

struct smok_stat spanie(struct smok_stat smok)
{
	if (smok.spi == 0)
	{
		if (smok.energia == smok.energia_max)
			printf_s("Smok nie potrzebuje snu");
		else
			smok.spi = 1;
	}
	else
	{
		if (smok.energia != 0)
			smok.spi = 0;

	}
	czekaj();
	return smok;
}