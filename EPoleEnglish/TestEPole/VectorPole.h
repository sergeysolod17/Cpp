#ifndef VECTOR_POLE_H
#define VECTOR_POLE_H
#define ERROR_VECTOR_LENGTH_NEG "Ошибка:значение длины вектора не может быть отрицательным числом"

#include "math.h"
//#include "FigurePole.h"

using namespace System::Drawing;
using namespace System;

ref class Figure abstract
{public:virtual void Draw(System::Drawing::Graphics ^Canvas,Pen ^pen)abstract;
public:float X,Y,Z;
};
ref class Point3D:public Figure
{public:Point3D(float _x,float _y,float _z);
public:virtual void Draw(System::Drawing::Graphics ^Canvas,Pen ^pen)override;
//public:float X,Y,Z;
};



value class Vector
{
public:float dX,dY,dZ;
	   Vector(float _dX,float _dY,float _dZ);
	   Vector(Point& _begin,Point& _end);
	   Vector(const Figure ^_begin,const Figure ^_end);
	   Vector(const Figure ^_begin,const Point3D ^_end);
	   //float GetLength();
	   property float Length
			{
			float get();
			void set(float new_len);
			}
	   void Reverse(void);
	   Vector operator +(const Vector &arg);
	   Vector operator -(const Vector &arg);
	   Vector operator *(const double &arg);
	   virtual System::String^ ToString()override;
	   
};
bool IsColinear(Vector& v1,Vector& v2);


//////////////////////////////////////////////////
Point3D::Point3D(float _x,float _y,float _z)
{
	X = _x;
	Y = _y;
	Z = _z;
}
void Point3D::Draw(System::Drawing::Graphics ^Canvas,Pen ^pen)
{}
///////
Vector::Vector(float _dX,float _dY,float _dZ)
{
	dX = _dX;
	dY = _dY;
	dZ = _dZ;
}
Vector::Vector(Point& _begin,Point& _end)
	{
		dX = _begin.X - _end.X;
		dY = _begin.Y - _end.Y;
		dZ = 0;
	}
Vector::Vector(const Figure ^_begin,const Figure ^_end)
{
dX = _end->X - _begin->X;
dY = _end->Y - _begin->Y;
dZ = _end->Z - _begin->Z;
}
Vector::Vector(const Figure ^_begin,const Point3D ^_end)
{
dX = _end->X - _begin->X;
dY = _end->Y - _begin->Y;
dZ = _end->Z - _begin->Z;
}
float Vector::Length::get()
		{return sqrt(dX*dX + dY*dY + dZ*dZ);}
void Vector::Reverse(void)
	{dX = -dX;
	dY = -dY;
	dZ = -dZ;
	}
Vector Vector::operator +(const Vector &arg)
	{
	Vector res(this->dX + arg.dX,this->dY + arg.dY,this->dZ + arg.dZ);
	return res;
	}
Vector Vector::operator -(const Vector &arg)
		{
		Vector res(this->dX - arg.dX,this->dY - arg.dY,this->dZ - arg.dZ);
		return res;
		}
Vector Vector::operator *(const double &arg)
{Vector res(this->dX*arg,this->dY*arg,this->dZ*arg);
return res;
}
System::String^ Vector::ToString()
{
	String ^res = gcnew String("(" + dX + ";" + dY + ";" + dZ + ")");
	return res;
}
void Vector::Length::set(float new_len)
{if(new_len < 0)
	{
	Exception ^e = gcnew Exception(ERROR_VECTOR_LENGTH_NEG);
	throw e;
	return;
	};
float kx,ky,kz;
if(dX != 0)
{
kx = (dX > 0)?1:-1;
ky = dY/dX;
kz = dZ/dX;
dX = kx*new_len/sqrt(ky*ky + kz*kz + 1);
dY = ky*dX;
dZ = kz*dX;
}
else if(dY != 0)
{
ky = (dY > 0)?1:-1;
kx = dX/dY;
kz = dZ/dY;
dY = ky*new_len/sqrt(kx*kx + kz*kz + 1);
dX = kx*dY;
dZ = kz*dY;
}
else if(dZ != 0)
{
kz = (dZ > 0)?1:-1;
kx = dX/dZ;
ky = dY/dZ;
dZ = kz*new_len/sqrt(kx*kx + ky*ky + 1);
dX = kx*dZ;
dY = ky*dZ;
}


}

#endif