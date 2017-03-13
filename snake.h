#pragma once
#include "kolejka.h" //musi byc bo definicja funkcji nizej 

//NA PODSTAWIE KIERUNKU USTALA NOWE POLOZENIE GLOWY
void ustal_pozycje_glowy(int kierunek, klocek **pom);

//ZWRACA PRAWDA JESLI ROBAK JEST ZJEDZONY JEST NA POCZATKU KOLEJKI
bool zjedzony_robak(int **pole, klocek **pierwszy);// TRUE jesli ogon nalezy przedluzyc