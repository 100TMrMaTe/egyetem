#include <stdio.h>
#include <stdlib.h>

void main()
{
	/*
	int n = 132565;
	int szamjegy = 0;
	int szamjegy_osszeg = 0;

	while (n > 0)
	{
		szamjegy_osszeg += n % 10;
		n = n / 10;
		szamjegy++;
	}
	printf("%d\n", szamjegy);
	printf("%d", szamjegy_osszeg);
	

	int n = 8;
	int sum = 0;
	while (n != 1)
	{
		sum++;
		printf("%d\n", n);
		if (n % 2 == 0)
		{
			n = n / 2;
		}
		else
		{
			n = 3 * n + 1;
		}
	}
	printf("%d\n", n);
	printf("%d lepes volt.\n", sum);
	
	//mennyi a szamok osszege 1000 ig
	int szamosszeg = 0;
	for (int i = 1;i <= 1000;i++)
	{
		szamosszeg += i;
	}
	printf("%d", szamosszeg);
	
	int n = 10;
	int fakt = 1;
	for (int i = 1;i <= n;i++)
	{
		fakt *= i;
	}
	printf("%d", fakt);
	
	int szelesseg = 4;
	int szam = 0;
	for (int i = 1;i <= szelesseg;i++)
	{
		for (int j =1; j <= i;j++)
		{
			szam++;
			printf("%d ", szam);
		}
		printf("\n");
	}
	*/
	int szelesseg = 5;
	int magassag = 5;
	int szam = 0;
	for (int i = 1;i <= magassag;i++)
	{
		for (int i = 1;i <= szelesseg;i++)
		{
			szam++;
			if (szam % 2 == 0)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
	
}
