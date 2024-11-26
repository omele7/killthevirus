#pragma once
#include "Entidad.h"

class SalidaI : public Entidad
{
public:

	SalidaI()
	{
		x = 115;
		y = 50;

		ancho = 122;
		alto = 162;
	}
};

class Salida1
{
private:
	vector<SalidaI*> salida1;

public:

	Salida1(int n = 1)
	{
		salida1.push_back(new SalidaI);
	}

	void Mostrar(Graphics^ g)
	{
		for (SalidaI* sal : salida1)
		{
			sal->Mostrar(g);
		}
	}

	bool Colision(Rectangle objeto)
	{
		for each (SalidaI* sal in salida1)
		{
			if (sal->timeArea().IntersectsWith(objeto)) return true;
		}
		return false;
	}

};