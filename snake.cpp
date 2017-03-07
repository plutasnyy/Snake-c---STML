#include "snake.h"
void ustal_pozycje_glowy(int kierunek, klocek **pom)
{
	if (kierunek == 1)(*pom)->x--;
	if (kierunek == 2)(*pom)->x++;
	if (kierunek == 3)(*pom)->y--; // bo numeracja okno w SFML od 0 w GORE!!!
	if (kierunek == 4)(*pom)->y++;
}

bool zjedzony_robak(int **pole, klocek **pierwszy)
{
	if (pole[(*pierwszy)->x][(*pierwszy)->y] == 4)
		return true;
	return false;
}