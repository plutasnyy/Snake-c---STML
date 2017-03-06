#include "plansza.h"
#include "kolejka.h"
#include <windows.h>
#include <iostream>
int main()
{
	klocek *pierwszy = NULL;
	klocek *ostatni = NULL;
	sf::Sprite Sprajty[3];
	sf::Texture Tekstury[3];
	wczytaj_sprajty(Sprajty, Tekstury);

	int T[20][20];

	wypelnij(T);
	sf::RenderWindow okno(sf::VideoMode(800, 640, 32), "Snake");
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
		lal(okno,Sprajty,T);
		Sleep(500);
	}
	return 0;
}