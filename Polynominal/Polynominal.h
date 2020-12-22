#include "stdio.h"
#include "math.h"
#include "ctype.h"
#include "string.h"

using namespace System;

struct PolynomItem
{
double a;
float power;
PolynomItem *next;
};

char* initial_name_var(void)
{
char* s = new char[2];
s[0] = 'x';
s[1] = '\0';
return s;
};

class Polynominal
{public:Polynominal();
		Polynominal(const Polynominal& copy_me);
		Polynominal& operator =(const Polynominal& copy_me);
		Polynominal(const char *str);
		Polynominal(System::String ^str);//инициализирует объект многочленом из строки str
		~Polynominal();//деструктор
public:void Add(double _a,float _power);//добавляет в многочлен член, коефициенты и степень которого заданы переменными _a и _power соответственно
	   System::String^ ToString()const;//возвращает строку содержащую многочлен
	   double operator ()(double _var);//возвращает значение многочлена при значении переменной заданым в аргументе функции
	   float GetMaxPower()const;//возвращает степень многочлена
	   double& operator [](float _power);//возвращает ссылку на переменную для хранения коэфициента в члене со степенью заданой в аргументе, если член отсувтвсвует он создается
	   friend Polynominal operator +(const Polynominal& polynom1,const Polynominal& polynom2);
	   friend Polynominal operator -(const Polynominal& polynom1,const Polynominal& polynom2);
	   friend Polynominal operator *(const Polynominal& polynom1,const Polynominal& polynom2);
	   friend Polynominal operator /(Polynominal divident,const Polynominal& divisor);
	   void operator +=(const Polynominal& add_me);
	   void operator -=(const Polynominal& add_me);
	   void operator *=(const Polynominal& add_me);
	   void InitialStr(const char *str);
	   void InitialStr(System::String ^str);
	   bool IsEmpty(void)const;

	   static char *name_var;
	   //Polynominal& operator =(const Polynominal& copy_me);
protected:PolynomItem *list;
		  void insert(PolynomItem *arg);
		  void delete_item(PolynomItem *ptr);
		  void initial_str(const char *s);

};

char* Polynominal::name_var = initial_name_var();


Polynominal::Polynominal()
{
list = NULL;
}
Polynominal::Polynominal(const char *str)
{
	InitialStr(str);
}
Polynominal::Polynominal(System::String ^str)
{
	InitialStr(str);
}

bool Polynominal::IsEmpty()const
{return (list == NULL);}

void Polynominal::Add(double _a,float _power=0)
{PolynomItem *link=list;
if(link != NULL)
	{
		bool is_insert = true;
		for(link;link != NULL;link = link->next)
		{
			if(link->power == _power)
				{
				is_insert = false;
				break;
				}
		};
		if(is_insert)
		{
			
			link = new PolynomItem;
			link->next = NULL;
			link->power = _power;
			link->a = _a;
			insert(link);
		}
		else
		{
			link->a += _a;
			if(link->a == 0)
				{delete_item(link);}
			return;
		}
	}
	else
	{
		list = new PolynomItem;
		link = list;
		link->power = _power;
		link->a = _a;
		link->next = NULL;
	}
	

}

void Polynominal::insert(PolynomItem *arg)
{
if(list == NULL)
{list = arg;
list->next = NULL;
return;}
else if(list->next == NULL)
{
	PolynomItem *temp = (list->power > arg->power)?arg:list;
	list = (list->power > arg->power)?list:arg;
	list->next = temp;
	return;
}
else
{
	PolynomItem *link = list; 
	for(link;link->next != NULL;link = link->next)
	{
		if(link->next->power < arg->power)
			{break;};
	};
	PolynomItem *temp = link->next;
	link->next = arg;
	arg->next = temp;
};
}
void Polynominal::delete_item(PolynomItem *ptr)
{
	if((list == NULL)||(ptr == NULL))
		{return;}
	else if(list == ptr)
		{
			list = list->next;
			delete ptr;
			ptr = list;
			return;
		}
	else
	{
		PolynomItem *link;
		for(link = list;list->next != NULL;link = link->next)
			{
				if(link->next == ptr)
					{break;}
			};
		if(link->next != NULL)
		{
			link->next = ptr->next;
			delete ptr;
		};
	
	};

}


