#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void feladat1()
{
	char szoveg[11] = {"prog1"};
	printf("%d\n", strlen(szoveg));
	printf("%c -- %c\n", szoveg[1], szoveg[3]);
	printf("%s\n", szoveg);
	/*for (int i = 0; i < strlen(szoveg); i++)
	{
		if (szoveg[i] == "\0")
		{
			break;
		}
		else
		{
			printf("%c", szoveg[i]);
		}
	}*/

}

void feladat2()
{
	char* szoveg = malloc(11 * sizeof(char));
	if (szoveg == NULL)
	{
		printf("Hiba a memoria foglalasnal!\n");
		return;
	}

	strcpy(szoveg, "prog5");
	printf("%c -- %c\n", szoveg[1], szoveg[3]);
	printf("%s\n", szoveg);

	free(szoveg);
}

int feladat3()
{
	char szoveg[127];
	printf("kerem a sgoveget: ");
	fgets(szoveg, sizeof(szoveg), stdin);

	// az fgets a sorvégi '\n'-t is beteszi, ezt le kell vágni
	szoveg[strcspn(szoveg, "\n")] = '\0';
	printf("A szoveg hossza: %d -- %s\n", strlen(szoveg), szoveg);

	return strlen(szoveg);
}

void feladat4()
{
	char szoveg[128];
	printf("kere ma szoveget: ");
	fgets(szoveg, sizeof(szoveg), stdin);
	szoveg[strcspn(szoveg, "\n")] = '\0';
	int count = 0;

	for (int i = 0; i < strlen(szoveg); i++)
	{
		if(szoveg[i] == 'e')
		{
			count++;
		}
	}
	printf("Az 'e' karakterek szama: %d\n", count);
}

void feladat5()
{
	char szoveg[128];
	printf("kere ma szoveget: ");
	fgets(szoveg, sizeof(szoveg), stdin);
	szoveg[strcspn(szoveg, "\n")] = '\0';
	char forditott[128];

	for (int i = strlen(szoveg) - 1;i >= 0;i--)
	{
		forditott[strlen(szoveg) - 1 - i] = szoveg[i];
	}
	forditott[strlen(szoveg)] = '\0';
	printf("A forditott szoveg: %s\n", forditott);
}

void feladat6()
{
	char szoveg[128];
	printf("kere ma szoveget: ");
	fgets(szoveg, sizeof(szoveg), stdin);
	szoveg[strcspn(szoveg, "\n")] = '\0';

	for (int i = 0;szoveg[i] != '\0';i++)
	{
		if (isupper(szoveg[i]))
		{
			szoveg[i] = tolower(szoveg[i]);
		}
		else if (islower(szoveg[i]))
		{
			szoveg[i] = toupper(szoveg[i]);
		}
	}
	printf("A szoveg: %s\n", szoveg);
}

void feladat7()
{
	char szoveg[128];
	printf("kere ma szoveget: ");
	fgets(szoveg, sizeof(szoveg), stdin);
	szoveg[strcspn(szoveg, "\n")] = '\0';
	
	char uj[128];
	int j = 0;
	for (int i = 0; szoveg[i] != '\0'; i++)
	{
		if (szoveg[i] != ' ')
		{
			uj[j++] = szoveg[i];
		}
	}
	uj[j] = '\0';

	printf("A szoveg: %s\n", uj);
}

int main()	
{
	//feladat1();
	//feladat2();
	//feladat3();
	//feladat4();
	//feladat5();
	//feladat6();
	feladat7();
	return 0;
}