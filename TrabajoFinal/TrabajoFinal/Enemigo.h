#pragma once
#include "Entidad.h"

class Enemigo : public Entidad
{
public:

	Enemigo(Bitmap^ imagenes)
	{
		x = rand() % 650 + 200;
		y = rand() % 650;

		if (rand() % 2 == 0)
		{
			dx = 4;
		}
		else
		{
			dy = 4;
		}

		ancho = 25;
		alto = 25;
	}

	void Mover(Graphics^ g)
	{
		if (!(x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width)) dx *= -1;
		if (!(y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height)) dy *= -1;

		x += dx;
		y += dy;
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
		for each (Enemigo* enm in enemigos)
		{
			if (enm->timeArea().IntersectsWith(objeto)) return true;
		}
		return false;
	}

};