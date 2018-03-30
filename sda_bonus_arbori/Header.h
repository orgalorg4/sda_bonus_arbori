#pragma once
typedef int Atom;
struct Nod
{
	Atom data;
	Nod *stg;
	Nod *drt;
};
int key(Atom data);

Nod *MakeNod(Atom val);
Nod *Search(Nod *r, int k);
void Insert(Nod *r, Atom a);
void Delete(Nod *&r, int k);