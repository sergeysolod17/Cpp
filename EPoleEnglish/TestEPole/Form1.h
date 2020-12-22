#pragma once

#include "stdafx.cpp"

#include "EPoleClass.h"
#include "VectorPole.h"
//#include "EPoleClass.h"
int coef_m = 10;

namespace TestEPole {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	value struct LineSection
	{
	int x_begin,y_begin,x_end,y_end;
	float Length;
	};




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
	private: System::Windows::Forms::Button^  buttonAdd;
	protected: 

	protected: 

	private:EPole ^pole;
			Graphics ^g;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Button^  button3;

	private: System::ComponentModel::IContainer^  components;
			 /// <summary>
		/// Required designer variable.
		/// </summary>

	private://void DrawE(System::Windows::Forms::MouseEventArgs^  e);
			int _tag;
			int _tag_potencial;
			int _w;
			int _xm,_ym;
			int ColorNew,ColorOld;
			bool draw_line_mouse;
			int x_mouse,y_mouse;
			int x_start,y_start,x_end,y_end;
			double EMax,WMax;
			LineSection Section;
			bool draw_e_proport_percent;
			bool draw_w_proport_percent;
			int index_current;
			bool sourse_drag;
			//System::Drawing::Bitmap ^image;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textVectorE;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textE;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::TextBox^  textBoxX;
	private: System::Windows::Forms::Label^  labelZ;
	private: System::Windows::Forms::TextBox^  textBoxZ;
	private: System::Windows::Forms::Label^  labelY;
	private: System::Windows::Forms::TextBox^  textBoxY;
	private: System::Windows::Forms::Label^  labelX;
	private: System::Windows::Forms::Label^  labelCharge;
	private: System::Windows::Forms::TextBox^  textBoxCharge;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::TextBox^  textBoxE_d;
	private: System::Windows::Forms::Label^  labelE_d;
	private: System::Windows::Forms::Label^  labelLenSection;
	private: System::Windows::Forms::TextBox^  textBoxLenSection;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  labelPotencial;
	private: System::Windows::Forms::TextBox^  textBoxPotencial;
	private: System::Windows::Forms::CheckBox^  checkBoxEProportional;
	private: System::Windows::Forms::TextBox^  textBoxU;
	private: System::Windows::Forms::Label^  labelU;
	private: System::Windows::Forms::TextBox^  textBoxEProportional;

	private: System::Windows::Forms::CheckBox^  checkBoxAutoRedraw;
	private: System::Windows::Forms::Button^  buttonRemove;
	private: System::Windows::Forms::Label^  labelMax;
	private: System::Windows::Forms::Label^  labelStatus;






