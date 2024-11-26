#pragma once
#include "Doctor.h"
#include "Enemigo.h"
#include "Botiquines.h"
#include "SalidaI.h"
#include "SalidaD.h"

ref class Juego
{
private:
	Doctor* doctor;
	Enemigos* enemigos;
	Botiquines* botiquines;
	Salida1* salida1;
	Salida2* salida2;

	Bitmap^ imagenVirus;
	Bitmap^ imagenDoctor;
	Bitmap^ imagenBotiquin;

	int cooldownVidaPerdida;

	int tiempo;

public:

	Juego(int v, int t)
	{
		imagenVirus = gcnew Bitmap("imagenes/Virus.png");
		imagenDoctor = gcnew Bitmap("imagenes/Doctor.png");
		imagenBotiquin = gcnew Bitmap("imagenes/Botiquin.png");

		doctor = new Doctor(imagenDoctor, v);
		enemigos = new Enemigos(10, doctor->Area(), imagenVirus);
		botiquines = new Botiquines(4, doctor->Area(), imagenBotiquin);
		salida1 = new Salida1();
		salida2 = new Salida2();

		cooldownVidaPerdida = 0;

		tiempo = t * 1000 + clock();
	}

	~Juego()
	{
		delete doctor, enemigos, botiquines;
		delete imagenVirus;
	}

	bool Mover(Graphics^ g)
	{
		if (doctor->getAccion() >= caminarArriba || doctor->getAccion() <= caminarDerecha)
		{
			doctor->setPuntos(botiquines->Eliminar(doctor->timeArea()));
		}

		if (enemigos->Colision(doctor->timeArea()) && clock() - cooldownVidaPerdida >= 2000)
		{
			doctor->setVidas(-1);
			cooldownVidaPerdida = clock();

			if (doctor->getVidas() == 0) return false;
		}

		if (clock() >= tiempo) return false;

		if (salida1->Colision(doctor->timeArea()) && doctor->getPuntos() == 4) return false;
		if (salida2->Colision(doctor->timeArea()) && doctor->getPuntos() == 4) return false;

		doctor->Mover(g);
		enemigos->Mover(g);

		return true;
	}

	void Mostrar(Graphics^ g)
	{
		g->DrawString("Tiempo: " + ((tiempo - clock()) / 1000), gcnew Font("Arial", 12), Brushes::BlueViolet, 1, 20);

		doctor->Mostrar(g, imagenDoctor);
		enemigos->Mostrar(g, imagenVirus);
		botiquines->Mostrar(g, imagenBotiquin);
		
		if (doctor->getPuntos() == 4) salida1->Mostrar(g);
		if (doctor->getPuntos() == 4) salida2->Mostrar(g);
	}

	void movimientoJugador(bool click, Keys tecla)
	{
		int velocidad = 4;

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