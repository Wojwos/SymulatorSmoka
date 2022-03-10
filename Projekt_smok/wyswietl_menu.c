#include "smok.h"
#include <stdio.h>

void wyswietl_menu(struct smok_stat smok)
{
	printf_s("Smok\n");
	printf_s("Rasa: Smok ");
	switch (smok.rasa)
	{
	case 1:
	{
		printf_s("Ognisty\n");
		break;
	}
	case 2:
	{
		printf_s("Morski\n");
		break;
	}
	case 3:
	{
		printf_s("Lesny\n");
		break;
	}
	case 4:
	{
		printf_s("Skalny\n");
		break;
	}
	}
	printf_s("Inteligencja: %d/%d\n", smok.inteligencja, smok.inteligencja_max);
	printf_s("Glod: %d/%d\n", smok.glod, smok.glod_max);
	printf_s("Prawgnienie: %d/%d\n", smok.pragnienie, smok.pragnienie_max);
	printf_s("Energia: %d/%d\n", smok.energia, smok.energia_max);
	printf_s("Zdrowie: %d/%d\n\n", smok.zdrowie, smok.zdrowie_max);
	printf_s("Wybierz co chcesz zrobic:\n");
	printf_s("1.Daj smokowi jesc\n");
	printf_s("2.Daj smokowi pic\n");
	if (smok.spi == 0)
	{
		printf_s("3.Daj smokowi odpoczac\n");
	}
	else
	{
		if (smok.energia != 0)
			printf_s("3.Obudz smoka\n");
		else
			printf_s("3.Obudz smoka (opcja zablokowana)\n");
	}
	printf_s("4.Daj smokowi lecznicze ziola\n");
	printf_s("5.Ucz smoka matematyki\n");
	printf_s("6.Udaj sie do sklepu\n");
	printf_s("7.Wyjdz z gry\n");
}