#include "smok.h"
#include <stdio.h>

struct smok_stat wybor(struct smok_stat smok)
{
	printf_s("Wybierz jajo smoka:\n");
	printf_s("1.Jajo smoka ognistego\n");
	printf_s("2.Jajo smoka morskiego\n");
	printf_s("3.Jajo smoka lesnego\n");
	printf_s("4.Jajo smoka skalnego\n");
	int jajo;
	while (1)
	{
		jajo = _getch();
		switch (jajo)
		{
		case 49:
		{
			smok.rasa = 1;
			smok.etap = 1;
			return smok;
			break;
		}
		case 50:
		{
			smok.rasa = 2;
			smok.etap = 1;
			return smok;
			break;
		}
		case 51:
		{
			smok.rasa = 3;
			smok.etap = 1;
			return smok;
			break;
		}
		case 52:
		{
			smok.rasa = 4;
			smok.etap = 1;
			return smok;
			break;
		}
		default:
			break;
		}
	}
}