			 Vector t;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textVectorE = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textE = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->labelCharge = (gcnew System::Windows::Forms::Label());
			this->textBoxCharge = (gcnew System::Windows::Forms::TextBox());
			this->labelZ = (gcnew System::Windows::Forms::Label());
			this->textBoxZ = (gcnew System::Windows::Forms::TextBox());
			this->labelY = (gcnew System::Windows::Forms::Label());
			this->textBoxY = (gcnew System::Windows::Forms::TextBox());
			this->labelX = (gcnew System::Windows::Forms::Label());
			this->textBoxX = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxE_d = (gcnew System::Windows::Forms::TextBox());
			this->labelE_d = (gcnew System::Windows::Forms::Label());
			this->labelLenSection = (gcnew System::Windows::Forms::Label());
			this->textBoxLenSection = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->labelPotencial = (gcnew System::Windows::Forms::Label());
			this->textBoxPotencial = (gcnew System::Windows::Forms::TextBox());
			this->checkBoxEProportional = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxU = (gcnew System::Windows::Forms::TextBox());
			this->labelU = (gcnew System::Windows::Forms::Label());
			this->textBoxEProportional = (gcnew System::Windows::Forms::TextBox());
			this->checkBoxAutoRedraw = (gcnew System::Windows::Forms::CheckBox());
			this->buttonRemove = (gcnew System::Windows::Forms::Button());
			this->labelMax = (gcnew System::Windows::Forms::Label());
			this->labelStatus = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(764, 437);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(75, 23);
			this->buttonAdd->TabIndex = 0;
			this->buttonAdd->Text = L"Add";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &Form1::buttonAdd_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(251, 549);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::Control;
			this->button3->Location = System::Drawing::Point(764, 408);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Tension";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(755, 541);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseMove);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseDown);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseUp);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(761, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Vector of tension";
			// 
			// textVectorE
			// 
			this->textVectorE->Location = System::Drawing::Point(764, 35);
			this->textVectorE->Name = L"textVectorE";
			this->textVectorE->ReadOnly = true;
			this->textVectorE->Size = System::Drawing::Size(158, 20);
			this->textVectorE->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(761, 58);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(124, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Module vector of tension";
			// 
			// textE
			// 
			this->textE->Location = System::Drawing::Point(767, 74);
			this->textE->Name = L"textE";
			this->textE->ReadOnly = true;
			this->textE->Size = System::Drawing::Size(155, 20);
			this->textE->TabIndex = 9;
			// 
			// timer1
			// 
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->labelCharge);
			this->panel1->Controls->Add(this->textBoxCharge);
			this->panel1->Controls->Add(this->labelZ);
			this->panel1->Controls->Add(this->textBoxZ);
			this->panel1->Controls->Add(this->labelY);
			this->panel1->Controls->Add(this->textBoxY);
			this->panel1->Controls->Add(this->labelX);
			this->panel1->Controls->Add(this->textBoxX);
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Location = System::Drawing::Point(764, 253);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(155, 149);
			this->panel1->TabIndex = 10;
			// 
			// labelCharge
			// 
			this->labelCharge->AutoSize = true;
			this->labelCharge->Location = System::Drawing::Point(4, 112);
			this->labelCharge->Name = L"labelCharge";
			this->labelCharge->Size = System::Drawing::Size(41, 13);
			this->labelCharge->TabIndex = 8;
			this->labelCharge->Text = L"Charge";
			// 
			// textBoxCharge
			// 
			this->textBoxCharge->Location = System::Drawing::Point(52, 112);
			this->textBoxCharge->Name = L"textBoxCharge";
			this->textBoxCharge->Size = System::Drawing::Size(100, 20);
			this->textBoxCharge->TabIndex = 7;
			this->textBoxCharge->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxCharge_TextChanged);
			// 
			// labelZ
			// 
			this->labelZ->AutoSize = true;
			this->labelZ->Location = System::Drawing::Point(3, 85);
			this->labelZ->Name = L"labelZ";
			this->labelZ->Size = System::Drawing::Size(21, 13);
			this->labelZ->TabIndex = 6;
			this->labelZ->Text = L"z =";
			// 
			// textBoxZ
			// 
			this->textBoxZ->Location = System::Drawing::Point(52, 85);
			this->textBoxZ->Name = L"textBoxZ";
			this->textBoxZ->Size = System::Drawing::Size(100, 20);
			this->textBoxZ->TabIndex = 5;
			this->textBoxZ->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxZ_TextChanged);
			// 
			// labelY
			// 
			this->labelY->AutoSize = true;
			this->labelY->Location = System::Drawing::Point(4, 58);
			this->labelY->Name = L"labelY";
			this->labelY->Size = System::Drawing::Size(21, 13);
			this->labelY->TabIndex = 4;
			this->labelY->Text = L"y =";
			// 
			// textBoxY
			// 
			this->textBoxY->Location = System::Drawing::Point(52, 58);
			this->textBoxY->Name = L"textBoxY";
			this->textBoxY->Size = System::Drawing::Size(100, 20);
			this->textBoxY->TabIndex = 3;
			this->textBoxY->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxY_TextChanged);
			// 
			// labelX
			// 
			this->labelX->AutoSize = true;
			this->labelX->Location = System::Drawing::Point(4, 31);
			this->labelX->Name = L"labelX";
			this->labelX->Size = System::Drawing::Size(21, 13);
			this->labelX->TabIndex = 2;
			this->labelX->Text = L"x =";
			// 
			// textBoxX
			// 
			this->textBoxX->Location = System::Drawing::Point(52, 31);
			this->textBoxX->Name = L"textBoxX";
			this->textBoxX->Size = System::Drawing::Size(100, 20);
			this->textBoxX->TabIndex = 1;
			this->textBoxX->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxX_TextChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(4, 4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(148, 21);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->DropDownClosed += gcnew System::EventHandler(this, &Form1::comboBox1_DropDownClosed);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(764, 467);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(133, 17);
			this->checkBox1->TabIndex = 11;
			this->checkBox1->Text = L"Draw vector of tension";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// textBoxE_d
			// 
			this->textBoxE_d->Location = System::Drawing::Point(767, 113);
			this->textBoxE_d->Name = L"textBoxE_d";
			this->textBoxE_d->Size = System::Drawing::Size(152, 20);
			this->textBoxE_d->TabIndex = 12;
			this->textBoxE_d->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxE_d_TextChanged);
			// 
			// labelE_d
			// 
			this->labelE_d->AutoSize = true;
			this->labelE_d->Location = System::Drawing::Point(770, 97);
			this->labelE_d->Name = L"labelE_d";
			this->labelE_d->Size = System::Drawing::Size(117, 13);
			this->labelE_d->TabIndex = 13;
			this->labelE_d->Text = L"Dielectrical permeability";
			// 
			// labelLenSection
			// 
			this->labelLenSection->AutoSize = true;
			this->labelLenSection->Location = System::Drawing::Point(764, 140);
			this->labelLenSection->Name = L"labelLenSection";
			this->labelLenSection->Size = System::Drawing::Size(73, 13);
			this->labelLenSection->TabIndex = 14;
			this->labelLenSection->Text = L"Length line(m)";
			// 
			// textBoxLenSection
			// 
			this->textBoxLenSection->Location = System::Drawing::Point(764, 157);
			this->textBoxLenSection->Name = L"textBoxLenSection";
			this->textBoxLenSection->ReadOnly = true;
			this->textBoxLenSection->Size = System::Drawing::Size(155, 20);
			this->textBoxLenSection->TabIndex = 15;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Control;
			this->button1->Location = System::Drawing::Point(841, 408);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Potential";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// labelPotencial
			// 
			this->labelPotencial->AutoSize = true;
			this->labelPotencial->Location = System::Drawing::Point(764, 180);
			this->labelPotencial->Name = L"labelPotencial";
			this->labelPotencial->Size = System::Drawing::Size(48, 13);
			this->labelPotencial->TabIndex = 17;
			this->labelPotencial->Text = L"Potential";
			// 
			// textBoxPotencial
			// 
			this->textBoxPotencial->Location = System::Drawing::Point(767, 197);
			this->textBoxPotencial->Name = L"textBoxPotencial";
			this->textBoxPotencial->ReadOnly = true;
			this->textBoxPotencial->Size = System::Drawing::Size(152, 20);
			this->textBoxPotencial->TabIndex = 18;
			// 
			// checkBoxEProportional
			// 
			this->checkBoxEProportional->AutoSize = true;
			this->checkBoxEProportional->Checked = true;
			this->checkBoxEProportional->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxEProportional->Location = System::Drawing::Point(764, 490);
			this->checkBoxEProportional->Name = L"checkBoxEProportional";
			this->checkBoxEProportional->Size = System::Drawing::Size(131, 17);
			this->checkBoxEProportional->TabIndex = 19;
			this->checkBoxEProportional->Text = L"Relative value tension";
			this->checkBoxEProportional->UseVisualStyleBackColor = true;
			this->checkBoxEProportional->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxEProportional_CheckedChanged);
			// 
			// textBoxU
			// 
			this->textBoxU->Location = System::Drawing::Point(827, 221);
			this->textBoxU->Name = L"textBoxU";
			this->textBoxU->ReadOnly = true;
			this->textBoxU->Size = System::Drawing::Size(95, 20);
			this->textBoxU->TabIndex = 20;
			this->textBoxU->Text = L"-";
			// 
			// labelU
			// 
			this->labelU->AutoSize = true;
			this->labelU->Location = System::Drawing::Point(770, 224);
			this->labelU->Name = L"labelU";
			this->labelU->Size = System::Drawing::Size(46, 13);
			this->labelU->TabIndex = 21;
			this->labelU->Text = L"Voltage:";
			// 
			// textBoxEProportional
			// 
			this->textBoxEProportional->Location = System::Drawing::Point(645, 548);
			this->textBoxEProportional->Name = L"textBoxEProportional";
			this->textBoxEProportional->Size = System::Drawing::Size(99, 20);
			this->textBoxEProportional->TabIndex = 22;
			this->textBoxEProportional->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// checkBoxAutoRedraw
			// 
			this->checkBoxAutoRedraw->AutoSize = true;
			this->checkBoxAutoRedraw->Location = System::Drawing::Point(764, 513);
			this->checkBoxAutoRedraw->Name = L"checkBoxAutoRedraw";
			this->checkBoxAutoRedraw->Size = System::Drawing::Size(143, 17);
			this->checkBoxAutoRedraw->TabIndex = 24;
			this->checkBoxAutoRedraw->Text = L"Automatically draw again";
			this->checkBoxAutoRedraw->UseVisualStyleBackColor = true;
			// 
			// buttonRemove
			// 
			this->buttonRemove->Location = System::Drawing::Point(841, 438);
			this->buttonRemove->Name = L"buttonRemove";
			this->buttonRemove->Size = System::Drawing::Size(75, 23);
			this->buttonRemove->TabIndex = 25;
			this->buttonRemove->Text = L"Remove";
			this->buttonRemove->UseVisualStyleBackColor = true;
			this->buttonRemove->Click += gcnew System::EventHandler(this, &Form1::buttonRemove_Click);
			// 
			// labelMax
			// 
			this->labelMax->AutoSize = true;
			this->labelMax->Location = System::Drawing::Point(463, 549);
			this->labelMax->Name = L"labelMax";
			this->labelMax->Size = System::Drawing::Size(35, 13);
			this->labelMax->TabIndex = 26;
			this->labelMax->Text = L"label4";
			this->labelMax->Visible = false;
			// 
			// labelStatus
			// 
			this->labelStatus->AutoSize = true;
			this->labelStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->labelStatus->Location = System::Drawing::Point(12, 547);
			this->labelStatus->Name = L"labelStatus";
			this->labelStatus->Size = System::Drawing::Size(165, 17);
			this->labelStatus->TabIndex = 27;
			this->labelStatus->Text = L"Tension of electrical field";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(968, 566);
			this->Controls->Add(this->labelStatus);
			this->Controls->Add(this->labelMax);
			this->Controls->Add(this->buttonRemove);
			this->Controls->Add(this->checkBoxAutoRedraw);
			this->Controls->Add(this->textBoxEProportional);
			this->Controls->Add(this->labelU);
			this->Controls->Add(this->textBoxU);
			this->Controls->Add(this->checkBoxEProportional);
			this->Controls->Add(this->textBoxPotencial);
			this->Controls->Add(this->labelPotencial);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBoxLenSection);
			this->Controls->Add(this->labelLenSection);
			this->Controls->Add(this->labelE_d);
			this->Controls->Add(this->textBoxE_d);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->textE);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textVectorE);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonAdd);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Electrical field";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonAdd_Click(System::Object^  sender, System::EventArgs^  e) 
			 {/*Point3D ^p = gcnew Point3D(0,0,0);
				Color c;
				Pen ^pen1 = gcnew Pen(c.Black);
				Pen ^pen2 = gcnew Pen(c.Red);

				float m;
				m = pole->GetE(p).Length;
				p = gcnew Point3D(Width,Height,0);
				m = (m + pole->GetE(p).Length)/4;

				Graphics ^g = this->CreateGraphics();
				for(int _x = 0;_x < Width;_x++)
					{
						for(int _y = 0;_y < Height;_y++)
						{
							p->X = _x;
							p->Y = _y;
							p->Z = 0;
							if(pole->GetE(p).Length > m)
							{}
							else
							{};
						}
				
					};*/
				 EPoleSoursePoint ^p = gcnew EPoleSoursePoint(400,400,0,22);
				pole->Register(p);
				LoadTextBox();
				comboBox1->SelectedIndex = comboBox1->Items->Count - 1;
				RefreshComboBox();
				_w = 0;
				timer1->Enabled = true;
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {pole = gcnew EPole();
			 g = this->pictureBox1->CreateGraphics();
			 e_dielectrical = 100;
			EPoleSoursePoint ^p1 = gcnew EPoleSoursePoint(200,300,0,2);
			EPoleSoursePoint ^p2 = gcnew EPoleSoursePoint(150,150,0,-1);
			EPoleSoursePoint ^p3 = gcnew EPoleSoursePoint(300,100,0,-1);
			pole->Register(p1);
			pole->Register(p2);
			pole->Register(p3);

			Color c;
			Pen ^pen = gcnew Pen(c.Black);
			p1->Draw(g,pen);

			_w = 0;
			_tag = 1;
			_xm = -1;
			_ym = -1;
			ColorNew = -1;
			ColorOld = -1;
			draw_line_mouse = false;
			_tag_potencial = 0;

			x_start = 0;
			x_end = this->Width;
			y_start = 0;
			y_end = this->Height;


			LoadTextBox();
			Section.x_begin = Section.x_end = Section.y_begin = Section.y_end = -1;
			Section.Length = 0;
			_tag_potencial = 0;
			draw_e_proport_percent = checkBoxEProportional->Checked;

			DrawEPoleSourse(0);
			if(_tag)
				 {_w = 0;
				  DrawE();
				 timer1->Enabled = true;
				 _tag = 0;
				 }
			/*Color c;
			Pen ^pen = gcnew Pen(c.Black);
			p1->Draw(g,pen);
			p2->Draw(g,pen);*/			
			 }
	private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			 {	Color c;
				Pen ^pen = gcnew Pen(c.White);
				 if(checkBox1->Checked)
				 {
				 //Pen ^pen;
				 //Color c;
				 pen = gcnew Pen(c.White);
				 float dx,dy;
				 int y;
				 int dH = 10*t.dY/1000;
				 int dW = 10*t.dX/1000;
				 dx = _xm + 10*t.dX/1000;
				 dy = _ym + 10*t.dY/1000;
				 g->DrawLine(pen,static_cast<float>(_xm),static_cast<float>(_ym),dx,dy);
				 for(int i = 0;i <= dW;i++)
				 {if(dW != 0)
					{
					y = _ym + dH*i/dW;
					Point3D ^p = gcnew Point3D(_xm+i,y,0);
					t = pole->GetE(p);
					pen = GetPenE(GetColorE(t));
				    g->DrawRectangle(pen,_xm+i,y,1,1);
					};
				 }

				 _xm = e->X;
				 _ym = e->Y;

				 pen = GetPenE(GetColorE(t));
				 g->DrawRectangle(pen,e->X,e->Y,1,1);
				 g->DrawRectangle(pen,e->X,e->Y,2,2);
				 g->DrawRectangle(pen,e->X,e->Y,3,3);
				 g->DrawRectangle(pen,e->X,e->Y,4,4);
				
				 
				 pen = gcnew Pen(c.White);
				 dx = e->X + 10*t.dX/1000;
				 dy = e->Y + 10*t.dY/1000;
				 g->DrawLine(pen,static_cast<float>(e->X),static_cast<float>(e->Y),dx,dy);
				 
				 };

				 Point3D ^p = gcnew Point3D(e->X,e->Y,0);//напруженість електричного поля
				 t = pole->GetE(p);
				 textVectorE->Text = Convert::ToString(t);// + " len=" + t.Length;
				 textE->Text = Convert::ToString(t.Length) + " N/Kl";
				 label1->Text = "X;Y = " + Convert::ToString(e->X) + ";" + Convert::ToString(e->Y);

				 EPoleSoursePoint ^pole_s = gcnew EPoleSoursePoint(e->X,e->Y,0,1);
				 float energy = pole->GetEnergy(pole_s);
				 textBoxPotencial->Text = Convert::ToString(energy) + " V";
				 //EPoleSoursePoint ^pole_e = gcnew EPoleSoursePoint(x_mouse,y_mouse,0,1);
				 //textBoxU->Text = Convert::ToString(pole->GetEnergy(pole_s)-pole->GetEnergy(pole_e));
				 
				 if(draw_line_mouse)
				 {/*if(x_mouse < e->X)
					{
						x_start = x_mouse;
						x_end =  e->X;
					}
				 else
					{
					 x_start = e->X;
					 x_end = x_mouse;
					};
				 if(y_mouse < e->Y)
					{
					 y_start = y_mouse;
					 y_end = e->Y;
					}
				 else
					{
					y_start = e->Y;
					y_end = y_mouse;
					};*/
					 EPoleSoursePoint ^pole_e = gcnew EPoleSoursePoint(x_mouse,y_mouse,0,1);
					 textBoxU->Text = Convert::ToString(static_cast<float>(pole->GetEnergy(pole_s)-pole->GetEnergy(pole_e))) + " V";


					 timer1->Enabled = true;
					 g->DrawLine(pen,x_mouse,y_mouse,e->X,e->Y);				 
				 };
				 if(draw_e_proport_percent)
				 {
					 textBoxEProportional->Text = Convert::ToString(static_cast<float>(t.Length/EMax)*100)+"%";
					 textBoxEProportional->Visible = true;
				 }
				 if(draw_w_proport_percent)
				 {
					 textBoxEProportional->Text = Convert::ToString(static_cast<float>(energy/WMax)*100)+"%";
					 textBoxEProportional->Visible = true;
				 }
				 if(sourse_drag)
				 {
					 _w = e->X;
					 timer1->Enabled = true;
					 pole->l[index_current]->X = e->X;
					 pole->l[index_current]->Y = e->Y;
					 _w = 0;
					 DrawEPoleSourse(1);
					 /*if(checkBoxAutoRedraw->Checked)
					 {
					 timer1->Enabled = true;
					 };*/
				 }
				 

			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 /*Color c;
				 Pen ^pen = gcnew Pen(c.Yellow);
				 for(int i= 0;i < pole->l->Count;i++)
				 {
				 pole->l[i]->Draw(g,pen);
				 }*/
				 //DrawEPoleSourse(0);				 
			 };
			 void LoadTextBox()
			 {
				 comboBox1->Items->Clear();
				for(int i = 0;i < pole->l->Count;i++)
					{comboBox1->Items->Add("charge" + Convert::ToString(i));};
				comboBox1->SelectedIndex = 0;
				textBoxE_d->Text = Convert::ToString(e_dielectrical);
				RefreshComboBox();
			 }
			 void DrawEPoleSourse(int i)
			 {
				 Color c;
				 Pen ^pen2;
				 if(_tag == 1)
				 {
					 pen2 = gcnew Pen(c.Black);
				 }
				 else if(_tag == 0)
					{pen2 = gcnew Pen(c.Yellow);}
				 for(int i= 0;i < pole->l->Count;i++)
				 {
				 pole->l[i]->Draw(g,pen2);
				 }
				 //g->DrawLine(pen2,0,0,100,100);
			 }
	 private:int GetColorE(Vector t)
			 {int res = -1;
			 double len = t.Length;
			 if(len > 100000)
				{res = 1;}
			 else if(len > 80000)
				{res = 2;}
			 else if(len > 60000)
				{res = 3;}
			 else if(len > 40000)
				{res = 4;}
			 else if(len > 20000)
				{res = 5;}
			 else if(len >= 0)
				{res = 6;}
			return res;
			 };
		 Pen^ GetPenE(int color)
		 {
			Pen ^pen;
			 Color c;
			 switch(color)
			 {case 1:pen = gcnew Pen(c.Black);
					 break;
			 case 2:pen = gcnew Pen(c.Navy);
					 break;
			 case 3:pen = gcnew Pen(c.Blue);
					 break;
			 case 4:pen = gcnew Pen(c.DodgerBlue);
					 break;
			 case 5:pen = gcnew Pen(c.SeaGreen);
					 break;
			 case 6:pen = gcnew Pen(c.ForestGreen);
					 break;
			 case 7:pen = gcnew Pen(c.Yellow);
					 break;
			 case 8:pen = gcnew Pen(c.Orange);
					 break;
			 case 9:pen = gcnew Pen(c.OrangeRed);
					 break;
			 case 10:pen = gcnew Pen(c.White);
					 break;
			 case 11:pen = gcnew Pen(c.LightGray);
					 break;
			 case 12:pen = gcnew Pen(c.Silver);
					 break;
			 case 13:pen = gcnew Pen(c.DarkGray);
					 break;
			 case 14:pen = gcnew Pen(c.Gray);
					 break;
			 case 15:pen = gcnew Pen(c.DimGray);
					 break;
			 case 16:pen = gcnew Pen(c.SlateGray);
					 break;
			 case 17:pen = gcnew Pen(c.DarkSlateGray);
					 break;
			 case 18:pen = gcnew Pen(c.DarkCyan);
					 break;
			 case 19:pen = gcnew Pen(c.Black);
					 break;
			 default:pen = gcnew Pen(c.White);
			 };
			 /*if(color == 1)
			 {pen = gcnew Pen(c.Black);}
			 else if(color == 2)
			 {pen = gcnew Pen(c.Violet);}
			 else if(color == 3)
			 {pen = gcnew Pen(c.Blue);}
			 else if(color == 4)
			 {pen = gcnew Pen(c.Green);}
			 else if(color == 5)
			 {pen = gcnew Pen(c.Orange);}
			 else if(color == 6)
			 {pen = gcnew Pen(c.Red);}
			 else
			 {pen = gcnew Pen(c.White);}*/
			return pen;	
		}
		 
		 
		 
		 
		 /*void DrawE(System::Windows::Forms::MouseEventArgs^  e)
			 {}*/
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
		 {/*Pen ^pen;
		 int _y = 0;
		 
		 //Pen _pen;
		 //this->Visible = false;
		 for(_w;_w < pictureBox1->Width;_w = _w + 3)
		 {
			 for(int i = 0;i < pictureBox1->Height;i = i + 3)
			 {Point3D ^p = gcnew Point3D(_w,i,0);
			 Vector t = pole->GetE(p);
			 pen = GetPenE(t);

			 //float _w = _w;
			 //float _i = i;
			 g->DrawRectangle(pen,_w,i,1,1);
			 g->DrawRectangle(pen,_w,i,2,2);
			 //this->Text = Convert::ToString(t.Length);
			 g->DrawRectangle(pen,_w,i,3,3);
			 //g->DrawRectangle(pen,_w,i,4,4);			 
			 }
		 }
		_w = 0;	
		pictureBox1->Visible = true;*/
		//this->Visible = true;
			 _w = x_start = 0;
			 y_start = 0;
			 x_end = 0;
			 y_end = pictureBox1->Height;
			 _tag_potencial = 0;
			 timer1->Enabled = true;
			 if(checkBoxEProportional->Checked)
			 {draw_e_proport_percent = true;}
			 else
			 {draw_e_proport_percent = false;
			 textBoxEProportional->Visible = false;}
			 labelStatus->Text = "Tension of electrical field";
			 //DrawEPoleSourse();
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
		 {//image = gcnew Bitmap(pictureBox1->Width,pictureBox1->Height);
		 
		 //image->Save("D:\My_picture.bmp");
		 }
private: System::Void Form1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
		 {Pen ^pen;
		 int _x = _w + 100;
		 int _y;
		 EPoleSoursePoint ^pole_s = gcnew EPoleSoursePoint();
		 pole_s->Charge = 1;
			 
		if(_tag_potencial == 0)
		 {
		 
		 //Pen _pen;
		 //this->Visible = false;
		 for(_w;_w < _x;_w = _w + 1)
		 {
			 _y = 0;
			 for(int i = y_start;i < y_end;i = i + 1)
			 {
			 Point3D ^p = gcnew Point3D(_w,i,0);
			 Vector t = pole->GetE(p);
			 ColorOld = ColorNew;
			 if(checkBoxEProportional->Checked)
			 {
			 DrawE();
			 ColorNew = GetColorE2(t);
			 }
			 else
			 {
			 ColorNew = GetColorE(t);
			 }
			 if(ColorNew != ColorOld)
			 {
				 pen = GetPenE(ColorOld);
				 g->DrawLine(pen,_w,_y,_w,_y + i);
				 _y = i;
			 }
			 else if(i == pictureBox1->Height - 1)
			 {
			 pen = GetPenE(ColorOld);
			 g->DrawLine(pen,_w,_y,_w,_y + i);
			 }

			 //float _w = _w;
			 //float _i = i;
			 //g->DrawRectangle(pen,_w,i,1,1);
			 //g->DrawRectangle(pen,_w,i,2,2);
			 //this->Text = Convert::ToString(t.Length);
			 //g->DrawRectangle(pen,_w,i,3,3);
			 //g->DrawRectangle(pen,_w,i,4,4);			 
			 }
			}
		 }
		 else
		 {
		 for(_w;_w < _x;_w = _w + 1)
		 {
			 _y = 0;
			 for(int i = y_start;i < y_end;i = i + 1)
			 {
				 pole_s->X = _w;
				 pole_s->Y = i;
			 ColorOld = ColorNew;
			 if(draw_w_proport_percent)
			 {
			 DrawW();
			 ColorNew = GetColorW2(pole->GetEnergy(pole_s));
			 }
			 else
			 {
			 ColorNew = GetColorW(pole->GetEnergy(pole_s));
			 }
			 //ColorNew = GetColorW(pole->GetEnergy(pole_s));
			 if(ColorNew != ColorOld)
			 {
				 pen = GetPenE(ColorOld);
				 g->DrawLine(pen,_w,_y,_w,_y + i);
				 _y = i;
			 }
			 else if(i == pictureBox1->Height - 1)
			 {
			 pen = GetPenE(ColorOld);
			 g->DrawLine(pen,_w,_y,_w,_y + i);
			 }

			 //float _w = _w;
			 //float _i = i;
			 //g->DrawRectangle(pen,_w,i,1,1);
			 //g->DrawRectangle(pen,_w,i,2,2);
			 //this->Text = Convert::ToString(t.Length);
			 //g->DrawRectangle(pen,_w,i,3,3);
			 //g->DrawRectangle(pen,_w,i,4,4);			 
			 }

			 
		 }
		 }
		 //timer1->Enabled = false;
		 if(_x >=  pictureBox1->Width)
		 {
			 timer1->Enabled = false;
			 _w = 0;
		 }
		 if(!sourse_drag)
		 {
			DrawEPoleSourse(1);
		 };
		 if(checkBoxEProportional->Checked)
		 {
			 labelMax->Text = (_tag_potencial)?"Potencial:" +  Convert::ToString(WMax):"E:" +  Convert::ToString(EMax);
		 labelMax->Text += " = 100%";
		 labelMax->Visible = true;
		 }
		 else{labelMax->Visible = false;};
		 /*if(!_tag)
			{timer1->Interval = 50;}*/
		 }

		 System::Void timer1_Tick2(System::Object^  sender, System::EventArgs^  e) 
		 {
		 
		 
		 
		 }
		 int GetColorE2(Vector t)
		 {
			 int res = -1;
			 double len = t.Length;

			 if(len > EMax*0.9)
				{res = 1;}
			 else if(len > EMax*0.75)
				{res = 2;}
			 else if(len > EMax*0.6)
				{res = 3;}
			 else if(len > EMax*0.4)
				{res = 4;}
			 else if(len > EMax*0.2)
				{res = 5;}
			 else if(len > EMax*0.1)
				{res = 6;}
			 else if(len > EMax*0.05)
				{res = 7;}
			 else if(len > EMax*0.025)
				{res = 8;}
			 else if(len > EMax*0.01)
				{res = 9;}
			 else if(len >= 0)
				{res = 10;}
			return res;
		 }
		 int GetColorW2(double energy)
		 {
			 int res = -1;
			 
			 if(energy > WMax*0.9)
				{res = 1;}
			 else if(energy > WMax*0.75)
				{res = 2;}
			 else if(energy > WMax*0.6)
				{res = 3;}
			 else if(energy > WMax*0.4)
				{res = 4;}
			 else if(energy > WMax*0.2)
				{res = 5;}
			 else if(energy > WMax*0.1)
				{res = 6;}
			 else if(energy > WMax*0.05)
				{res = 7;}
			 else if(energy > WMax*0.025)
				{res = 8;}
			 else if(energy > WMax*0.01)
				{res = 9;}
			 else if(energy >= 0)
				{res = 10;}
			 else if(energy > -WMax*0.01)
				{res = 11;}
			 else if(energy > -WMax*0.025)
				{res = 12;}
			 else if(energy > -WMax*0.05)
				{res = 13;}
			 else if(energy > -WMax*0.1)
				{res = 14;}
			 else if(energy > -WMax*0.2)
				{res = 15;}
			 else if(energy > -WMax*0.4)
				{res = 16;}
			 else if(energy > -WMax*0.6)
				{res = 17;}
			 else if(energy > -WMax*0.75)
				{res = 18;}
			 /*else if(energy > -WMax*0.9)
				{res = 19;}*/
			 else{res = 19;};
			return res;
		 }


		 int GetColorW(double energy)
		 {
		 int res = 20;
		 if(energy > 20000000)
			{res = 1;}
		 else if(energy > 10000000)
		 {res = 2;}
		 else if(energy > 5000000)
		 {res = 3;}
		 else if(energy >2500000)
		 {res = 4;}
		 else if(energy > 1500000)
		 {res = 5;}
		 else if(energy > 1000000)
		 {res = 6;}
		 else if(energy > 700000)
		 {res = 7;}
		 else if(energy > 500000)
		 {res = 8;}
		 else if(energy > 4000)
		 {res = 9;}
		 else if((energy <= 4000)&&(energy >= -4000))
		 {res = 1;}
		 /*else if(energy < -4000)
		 {res = 10;}*/
		 else if(energy > -500000)
		 {res = 11;}
		 else if(energy > -700000)
		 {res = 12;}
		 else if(energy > -1000000)
		 {res = 13;}
		 else if(energy > -1500000)
		 {res = 14;}
		 else if(energy > -2500000)
		 {res = 15;}
		 else if(energy > -5000000)
		 {res = 16;}
		 else if(energy > -10000000)
		 {res = 17;}
		 else if(energy > -25000000)
		 {res = 18;}
		 else if(energy <= -25000000)
		 {res = 19;}
		 return res;
		 }

		 void DrawE()
		 {EPoleSourse ^p;
		 try{
			 p = pole->l[0];
			}
		 catch(...)
		 {return;}
		 for(int i = 0;i < pole->l->Count;i++)
		 {
			 if(abs(pole->l[i]->Charge) > abs(p->Charge))
			 {p = pole->l[i];};
		 }
		 Point3D ^point = gcnew Point3D(p->X+2*coef_m,p->Y+2*coef_m,p->Z+2*coef_m);
		 double Max;
		 p->GetE(point,Max);
		 EMax = abs(Max);
		 }

		 void DrawW()
		 {EPoleSourse ^p;
		 try{
			 p = pole->l[0];
			}
		 catch(...)
			{return;}
		 for(int i = 0;i < pole->l->Count;i++)
		 {
			 if(abs(pole->l[i]->Charge) > abs(p->Charge))
			 {p = pole->l[i];};
		 }
		 EPoleSoursePoint ^point = gcnew  EPoleSoursePoint(p->X+2*coef_m,p->Y+2*coef_m,p->Z+2*coef_m,1);
		 double Max;
		 Max = p->GetEnergy(point);
		 if(Max >= 0)
		 {
			WMax = Max;
		}
		 else
		 {WMax = -Max;}
		 
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //MessageBox::Show(Convert::ToString(pole->l->Count),"JJJ");
			 /*Color c;
			 Pen ^pen = gcnew Pen(c.Black,6);
			 g->DrawEllipse(pen,100,100,110,110);*/
		 }
private: System::Void comboBox1_DropDownClosed(System::Object^  sender, System::EventArgs^  e) 
		 {
			RefreshComboBox(); 
		 }
		 void RefreshComboBox()
		 {if(comboBox1->Items->Count > 0)
		 {
			 textBoxX->Text = Convert::ToString(pole->l[comboBox1->SelectedIndex]->X);
			 textBoxY->Text = Convert::ToString(pole->l[comboBox1->SelectedIndex]->Y);
			 textBoxZ->Text = Convert::ToString(pole->l[comboBox1->SelectedIndex]->Z);
			 textBoxCharge->Text = Convert::ToString(pole->l[comboBox1->SelectedIndex]->Charge);
			 textBoxLenSection->Text = Convert::ToString(Section.Length);
			 if(checkBoxAutoRedraw->Checked)
			 {
				 RefreshImage();
			 }
		 };
		 };
		 void RefreshImage()
		 {
		 _w = 0;
		 timer1->Enabled = true;
		 }
private: System::Void textBoxX_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 try
			 {
				 pole->l[comboBox1->SelectedIndex]->X = Convert::ToDouble(textBoxX->Text);
				 if(checkBoxAutoRedraw->Checked)
				 {
					RefreshImage();
				 }
			 }
			 catch(FormatException ^e)
			 {}

		 }
private: System::Void textBoxY_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 try
			 {
				 pole->l[comboBox1->SelectedIndex]->Y = Convert::ToDouble(textBoxY->Text);
				 if(checkBoxAutoRedraw->Checked)
				 {
					RefreshImage();
				 }
			 }
			 catch(FormatException ^e)
			 {}
		 }
