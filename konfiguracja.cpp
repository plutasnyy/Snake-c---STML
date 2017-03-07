#include "konfiguracja.h"
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <Windows.h>
using namespace std;
#pragma warning (disable : 4996)
int wczytaj_level()
{
	std::cout << 1;
	return 1;
}

void ranking(int punkty, int level, int max_pol)
{
	int all = punkty * level * 1000 / max_pol;
	int pom;

	int i = 0;
	int nr[32];

	FILE *plik = fopen("ranking.txt", "a+");    // otworzenie pliku do odczytu
	if (!plik)
	{
		puts("Brak pliku numery.txt");
	}
	while (true)
	{
		//fscanf(plik, "%d\n", &nr[i]);
		//if (feof(plik) != 0)
		//	break;
		//printf("%d %d\n", i + 1, nr[i]);
		//++i;
		fprintf(plik, "%d", all);
		break;
		
	}
	Sleep(500);
	fclose(plik);
}