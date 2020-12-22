#pragma once

#include "Polynominal.h"

namespace PolynominalTestVisual {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	Polynominal p1,p2;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ListBox^  listBoxResult;


	private:int _tag;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  labelExample;
	private: System::Windows::Forms::TextBox^  textBoxExample;
			 /// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listBoxResult = (gcnew System::Windows::Forms::ListBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->labelExample = (gcnew System::Windows::Forms::Label());
			this->textBoxExample = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(163, 51);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(290, 23);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 16);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(142, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Enter two polynomial.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(17, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(110, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"First polynomial:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(17, 79);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(131, 17);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Second polynomial:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(163, 79);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(290, 23);
			this->textBox2->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(273, 309);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(81, 29);
			this->button1->TabIndex = 3;
			this->button1->Tag = L"0";
			this->button1->Text = L"Next";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(376, 309);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 29);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Close";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// listBoxResult
			// 
			this->listBoxResult->FormattingEnabled = true;
			this->listBoxResult->HorizontalScrollbar = true;
			this->listBoxResult->ItemHeight = 16;
			this->listBoxResult->Location = System::Drawing::Point(18, 19);
			this->listBoxResult->Name = L"listBoxResult";
			this->listBoxResult->Size = System::Drawing::Size(433, 244);
			this->listBoxResult->TabIndex = 5;
			this->listBoxResult->Visible = false;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(163, 266);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 23);
			this->textBox3->TabIndex = 6;
			this->textBox3->Text = L"0";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Form1::textBox3_TextChanged);
			this->textBox3->Leave += gcnew System::EventHandler(this, &Form1::textBox3_Leave);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(25, 266);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(76, 17);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Value var: ";
			// 
			// labelExample
			// 
			this->labelExample->AutoSize = true;
			this->labelExample->Location = System::Drawing::Point(20, 121);
			this->labelExample->Name = L"labelExample";
			this->labelExample->Size = System::Drawing::Size(65, 17);
			this->labelExample->TabIndex = 8;
			this->labelExample->Text = L"Example:";
			// 
			// textBoxExample
			// 
			this->textBoxExample->Location = System::Drawing::Point(91, 118);
			this->textBoxExample->Name = L"textBoxExample";
			this->textBoxExample->ReadOnly = true;
			this->textBoxExample->Size = System::Drawing::Size(172, 23);
			this->textBoxExample->TabIndex = 9;
			this->textBoxExample->Text = L"12x^12+45x^5+4x^2";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(467, 350);
			this->Controls->Add(this->textBoxExample);
			this->Controls->Add(this->labelExample);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->listBoxResult);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form1";
			this->Text = L"Test of class Polynominal";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
			 {this->Close();
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(_tag == 0)
			 {
				 try{
				p1.InitialStr(textBox1->Text);
				p2.InitialStr(textBox2->Text);
				 }
				 catch(FormatException ^e)
				 {MessageBox::Show("Enter in field polynomial","Error");
					return;};
				if(!(p1.IsEmpty()&&p2.IsEmpty()))
				{
				listBoxResult->Items->Clear();
				listBoxResult->Items->Add("You entered polynomials:");
				listBoxResult->Items->Add(p1.ToString() + " i " + p2.ToString());
				listBoxResult->Visible = true;
				Polynominal sum,rem,mul,div;
				sum = p1 + p2;
				rem = p1-p2;
				mul = p1*p2;
				try{
				div = p1/p2;
				}
				catch(...){};
				listBoxResult->Items->Add(" ");
				listBoxResult->Items->Add("( " + p1.ToString() + " ) + ( " + p2.ToString() + " ) = " + sum.ToString());
				listBoxResult->Items->Add("( " + p1.ToString() + " ) - ( " + p2.ToString() + " ) = " + rem.ToString());
				listBoxResult->Items->Add("( " + p1.ToString() + " ) * ( " + p2.ToString() + " ) = " + mul.ToString());
				if(!div.IsEmpty())
					{listBoxResult->Items->Add("( " + p1.ToString() + " ) / ( " + p2.ToString() + " ) = " + div.ToString());}
				}
				else
				{
					MessageBox::Show("Enter in field polynomial","Error");
					return;
				};
				_tag = 1;
				textBoxExample->Visible = false;
				labelExample->Visible = false;
				button1->Text = "Once again";
			 }
			 else if(_tag == 1)
			 {listBoxResult->Visible = false;
			 textBox1->Text = "";
			 textBox2->Text = "";
			 textBoxExample->Visible = true;
			 labelExample->Visible = true;
			 _tag = 0;
			 };
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
		 {_tag = 0;
		 }
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {/*if(_tag == 1)
		 {
		 try
		 {
			 listBoxResult->Items->Add("При х = " + textBox3->Text + " ( " + p1.ToString() + " ) = " + p1(Convert::ToDouble(textBox3->Text))); 
		 
		 }
		 catch(...)
		 {}
		 };*/
		 }
private: System::Void textBox3_Leave(System::Object^  sender, System::EventArgs^  e) 
		 {if(_tag == 1)
		 {
		 try
		 {
			 listBoxResult->Items->Add("Under х = " + textBox3->Text + " value polynomial (" + p1.ToString() + "): " + p1(Convert::ToDouble(textBox3->Text))); 
		 
		 }
		 catch(...)
		 {}
		 };
		 }
};
}

