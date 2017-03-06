#include "kolejka.h"
#include <iostream>
void push(klocek *klocek1, klocek **pierwszy, klocek **ostatni)
{
	if (*pierwszy == NULL)
		*pierwszy = klocek1;
	else
		(*ostatni)->next = klocek1;

	*ostatni = klocek1;
}
void pop(klocek **pierwszy)
{
	(*pierwszy) = (*pierwszy)->next;
}