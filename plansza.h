#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
void wypelnij(int **pole,int x,int y);
void odswiez(sf::RenderWindow &okno, sf::Sprite Sprajty[], int **pole, int x, int y);
void wczytaj_sprajty(sf::Sprite Sprajty[],sf::Texture Tekstury[]);