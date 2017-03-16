#include "plansza.h"
void wypelnij(int **pole,int x,int y)
{
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			pole[i][j] = 0;
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
string oblicz_punkty(int punkty)
{
	string pom = "";
	char liczba;
	if (punkty == 0)return "0";
	while (punkty > 0)
	{
		liczba = punkty % 10 + 48;
		pom += liczba;
		punkty /= 10;
	}
	for (int i = 0; i < pom.size() / 2; i++)swap(pom[i], pom[pom.size() - 1 - i]);
	return pom;
}
void odswiez(sf::RenderWindow &okno, sf::Sprite Sprajty[], int **pole, int x, int y, int punkty, sf::Text tekst)
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
				case 4: Sprajty[3].setPosition(i * 20, j * 20); okno.draw(Sprajty[3]); break;
				default: continue;
				}
			}
		}
	}

	string punkt = oblicz_punkty(punkty);
	tekst.setString("Zjedzone robaki: ");
	tekst.setPosition(10, y * 20 + 20);
	okno.draw(tekst);
	tekst.setString(punkt);
	tekst.setPosition(10, y * 20 + 45);
	okno.draw(tekst);
	okno.display();

}
bool wczytaj_sprajty(sf::Sprite Sprajty[],sf::Texture Tekstury[])
{
	if (Tekstury[0].loadFromFile("ramka.png") && Tekstury[1].loadFromFile("body.png") && Tekstury[2].loadFromFile("robak.png") && Tekstury[3].loadFromFile("zjedzony.png"))
	{
		Sprajty[0].setTexture(Tekstury[0]);
		Sprajty[1].setTexture(Tekstury[1]);
		Sprajty[2].setTexture(Tekstury[2]);
		Sprajty[3].setTexture(Tekstury[3]);
		return true;
	}
	else return false;
}
bool dodaj_robaka(int **pole, int x, int y)
{
	int x_robaka, y_robaka, flaga = 0;

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			if (pole[i][j] == 0)
				flaga = 1;
	if (flaga == 0)
		return false;

	do
	{
		x_robaka = rand() % (x - 1) + 1;
		y_robaka = rand() % (y - 1) + 1;
	} while (pole[x_robaka][y_robaka] != 0);
	pole[x_robaka][y_robaka] = 3;
	return true;
}