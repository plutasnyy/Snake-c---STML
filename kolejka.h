#pragma once
#include <iostream> //bez tego nie dalo sie porownac do NULL
struct klocek
{
	int x;
	int y;
	klocek *next;
};
void push(klocek **klocek1,klocek **pierwszy, klocek **ostatni);
klocek pop(klocek **pierwszy);