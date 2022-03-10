#include "smok.h"
#include <stdio.h>

void zapisywanie(struct smok_stat smok, int argc, char *argv)
{
	char *nazwa_pliku = "smok.dat";
	if (argc>1)
		nazwa_pliku = &argv[1];
	FILE *plik;
	fopen_s(&plik, nazwa_pliku, "w");
	fprintf_s(plik, "%d\n", smok.etap);
	fprintf_s(plik, "%d\n", smok.rasa);
	fprintf_s(plik, "%lld\n", smok.czas_jajko);
	fprintf_s(plik, "%lld\n", smok.czas_zapisany);
	fprintf_s(plik, "%d\n", smok.zdrowie);
	fprintf_s(plik, "%d\n", smok.zdrowie_max);
	fprintf_s(plik, "%d\n", smok.glod_max);
	fprintf_s(plik, "%d\n", smok.glod);
	fprintf_s(plik, "%d\n", smok.pragnienie_max);
	fprintf_s(plik, "%d\n", smok.pragnienie);
	fprintf_s(plik, "%d\n", smok.energia);
	fprintf_s(plik, "%d\n", smok.energia_max);
	fprintf_s(plik, "%d\n", smok.inteligencja);
	fprintf_s(plik, "%d\n", smok.inteligencja_max);
	fprintf_s(plik, "%d\n", smok.spi);
	fprintf_s(plik, "%d\n", smok.leczenie);
	fclose(plik);
}