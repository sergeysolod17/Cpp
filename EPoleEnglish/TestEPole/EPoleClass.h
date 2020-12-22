#ifndef EPOLE_CLASS_H
#define EPOLE_CLASS_H

#include "VectorPole.h"
#include "DrawEPole.h"
#include "stdafx.cpp"

using namespace System;
//using System::Collections::Generic::List;

class FisikConst
{
public:FisikConst(){};
	
	static double e;
	static double m_e;
	static double G;
	static double e_d;
	static double e_d_Pi_4;
	static double h;
	static double Pi;
};

double FisikConst::e(1.6E-19);
double FisikConst::G(6.67E-11);
double FisikConst::e_d(8.85E-12);
double FisikConst::h(6.626E-34);
double FisikConst::m_e(9.11E-31);
double FisikConst::Pi(3.1415);
double FisikConst::e_d_Pi_4(4*FisikConst::Pi*FisikConst::e_d);

double e_dielectrical = 1;
/*ref class Figure abstract
{
public:float X,Y,Z;
};*/
ref class EPoleSoursePoint;
ref class Pole
{
public:
};
ref class EPoleSourse;
ref class EPole
{public:EPole();

public:Vector GetE(Figure ^point);
	   double GetEnergy(EPoleSoursePoint ^point);
	   void Register(EPoleSourse ^sourse);
public:System::Collections::Generic::List<EPoleSourse ^> ^l;
};

ref class EPoleSourse:public Figure
{
public:virtual Vector GetE(const Figure ^point)=0;
	   virtual void GetE(const Figure ^point,Vector& res)=0;
	   virtual void GetE(const Figure ^point,double& res)=0;
	   double GetF(const EPoleSourse^ sourse);
	   virtual double GetEnergy(EPoleSoursePoint ^point)=0;
	   virtual bool IsPointMouse(int x,int y){return false;};
	   property double Charge
	   {
	   double get();
	   void set(double new_charge);
	   }
protected:double charge;
};
ref class EPoleSoursePoint:public EPoleSourse
{public:EPoleSoursePoint();
		EPoleSoursePoint(const float _x,const float _y,const float _z,const double _charge);
		virtual void Draw(System::Drawing::Graphics ^Canvas,Pen ^pen)override;
public:virtual Vector GetE(const Figure ^point)override;
		virtual void GetE(const Figure ^point,Vector& res)override;
		virtual void GetE(const Figure ^point,double& res)override;
		virtual double GetEnergy(EPoleSoursePoint ^point)override
			{
				//double res = point->Charge*this->GetE(point).Length*sqrt((X - point->X)*(X - point->X)+(Y - point->X)*(Y - point->X)+(Z - point->X)*(Z - point->X));
				double res = Charge*point->Charge/(sqrt((X - point->X)*(X - point->X)+(Y - point->Y)*(Y - point->Y)+(Z - point->Z)*(Z - point->Z))*FisikConst::e_d_Pi_4*e_dielectrical);
				/*if(this->Charge < 0)
					{res = -res;}*/
				return res;
			}
		virtual bool IsPointMouse(int x,int y)override;
public://float r_ellipse;
	
	/*ref struct DrawingMode
	   {
	   float r_ellipse;
	   };
	   static DrawingMode drawing_mode;*/
};
//Vector GetF(EPoleSourse ^sourse1,EPoleSourse ^sourse2);

//////////////////////////////////////

Vector EPole::GetE(Figure ^point)
{
	Vector res(0,0,0);
	for(int i = 0;i < l->Count;i++)
		{res = res + l[i]->GetE(point);};
	return res;
}
EPole::EPole()
{
l = gcnew System::Collections::Generic::List<EPoleSourse ^>();
}
void EPole::Register(EPoleSourse ^sourse)
{
	l->Add(sourse);
}

double EPoleSourse::Charge::get()
{return charge;}
double EPoleSourse::GetF(const EPoleSourse^ sourse)
{
	double res(this->charge*sourse->charge/(e_dielectrical*FisikConst::e_d_Pi_4*((X-sourse->X)*(X-sourse->X)+(Y-sourse->Y)*(Y-sourse->Y)+(Z-sourse->Z)*(Z-sourse->Z))));
	return res;
}
////////////////////////////////////////
EPoleSoursePoint::EPoleSoursePoint()
{
X = 0;
Y = 0;
Z = 0;
charge = 0;
}
EPoleSoursePoint::EPoleSoursePoint(const float _x,const float _y,const float _z,const double _charge)
{
	X = _x;
	Y = _y;
	Z = _z;
	charge = _charge;
}

void EPoleSourse::Charge::set(double new_charge)
{
	charge = new_charge;
}

Vector EPoleSoursePoint::GetE(const Figure ^point)
{
	Vector res;
	this->GetE(point,res);
	return res;
}

void EPoleSoursePoint::GetE(const Figure ^point,Vector& res)
{res =  Vector(this,point);
if(charge < 0)
{
	res.Reverse();
};
float len = abs(charge)/(FisikConst::e_d_Pi_4*e_dielectrical*(res.dX*res.dX + res.dY*res.dY + res.dZ*res.dZ));
res.Length = len;
//res.Length = charge/(FisikConst::e_d*FisikConst::Pi*(res.dX*res.dX + res.dY*res.dY + res.dZ*res.dZ));
}

void EPoleSoursePoint::GetE(const Figure ^point,double& res)
{
	res = charge/(e_dielectrical*FisikConst::e_d_Pi_4*((X-point->X)*(X-point->X)+(Y-point->Y)*(Y-point->Y)+(Z-point->Z)*(Z-point->Z)));
}
/*double EPoleSoursePoint::GetEnergy(EPoleSourse ^point)
{
	double res = point->Charge*this->GetE(point).Length;
	return res;
}*/
double EPole::GetEnergy(EPoleSoursePoint ^point)
{double res = 0;
	for(int i = 0;i < l->Count;i++)
	{res += l[i]->GetEnergy(point);};
	return res;
}


void EPoleSoursePoint::Draw(System::Drawing::Graphics ^Canvas,Pen ^pen)
{
	/*Canvas->DrawEllipse(pen,X-4,Y-4,16.00,15.00);
	Canvas->DrawEllipse(pen,X-4,Y-4,16.00,14.00);
	Canvas->DrawEllipse(pen,X-4,Y-4,16.00,16.00);*/
	Canvas->DrawEllipse(pen,X-9,Y-9,18.00,18.00);
	if(charge >= 0)
	{
	Canvas->DrawLine(pen,X,Y-6,X,Y+6);
	};
	Canvas->DrawLine(pen,X-6,Y,X+6,Y);
}
bool EPoleSoursePoint::IsPointMouse(int x,int y)
{
if((x >= X - 9)&&(y >= Y-9)&&(x <= X + 9)&&(y <= Y + 9))
{return true;}
else 
{return false;}
}

#endif