////
Polynominal::~Polynominal()
{PolynomItem *temp;
for(list;list != NULL;)
	{
		temp = list;
		list = list->next;
		delete temp;
	};
}

Polynominal::Polynominal(const Polynominal& copy_me)
{
if(copy_me.list == NULL)
{
	list = NULL;
	return;
};
PolynomItem *link;
PolynomItem *linkc = copy_me.list;
list = new PolynomItem;
list->a = linkc->a;
list->power = linkc->power;
link = list;
linkc = linkc->next;
for(linkc;linkc != NULL;linkc = linkc->next)
	{
		link->next = new PolynomItem;
		link = link->next;
		link->a = linkc->a;
		link->power = linkc->power;
	};
link->next = NULL;
}

Polynominal& Polynominal::operator =(const Polynominal& copy_me)
{
if(this == &copy_me)
{
	return *this;
}
if(copy_me.list == NULL)
{
	list = NULL;
	return *this;
};
PolynomItem *link;
PolynomItem *linkc = copy_me.list;
list = new PolynomItem;
list->a = linkc->a;
list->power = linkc->power;
link = list;
linkc = linkc->next;
for(linkc;linkc != NULL;linkc = linkc->next)
	{
		link->next = new PolynomItem;
		link = link->next;
		link->a = linkc->a;
		link->power = linkc->power;
	};
link->next = NULL;
return *this;
}

Polynominal operator +(const Polynominal& polynom1,const Polynominal& polynom2)
{
	Polynominal res(polynom1);
	PolynomItem *link = polynom2.list;
	for(link;link != NULL;link = link->next)
		{res.Add(link->a,link->power);};
	return res;
}

Polynominal operator -(const Polynominal& polynom1,const Polynominal& polynom2)
{
	Polynominal res(polynom1);
	PolynomItem *link = polynom2.list;
	for(link;link != NULL;link = link->next)
		{res.Add((-link->a),link->power);};
	return res;
}

Polynominal operator *(const Polynominal& polynom1,const Polynominal& polynom2)
{
	Polynominal res;
	if((polynom1.list == NULL)||(polynom2.list == NULL))
		{return res;};
	//res = polynom1;
	for(PolynomItem *link2 = polynom2.list;link2 != NULL;link2 = link2->next)
		{
			for(PolynomItem *link = polynom1.list;link != NULL;link = link->next)
				{
					res.Add(link->a*link2->a,link->power+link2->power);
				};
		};
	return res;
}
Polynominal operator /(Polynominal divident,const Polynominal& divisor)
{
	if(divident.GetMaxPower() < divisor.GetMaxPower())
		{FormatException ^e = gcnew FormatException("Неможливо поділити \"" + divident.ToString() + "\" на \"" + divisor.ToString() + "\"");
		throw e;
		}
	Polynominal temp;
	Polynominal res;
	double _a;
	float _power;
	for(PolynomItem *link = divident.list;link != NULL;)
	{
		if(link->a != NULL)
		{
			_a = link->a/divisor.list->a;
			_power = link->power - divisor.list->power;
			if(_power < 0){break;};
			res.Add(_a,_power);
			temp = divisor;
			for(PolynomItem *link_t = temp.list;link_t != NULL;link_t = link_t->next)
				{
				link_t->a *= _a;
				link_t->power += _power;
				};
			divident -= temp;
			link = divident.list;
		};
	}
return res;
}

double Polynominal::operator ()(double _var)
{
double res = 0;
for(PolynomItem *link = list;link != NULL;link = link->next)
{
	res += link->a*pow(_var,static_cast<double>(link->power));
};
return res;
}
double& Polynominal::operator [](float _power)
{
	PolynomItem *link = list;
	for(link;link != NULL;link = link->next)
		{
			if(link->power == _power)
			{break;};
		};
	if((link == NULL)||((link == list)&&(link->power != _power)))
	{
		link = new PolynomItem;
		link->a = 0;
		link->power = _power;
		insert(link);
	}
	return link->a;
}


