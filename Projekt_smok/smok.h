#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <crtdbg.h>

struct smok_stat
{
	int zdrowie_max, zdrowie, glod_max, glod, pragnienie_max, pragnienie, energia, energia_max, inteligencja, inteligencja_max;
	int spi, leczenie;
	int rasa, etap;
	time_t czas_jajko;
	time_t czas_zapisany;
	int wyjscie;
};

struct sklep
{
	int typ;
	struct sklep *nast;
};

int istnienie_pliku();
struct smok_stat wczytywanie(struct smok_stat smok, int argc, char *argv);
void zapisywanie(struct smok_stat smok, int argc, char *argv);
struct smok_stat wybor(struct smok_stat smok);
struct smok_stat tworzenie_smoka(struct smok_stat smok);
void czekaj();
struct smok_stat etap1(struct smok_stat smok);
struct smok_stat symulacja(struct smok_stat smok);
struct smok_stat tworzenie_duzego_smoka(struct smok_stat smok);
void wyswietl_menu(struct smok_stat smok);
struct smok_stat matematyka(struct smok_stat smok);
struct smok_stat jedzenie(struct smok_stat smok);
struct smok_stat picie(struct smok_stat smok);
struct smok_stat spanie(struct smok_stat smok);
struct smok_stat leczenie(struct smok_stat smok);
struct smok_stat zakupy(struct smok_stat smok);
struct smok_stat etap2(struct smok_stat smok);
struct smok_stat etap3(struct smok_stat smok);
struct smok_stat menu_etap(struct smok_stat smok);