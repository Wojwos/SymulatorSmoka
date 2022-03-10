#include "smok.h"
#include <stdio.h>
#include <conio.h>
#include <time.h>

struct smok_stat etap2(struct smok_stat smok)
{
	int long long czas = 0, czas_max=900;
	char znak, koniec = 0;
	wyswietl_menu(smok);
	time_t czas_teraz = time(NULL);
	while (1)    //II etap: m³ody smok
	{
		time_t czas_teraz = time(NULL);
		czas = czas_teraz - smok.czas_zapisany;
		if (czas >= 3600 && smok.inteligencja==5)
			break;
		if (smok.wyjscie != 0)
			break;
		if (koniec == 1)
			break;
		if (_kbhit() == 1)
		{
			system("cls");
			znak = _getch();
			switch (znak)
			{
			case 49:
			{
				smok = jedzenie(smok);
				break;
			}
			case 50:
			{
				smok = picie(smok);
				break;
			}
			case 51:
			{
				smok = spanie(smok);
				break;
			}
			case 52:
			{
				smok = leczenie(smok);
				break;
			}
			case 53:
			{
				if (smok.spi == 0)
					smok = matematyka(smok);
				else
					printf_s("Smok spi nie mozesz go uczyc");
				czekaj();
				break;
			}
			case 54:
			{
				smok=zakupy(smok);
				break;
			}
			case 55:
			{
				smok.wyjscie = 1;
				break;
			}
			default:
			{
				break;
			}
			}
			system("cls");
			wyswietl_menu(smok);
		}
		if (czas > czas_max)
		{
			czas_max = czas_max + 900;
				smok = symulacja(smok);
				if (smok.zdrowie <= 0)
				{
					koniec = 1;
					break;
				}
			system("cls");
			wyswietl_menu(smok);
		}
	}
	system("cls");
	if (koniec == 1)
		smok.wyjscie = 2;
	if (smok.wyjscie == 0)
		smok = tworzenie_duzego_smoka(smok);
	return smok;
}