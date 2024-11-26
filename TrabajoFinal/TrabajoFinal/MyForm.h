#pragma once
#include "Juego.h"

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Juego^ juego;

	private:
		SoundPlayer^ music;

	public:
		MyForm(int v, int t)
		{
			InitializeComponent();
			srand(time(NULL));

			bmpMap = gcnew Bitmap("imagenes/Fondo.png");

			juego = gcnew Juego(v, t);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete juego;
		}
	private: System::Windows::Forms::Timer^ Reloj;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Bitmap^ bmpMap;
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Reloj = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// Reloj
			// 
			this->Reloj->Enabled = true;
			this->Reloj->Interval = 33;
			this->Reloj->Tick += gcnew System::EventHandler(this, &MyForm::Reloj_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1022, 756);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion

		void Musica()
		{
			music = gcnew SoundPlayer("sonido/CentroPokemon.wav");

			music->PlayLooping();
		}

	Void MyForm_Load(Object^ sender, EventArgs^ e)
	{
		Musica();
	}
	Void Reloj_Tick(Object^ sender, EventArgs^ e) 
	{
		Graphics^ g = this->CreateGraphics();

		BufferedGraphicsContext^ bfc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = bfc->Allocate(g, this->ClientRectangle);

		bf->Graphics->Clear(Color::White);

		bf->Graphics->DrawImage(bmpMap, 0, 0, bmpMap->Width * 0.75, bmpMap->Height * 0.75);
		juego->Mostrar(bf->Graphics);

		bf->Render(g);

		if (juego->Mover(g) == false) this->Close(), music->Stop();

	}
	Void MyForm_KeyDown(Object^ sender, KeyEventArgs^ e) 
	{
		juego->movimientoJugador(true, e->KeyCode);
	}
	Void MyForm_KeyUp(Object^ sender, KeyEventArgs^ e) 
	{
		juego->movimientoJugador(false, e->KeyCode);
	}
	};
}
