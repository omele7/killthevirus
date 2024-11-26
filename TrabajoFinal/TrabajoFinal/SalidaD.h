#pragma once
#include "Entidad.h"

class SalidaD : public Entidad
{
public:

	SalidaD()
	{
		x = 763;
		y = 45;

		ancho = 112;
		alto = 162;
	}
};

class Salida2
{
private:
	vector<SalidaD*> salida1;

public:

	Salida2(int n = 1)
	{
		salida1.push_back(new SalidaD);
	}

	void Mostrar(Graphics^ g)
	{
		for (SalidaD* sal : salida1)
		{
			sal->Mostrar(g);
		}
	}

	bool Colision(Rectangle objeto)
	{
		for each (SalidaD * sal in salida1)
		{
			if (sal->timeArea().IntersectsWith(objeto)) return true;
		}
		return false;
	}

};