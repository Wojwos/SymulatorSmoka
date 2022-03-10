#include "smok.h"
#include <stdio.h>

struct smok_stat tworzenie_duzego_smoka(struct smok_stat smok)
{
	smok.inteligencja_max = 10;
	smok.glod_max = 10;
	smok.pragnienie_max = 10;
	smok.zdrowie_max = 10;
	smok.energia_max = 10;
	return smok;
}