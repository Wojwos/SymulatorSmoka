#include "smok.h"
#include <stdio.h>

void wczytaj_sklep(struct sklep *program)
{
	struct sklep *wsk, *nowy;
	wsk = program;
	int dane;
	FILE *plik;
	fopen_s(&plik, "sklep.txt","r");
	fscanf_s(plik, "%d", &dane);
	wsk->typ = dane;
	printf_s("DANE: %d WSK: %d\n", dane, wsk->typ);
	for(int i=0;i<11;i++)
	{
		fscanf_s(plik, "%d", &dane);
		nowy = malloc(sizeof(struct sklep));
		nowy->typ = dane;
		nowy->nast = NULL;
		wsk->nast = nowy;
		printf_s("DANE: %d WSK: %d\n", dane, wsk->typ);
		if(i<10)
		wsk = wsk->nast;
	}
	fclose(plik);
}

struct smok_stat dzialanie(struct smok_stat smok, struct sklep *wsk)
{
	switch (wsk->typ)
	{
	case 1:
	{
		smok = jedzenie(smok);
		break;
	}
	case 2:
	{
		smok = picie(smok);
		break;
	}
	case 3:
	{
		smok = leczenie(smok);
		break;
	}
	default:
		break;
	}
	return smok;
}

void usuwanie(struct sklep *produkt)
{
	struct sklep *wsk;
	while(produkt != NULL)
	{
		wsk = produkt;
		produkt = produkt->nast;
		free(wsk);
	}
}

struct smok_stat zakupy(struct smok_stat smok)
{
	struct sklep *produkt;
	produkt = malloc (sizeof(struct sklep));
	produkt->typ = 1;
	produkt->nast = NULL;
	int numer;
	int i=1;
	wczytaj_sklep(produkt);
	system("cls");
	struct sklep *wsk;
	wsk = produkt;
	printf_s("Wybierz co chcesz kupic: \n");
	while (1)
	{
		if(wsk->typ==1)
		printf_s("%d.%s\n", i, "jedzenie");
		if (wsk->typ == 2)
		printf_s("%d.%s\n", i, "napoj");
		if (wsk->typ == 3)
		printf_s("%d.%s\n", i, "lek");
		if (wsk->nast == NULL)
			break;
		wsk = wsk->nast;
		i++;
	}
	wsk = produkt;
	scanf_s("%d", &numer);
	i = 1;
	while(1)
	{
		if (wsk == NULL)
			break;
		if (i==numer)
		{
			smok = dzialanie(smok, wsk);
			break;
		}
		wsk = wsk->nast;
		i++;
	}
	usuwanie(produkt);
	return smok;
}