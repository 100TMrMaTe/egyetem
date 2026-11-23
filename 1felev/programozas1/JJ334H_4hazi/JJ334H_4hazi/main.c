#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void feladat1();
void feladar2();

int main() {
	feladat1();
}

void feladat1()
{

	int szam;
	printf("hany karakterbol aljon a jelszod: ");
	scanf("%d", &szam);

	char jelszo[100];
	do
	{
		printf("Adja meg a jelszot: ");
		scanf("%s", jelszo);
	}
	while (strlen(jelszo) != szam);

	int nagybetu = 0;
	int kisbetu = 0;
	int szamell = 0;
	int specialis = 0;

	for (int i = 0; i < strlen(jelszo); i++)
	{
		if (isupper(jelszo[i]))
		{
			nagybetu = 1;
		}
		if (islower(jelszo[i]))
		{
			kisbetu = 1;
		}
		if (isdigit(jelszo[i]))
		{
			szamell = 1;
		}
		if (ispunct(jelszo[i]))
		{
			specialis = 1;
		}
	}

	if (strlen(jelszo) < 8)
	{
		printf("A jelszo nincs 8 karakter hosszu!\n");
	}
	if(nagybetu == 0)
	{
		printf("A jelszo nem tartalmaz nagybetut!\n");
	}
	if(kisbetu == 0)
	{
		printf("A jelszo nem tartalmaz kisbetut!\n");
	}
	if(szamell == 0)
	{
		printf("A jelszo nem tartalmaz szamot!\n");
	}
	if(specialis == 0)
	{
		printf("A jelszo nem tartalmaz specialis karaktert!\n");
	}
	if (nagybetu == 1 && kisbetu == 1 && szamell == 1 && specialis == 1 && strlen(jelszo) >= 8)
	{
		printf("A jelszo megfelelo!\n");
	}
}

void feladat2()
{
	int szam;
	printf("milyen hosszu szoveget adsz meg: ");
	scanf("%d", &szam);

	char* szoveg = (char*)malloc((szam + 1) * sizeof(char));
}