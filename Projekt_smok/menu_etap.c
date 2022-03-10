#include "smok.h"
#include <stdio.h>

struct smok_stat menu_etap(struct smok_stat smok)
{
	while (smok.wyjscie == 0)
	{
		switch (smok.etap)
		{
		case 0:
		{
			smok = wybor(smok);
			smok.czas_jajko = time(NULL);
			break;
		}
		case 1:
		{
			smok = etap1(smok);
			if (smok.wyjscie == 0)
			{
				smok.czas_zapisany = time(NULL);
				smok.etap = 2;
			}
			break;
		}
		case 2:
		{
			smok = etap2(smok);
			if (smok.wyjscie == 0)
				smok.etap = 3;
			break;
		}
		case 3:
		{
			smok = etap3(smok);
			break;
		}
		}
	}
	return smok;
}