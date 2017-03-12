#pragma once
#include <SFML/Graphics.hpp>

//WYPELNIA PLANSZE ZERAMI I USTAWIA WARTOSCI RAMKI na podstawie pola, x,y ROZMIAR a nie ostatnie indeksy
void wypelnij(int **pole,int x,int y);

void odswiez(sf::RenderWindow &okno, sf::Sprite Sprajty[], int **pole, int x, int y, int punkty, sf::Text tekst);

//ZWRACA FALSZ PRZY BRAKU GRAFIKI
bool wczytaj_sprajty(sf::Sprite Sprajty[],sf::Texture Tekstury[]);

void dodaj_robaka(int **pole, int x, int y);