#pragma once
#include "Entidad.h"


class Enemigo : public Entidad
{
public:

	Enemigo(Bitmap^ imagenes)
	{
		x = rand() % 500 ;
		y = rand() % 500 ;

		ancho = 25;
		alto = 25;
	}

	void Mostrar(Graphics^ g, Bitmap^ imagenes)
	{
		g->DrawImage(imagenes, Area());
	}
};

class Enemigos
{
private:
	vector<Enemigo*> enemigos;

public:

	Enemigos(int n, Rectangle objeto, Bitmap^ imagenes)
	{
		for (int i = 0; i < n; i++)
		{
			Enemigo* enm = new Enemigo(imagenes);

			if (enm->timeArea().IntersectsWith(objeto) == false && Colision(enm->timeArea()) == false) enemigos.push_back(enm);
			else
			{
				delete enm;
				i--;
			}
		}
	}

	~Enemigos()
	{
		for (int i = 0; i < enemigos.size(); i++)
			delete enemigos.at(i);
	}

	void Mover(Graphics^ g)
	{
		for (int i = 0; i < enemigos.size(); i++)
		{
			enemigos.at(i)->Mover(g);
		}
	}

	void Mostrar(Graphics^ g, Bitmap^ imagenes)
	{
		for (Enemigo* enm : enemigos)
		{
			enm->Mostrar(g, imagenes);
		}
	}

	bool Colision(Rectangle objeto)
	{
		for each (Enemigo * enm in enemigos)
		{
			if (enm->timeArea().IntersectsWith(objeto)) return true;
		}
		return false;
	}

};