#pragma once


namespace FigureCenterTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace FigureCenter;

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
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected: 
	private: System::Windows::Forms::ComboBox^  comboBox1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private:Triangle ^t;
			Circle ^c;
			FigureCenter::Rectangle ^r;
			Pen ^tPen,^cPen,^rPen;
			Figure ^CurFg;
			Pen ^temp;
			bool FgMove;
	private: System::Windows::Forms::Label^  labelA;
	private: System::Windows::Forms::Label^  labelB;
	private: System::Windows::Forms::CheckBox^  checkBoxRedraw;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBoxPenColor;






			 int _tag;
			void SetTextBoxF(Figure ^fg)
			{
				textBoxX->Text = Convert::ToString(fg->X);
				textBoxY->Text = Convert::ToString(fg->Y);
			}
			void SetTextBoxT(Triangle ^tr)
			{
				SetTextBoxF(tr);
				textBoxA->Text = Convert::ToString(tr->Length);
				labelA->Text = "Length side:";
				labelB->Visible = false;
				textBoxB->Visible = false;
				pictureBoxPenColor->BackColor = tPen->Color;
			}
			void SetTextBoxC(Circle ^cr)
			{
				SetTextBoxF(cr);
				textBoxA->Text = Convert::ToString(cr->Radius);
				labelA->Text = "Radius";
				labelB->Visible = false;
				textBoxB->Visible = false;
				pictureBoxPenColor->BackColor = cPen->Color;
			}
			void SetTextBoxR(FigureCenter::Rectangle ^rec)
			{
				SetTextBoxF(rec);
				textBoxA->Text = Convert::ToString(rec->Width);
				labelA->Text = "Big side:";
				textBoxB->Text = Convert::ToString(rec->Height);
				labelB->Text = "Smaller side:";
				pictureBoxPenColor->BackColor = rPen->Color;
				labelB->Visible = true;
				textBoxB->Visible = true;
			}
			void SetFigureXY(Figure ^fg)
			{
				try
				{
				fg->MoveTo(Convert::ToInt32(textBoxX->Text),Convert::ToInt32(textBoxY->Text));
				}
				catch(FormatException^ e)
				{}
			}
			void DrawFg()
			{
				c->Draw(g,cPen);
				t->Draw(g,tPen);
				r->Draw(g,rPen);
			}
			void SetFigureSize()
			{
				if(_tag == 1)
				{//temp = gcnew Pen(this->BackColor);
				t->Draw(g,temp);
				t->Length = Convert::ToInt32(textBoxA->Text);
				DrawFg();
				}
				else if(_tag == 2)
				{
				c->Draw(g,temp);
				c->Radius = Convert::ToInt32(textBoxA->Text);
				DrawFg();
				}
				else if(_tag == 3)
				{
				r->Draw(g,temp);
				r->Width = Convert::ToInt32(textBoxA->Text);
				r->Height = Convert::ToInt32(textBoxB->Text);
				DrawFg();
				};
			
			}


	private: System::Windows::Forms::Label^  labelMouse;
	private: System::Windows::Forms::Label^  labelY;





	private: System::Windows::Forms::Label^  labelX;



	private: System::Windows::Forms::TextBox^  textBoxB;

	private: System::Windows::Forms::TextBox^  textBoxA;

	private: System::Windows::Forms::TextBox^  textBoxY;

	private: System::Windows::Forms::TextBox^  textBoxX;


			 Graphics ^g;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBoxPenColor = (gcnew System::Windows::Forms::PictureBox());
			this->checkBoxRedraw = (gcnew System::Windows::Forms::CheckBox());
			this->labelB = (gcnew System::Windows::Forms::Label());
			this->labelA = (gcnew System::Windows::Forms::Label());
			this->labelY = (gcnew System::Windows::Forms::Label());
			this->labelX = (gcnew System::Windows::Forms::Label());
			this->textBoxB = (gcnew System::Windows::Forms::TextBox());
			this->textBoxA = (gcnew System::Windows::Forms::TextBox());
			this->textBoxY = (gcnew System::Windows::Forms::TextBox());
			this->textBoxX = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->labelMouse = (gcnew System::Windows::Forms::Label());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxPenColor))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->pictureBoxPenColor);
			this->groupBox1->Controls->Add(this->checkBoxRedraw);
			this->groupBox1->Controls->Add(this->labelB);
			this->groupBox1->Controls->Add(this->labelA);
			this->groupBox1->Controls->Add(this->labelY);
			this->groupBox1->Controls->Add(this->labelX);
			this->groupBox1->Controls->Add(this->textBoxB);
			this->groupBox1->Controls->Add(this->textBoxA);
			this->groupBox1->Controls->Add(this->textBoxY);
			this->groupBox1->Controls->Add(this->textBoxX);
			this->groupBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->groupBox1->Location = System::Drawing::Point(506, 46);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 255);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 125);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Color pen:";
			// 
			// pictureBoxPenColor
			// 
			this->pictureBoxPenColor->Location = System::Drawing::Point(94, 125);
			this->pictureBoxPenColor->Name = L"pictureBoxPenColor";
			this->pictureBoxPenColor->Size = System::Drawing::Size(100, 21);
			this->pictureBoxPenColor->TabIndex = 9;
			this->pictureBoxPenColor->TabStop = false;
			this->pictureBoxPenColor->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			// 
			// checkBoxRedraw
			// 
			this->checkBoxRedraw->AutoSize = true;
			this->checkBoxRedraw->Location = System::Drawing::Point(9, 207);
			this->checkBoxRedraw->Name = L"checkBoxRedraw";
			this->checkBoxRedraw->Size = System::Drawing::Size(157, 17);
			this->checkBoxRedraw->TabIndex = 8;
			this->checkBoxRedraw->Text = L"Draw again without deleting";
			this->checkBoxRedraw->UseVisualStyleBackColor = true;
			// 
			// labelB
			// 
			this->labelB->AutoSize = true;
			this->labelB->Location = System::Drawing::Point(6, 102);
			this->labelB->Name = L"labelB";
			this->labelB->Size = System::Drawing::Size(0, 13);
			this->labelB->TabIndex = 7;
			// 
			// labelA
			// 
			this->labelA->AutoSize = true;
			this->labelA->Location = System::Drawing::Point(6, 75);
			this->labelA->Name = L"labelA";
			this->labelA->Size = System::Drawing::Size(0, 13);
			this->labelA->TabIndex = 6;
			// 
			// labelY
			// 
			this->labelY->AutoSize = true;
			this->labelY->Location = System::Drawing::Point(6, 45);
			this->labelY->Name = L"labelY";
			this->labelY->Size = System::Drawing::Size(26, 13);
			this->labelY->TabIndex = 5;
			this->labelY->Text = L"Y = ";
			// 
			// labelX
			// 
			this->labelX->AutoSize = true;
			this->labelX->Location = System::Drawing::Point(6, 19);
			this->labelX->Name = L"labelX";
			this->labelX->Size = System::Drawing::Size(26, 13);
			this->labelX->TabIndex = 4;
			this->labelX->Text = L"X = ";
			// 
			// textBoxB
			// 
			this->textBoxB->Location = System::Drawing::Point(94, 99);
			this->textBoxB->Name = L"textBoxB";
			this->textBoxB->Size = System::Drawing::Size(100, 20);
			this->textBoxB->TabIndex = 3;
			this->textBoxB->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxB->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBoxB_KeyDown);
			this->textBoxB->Leave += gcnew System::EventHandler(this, &Form1::textBoxB_Leave);
			// 
			// textBoxA
			// 
			this->textBoxA->Location = System::Drawing::Point(94, 72);
			this->textBoxA->Name = L"textBoxA";
			this->textBoxA->Size = System::Drawing::Size(100, 20);
			this->textBoxA->TabIndex = 2;
			this->textBoxA->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxA->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBoxA_KeyDown);
			this->textBoxA->Leave += gcnew System::EventHandler(this, &Form1::textBoxA_Leave);
			this->textBoxA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::textBoxA_MouseDown);
			// 
			// textBoxY
			// 
			this->textBoxY->Location = System::Drawing::Point(94, 45);
			this->textBoxY->Name = L"textBoxY";
			this->textBoxY->Size = System::Drawing::Size(100, 20);
			this->textBoxY->TabIndex = 1;
			this->textBoxY->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxY->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxY_TextChanged);
			this->textBoxY->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBoxY_KeyDown);
			this->textBoxY->Leave += gcnew System::EventHandler(this, &Form1::textBoxY_Leave);
			// 
			// textBoxX
			// 
			this->textBoxX->Location = System::Drawing::Point(94, 19);
			this->textBoxX->Name = L"textBoxX";
			this->textBoxX->Size = System::Drawing::Size(100, 20);
			this->textBoxX->TabIndex = 0;
			this->textBoxX->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxX->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxX_TextChanged);
			this->textBoxX->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBoxX_KeyDown);
			this->textBoxX->Leave += gcnew System::EventHandler(this, &Form1::textBoxX_Leave);
			this->textBoxX->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBoxX_KeyPress);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Triangle", L"Circle", L"Rectangle"});
			this->comboBox1->Location = System::Drawing::Point(506, 19);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(200, 21);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// labelMouse
			// 
			this->labelMouse->AutoSize = true;
			this->labelMouse->Location = System::Drawing::Point(49, 400);
			this->labelMouse->Name = L"labelMouse";
			this->labelMouse->Size = System::Drawing::Size(35, 13);
			this->labelMouse->TabIndex = 1;
			this->labelMouse->Text = L"label1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(718, 425);
			this->Controls->Add(this->labelMouse);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Form1";
			this->Text = L"Testing the system of  classes Figure";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->DoubleClick += gcnew System::EventHandler(this, &Form1::Form1_DoubleClick);
			this->Click += gcnew System::EventHandler(this, &Form1::Form1_Click);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseDown);
			this->Move += gcnew System::EventHandler(this, &Form1::Form1_Move);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxPenColor))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {t = gcnew Triangle(100,100,60);
			 c = gcnew Circle(50,50,50);
			 r = gcnew FigureCenter::Rectangle(200,200,100,100);
			 Color col;
			 tPen = gcnew Pen(col.Black);
			 cPen = gcnew Pen(col.Green);
			 rPen = gcnew Pen(col.Red);
			 temp = gcnew Pen(BackColor);
			 g = this->CreateGraphics();
			 FgMove = false;
			 comboBox1->SelectedIndex = 2;
			 //Graphics ^gg = CreateGraphics();
			 //Pen ^pp = gcnew Pen(col.Black);
			 //c->Draw(g,cPen);
			 //gg->DrawEllipse(pp,10,100,100,100);
			 }
	private: System::Void Form1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			 {
				 /*if(_tag <= 0)
				 {_tag = 1;};*/
				 if(t->IsPoint(e->X,e->Y))
				 {_tag = 1;
				 this->SetTextBoxT(t);
				 CurFg = t;
				 FgMove = true;
				 }
				 else if(c->IsPoint(e->X,e->Y))
				 {_tag = 2;
				 this->SetTextBoxC(c);
				 CurFg = c;
				 FgMove = true;
				 }
				 else if(r->IsPoint(e->X,e->Y))
				 {_tag = 3;
				 this->SetTextBoxR(r);
				 CurFg = r;
				 FgMove = true;
				 }
				 comboBox1->SelectedIndex = _tag-1;
				 //this->Text = Convert::ToString(comboBox1->Items[_tag-1]);
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
			 }
