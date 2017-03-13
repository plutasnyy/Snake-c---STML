#pragma once
#include <SFML/Graphics.hpp>	
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

//WYPELNIA PLANSZE ZERAMI I USTAWIA WARTOSCI RAMKI na podstawie pola, x,y ROZMIAR a nie ostatnie indeksy
void wypelnij(int **pole,int x,int y);

//RYSUJE NA NOWO SCENE
void odswiez(sf::RenderWindow &okno, sf::Sprite Sprajty[], int **pole, int x, int y, int punkty, sf::Text tekst);

//ZWRACA FALSZ PRZY BRAKU GRAFIKI
bool wczytaj_sprajty(sf::Sprite Sprajty[],sf::Texture Tekstury[]);

//LOSUJE ROBAKA NA PLANSZY W WOLNYM POLU
void dodaj_robaka(int **pole, int x, int y);

//INT -> STRING
string oblicz_punkty(int punkty);