void Polynominal::operator +=(const Polynominal& add_me)
{
	for(PolynomItem *link = add_me.list;link != NULL;link = link->next)
		{
			Add(link->a,link->power);
		}
}
void Polynominal::operator -=(const Polynominal& add_me)
{
	for(PolynomItem *link = add_me.list;link != NULL;link = link->next)
		{
			Add(-link->a,link->power);
		}
}
void Polynominal::operator *=(const Polynominal& add_me)
{
	if((add_me.list == NULL)||(list == NULL))
		{return;};
	for(PolynomItem *link2 = add_me.list;link2 != NULL;link2 = link2->next)
		{
			for(PolynomItem *link = list;link != NULL;link = link->next)
				{
					Add(link->a*link2->a,link->power+link2->power);
				};
		};
}

void Polynominal::initial_str(const char *s)
{
/*	char *s = new char[strlen(str)+1];
	int index = 0;
	for(int i = 0;i < strlen(str);i++)
		{
			if(!isspace(str[i]))
			{
			s[index] = str[i];
			index++;
			};
		};
	s[index] = '\0';*/
	double _a,_power;
	const char *link = s;
	for(link;*link != '\0';)
		{//_power = 0;
		if(isdigit(*link)||(*link == '+')||(*link == '-'))
			{
			_a = atof(link);
			for(link;isdigit(*link)||(*link == '+')||(*link == '-');link++)
				{};
			if(*link == '*')
				{link++;};
			}
		else{_a = 1;};
		if(isalpha(*link)||(*link == '_'))
		{
			for(link;isalpha(*link)||(*link == '_');link++)
				{};
			_power = 1;
			if(*link == '^')
				{
				link++;
				_power = atof(link);
				for(link;isdigit(*link);link++)
					{};
				};
		
		}
		else
		{_power = 0;};
		this->Add(_a,_power);
		};
	delete [] s;
}
void Polynominal::InitialStr(System::String ^str)
{
char *s = new char[str->Length+1];
int index = 0;
for(int i = 0;i < str->Length;i++)
		{
			if(!isspace(str[i]))
			{
			s[index] = str[i];
			index++;
			};
		};
s[index] = '\0';
this->initial_str(s);

}
void Polynominal::InitialStr(const char *str)
{
char *s = new char[strlen(str)+1];
int index = 0;
for(int i = 0;i < strlen(str);i++)
		{
			if(!isspace(str[i]))
			{
			s[index] = str[i];
			index++;
			};
		};
s[index] = '\0';
this->initial_str(s);
}

System::String^ Polynominal::ToString()const
{
	System::String^ res = gcnew String("");
	PolynomItem *link=list;
	for(link;link != NULL;link = link->next)
		{
			if(link->a != 0)
			{
				if((link->a > 0)&&(res->Length > 0))
					{
						res = res + "+";
					}
				else
					{
					res = res + Convert::ToString(link->a);
					};
				if(link->power != 0)
				{res = res + "x";
				if(link->power != 1)
					{res = res + "^" + Convert::ToString(link->power);};
				}
				/*if(link->next != NULL)
					{
						res = res + "+";
					};*/
			};
		};

	return res;
}

float Polynominal::GetMaxPower()const
{float res = list->power;
for(PolynomItem *link = list;link != NULL;link = link->next)
	{
		if(link->power > res)
			{res = link->power;};
	};
return res;
}


/*Polynominal operator +(Polynominal& polynom1,Polynominal& polynom2)
{Polynominal res;
PolynomItem *link1 = polynom1.list;
PolynomItem *link2 = polynom2.list;
if(link1 == NULL)
{
	res = polynom2;
	
}
else if(link2 == NULL)
{
	res = polynom1;
};


return res;
}*/