private: System::Void textBoxZ_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 try
			 {
				 pole->l[comboBox1->SelectedIndex]->Z = Convert::ToDouble(textBoxZ->Text);
				 if(checkBoxAutoRedraw->Checked)
				 {
					RefreshImage();
				 }
			 }
			 catch(FormatException ^e)
			 {}
		 }
private: System::Void textBoxCharge_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 try
			 {
				 pole->l[comboBox1->SelectedIndex]->Charge = Convert::ToDouble(textBoxCharge->Text);
				 if(checkBoxAutoRedraw->Checked)
				 {
					RefreshImage();
				 }
			 }
			 catch(FormatException ^e)
			 {}
		 }
private: System::Void textBoxE_d_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 try
			 {
				 e_dielectrical = Convert::ToDouble(textBoxE_d->Text);
				 if(checkBoxAutoRedraw->Checked)
				 {
					RefreshImage();
				 }
			 }
			 catch(FormatException ^e)
			 {}
		 }
private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 //EPoleSourse ^p;
			 sourse_drag = false;
			 int i;
			 for(i = 0;i < pole->l->Count;i++)
			 {
				 if(pole->l[i]->IsPointMouse(e->X,e->Y))
				 {
					 index_current = i;
					 sourse_drag = true;
					 break;
				 };
			 }
			 if(sourse_drag)
			 {
				 comboBox1->SelectedIndex = i;
				 RefreshComboBox();
				 return;
			 }

			
			 draw_line_mouse = true;
			 x_mouse = e->X;
			 y_mouse = e->Y;
		 }
