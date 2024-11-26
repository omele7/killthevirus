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
	int vidas;
	int puntos;
	spriteDoctor accion;

public:

	Doctor(Bitmap^ imagenes, int v)
	{
		x = 30;
		y = 300;

		dx = dy = 0;

		alto = imagenes->Height / 4;
		ancho = imagenes->Width / 4;

		accion = caminarDerecha;

		vidas = v;

		puntos = 0;
	}

	void Mover(Graphics^ g)
	{
		if ((x + dx >= 0) && (x + ancho + dx < g->VisibleClipBounds.Width)) x += dx;
		if ((y + dy >= 0) && (y + alto + dy < g->VisibleClipBounds.Height)) y += dy;
	}

	void Mostrar(Graphics^ g, Bitmap^ imagenes)
	{
		g->DrawString("Vidas: " + vidas, gcnew Font("Arial", 12), Brushes::Red, 1, 1);
		g->DrawString("Botiquines: " + puntos, gcnew Font("Arial", 12), Brushes::Green, 1, 40);

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

	spriteDoctor getAccion()
	{
		return accion;
	}

	void setVidas(int valor)
	{
		vidas += valor;
	}

	int getVidas()
	{
		return vidas;
	}

	int getPuntos()
	{
		return puntos;
	}

	void setPuntos(int valor)
	{
		puntos += valor;
	}

};