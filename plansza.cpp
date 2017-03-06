
#include "plansza.h"
#include <iostream>
void wypelnij(int T[20][20])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			T[i][j] = 0;
		}
	}
	for (int i = 0; i < 20; i++)
	{
		T[0][i] = 1;
		T[19][i] = 1;
		T[i][0] = 1;
		T[i][19] = 1;
	}
	T[2][3] = 2;
	T[4][5] = 3;
}
void lal(sf::RenderWindow &okno, sf::Sprite Sprajty[], int T[20][20])
{
	okno.clear();
	for (int i = 0; i < 20; i += 1)
	{
		for (int j = 0; j < 20; j += 1)
		{
			if (T[i][j] != 0)
			{
				switch (T[i][j])
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