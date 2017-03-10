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
int ranking(int punkty, int level, int max_pol)
{
	int all = punkty * level * 1000 / max_pol;
	int rozmiar, pozycja = 0, flaga = 0;
	FILE *plik = fopen("ranking.txt", "r");    // otworzenie pliku do odczytu
	if (!plik)
	{
		puts("Brak pliku ranking.txt");
	}
	fscanf(plik, "%d", &rozmiar);
	if (rozmiar > 10000)rozmiar = 10000;
	cout << rozmiar << endl;
	int *tab =new int [rozmiar+1]; //jedno miejsce wiecej aby dodac
	for (int i = 0; i < rozmiar; i++)//wczytaj dane i ustal pozycje
	{
		fscanf(plik,"%d", &tab[i]);
		cout << tab[i] << endl;
		if (flaga == 0 && tab[i] <= all)
		{
			flaga = 1;
			pozycja = i + 1;
		}
	}
	Sleep(500);
	fclose(plik);
	tab[rozmiar] = all;
	flaga = 0;
	for (int i = rozmiar; i > 0; i--)
	{
		flaga = 0;
		for (int j = i; j > 0; j--)
		{
			if (tab[j] > tab[j - 1])swap(tab[j], tab[j - 1]);
			flaga = 1;
		}
		if (flaga == 0) break;
	}

	FILE *plik2 = fopen("ranking.txt", "w+");
	fprintf(plik2, "%d\n", rozmiar + 1);
	for (int i = 0; i < rozmiar + 1; i++)
		fprintf(plik2, "%d\n", tab[i]);
	
	cout << "Pozycja: " << pozycja << "Punkty: " << all;
	fclose(plik2);
	Sleep(1000);
	return pozycja;
}