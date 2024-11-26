#pragma once
#include "MyForm.h"

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MenuJuego
	/// </summary>
	public ref class MenuJuego : public System::Windows::Forms::Form
	{

	public:
		MenuJuego(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~MenuJuego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Iniciar;
	protected:

	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Iniciar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Iniciar
			// 
			this->Iniciar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Iniciar->Location = System::Drawing::Point(133, 201);
			this->Iniciar->Name = L"Iniciar";
			this->Iniciar->Size = System::Drawing::Size(267, 132);
			this->Iniciar->TabIndex = 0;
			this->Iniciar->Text = L"Jugar";
			this->Iniciar->UseVisualStyleBackColor = true;
			this->Iniciar->Click += gcnew System::EventHandler(this, &MenuJuego::Iniciar_Click);
			// 
			// MenuJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(546, 563);
			this->Controls->Add(this->Iniciar);
			this->Name = L"MenuJuego";
			this->Text = L"MenuJuego";
			this->ResumeLayout(false);

		}
#pragma endregion

	Void Iniciar_Click(Object^ sender, EventArgs^ e) 
	{
		MyForm^ menu = gcnew MyForm(5, 61);

		this->Visible = false;
		menu->ShowDialog();
		this->Visible = true;
	}
	};
}
