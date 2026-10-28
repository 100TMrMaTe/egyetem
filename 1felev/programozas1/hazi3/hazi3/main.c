#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int beker(int a, int b);
double bekerhomerseklet(double a, double b);
void feladat2();
void feladat3();

int main()
{
	//1. feladat
	beker(1, 10);
	//2. feladat
	feladat2();
	//3. feladat
	feladat3();

	return 0;
}

int beker(int a, int b)
{
	printf("1.feladat\n");
	int szam;
	do
	{
		printf("kerek egy %d es %d kozotti szamot: ", a, b);
		scanf("%d", &szam);
	} while (szam < a || szam > b);
	return szam;
}

double bekerhomerseklet(double a, double b)
{
	double homerseklet;
	do
	{
		printf("kerem adja meg a homerseklet erteket: ");
		scanf("%lf", &homerseklet);
	} while (homerseklet < a || homerseklet > b);
	return homerseklet;
}

void feladat2()
{
	printf("2.feladat\n");
	double homersekletek[21];
	for (int i = 0; i < 21; i++)
	{
		homersekletek[i] = bekerhomerseklet(-40, 50);
	}
	double atlagok[7];
	for (int i = 0; i < 21; i += 3)
	{
		atlagok[i / 3] = (homersekletek[i] + homersekletek[i + 1] + homersekletek[i + 2]) / 3;
	}
	int minindex = 0;
	double minatlag = atlagok[0];
	int maxindex = 0;
	double maxatlag = atlagok[0];
	double osszeg = 0;
	for (int i = 0; i < 7; i++)
	{
		osszeg += atlagok[i];
		if (atlagok[i] < minatlag)
		{
			minatlag = atlagok[i];
			minindex = i;
		}
		if (atlagok[i] > maxatlag)
		{
			maxatlag = atlagok[i];
			maxindex = i;
		}
	}
	printf("\nLegmelegebb nap: %d. nap (%.2f Celsius)\n", maxindex + 1, maxatlag);
	printf("Leghidegebb nap: %d. nap (%.2f Celsius)\n", minindex + 1, minatlag);

	double hetiAtlag = osszeg / 7;
	printf("Valoszinu evszak: ");
	if (hetiAtlag < 5)
		printf("tel\n");
	else if (hetiAtlag < 15)
		printf("tavasz vagy osz\n");
	else
		printf("nyar\n");
}

void feladat3()
{
	printf("3.feladat\n");

	int also;
	int felso;
	do
	{
		printf("add meg az intervallum also hatarat: ");
		scanf("%d", &also);
		printf("add meg az intervallum felso hatarat: ");
		scanf("%d", &felso);
	} while (also >= felso);

	int lepesek = 0;
	char valasz;

	printf("gondolj egy szamra %d es %d kozott\n", also, felso);

	while (also <= felso)
	{
		int tipp = also + (felso - also) / 2;
		lepesek++;

		printf("%d. tipp: %d\n", lepesek, tipp);
		do
		{
			printf("talalt =, a gondolt szam kisebb < vagy nagyobb >? ");
			scanf(" %c", &valasz);
		} while (valasz != '=' && valasz != '<' && valasz != '>');

		if (valasz == '=')
		{
			printf("kitalaltad a szamot %d lepesben!\n", lepesek);
			return;
		}
		else if (valasz == '<')
			felso = tipp - 1;
		else
		also = tipp + 1;
	}
	printf("nem jo kezd ujra\n");
}