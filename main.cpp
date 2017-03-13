#include "konfiguracja.h"
#include "snake.h"

int main()
{
	enum {
		LEWO=1, PRAWO, GORA , DOL
	}kierunek=LEWO,nowy_kierunek=LEWO;

	enum {
		GRA, KONIEC, BLAD
	}stan = GRA;

	srand(time(NULL));

	int rozmiar_x = 15, rozmiar_y = 15, max_speed = 0, level = 0, punkty, wartosc_pom, min_speed = 0, skok = 0, speed = 0;
	
	sf::Text tekst;
	sf::Font font;
	sf::Sprite Sprajty[4];
	sf::Texture Tekstury[4];

	string zjedzone_robaki = "Liczba zjedzonych robakow: ";

	if (!font.loadFromFile("RobotoCondensed-Light.ttf") || !wczytaj_sprajty(Sprajty, Tekstury))
		stan = BLAD;
	tekst.setFont(font);

	bool zakonczenie = false;
	while (!zakonczenie)
	{
		zakonczenie = true;
		stan = GRA;
		wartosc_pom = 0;
		punkty = 0;
		konfiguracja(rozmiar_x, rozmiar_y, level, max_speed, skok, min_speed, tekst);

		sf::RenderWindow okno(sf::VideoMode(rozmiar_x * 20, rozmiar_y * 20 + 100, 32), "Snake");
		sf::Event zdarzenie;

		klocek *pierwszy = NULL, *ostatni = NULL, *korzen = NULL, zlap_ostatni;
		klocek *start = new klocek;
		klocek *drugi = new klocek;

		start->x = rozmiar_x / 2;
		drugi->y = start->y = rozmiar_y / 2;
		drugi->x = start->x + 1;
		start->next = drugi->next = NULL;
		push(&start, &pierwszy, &ostatni);
		push(&drugi, &pierwszy, &ostatni);


		int **pole = new int*[rozmiar_x];
		for (int i = 0; i < rozmiar_x; i++)
			pole[i] = new int[rozmiar_y];

		wypelnij(pole, rozmiar_x, rozmiar_y);//plansza
		dodaj_robaka(pole, rozmiar_x, rozmiar_y);//plansza

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
						nowy_kierunek = LEWO;
					else if (zdarzenie.key.code == sf::Keyboard::W)
						nowy_kierunek = GORA;
					else if (zdarzenie.key.code == sf::Keyboard::D)
						nowy_kierunek = PRAWO;
					else if (zdarzenie.key.code == sf::Keyboard::S)
						nowy_kierunek = DOL;
				}
			}
			if (stan == GRA)
			{
				//TWORZENIE PRZODU WEZA OBSLUGA LISTY i POLA
				klocek *pom = new klocek; //GLOWA
				pom->x = ostatni->x;
				pom->y = ostatni->y;
				pom->next = NULL;

				//BLOKADA RUCHU W TYL
				if (!(kierunek == LEWO && nowy_kierunek == PRAWO || kierunek == PRAWO && nowy_kierunek == LEWO || kierunek == GORA && nowy_kierunek == DOL || kierunek == DOL &&nowy_kierunek == GORA))
					kierunek = nowy_kierunek;

				//WYZNACZ NOWE POLE NA PODSTAWIE KIERUNKU
				wartosc_pom = kierunek;
				ustal_pozycje_glowy(wartosc_pom, &pom); //snake

				if (!(pole[pom->x][pom->y] == 0 || pole[pom->x][pom->y] == 3))//TRAF W SCIANE BADZ W SIEBIE
				{
					stan = KONIEC;
					continue;
				}
				else if (pole[pom->x][pom->y] == 3) // ROBAK
				{
					punkty++;
					pole[pom->x][pom->y] = 4;
					dodaj_robaka(pole, rozmiar_x, rozmiar_y);//plansza
				}
				else pole[pom->x][pom->y] = 2; //PUSTE POLE wpisuje nowa glowe

				push(&pom, &pierwszy, &ostatni);//odkladam glowe do kolejki

				//TYL WEZA
				if (zjedzony_robak(pole, &pierwszy))//ZJEDZONY ROBAK, ZAMIANA NA CIALO WEZA, snake
					pole[pierwszy->x][pierwszy->y] = 2;
				else//USUNIECIE TYLU
				{
					zlap_ostatni = pop(&pierwszy);
					pole[zlap_ostatni.x][zlap_ostatni.y] = 0;
				}

				odswiez(okno, Sprajty, pole, rozmiar_x, rozmiar_y, punkty, tekst);//plansza

				speed = min_speed - punkty*skok;
				if (speed < max_speed)speed = max_speed;
				Sleep(speed);
			}

			else if (stan == BLAD)
				okno.close();
			
			if (stan == KONIEC)
			{
				zakonczenie = ranking(punkty, level, (rozmiar_x - 2)*(rozmiar_y - 2), tekst) ? true : false;
				okno.close();
			}

		}
		for (int i = 0; i < rozmiar_y; i++)
		delete[] pole[i];
		delete[] pole;

		klocek *uchwyt = new klocek;
		while (pierwszy->next != NULL)
		{
			uchwyt = pierwszy;
			pierwszy = pierwszy->next;
			delete uchwyt;
		}
		delete pierwszy;
	}
	return 0;
}