#include "smok.h"
#include <stdio.h>

int istnienie_pliku()
{
	FILE* plik;
	fopen_s(&plik, "smok.dat", "a");
	if (plik)
	{
		fclose(plik);
		return 1;
	}
		fclose(plik);
		return 0;
}