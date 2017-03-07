#include "kolejka.h"
#include <iostream>
void push(klocek **klocek1,klocek **pierwszy, klocek **ostatni)
{
	if (*pierwszy == NULL)
	{
		*pierwszy = *klocek1;
		*ostatni = *klocek1;
		std:: cout << "jestem tu";
	}
	else
	{
		(**ostatni).next = *klocek1;
		(*ostatni) = *klocek1;
	}
}
klocek pop(klocek **pierwszy)
{
	klocek pom;
	pom.x = (*pierwszy)->x;
	pom.y = (*pierwszy)->y;
	pom.next = (*pierwszy)->next;
	(*pierwszy) = (**pierwszy).next;
	return pom;
}