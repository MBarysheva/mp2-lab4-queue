#pragma once
#include"../Queue/Queue.h"
namespace Exe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		int MaxSize, size, push, pop;
		double p, q;
		TQueue<int>* queue;
		int CenterX, CenterY, Width, Height;
		Graphics^ gr;
		Random^ rndl;
		Pen^ BlackPen;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	
	public:
		Form1(void)
		{
			InitializeComponent();
			gr = this->CreateGraphics();
			rndl = gcnew Random();
			BlackPen = gcnew Pen(Color::Black);
			BlackPen->Width = 2.0F;
			WhitePen = gcnew Pen(SystemColors::Control);
			WhitePen->Width = 2.5F;
			CenterX = 180;
			CenterY = 250;
			Width = Height = 150;
			pop = push = 0; 
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
		   Pen^ WhitePen;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::ComponentModel::IContainer^ components;



	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(34, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 15);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Max size of queue";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(34, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(125, 15);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Starting size of queue";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Window;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(332, 145);
			this->button1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(141, 63);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Stop";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::Window;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->Location = System::Drawing::Point(332, 62);
			this->button2->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(141, 66);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Start";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(34, 145);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(224, 15);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Probability of the element being queued";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(34, 209);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(223, 15);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Probability of deleting element in queue";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(515, 145);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(103, 15);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Added to a queue";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(515, 60);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(147, 15);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Extracted  from the queue";
			// 
			// timer1
			// 
			this->timer1->Interval = 250;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(37, 43);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 21);
			this->textBox1->TabIndex = 15;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(37, 107);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 21);
			this->textBox2->TabIndex = 16;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(37, 177);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 21);
			this->textBox3->TabIndex = 17;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(37, 238);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 21);
			this->textBox4->TabIndex = 18;
			// 
			// textBox5
			// 
			this->textBox5->Cursor = System::Windows::Forms::Cursors::No;
			this->textBox5->Enabled = false;
			this->textBox5->Location = System::Drawing::Point(518, 107);
			this->textBox5->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 21);
			this->textBox5->TabIndex = 19;
			// 
			// textBox6
			// 
			this->textBox6->Cursor = System::Windows::Forms::Cursors::No;
			this->textBox6->Enabled = false;
			this->textBox6->Location = System::Drawing::Point(518, 187);
			this->textBox6->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 21);
			this->textBox6->TabIndex = 20;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(727, 459);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"Form1";
			this->Text = L"Queue";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	gr->DrawArc(BlackPen, CenterX, CenterY, Width, Height, 0, 180);
	gr->DrawLine(Pens::Red, 400, 400, 400, 0);
	timer1->Enabled = false;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	MaxSize = Convert::ToInt32(textBox1->Text);
	size = Convert::ToInt32(textBox2->Text);
	p = Convert::ToDouble(textBox3->Text);
	q = Convert::ToDouble(textBox4->Text);
	queue = new TQueue<int>(MaxSize);
	push = 0;
	pop = 0;
	for (int i = 0; i < size; i++)
		queue->Push(i);
	DrawQueue();
	timer1->Enabled = true;
}
	   void DrawQueue()
	   {
		   int start = 1 * queue->GetNumberHead() / queue->GetMaxSize();
		   int finish = 360 * queue->GetDataCount() / queue->GetMaxSize();
		   gr->DrawArc(BlackPen, CenterX, CenterY, Width, Height, start, finish);
	   }
	   void Clean()
	   {
		   gr->DrawArc(BlackPen, CenterX, CenterY, Width, Height, 0, 360);
	   }
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	Clean();
	if (rndl->NextDouble() < p)
	{
		if (size < MaxSize)
		{
			queue->Push(1);
			size++;
			push++;
		}
	}
	if (rndl->NextDouble() < q)
	{
		if (size > 0)
		{
			queue->GetHead();
			size--;
			pop++;
		}
	}
	DrawQueue();
	textBox5->Text = Convert::ToString(push);
	textBox6->Text = Convert::ToString(pop);
}
private: System::Void Form1_Load(System::Object ^ sender, System::EventArgs ^ e) {
}

};

}
