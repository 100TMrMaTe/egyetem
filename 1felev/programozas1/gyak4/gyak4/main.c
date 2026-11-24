#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char nev[50];
	int osztaly;
	int pont;
} Tanulo;

void beolvas(char* fajlnev, Tanulo* tanulok, int sorok)
{
	FILE* f = fopen(fajlnev, "r");
	// hiba kezeles
	for (int i = 0; i < sorok; i++)
	{
		fscanf(f, "%20[^\t]\t%d\n", tanulok[i].nev, &tanulok[i].osztaly);
		tanulok[i].pont = 0;
	}
	fclose(f);
}


int sorszamlalo(char* fajlnev)
{
	FILE* f = fopen(fajlnev, "r");
	// hiba kezeles
	char c;
	int db = 0;
	while ((c = fgetc(f)) != EOF)
	{
		if (c == '\n')
		{
			db++;
		}
	}
	fclose(f);
	return db;
}

void kiir(Tanulo* tanulok, int sorok)
{
	for (int i = 0; i < sorok; i++)
	{
		printf("%s\t%d\t%d\n", tanulok[i].nev, tanulok[i].osztaly, tanulok[i].pont);
	}
}

void verseny(Tanulo* tanulok, int sorok)
{
	for (int i = 0; i < sorok; i++)
	{
		printf("hogyan teljesitett %s nevu halgato a %d osztalyban: ", tanulok[i].nev, tanulok[i].osztaly);
		int pont;
		scanf("%d", &pont);
		tanulok[i].pont += pont;
	}
}
void legtobb(Tanulo* tanulok, int sorok)
{
	int max = tanulok[0].pont;
	int indexmax = 0;
	for (int i = 0; i < sorok; i++)
	{
		if (tanulok[i].pont > max)
		{
			max = tanulok[i].pont;
			indexmax = i;
		}
	}
	printf("Alegtobb pontot %s kapta %d pontal\n", tanulok[indexmax].nev, max);
}

void mentes(char* fajlnev, Tanulo* tanulok, int sorok)
{
	FILE* f = fopen(fajlnev, "w");
	for (int i = 0; i < sorok; i++)
	{
		fprintf(f, "%s\t%d\t%d\n", tanulok[i].nev, tanulok[i].osztaly, tanulok[i].pont);
	}
	fclose(f);
}

void levonas(Tanulo* tanulok, int sorok)
{
	char nev[50];
	printf("Kitől vonsz le pontot: ");
	fgets(nev, sizeof(nev), stdin);
	nev[strcspn(nev, "\n")] = '\0';

	int szam1;
	printf("Mennyit: ");
	scanf("%d", &szam1);

	for (int i = 0; i < sorok; i++)
	{
		if (strcmp(tanulok[i].nev, nev) == 0) {
			tanulok[i].pont -= szam1;
		}
	}
}

int main()
{
	char fajlnev[] = "nevek.txt";
	int sorok = sorszamlalo(fajlnev);
	printf("A fajlban %d sor van.\n", sorok);

	Tanulo* tanulok = malloc(sorok * sizeof(Tanulo));
	beolvas(fajlnev, tanulok, sorok);
	/*
	kiir(tanulok, sorok);
	verseny(tanulok, sorok);
	kiir(tanulok, sorok);
	legtobb(tanulok, sorok);
	mentes("eredmenyek.txt", tanulok, sorok);
	*/
	int szam;
	do
	{
		printf("1 kiir, 2 verseny, 3 legtobb, 4 mentes, 0 kilepes\n");
		printf("mit szeretne csinalni: ");
		scanf("%d", &szam);
		switch (szam)
		{
			case 1:
				kiir(tanulok, sorok);
				break;
			case 2:
				verseny(tanulok, sorok);
				break;
			case 3:
				legtobb(tanulok, sorok);
				break;
			case 4:
				mentes("eredmenyek.txt", tanulok, sorok);
				break;
			case 5:
				levonas(tanulok, sorok);
				break;
		}
	} while (szam != 0);


	return 0;
}