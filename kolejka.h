#pragma once
struct klocek
{
	int x;
	int y;
	klocek *next;
};
void push(klocek *klocek1,klocek **pierwszy, klocek **ostatni);
void pop(klocek **pierwszy);