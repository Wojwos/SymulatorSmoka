#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "smok.h"
#include <crtdbg.h>

int main(int argc, char *argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	struct smok_stat smok;
	smok.czas_jajko = time(NULL);
	smok.czas_zapisany = time(NULL);
	smok.wyjscie = 0;
	smok.etap = 0;
	smok = wczytywanie(smok, argc, *argv);
	smok = menu_etap(smok);
	if (smok.wyjscie == 1)
		zapisywanie(smok, argc, *argv);
	if (smok.wyjscie == 2)
	{
		printf_s("Koniec gry");
		czekaj();
		remove("smok.dat");
	}
	return 0;
}











