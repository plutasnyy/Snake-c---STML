#pragma once
#include "kolejka.h" //musi byc bo definicja funkcji nizej 
void ustal_pozycje_glowy(int kierunek, klocek **pom);
bool zjedzony_robak(int **pole, klocek **pierwszy);// ZWRACA TRUE jesli ogon nalezy przedluzyc