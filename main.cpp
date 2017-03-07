#include "plansza.h"
#include "kolejka.h"
#include "snake.h"
#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
	enum {
		LEWO=1, PRAWO, GORA , DOL
	}kierunek=LEWO;

	enum {
		GRA, KONIEC
	}stan = GRA;

	srand(time(NULL));

	int rozmiar_x = 30, rozmiar_y = 20, speed = 200, level = 10, punkty = 0, wartosc_pom = 0;

	klocek *pierwszy = NULL, *ostatni = NULL, *korzen = NULL, zlap_ostatni;
	klocek *start = new klocek;
	klocek *drugi = new klocek;

	start->x = rozmiar_x / 2;
	drugi->y = start->y = rozmiar_y / 2 ;
	drugi->x = start->x + 1;
	push(&start, &pierwszy, &ostatni);
	push(&drugi, &pierwszy, &ostatni);
	korzen = pierwszy; // do czyszczenia

	sf::Sprite Sprajty[4];
	sf::Texture Tekstury[4];

	if(!wczytaj_sprajty(Sprajty, Tekstury))
		stan=KONIEC;

	int **pole = new int*[rozmiar_x];
	for (int i = 0; i < rozmiar_x; i++)
		pole[i] = new int[rozmiar_y];
	wypelnij(pole, rozmiar_x, rozmiar_y);//plansza
	dodaj_robaka(pole,rozmiar_x,rozmiar_y);//plansza

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

			if (zdarzenie.type == sf::Event::KeyPressed)
			{
				if (zdarzenie.key.code == sf::Keyboard::A)
					kierunek = LEWO;
				else if (zdarzenie.key.code == sf::Keyboard::W)
					kierunek = GORA;
				else if (zdarzenie.key.code == sf::Keyboard::D)				
					kierunek = PRAWO;				
				else if (zdarzenie.key.code == sf::Keyboard::S)				
					kierunek = DOL;				
			}
		}
		if (stan == GRA)
		{
			//TWORZENIE PRZODU WEZA OBSLUGA LISTY i POLA
			klocek *pom = new klocek; //GLOWA
			pom->x = ostatni->x;
			pom->y = ostatni->y;
			
			wartosc_pom = kierunek;
			ustal_pozycje_glowy(wartosc_pom,&pom); //WYZNACZ NOWE POLE NA PODSTAWIE KIERUNKU, snake

			if (pole[pom->x][pom->y] == 1 || pole[pom->x][pom->y] == 2) // TRAF W SCIANE BADZ W SIEBIE
			{
				stan = KONIEC;
				continue;
			}
			else if (pole[pom->x][pom->y] == 3) // ROBAK
			{
				punkty++;
				pole[pom->x][pom->y] = 4;
				dodaj_robaka(pole, rozmiar_x, rozmiar_y);
			}
			else pole[pom->x][pom->y] = 2;
			push(&pom, &pierwszy, &ostatni);

			//TYL WEZA
			if (pole[(*pierwszy).x][(*pierwszy).y] == 4)//ZJEDZONY ROBAK, ZAMIANA NA CIALO WEZA
				pole[pierwszy->x][pierwszy->y] = 2;
			else//USUNIECIE TYLU
			{
				zlap_ostatni = pop(&pierwszy);
				pole[zlap_ostatni.x][zlap_ostatni.y] = 0;
			}

			odswiez(okno, Sprajty, pole, rozmiar_x, rozmiar_y);
			Sleep(speed);
		}
	}

	for (int i = 0; i < rozmiar_y; i++)
	{
		delete [] pole[i];
	}
//	delete [] *pole;
	klocek *uchwyt = new klocek;
//	while ((*korzen).next != NULL)
//	{
	//	uchwyt = korzen;
		//korzen = korzen->next;
		//delete uchwyt;
	//}
	delete uchwyt;
	delete korzen;
	return 0;
}