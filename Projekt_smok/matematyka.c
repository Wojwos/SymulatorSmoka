#include "smok.h"
#include <stdio.h>

menu_matematyka(struct smok_stat smok)
{
	system("cls");
	if (smok.energia > 1)
	{
		printf_s("Wybierz czego chcesz uczyæ smoka: \n");
		if (smok.inteligencja <= 3)
		{
			printf_s("1.Dodawania\n");
			printf_s("2.Odejmowania (zablokowane)\n");
			printf_s("3.Mnozenia (zablokowane)\n");
		}
		if (smok.inteligencja > 3&& smok.inteligencja < 5)
		{
			printf_s("1.Dodawania (Smok juz to umie)\n");
			printf_s("2.Odejmowania\n");
			printf_s("3.Mnozenia (zablokowane)\n");
		}
		if (smok.inteligencja >= 5&& smok.inteligencja != 5)
		{
			printf_s("1.Dodawania (Smok juz to umie)\n");
			printf_s("2.Odejmowania (Smok juz to umie)\n");
			printf_s("3.Mnozenia\n");
		}
		if (smok.inteligencja == 10)
		{
			printf_s("1.Dodawania (Smok juz to umie)\n");
			printf_s("2.Odejmowania (Smok juz to umie)\n");
			printf_s("3.Mnozenia (Smok juz to umie)\n");
		}

	}
	else
	{
		printf_s("Smok jest zbyt zmeczony\n");
	}
}

void pytania()
{
	printf_s("1.Tak\n");
	printf_s("2.Wynik jest wiekszy\n");
	printf_s("3.Wynik jest mniejszy\n");
}

int przedzial(int liczba)
{
	printf_s("Podaj liczbe z przedzialu <0,100>\n");
	scanf_s("%d", &liczba);
	if (liczba >= 0 && liczba <= 100)
		return liczba;
	else
		return przedzial(liczba);
}

int przedzial_mno(int liczba)
{
	printf_s("Podaj liczbe z przedzialu <0,100>\n");
	scanf_s("%d", &liczba);
	if (liczba >= 0 && liczba <= 10)
		return liczba;
	else
		return przedzial(liczba);
}

int przedzial_ode(int liczba,int a)
{
	printf_s("Podaj liczbe z przedzialu <0,%d>\n",a);
	scanf_s("%d", &liczba);
	if (liczba >= 0 && liczba <= a)
		return liczba;
	else
		return przedzial(liczba);
}

char odpowiedz(int x, int y, int c_smoka)
{
	char znak;
	while (1)
	{
		znak = _getch();
		switch (znak)
		{
		case 49:
		{
			return 1;
			break;
		}
		case 50:
		{
			if (c_smoka + 1 == y + 1)
			{
				printf_s("Smok: To nie mozliwe!\n");
				czekaj();
				return 0;
			}
			else
			{
				return 2;
			}
			break;
		}
		case 51:
		{
			if (c_smoka - 1 == x - 1)
			{
				printf_s("Smok: To nie mozliwe!\n");
				czekaj();
				return 0;
			}
			else
			{
				return 3;
			}
			break;
		}
		default:
			break;
		}
	}
	return 0;
}

int losowanie(int c_smoka, int zakres, int x, int y)
{
	c_smoka = rand() % zakres;
	if (c_smoka > x&&c_smoka < y)
		return c_smoka;
	else
		return losowanie(c_smoka, zakres, x, y);
}

struct smok_stat dodawanie(struct smok_stat smok)
{
	int a = 101, b = 101, c, c_smoka=0, x = 0, y = 200, zakres = 201;
	char odp=0;
	a=przedzial(a);
	system("cls");
	b=przedzial(b);
	system("cls");
	c = a + b;
	if (smok.inteligencja > 3)
	{
		printf_s("Smok: Wynik to: %d\n", c);
	}
	else
	{
		while (1)
		{
			c_smoka=losowanie(c_smoka, zakres, x, y);
			printf_s("Smok: Czy wynik to: %d?\n", c_smoka);
			pytania();
			odp = odpowiedz(x, y, c_smoka);
			if (odp == 1)
				break;
			if (odp == 2)
				x = c_smoka;
			if (odp == 3)
				y = c_smoka;
		}
		if (c == c_smoka)
			smok.inteligencja++;
	}
	return smok;
}

struct smok_stat odejmowanie(struct smok_stat smok)
{
	int a = 101, b = 101, c, c_smoka=0, x = 0, y = 100, zakres = 201;
	char odp=0;
	a=przedzial(a);
	system("cls");
	b=przedzial_ode(b,a);
	system("cls");
	c = a - b;
	if (smok.inteligencja >= 5)
	{
		printf_s("Smok: Wynik to: %d\n", c);
	}
	else
	{
		while (1)
		{
			c_smoka=losowanie(c_smoka, zakres, x, y);
			printf_s("Smok: Czy wynik to: %d?\n", c_smoka);
			pytania();
			odp = odpowiedz(x, y, c_smoka);
			if (odp == 1)
				break;
			if (odp == 2)
				x = c_smoka;
			if (odp == 3)
				y = c_smoka;
		}
		if (c == c_smoka)
			smok.inteligencja++;
	}
	return smok;
}

struct smok_stat mnozenie(struct smok_stat smok)
{
	int a = 11, b = 11, c, c_smoka=0, x = 0, y = 10, zakres = 101;
	char odp=0;
	a=przedzial_mno(a);
	system("cls");
	b=przedzial_mno(b);
	system("cls");
	c = a*b;
	if (smok.inteligencja == 10)
	{
		printf_s("Smok: Wynik to: %d\n", c);
	}
	else
	{
		while (1)
		{
			c_smoka=losowanie(c_smoka, zakres, x, y);
			printf_s("Smok: Czy wynik to: %d?\n", c_smoka);
			pytania();
			odp = odpowiedz(x, y, c_smoka);
			if (odp == 1)
				break;
			if (odp == 2)
				x = c_smoka;
			if (odp == 3)
				y = c_smoka;
		}
		if (c == c_smoka)
			smok.inteligencja++;
	}
	return smok;
}

struct smok_stat matematyka(struct smok_stat smok)
{
	char znak;
	menu_matematyka(smok);
	while (1)
	{
		znak = _getch();
		switch (znak)
		{
		case 49:
		{
			system("cls");
			smok = dodawanie(smok);
			return smok;
			break;
		}
		case 50:
		{
			if (smok.inteligencja > 3 && smok.etap == 2)
			{
				system("cls");
				smok = odejmowanie(smok);
				return smok;
			}
			break;
		}
		case 51:
		{
			if (smok.inteligencja < 10 && smok.etap == 3)
			{
				system("cls");
				smok = mnozenie(smok);
				return smok;
			}
			break;
		}
		default:
			break;
		}
	}
	return smok;
}
