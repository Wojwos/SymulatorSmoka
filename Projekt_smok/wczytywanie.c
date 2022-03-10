#include "smok.h"
#include <stdio.h>

struct smok_stat wczytywanie(struct smok_stat smok, int argc, char *argv)
{
	char *nazwa_pliku = "smok.dat";
	if (argc>1)
		nazwa_pliku = &argv[1];
	if (istnienie_pliku() == 1)
	{
	FILE *plik;
	    fopen_s(&plik, nazwa_pliku, "r");
		if (plik)
		{
			fscanf_s(plik, "%d", &smok.etap);
			fscanf_s(plik, "%d", &smok.rasa);
			fscanf_s(plik, "%lld", &smok.czas_jajko);
			fscanf_s(plik, "%lld", &smok.czas_zapisany);
			fscanf_s(plik, "%d", &smok.zdrowie);
			fscanf_s(plik, "%d", &smok.zdrowie_max);
			fscanf_s(plik, "%d", &smok.glod_max);
			fscanf_s(plik, "%d", &smok.glod);
			fscanf_s(plik, "%d", &smok.pragnienie_max);
			fscanf_s(plik, "%d", &smok.pragnienie);
			fscanf_s(plik, "%d", &smok.energia);
			fscanf_s(plik, "%d", &smok.energia_max);
			fscanf_s(plik, "%d", &smok.inteligencja);
			fscanf_s(plik, "%d", &smok.inteligencja_max);
			fscanf_s(plik, "%d", &smok.spi);
			fscanf_s(plik, "%d", &smok.leczenie);
			fclose(plik);
			return smok;
		}
		fclose(plik);
	}
	return smok;
}