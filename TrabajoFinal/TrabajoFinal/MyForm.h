#pragma once
#include "Juego.h"

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Juego^ juego;


	public:
		MyForm(void)
		{
			InitializeComponent();

			juego = gcnew Juego();
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
			this->ClientSize = System::Drawing::Size(589, 510);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	Void Reloj_Tick(Object^ sender, EventArgs^ e) 
	{
		Graphics^ g = this->CreateGraphics();
		g->Clear(Color::White);

		juego->Mover(g);
		juego->Mostrar(g);
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
