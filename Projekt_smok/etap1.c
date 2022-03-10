#include "smok.h"
#include <stdio.h>
#include <conio.h>

struct smok_stat etap1(struct smok_stat smok)
{
	int long long czas=0;
	time_t czas_teraz = time(NULL);
	char znak;
	printf_s("Smok powinien sie wykluc za pol godziny\n");
	printf_s("Kliknij 1 aby wyjsc\n");
	while(1)
	{
		if (_kbhit() == 1)
		{
			znak = _getch();
			if (znak == 49)
			{
				smok.wyjscie = 1;
				break;
			}
		}
		time_t czas_teraz = time(NULL);
		czas = czas_teraz - smok.czas_jajko;
		if (czas >= 900)
			break;
	}
	if (smok.wyjscie == 0)
		system("cls");
		smok = tworzenie_smoka(smok);
	return smok;
}