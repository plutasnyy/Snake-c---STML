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
	klocek pom1;
	pom1.x = rozmiar_x / 2;
	pom1.y = rozmiar_y / 2;
	klocek *pierwszy = NULL;
	klocek *ostatni = NULL;
	klocek pom;

	pierwszy = &pom1;
	ostatni = &pom1;
	sf::Sprite Sprajty[3];
	sf::Texture Tekstury[3];
	wczytaj_sprajty(Sprajty, Tekstury);
	
	
	int **pole = new int*[rozmiar_x];
	for (int i = 0; i < rozmiar_x; i++)
	{
		pole[i] = new int[rozmiar_y];
	}

	wypelnij(pole,rozmiar_x,rozmiar_y);
	sf::RenderWindow okno(sf::VideoMode(rozmiar_x*20+100, rozmiar_y*20+100, 32), "Snake");
	sf::Event zdarzenie;
	for (int i = 2; i <= 6; i+=2)
	{
		pom = funkcja(rozmiar_x, rozmiar_y, 0, pole);
		pom.x += i;
		push(&pom, &pierwszy, &ostatni);
		cout<<pierwszy->x<<endl;
	}
	pop(&pierwszy);
	cout << pierwszy->x << endl;
	Sleep(2000);
	return 0;
//	cout << pierwszy->x << " " << pierwszy->next->x;
	bool robak = false;
	int j = 0;
	while (okno.isOpen())
	{
		while (okno.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::Closed)
				okno.close();

			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
				okno.close();
		}
		
		pom.x = pierwszy->x + 1;
		pom.y = pierwszy->y;
		push(&pom, &pierwszy, &ostatni);
		pole[pom.x][pom.y] = 2;

	////	if (!robak && pierwszy->next != NULL  && j>2)
	//	{
	//		pom = pop(&ostatni);
		//	pole[pom.x][pom.y] = 0;
	//	}
		j++;
		odswiez(okno,Sprajty,pole,rozmiar_x,rozmiar_y);
		Sleep(speed);
	}
	return 0;
}