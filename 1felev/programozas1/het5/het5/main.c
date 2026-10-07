#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const char* beker()
{
	int sz;
	scanf("%d", &sz);
	
	if (sz > 0)
	{
		return "pozitiv";
	}
	else if (sz = 0)
	{
		return "semleges";
	}
	else
	{
		return "negativ";
	}

}
double beker1()
{
	double bekert;
	scanf("%lf", &bekert);
	return bekert;
}
int beker2()
{
	
	while(1)
	{
		int szam;
		printf("kerem adj meg egy szamot: ");
		scanf("%d", &szam);
		int len = sizeof(szam);
		if (szam >= 100 && szam <= 1000)
		{
			return szam;
		}
	}
}


int main()
{
	/*int a;
	scanf("%d", &a);
	printf("szam: %d\n", a);
	printf("%s",beker());
	double szam = beker1();
	printf("%.2f", szam);
	printf("%d", beker2());*/
	return 0;
}