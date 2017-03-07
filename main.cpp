#include "plansza.h"
#include "kolejka.h"
#include "snake.h"
#include <windows.h>
#include <iostream>
using namespace std;
klocek funkcja(int x, int y, int i,int **pole)
{
	klocek klocek1;
	pole[x / 2 + i][y / 2] = 2;
	klocek1.x = x / 2 + i;
	klocek1.y = y / 2;
	return klocek1;
}
int main()
{
	int rozmiar_x = 30, rozmiar_y = 20, speed = 200, level = 10;

	klocek *pierwszy = NULL;
	klocek *ostatni = NULL;
	klocek *start = new klocek;
	klocek *korzen = NULL;
	klocek zlap_ostatni;
	start->x = rozmiar_x / 2;
	start->y = rozmiar_y / 2;
	push(&start, &pierwszy, &ostatni);
	korzen = pierwszy; // do czyszczenia

	sf::Sprite Sprajty[3];
	sf::Texture Tekstury[3];
	wczytaj_sprajty(Sprajty, Tekstury);


	int **pole = new int*[rozmiar_x];
	for (int i = 0; i < rozmiar_x; i++)
	{
		pole[i] = new int[rozmiar_y];
	}
	wypelnij(pole, rozmiar_x, rozmiar_y);


	bool robak = false;
	int j = 0;
	sf::RenderWindow okno(sf::VideoMode(rozmiar_x * 20 + 100, rozmiar_y * 20 + 100, 32), "Snake");
	sf::Event zdarzenie;

	while (okno.isOpen())
	{
		while (okno.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::Closed)
				okno.close();

			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
				okno.close();
		}
		klocek *pom = new klocek;
		pom->x = ostatni->x + 1;
		pom->y = ostatni->y;
		push(&pom, &pierwszy, &ostatni);
		pole[pom->x][pom->y] = 2;

		if (!robak && pierwszy->next != NULL  && j>2)
		{
			zlap_ostatni = pop(&pierwszy);
			pole[zlap_ostatni.x][zlap_ostatni.y] = 0;
		}
		j++;
		odswiez(okno,Sprajty,pole,rozmiar_x,rozmiar_y);
		Sleep(speed);
	}
	for (int i = 0; i < rozmiar_y; i++)
	{
		delete [] pole[i];
	}
	delete [] *pole;
	klocek *uchwyt = new klocek;
	while (korzen->next != NULL)
	{
		uchwyt = korzen;
		korzen = korzen->next;
		delete uchwyt;
	}
	delete uchwyt;
	delete korzen;
	return 0;
}