private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 draw_line_mouse = false;
			 //timer1->Enabled = false;
			 Section.x_begin = x_mouse;
			 Section.y_begin = y_mouse;
			 Section.x_end = e->X;
			 Section.y_end = e->Y;
			 Section.Length = sqrt((x_mouse - Section.x_end)*(x_mouse - Section.x_end)+(y_mouse - Section.y_end)*(y_mouse - Section.y_end) + 1.00 - 1.00);
			 RefreshComboBox();
			 sourse_drag = false;
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {_tag_potencial = 1;
		 _w = 0;
		 y_end = pictureBox1->Height;
		 if(checkBoxEProportional->Checked)
		 {draw_w_proport_percent = true;}
		 else
		 {draw_w_proport_percent = false;
		 DrawW();}
		 timer1->Enabled = true;
		 labelStatus->Text = "Potencial of elecrical field";
		 }

		 void DrawProportionalW()
		 {
		 EPoleSourse ^p;
		 try{
			 p = pole->l[0];
			}
		 catch(...)
		 {return;}
		 for(int i = 0;i < pole->l->Count;i++)
		 {
			 if(abs(pole->l[i]->Charge) > abs(p->Charge))
			 {p = pole->l[i];};
		 }
		 EPoleSoursePoint ^point = gcnew EPoleSoursePoint(p->X+2*coef_m,p->Y+2*coef_m,p->Z+2*coef_m,1);
		 double Max;
		 p->GetEnergy(point);
		 WMax = Max; 
		 }
private: /*System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 MessageBox ^b = gcnew MessageBox;
			 b->Show(Convert::ToString(pole->l->Count)+"   ","HHHHH");
		 }*/
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
		 {
		 }
private: System::Void buttonRemove_Click(System::Object^  sender, System::EventArgs^  e) 
		 {try
		 {
			 pole->l->RemoveAt(comboBox1->SelectedIndex);
			 MessageBox::Show(Convert::ToString(pole->l->Count),"LLLLLLL");
			 LoadTextBox();
			 RefreshComboBox();
			 _w = 0;
			 timer1->Enabled = true;
		 }
		 catch(...)
		 {}
		 }
private: System::Void checkBoxEProportional_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(!checkBoxEProportional->Checked)
			 {
				 textBoxEProportional->Visible = false;
			 }
			 if(checkBoxAutoRedraw->Checked)
			 {
				 RefreshImage();
			 }
		 }
private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
		 {/*if(_tag)
		 {
		 _w = 0;
		 timer1->Enabled = true;
		 _tag = 0;
		 };*/
		 }
};
}

