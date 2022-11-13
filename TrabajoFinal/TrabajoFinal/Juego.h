#pragma once
#include "Doctor.h"
#include "Enemigo.h"

ref class Juego
{
private:
	Doctor* doctor;
	Enemigos* enemigos;

	Bitmap^ imagenVirus;
	Bitmap^ imagenDoctor;

public:

	Juego()
	{
		imagenVirus = gcnew Bitmap("imagenes/Virus.png");
		imagenDoctor = gcnew Bitmap("imagenes/Doctor.png");

		doctor = new Doctor(imagenDoctor);
		enemigos = new Enemigos(5, doctor->Area(), imagenVirus);
	}

	~Juego()
	{
		delete doctor, enemigos;
		delete imagenVirus;
	}

	void Mover(Graphics^ g)
	{
		if (enemigos->Colision(doctor->timeArea()) == false) doctor->Mover(g);

		enemigos->Mover(g);
	}

	void Mostrar(Graphics^ g)
	{
		doctor->Mostrar(g, imagenDoctor);
		enemigos->Mostrar(g, imagenVirus);
	}

	void movimientoJugador(bool click, Keys tecla)
	{
		int velocidad = 5;

		if (click == true)
		{
			if (tecla == Keys::Up)
			{
				doctor->setDY(-velocidad);
				doctor->setAccion(caminarArriba);
			}

			else if (tecla == Keys::Down)
			{
				doctor->setDY(velocidad);
				doctor->setAccion(caminarAbajo);
			}

			else if (tecla == Keys::Left)
			{
				doctor->setDX(-velocidad);
				doctor->setAccion(caminarIzquierda);
			}

			else if (tecla == Keys::Right)
			{
				doctor->setDX(velocidad);
				doctor->setAccion(caminarDerecha);
			}
		}
		else
		{
			if (tecla == Keys::Up) doctor->setDY(0);
			else if (tecla == Keys::Down) doctor->setDY(0);
			else if (tecla == Keys::Left) doctor->setDX(0);
			else if (tecla == Keys::Right) doctor->setDX(0);
		}
	}

};