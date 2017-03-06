
#include "plansza.h"
#include <iostream>
void wypelnij(int **pole,int x,int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			pole[i][j] = 0;
		}
	}
	for (int i = 0; i < y; i++)
	{
		pole[0][i] = 1;
		pole[x-1][i] = 1;
	}
	for (int i = 0; i < x; i++)
	{
		pole[i][0] = 1;
		pole[i][y-1] = 1;
	}
}
void odswiez(sf::RenderWindow &okno, sf::Sprite Sprajty[], int **pole, int x, int y)
{
	okno.clear();
	for (int i = 0; i < x; i += 1)
	{
		for (int j = 0; j < y; j += 1)
		{
			if (pole[i][j] != 0)
			{
				switch (pole[i][j])
				{
				case 1: Sprajty[0].setPosition(i * 20, j * 20); okno.draw(Sprajty[0]); break;
				case 2: Sprajty[1].setPosition(i * 20, j * 20 ); okno.draw(Sprajty[1]); break;
				case 3: Sprajty[2].setPosition(i * 20, j * 20); okno.draw(Sprajty[2]); break;
				default: continue;
				}
			}
		}
	}
	okno.display();
}
void wczytaj_sprajty(sf::Sprite Sprajty[],sf::Texture Tekstury[])
{

	if (Tekstury[0].loadFromFile("ramka.png") && Tekstury[1].loadFromFile("body.png") && Tekstury[2].loadFromFile("robak.png"))
	{
		Tekstury[0].loadFromFile("ramka.png");
		Sprajty[0].setTexture(Tekstury[0]);
		Tekstury[1].loadFromFile("body.png");
		Sprajty[1].setTexture(Tekstury[1]);
		Tekstury[2].loadFromFile("robak.png");
		Sprajty[2].setTexture(Tekstury[2]);
	}
	else
	{
		std::cout << "Brak grafiki!";
	}

}