private: System::Void Form1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {DrawFg(); }
private: System::Void Form1_Move(System::Object^  sender, System::EventArgs^  e) 
		 {
		 }
private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
		 {DrawFg(); }
private: System::Void Form1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 this->labelMouse->Text = Convert::ToString(e->X) + ";" + Convert::ToString(e->Y); 
			 if(FgMove&&CurFg->IsPoint(e->X,e->Y))
			 {
				 if(!checkBoxRedraw->Checked)
					{CurFg->Draw(g,temp);};
				 CurFg->MoveTo(e->X,e->Y);
				 SetTextBoxF(CurFg);
				 DrawFg();			 
			 };


		 }
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 _tag = comboBox1->SelectedIndex+1;
			 switch(_tag)
			 {case 1:this->SetTextBoxT(t);
					 CurFg = t;	
					 break;
			 case 2:this->SetTextBoxC(c);
					CurFg = c;
					break;
			 case 3:this->SetTextBoxR(r);
					CurFg = t;
					break; 
			 
			 }; 
			 groupBox1->Text = Convert::ToString(comboBox1->Items[_tag-1]);
		 }
private: System::Void textBoxX_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //SetFigureXY(CurFg);
		 }
private: System::Void textBoxX_Leave(System::Object^  sender, System::EventArgs^  e) 
		 {
			 temp = gcnew Pen(this->BackColor);
			 CurFg->Draw(g,temp);
			 SetFigureXY(CurFg);
			 DrawFg();
		 }
