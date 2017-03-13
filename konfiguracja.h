#pragma once
#include <SFML/Graphics.hpp>
#include "plansza.h"
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning (disable : 4996)
int ranking(int punkty, int level, int max_pol, sf::Text &tekst);
bool konfiguracja(int &rozmiar_x, int &rozmiar_y, int &level, int &max_speed, int &skok, int &min_speed, sf::Text &tekst);