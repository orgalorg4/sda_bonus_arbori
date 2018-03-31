#include <iostream>
#include "Header.h"

int main()
{
	Nod *r = 0;
	Atom n;
	/*
	std::cout << "introd sir numere separate prin spatiu terminat cu 0 :";
	do {
		std::cin >> n;
		Insert(r, n);
	} while (n != 0);
	while (r)
	{
		std::cout << r->data << " ";
		Delete(r, key(r->data));
	}
	std::cout << std::endl;
	*/
	r = MakeNod(5);
	Nod *k = Search(r, 5);
	//std::cout << key(k->data) << std::endl;
	if(r)std::cout << key(r->data)<<std::endl;
	//Delete(r, 5);
	Nod *p=k;
	if(r->stg==0)r = r->drt;
	delete p;
	if (r)std::cout << key(r->data) << std::endl;
	return 0;
}