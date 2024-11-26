#pragma once
#include "Entidad.h"

class Botiquin : public Entidad
{
public:

	Botiquin(Bitmap^ imagenes)
	{
		x = rand() % 600 + 150;
		y = rand() % 500 + 200;

		ancho = 25;
		alto = 25;
	}

	void Mostrar(Graphics^ g, Bitmap^ imagenes)
	{
		g->DrawImage(imagenes, Area());
	}
};

class Botiquines
{
private:
	vector<Botiquin*> botiquines;

public:

	Botiquines(int n, Rectangle objeto, Bitmap^ imagenes)
	{
		for (int i = 0; i < n; i++)
		{
			Botiquin* bot = new Botiquin(imagenes);

			if (bot->timeArea().IntersectsWith(objeto) == false && Colision(bot->timeArea()) == false) botiquines.push_back(bot);
			else
			{
				delete bot;
				i--;
			}
		}
	}

	~Botiquines()
	{
		for (int i = 0; i < botiquines.size(); i++)
			delete botiquines.at(i);
	}

	void Mostrar(Graphics^ g, Bitmap^ imagenes)
	{
		for (Botiquin* bot : botiquines)
		{
			bot->Mostrar(g, imagenes);
		}
	}

	bool Colision(Rectangle objeto)
	{
		for each (Botiquin* bot in botiquines)
		{
			if (bot->timeArea().IntersectsWith(objeto)) return true;
		}
		return false;
	}

	int Eliminar(Rectangle rect)
	{
		int cant = 0;

		for (int i = 0; i < botiquines.size(); i++)
		{
			if (botiquines[i]->Area().IntersectsWith(rect))
			{
				botiquines.erase(botiquines.begin() + i--);
				cant++;
			}
		}

		return cant;
	}
};