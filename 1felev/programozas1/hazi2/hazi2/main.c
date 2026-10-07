#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	//1
	printf("adjon meg egy egesz szamot: ");
	float beszam1;
	scanf("%f", &beszam1);
	printf("adjon meg egy egesz szamot: ");
	float beszam2;
	scanf("%f", &beszam2);
	float osszeg = beszam1 + beszam2;
	int szam1lenght = sizeof(beszam1);
	int szam2lenght = sizeof(beszam2);
	int osszeglenght = sizeof(osszeg);
	for (int i = 0;i < 12 - szam1lenght;i++)
	{
		printf("-");
	}
	printf("%.2f + ", beszam1);
	for (int i = 0;i < 12 - szam2lenght;i++)
	{
		printf("-");
	}
	printf("%.2f = ", beszam2);
	for (int i = 0;i < 12 - osszeglenght;i++)
	{
		printf("-");
	}
	printf("%.2f\n", osszeg);

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
		printf("A muvelet eredmenye: %f", osszeg);
	}
	else if (muvelet == 2)
	{
		float osszeg = szam21 - szam22;
		printf("A muvelet eredmenye: %f", osszeg);
	}
	else if (muvelet == 3)
	{
		float osszeg = szam21 * szam22;
		printf("A muvelet eredmenye: %f", osszeg);
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
			printf("A muvelet eredmenye: %f", osszeg);
		}
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

	int a = scanf("kerem az a erteket%d")
}

