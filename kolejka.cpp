#include "kolejka.h"
#include <iostream>
void push(klocek **klocek1,klocek **pierwszy, klocek **ostatni)
{
	if (*pierwszy == NULL)
	{
		*pierwszy = *klocek1;
		*ostatni = *klocek1;
	}
	else
	{
		(**ostatni).next = *klocek1;
		(*ostatni) = *klocek1;
		(**ostatni).next = NULL;
	}
}
klocek pop(klocek **pierwszy)
{
	klocek pom,*pom2;
	pom2 = *pierwszy;
	pom.x = (*pierwszy)->x;
	pom.y = (*pierwszy)->y;
	pom.next = (*pierwszy)->next;
	(*pierwszy) = (**pierwszy).next;
	delete pom2;
	return pom;
}