#include "smok.h"
#include <stdio.h>

struct smok_stat symulacja(struct smok_stat smok)
{
	if (smok.glod > 0)
		smok.glod--;
	if (smok.pragnienie > 0)
		smok.pragnienie--;
	if (smok.spi == 1)
	{
		if (smok.energia < smok.energia_max)
		{
			smok.energia++;
			if (smok.energia == smok.energia_max)
				smok.spi = 0;
		}
	}
	else
		smok.energia--;
	if (smok.energia == 0)
		smok.spi = 1;
	if (smok.glod == 0)
		smok.zdrowie--;

	if (smok.pragnienie == 0)
		smok.zdrowie--;
	if (smok.leczenie)
	{
		if (smok.zdrowie < smok.zdrowie_max)
			smok.zdrowie++;
		else
			smok.leczenie = 0;
	}
	return smok;
}