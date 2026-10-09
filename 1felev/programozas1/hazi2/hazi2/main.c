#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

/****************************************
** File: JJ334H_2hazi.txt
**
** Programozo: Konyhasi Mate
** E-mail: JJ334H@tr.pte.hu
** Datum: 2026.10.09
** Neptun kod: JJ334H
**
** Leiras: Hazi Feladat/2
****************************************/

int main()
{
	//1
	printf("adjon meg egy valos szamot: ");
	float beszam1;
	scanf("%f", &beszam1);
	printf("adjon meg egy valos szamot: ");
	float beszam2;
	scanf("%f", &beszam2);
	float osszeg = beszam1 + beszam2;

	char szoveg[64];

	sprintf(szoveg, "%.2f", beszam1);
	for (int i = 0; i < 12 - (int)strlen(szoveg); i++)
	{
		printf("-");
	}
	printf("%s + ", szoveg);

	sprintf(szoveg, "%.2f", beszam2);
	for (int i = 0; i < 12 - (int)strlen(szoveg); i++)
	{
		printf("-");
	}
	printf("%s = ", szoveg);

	sprintf(szoveg, "%.2f", osszeg);
	for (int i = 0; i < 12 - (int)strlen(szoveg); i++)
	{
		printf("-");
	}
	printf("%s\n", szoveg);

	//2
	printf("kerem adja meg a muvelet sorszamat: ");
	float muvelet;
	scanf("%f", &muvelet);
	printf("kerem adja meg az elso szamot: ");
	float szam21;
	scanf("%f", &szam21);
	printf("kerem adja meg a masodik szamot: ");
	float szam22;
	scanf("%f", &szam22);
	if (muvelet == 1)
	{
		float osszeg = szam21 + szam22;
		printf("a muvelet eredmenye: %f", osszeg);
	}
	else if (muvelet == 2)
	{
		float osszeg = szam21 - szam22;
		printf("a muvelet eredmenye: %f", osszeg);
	}
	else if (muvelet == 3)
	{
		float osszeg = szam21 * szam22;
		printf("a muvelet eredmenye: %f", osszeg);
	}
	else if (muvelet == 4)
	{
		if (szam22 == 0)
		{
			printf("nullaval nem osztunk.");
		}
		else
		{
			float osszeg = szam21 / szam22;
			printf("a muvelet eredmenye: %.2f", osszeg);
		}
	}
	else
	{
		printf("hibas muvelet sorszam");
	}

	//3
	printf("\nKerem adja meg a tavolsagot (km): ");
	float tavolsag;
	scanf("%f", &tavolsag);

	printf("Napszak (1 = reggel, 2 = kora delutan, 3 = este): ");
	int napszak;
	scanf("%d", &napszak);

	float sebesseg = 0;

	if (napszak == 1)
	{
		sebesseg = 55;
	}
	else if (napszak == 2)
	{
		sebesseg = 68;
	}
	else if (napszak == 3)
	{
		sebesseg = 65;
	}

	if (sebesseg == 0)
	{
		printf("Hibas napszak!");
	}
	else
	{
		float ora = tavolsag / sebesseg;
		float perc = ora * 60;
		printf("Az utazashoz elore lathatoan %.2f ora, vagyis %.0f perc szukseges.", ora, perc);
	}

	//4
	printf("\nKerem adja meg az a egyutthatot: ");
	float a;
	scanf("%f", &a);
	printf("Kerem adja meg a b egyutthatot: ");
	float b;
	scanf("%f", &b);
	printf("Kerem adja meg a c egyutthatot: ");
	float c;
	scanf("%f", &c);

	if (a == 0)
	{
		printf("Az egyenlet nem masodfoku.");
	}
	else
	{
		float d = b * b - 4 * a * c;

		if (d < 0)
		{
			printf("Az egyenletnek nincs valos gyoke.");
		}
		else if (d == 0)
		{
			float x = -b / (2 * a);
			printf("Az egyenlet gyoke: %.2f", x);
		}
		else
		{
			float x1 = (-b - sqrt(d)) / (2 * a);
			float x2 = (-b + sqrt(d)) / (2 * a);

			if (x1 > x2)
			{
				float csere = x1;
				x1 = x2;
				x2 = csere;
			}

			printf("Az egyenlet gyokei: %.2f es %.2f", x1, x2);
		}
	}
}

