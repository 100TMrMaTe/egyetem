#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/****************************************
** File: JJ334H_3hazi.txt
**
** Programozo: Konyhasi Mate
** E-mail: JJ334H@tr.pte.hu
** Datum: 2026.10.30
** Neptun kod: JJ334H
**
** Leiras: Hazi Feladat/3
****************************************/

int beker(int a, int b);
double bekerhomerseklet(double a, double b);
void feladat2();
void feladat3();
void feladat4();

int main()
{
	//1. feladat
	printf("1.feladat\n");
	beker(1, 10);
	//2. feladat
	feladat2();
	//3. feladat
	feladat3();
	//4. feladat
	feladat4();

	return 0;
}

int beker(int a, int b)
{
	
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

void feladat4()
{
	printf("4.feladat\n");
	double penzek[20];

	for (int i = 0; i < 20; i++)
	{
		do
		{
			printf("kerem adja meg a %d. ugyfel kezdo egyenleget: ", i + 1);
			scanf("%lf", &penzek[i]);
		} while (penzek[i] < 0);
	}
	printf("\n");

	int szam;
	do
	{
		int ugyfel;
		do
		{
			printf("Kerem adja meg az ugyfel szamat (1-20): ");
			scanf("%d", &ugyfel);
		} while (ugyfel < 1 || ugyfel > 20);

		int dij = 0;
		if (penzek[ugyfel - 1] >= 5000)
		{
			penzek[ugyfel - 1] -= 5000;
			dij = 1;
			printf("Ugyintezesi dij levonva.\n");
		}
		else
		{
			printf("Az egyenleg nem fedezi az ugyintezesi dijat, amig nem eri el az 5000 Ft-ot, csak befizetni lehet!\n\n");
		}

		do
		{
			printf("Adatok listazasa: 1\n");
			printf("Penz befizetes: 2\n");
			printf("Penz felvetel: 3\n");
			printf("Utalas bankon belul: 4\n");
			printf("Utalas bankon kivul: 5\n");
			printf("Ugyfel ugyintezesenek vege: 6\n");
			printf("Kilepes a programbol: 7\n\n");
			printf("Kerem adja meg a muvelet sorszamat: ");
			scanf("%d", &szam);

			if (dij == 0 && szam >= 3 && szam <= 5)
			{
				printf("Amig az egyenleg nem eri el az 5000 Ft-ot, csak befizetni lehet!\n\n");
				continue;
			}

			switch (szam)
			{
			case(1):
			{
				for (int i = 0; i < 20; i++)
				{
					printf("%d. ugyfel: %.2f Ft\n", i + 1, penzek[i]);
				}
				printf("\n");
				break;
			}

			case(2):
			{
				double befizetes;
				do
				{
					printf("Kerem adja meg a befizetendo osszeget: ");
					scanf("%lf", &befizetes);
				} while (befizetes <= 0);

				penzek[ugyfel - 1] += befizetes;
				printf("A befizetes sikeres!\n");

				if (dij == 0 && penzek[ugyfel - 1] >= 5000)
				{
					penzek[ugyfel - 1] -= 5000;
					dij = 1;
					printf("Ugyintezesi dij levonva.\n");
				}
				break;
			}

			case(3):
			{
				double felvetel;
				do
				{
					printf("kerem adja meg a felvenni kivant osszeget: ");
					scanf("%lf", &felvetel);
				} while (felvetel <= 0);

				double koltseg = felvetel * 1.1;
				if (penzek[ugyfel - 1] >= koltseg)
				{
					penzek[ugyfel - 1] -= koltseg;
					printf("A felvetel sikeres!\n");
				}
				else
				{
					printf("Nincs eleg fedezet a felvetelhez!\n\n");
				}
				break;
			}

			case(4):
			{
				int cimzett;
				do
				{
					printf("kerem adja meg a cimzett ugyfel szamat (1-20): ");
					scanf("%d", &cimzett);
				} while (cimzett < 1 || cimzett > 20);

				if (ugyfel == cimzett)
				{
					printf("Sajat maganak nem utalhat!\n\n");
					break;
				}

				double utalas;
				do
				{
					printf("Kerem adja meg az utalando osszeget: ");
					scanf("%lf", &utalas);
				} while (utalas <= 0);

				if (penzek[ugyfel - 1] >= utalas)
				{
					penzek[ugyfel - 1] -= utalas;
					penzek[cimzett - 1] += utalas;
					printf("az utalas sikeres!\n");
				}
				else
				{
					printf("nincs eleg fedezet az utalashoz!\n\n");
				}
				break;
			}

			case(5):
			{
				double utalas;
				do
				{
					printf("kerem adja meg az utalando osszeget: ");
					scanf("%lf", &utalas);
				} while (utalas <= 0);

				double koltseg = utalas * 1.1;
				if (penzek[ugyfel - 1] >= koltseg)
				{
					penzek[ugyfel - 1] -= koltseg;
					printf("az utalas sikeres\n\n");
				}
				else
				{
					printf("nincs eleg fedezet!\n\n");
				}
				break;
			}

			case(6):
			{
				printf("Az ugyfel ugyintezese befejezodott.\n\n");
				break;
			}
			case(7):
			{
				break;
			}
			default:
			{
				printf("hibas muvelet\n\n");
				break;
			}
			}
		} while (szam != 6 && szam != 7);
	} while (szam != 7);
}