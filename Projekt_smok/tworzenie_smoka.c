#include "smok.h"
#include <stdio.h>

struct smok_stat tworzenie_smoka(struct smok_stat smok)
{
	smok.inteligencja = 1;
	smok.inteligencja_max = 5;
	smok.glod_max = 5;
	smok.glod = 2;
	smok.pragnienie_max = 5;
	smok.pragnienie = 2;
	smok.zdrowie_max = 5;
	smok.zdrowie = 5;
	smok.energia = 5;
	smok.energia_max = 5;
	smok.spi = 0;
	smok.leczenie = 0;
	return smok;
}