private: System::Void textBoxY_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {//SetFigureXY(CurFg);
		 }
private: System::Void textBoxY_Leave(System::Object^  sender, System::EventArgs^  e) 
		 {
			 temp = gcnew Pen(this->BackColor);
			 CurFg->Draw(g,temp);
			 SetFigureXY(CurFg);
			 DrawFg();
		 }
private: System::Void textBoxX_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
		 {
		 }
private: System::Void textBoxX_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
		 {if(e->KeyCode == Keys::Enter)
			{
			//temp = gcnew Pen(this->BackColor);
			 CurFg->Draw(g,temp);
			 SetFigureXY(CurFg);
			 DrawFg();
			};
		 }
private: System::Void textBoxY_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
		 {
		if(e->KeyCode == Keys::Enter)
			{
			//temp = gcnew Pen(this->BackColor);
			 CurFg->Draw(g,temp);
			 SetFigureXY(CurFg);
			 DrawFg();
			};
		 }
private: System::Void textBoxA_Leave(System::Object^  sender, System::EventArgs^  e) 
		 {	
			
			 this->SetFigureSize();
			 
		 }
private: System::Void textBoxA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
		
		 }
private: System::Void textBoxA_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
		 {if(e->KeyCode == Keys::Enter)
			{
			//temp = gcnew Pen(this->BackColor);
			 //CurFg->Draw(g,temp);
			 this->SetFigureSize();
			 //DrawFg();
			};
		 }
private: System::Void textBoxB_Leave(System::Object^  sender, System::EventArgs^  e) 
		 {this->SetFigureSize(); }
private: System::Void textBoxB_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
		 {if(e->KeyCode == Keys::Enter)
			{
			 this->SetFigureSize();
			};
		 }
private: System::Void Form1_DoubleClick(System::Object^  sender, System::EventArgs^  e) 
		 {/*FgMove = !FgMove;*/}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {colorDialog1->ShowDialog();
		 pictureBoxPenColor->BackColor = colorDialog1->Color;
		 switch(_tag)
		 {case 1:tPen->Color = colorDialog1->Color;	
					 break;
			 case 2:cPen->Color = colorDialog1->Color;
					break;
			 case 3:rPen->Color = colorDialog1->Color;
					break; 
			 
			 }; 

		 }
private: /*System::Void pictureBox1_Click_1(System::Object^  sender, System::EventArgs^  e) 
		 {colorDialog1->ShowDialog();
		 pictureBoxBrushColor->BackColor = colorDialog1->Color;
		 
		 }*/
private: System::Void Form1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {FgMove = false;}
};
}

