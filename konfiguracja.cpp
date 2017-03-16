#include "konfiguracja.h"
void sortuj(int *tab, int rozmiar)
{
	int flaga = 0;
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
}
bool wyswietl_okno(int all, int pozycja, int *tab, sf::Text &tekst,int rozmiar)
{
	string slowa = "";
	slowa += "TWOJE PUNKTY: \n";
	slowa += oblicz_punkty(all); //plansza
	slowa += "\n\nTWOJA POZYCJA: \n";
	slowa += oblicz_punkty(pozycja);
	slowa += " / ";
	slowa += oblicz_punkty(rozmiar);
	slowa += "\n\n TOP 5:\n";
	char pom;
	for (int i = 0; i < 5; i++)
	{
		pom = i + 49;
		slowa += pom;
		slowa += ". ";
		slowa += oblicz_punkty(tab[i]);
		slowa += "\n";
	}

	slowa += "\nCzy chcesz zagrac ponownie? 1. TAK 2. NIE";
	tekst.setString(slowa);
	tekst.setPosition(10, 10);
	sf::RenderWindow okno(sf::VideoMode(500, 400, 32), "Ranking");
	sf::Event zdarzenie;
	int key = 0;
	while (okno.isOpen())
	{
		okno.clear();
		okno.draw(tekst);
		while (okno.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::Closed)
				okno.close();

			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
				okno.close();
			if (zdarzenie.type == sf::Event::KeyPressed)
			{
				if (zdarzenie.key.code == sf::Keyboard::Num1)
					key = 1;
				else if (zdarzenie.key.code == sf::Keyboard::Num2)
					key = 2;
			}
		}
		if (key == 1 || key == 2)
		{
			okno.close();
			if (key == 1)return false;
			if (key == 2)return true;
		}
		okno.display();
	}
}
int ranking(int punkty, int level, int max_pol, sf::Text &tekst)
{
	//WCZYTANIE
	double d_level = (level + 1) / 2;
	int all = (punkty + 30 )  * d_level * 10000 / max_pol;
	int rozmiar, pozycja = 0, flaga = 0;
	FILE *plik = fopen("ranking.txt", "r");    // otworzenie pliku do odczytu
	if (plik)
	{
		fscanf(plik, "%d", &rozmiar);
		if (rozmiar > 10000)rozmiar = 10000;
		int *tab = new int[rozmiar + 1]; //jedno miejsce wiecej aby dodac
		for (int i = 0; i < rozmiar; i++)//wczytaj dane i ustal pozycje
		{
			fscanf(plik, "%d", &tab[i]);
			if (flaga == 0 && tab[i] <= all)
			{
				flaga = 1;
				pozycja = i + 1; //zapisz pozycje
			}
		}
		fclose(plik);

		tab[rozmiar] = all;
		sortuj(tab, rozmiar); //Sortuje tylko bablem, bo na starcie jest prawie posortowana

		FILE *plik2 = fopen("ranking.txt", "w+");
		if (plik2)
		{
			fprintf(plik2, "%d\n", rozmiar + 1);
			for (int i = 0; i < rozmiar + 1; i++)
				fprintf(plik2, "%d\n", tab[i]);
		}
		fclose(plik2);
		flaga=wyswietl_okno(all, pozycja,tab, tekst, rozmiar); // wyswietla okno i zwraca czy kontynuowac gre
	}
	else fclose(plik);

	if (flaga == true)return true;
	else return false;
}


bool konfiguracja(int &rozmiar_x, int &rozmiar_y, int &level, int &max_speed, int &skok, int &min_speed, sf::Text &tekst)
{
	sf::RenderWindow okno(sf::VideoMode(500, 300, 32), "Konfiguracja");
	sf::Event zdarzenie;	
	int key = 0, flaga = 0, t_rozmiarow[6] = { 15,15,20,20,25,25 };
	string slowa = "Wybierz poziom trudnosci <1:8> : ";
	tekst.setString(slowa);
	tekst.setCharacterSize(20);

	level = 0;
	rozmiar_x = 15;
	rozmiar_y = 15; //wartosci poczatkowe w razie bledu

	while (okno.isOpen())
	{
		okno.clear();
		okno.draw(tekst);
		while (okno.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::Closed)
				okno.close();

			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
				okno.close();

			if (zdarzenie.type == sf::Event::TextEntered)
			{
				if (zdarzenie.text.unicode >= 48 && zdarzenie.text.unicode <= 56)
					key = zdarzenie.text.unicode;	
			}
			if (flaga == 2)
			{
				Sleep(400);//zeby nie zniknelo okieno, nie przestawiac nizej, wazna kolejnosc!
				okno.close();
			}
			if (key != 0 && flaga == 0)
			{
				flaga = 1;
				level = key-48;
				slowa += static_cast <char> (key);
				key = 0;
				okno.clear();
				slowa += "\nWybierz rozmiar planszy 1 - mala 2 - srednia 3 - duza : ";
				tekst.setString(slowa);
			}
			if (key >= 49 && key <= 51 && flaga == 1)
			{
				slowa += static_cast<char>(key);
				tekst.setString(slowa);
				key -= 49;
				rozmiar_x = t_rozmiarow[2 * key];
				rozmiar_y = t_rozmiarow[2 * key + 1];
				flaga = 2;
			}
		}
		okno.display();
	}

	max_speed = 30 + 20 * (8-level); //min
	int ilosc_skokow = (rozmiar_x - 2)*(rozmiar_y - 2) * 10 / 100;
	min_speed = 500 - 20 * level;
	skok = (min_speed-max_speed)/ilosc_skokow;
	if (flaga == 4)return true;
	else return false;
}