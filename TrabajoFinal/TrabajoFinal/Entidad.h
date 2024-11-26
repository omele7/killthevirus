#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#include <time.h>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class Entidad
{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int idx;

public:

	Entidad()
	{
		x = y = 0;
		dx = dy = 0;
		ancho = alto = 0;
		idx = 0;
	}

	Rectangle Area()
	{
		return Rectangle(x, y, ancho, alto);
	}

	Rectangle timeArea()
	{
		return Rectangle(x + dx, y + dy, ancho, alto);
	}

	virtual void Mover(Graphics^ g)
	{
		x += dx;
		y += dy;
	}

	virtual void Mostrar(Graphics^ g)
	{
		g->FillRectangle(Brushes::White, Area());
	}

	void setDX(int aux)
	{
		dx = aux;
	}

	void setDY(int aux)
	{
		dy = aux;
	}
};