#include "Header.h"

int key(Atom data) { return data; }

Nod *MakeNod(Atom val)
{
	Nod *r = new Nod;
	r->data = val;
	r->stg = 0;
	r->drt = 0;
	return r;
}
Nod *Search(Nod *r, int k)
{
	if (r == 0 || k == key(r->data)) 
		return r;
	Nod *p = r;
	while (p && k != key(p->data))
	{
		if (k < key(p->data))
			p = p->stg;
		else
			p = p->drt;
	}
	return p;
}
void Insert(Nod *r, Atom a)
{
	if (r == 0)
		r = MakeNod(a);
	else
	{
		Nod *p = r;
		Nod *p1=p;
		while (p)
		{
			p1 = p;
			if (key(a) < key(p->data))
				p = p->stg;
			else
				if (key(a) > key(p->data))
					p = p->drt;
				else
					return;
		}
		if (key(a) < key(p1->data))
			p1->stg = MakeNod(a);
		else
			p1->drt = MakeNod(a);
	}
}/*
void Delete(Nod *&r, int k)
{
	if (r == 0)
		return;
	else
	{
		Nod *r2 = Search(r, k);
		Nod *p;
		if (r2->stg == 0)
		{
			p = r2->drt;
			delete r2;
			r2 = p;
		}
		else
		{
			if (r2->drt == 0)
			{
				p = r2->stg;
				delete r2;
				r2 = p;
			}
			else
			{
				Nod *r3 = r2->stg;
				while (r3->drt)
					r3 = r3->drt;
				p = r3;
				r3 = r3->stg;
				p->stg = r3->stg;
				p->drt = r3->drt;
				delete r3;
				r3 = p;
			}
		}
	}
}
*/

void Delete(Nod *&r, int k)
{
	if (r == 0)
		return;
	else
	{
		Nod *r2 = Search(r, k);
		Nod *p=r2;
		if (r2->stg == 0)r2 = r2->drt;
		else if (r2->drt == 0)r2 = r2->stg;
		else
		{
			Nod *r3 = r2->stg;
			while (r3->drt)
				r3 = r3->drt;
			p = r3;
			r3 = r3->stg;

			r3->stg = p->stg;
			r3->drt = p->drt;
		}
		delete p;
	}
}