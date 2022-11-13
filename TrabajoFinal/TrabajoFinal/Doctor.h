#pragma once
#pragma once
#include "Entidad.h"

enum spriteDoctor
{
	caminarAbajo,
	caminarIzquierda,
	caminarDerecha,
	caminarArriba,
};

class Doctor : public Entidad
{
private:
	spriteDoctor accion;

public:

	Doctor(Bitmap^ imagenes)
	{
		x = 30;
		y = 200;

		dx = dy = 0;

		alto = imagenes->Height / 4;
		ancho = imagenes->Width / 4;

		accion = caminarDerecha;
	}

	void Mover(Graphics^ g)
	{
		if ((x + dx >= 0) && (x + ancho + dx < g->VisibleClipBounds.Width)) x += dx;
		if ((y + dy >= 0) && (y + alto + dy < g->VisibleClipBounds.Height)) y += dy;
	}

	void Mostrar(Graphics^ g, Bitmap^ imagenes)
	{
		Rectangle corte = Rectangle(idx * ancho, accion * alto, ancho, alto);
		g->DrawImage(imagenes, Area(), corte, GraphicsUnit::Pixel);

		if (dx != 0 || dy != 0)
		{
			idx = (idx + 1) % 4;
		}
	}

	void setAccion(spriteDoctor valor)
	{
		accion = valor;
	}

};