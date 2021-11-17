#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <math.h>
#include <cassert>
using namespace std;
class Fraction
{
private:
	int numerator;
	int dernumerator;
	void nod()
	{
		int n = numerator;
		int d = dernumerator;
		while (n != 0 && d != 0)
		{
			if (n > d)
			{
				n %= d;
			}
			else
			{
				d %= n;
			}
		}
		numerator = numerator / (n + d);
		dernumerator = dernumerator / (n + d);
	}
public:

	Fraction(int numerator = 0, int dernumerator = 1)
	{
		this->numerator = numerator;
		if (dernumerator != 0)
		{
			this->dernumerator = dernumerator;
		}
		else
			this->dernumerator = 1;
		if (this->numerator > 0)
		{
			nod();
		}
	}
	void setdernumerator(int dernumerator)
	{
		if (dernumerator != 0)
		{
			this->dernumerator = dernumerator;
		}
		else
			this->dernumerator = 1;
		nod();
	}
	void setnumerator(int numerator)
	{
		this->numerator = numerator;
		nod();
	}
	int getnumerator() { return numerator; }
	int getdernumerator() { return dernumerator; }
	void print()
	{
		cout << numerator << "/" << dernumerator << endl;
	}

	template < class T1>
	static Fraction add(T1 value, const Fraction& fobj1)
	{
		double d = 0.1;
		int n = 0;
		if (fmod(value,1) == 0)
		{
			return Fraction(fobj1.numerator  + value * fobj1.dernumerator, fobj1.dernumerator);
		}
		else 
		{
			T1 foi = value;
			while (foi > 0)
			{
				foi = fmod(foi , d);
				d *= 0.1;
				n++;
			}
			switch (n)
			{
			case 1:
			{
				int h = fmod(value , 1)*10;
				int y = value / 1;
				y *= 10;
				h += y;
				return Fraction(fobj1.numerator*10 + h* fobj1.dernumerator, fobj1.dernumerator*10);
				break;
			}
			case 2:
			{
				int h = fmod(value, 1) * 100;
				int y = value / 1;
				y *= 100;
				h += y;
				return Fraction(fobj1.numerator * 100 + h * fobj1.dernumerator, fobj1.dernumerator * 100);
				break;
			}
			case 3:
			{
				int h = fmod(value, 1) * 1000;
				int y = value / 1;
				y *= 1000;
				h += y;
				return Fraction(fobj1.numerator * 1000 + h * fobj1.dernumerator, fobj1.dernumerator * 1000);
				break;
			}
			case 4:
			{
				int h = fmod(value, 1) * 10000;
				int y = value / 1;
				y *= 10000;
				h += y;
				return Fraction(fobj1.numerator * 10000 + h * fobj1.dernumerator, fobj1.dernumerator * 10000);
				break;
			}
			case 5:
			{
				int h = fmod(value, 1) * 100000;
				int y = value / 1;
				y *= 100000;
				h += y;
				return Fraction(fobj1.numerator * 100000 + h * fobj1.dernumerator, fobj1.dernumerator * 100000);
				break;
			}
			default:
			{
				int h = fmod(value, 1) * 100000;
				int y = value / 1;
				y *= 100000;
				h += y;
				return Fraction(fobj1.numerator * 100000 + h * fobj1.dernumerator, fobj1.dernumerator * 100000);
				break; 
			}
			}
		}
	}
	template < class T1>
	static Fraction sub(T1 value, const Fraction& fobj1)
	{
		double d = 0.1;
		int n = 0;
		if (fmod(value, 1) == 0)
		{
			return Fraction(value * fobj1.dernumerator-fobj1.numerator, fobj1.dernumerator);
		}
		else
		{
			T1 foi = value;
			while (foi > 0.000001)
			{
				foi = fmod(foi, d);
				d *= 0.1;
				n++;
			}
			switch (n)
			{
			case 1:
			{
				int h = fmod(value, 1) * 10;
				int y = value / 1;
				y *= 10;
				h += y;
				return Fraction(h * fobj1.dernumerator - fobj1.numerator * 10  , fobj1.dernumerator * 10);
				break;
			}
			case 2:
			{
				int h = fmod(value, 1) * 100;
				int y = value / 1;
				y *= 100;
				h += y;
				return Fraction(h * fobj1.dernumerator - fobj1.numerator * 100, fobj1.dernumerator * 100);
				break;
			}
			case 3:
			{
				int h = fmod(value, 1) * 1000;
				int y = value / 1;
				y *= 1000;
				h += y;
				return Fraction(h * fobj1.dernumerator - fobj1.numerator * 1000 , fobj1.dernumerator * 1000);
				break;
			}
			case 4:
			{
				int h = fmod(value, 1) * 10000;
				int y = value / 1;
				y *= 10000;
				h += y;
				return Fraction(h * fobj1.dernumerator - fobj1.numerator * 10000  , fobj1.dernumerator * 10000);
				break;
			}
			case 5:
			{
				int h = fmod(value, 1) * 100000;
				int y = value / 1;
				y *= 100000;
				h += y;
				return Fraction(h * fobj1.dernumerator - fobj1.numerator * 100000  , fobj1.dernumerator * 100000);
				break;
			}
			default:
			{
				int h = fmod(value, 1) * 100000;
				int y = value / 1;
				y *= 100000;
				h += y;
				return Fraction(h * fobj1.dernumerator - fobj1.numerator * 100000 , fobj1.dernumerator * 100000);
				break;
			}
			}
		}
	}
	template < class T1>
	static Fraction mult(T1 value, const Fraction& fobj1)
	{
		double d = 0.1;
		int n = 0;
		if (fmod(value, 1) == 0)
		{
			return Fraction(fobj1.numerator * value , fobj1.dernumerator);
		}
		else
		{
			T1 foi = fmod(value, 1);
			while (foi > 0.000001)
			{
				foi = fmod(foi, d);
				d *= 0.1;
				n++;
			}
			switch (n)
			{
			case 1:
			{
				int h = fmod(value, 1) * 10;
				int y = value / 1;
				y *= 10;
				h += y;
				return Fraction(fobj1.numerator *  h , fobj1.dernumerator * 10);
				break;
			}
			case 2:
			{
				int h = fmod(value, 1) * 100;
				int y = value / 1;
				y *= 100;
				h += y;
				return Fraction(fobj1.numerator *  h , fobj1.dernumerator * 100);
				break;
			}
			case 3:
			{
				int h = fmod(value, 1) * 1000;
				int y = value / 1;
				y *= 1000;
				h += y;
				return Fraction(fobj1.numerator * h, fobj1.dernumerator * 1000);
				break;
			}
			case 4:
			{
				int h = fmod(value, 1) * 10000;
				int y = value / 1;
				y *= 10000;
				h += y;
				return Fraction(fobj1.numerator * h, fobj1.dernumerator * 10000);
				break;
			}
			case 5:
			{
				int h = fmod(value, 1) * 100000;
				int y = value / 1;
				y *= 100000;
				h += y;
				return Fraction(fobj1.numerator * h, fobj1.dernumerator * 100000);
				break;
			}
			default:
			{
				int h = fmod(value, 1) * 100000;
				int y = value / 1;
				y *= 100000;
				h += y;
				return Fraction(fobj1.numerator * h, fobj1.dernumerator * 100000);
				break;
			}
			}
		}
	}
	template < class T1>
	static Fraction div(T1 value, const Fraction& fobj1)
	{
		double d = 0.1;
		int n = 0;
		if (fmod(value, 1) == 0)
		{
			return Fraction(fobj1.numerator , fobj1.dernumerator * value);
		}
		else
		{
			T1 foi = fmod(value, 1);
			while (foi > 0.000001)
			{
				foi = fmod(foi, d);
				d *= 0.1;
				n++;
			}
			switch (n)
			{
			case 1:
			{
				int h = fmod(value, 1) * 10;
				int y = value / 1;
				y *= 10;
				h += y;
				return Fraction(fobj1.numerator * 10, fobj1.dernumerator  * h);
				break;
			}
			case 2:
			{
				int h = fmod(value, 1) * 100;
				int y = value / 1;
				y *= 100;
				h += y;
				return Fraction(fobj1.numerator * 100, fobj1.dernumerator  * h);
				break;
			}
			case 3:
			{
				int h = fmod(value, 1) * 1000;
				int y = value / 1;
				y *= 1000;
				h += y;
				return Fraction(fobj1.numerator * 1000, fobj1.dernumerator  * h);
				break;
			}
			case 4:
			{
				int h = fmod(value, 1) * 10000;
				int y = value / 1;
				y *= 10000;
				h += y;
				return Fraction(fobj1.numerator * 10000, fobj1.dernumerator  * h);
				break;
			}
			case 5:
			{
				int h = fmod(value, 1) * 100000;
				int y = value / 1;
				y *= 100000;
				h += y;
				return Fraction(fobj1.numerator * 100000, fobj1.dernumerator  * h);
				break;
			}
			default:
			{
				int h = fmod(value, 1) * 100000;
				int y = value / 1;
				y *= 100000;
				h += y;
				return Fraction(fobj1.numerator * 100000, fobj1.dernumerator * h);
				break;
			}
			}
		}
	}
	template < class T1>
	static Fraction div( const Fraction&fobj1, T1 value )
	{
		double d = 0.1;
		int n = 0;
		if (fmod(value, 1) == 0)
		{
			return Fraction(fobj1.numerator, fobj1.dernumerator * value);
		}
		else
		{
			T1 foi = fmod(value, 1);
			while (foi > 0.000001)
			{
				foi = fmod(foi, d);
				d *= 0.1;
				n++;
			}
			switch (n)
			{
			case 1:
			{
				int h = fmod(value, 1) * 10;
				int y = value / 1;
				y *= 10;
				h += y;
				return Fraction(fobj1.numerator * 10, fobj1.dernumerator * h);
				break;
			}
			case 2:
			{
				int h = fmod(value, 1) * 100;
				int y = value / 1;
				y *= 100;
				h += y;
				return Fraction(fobj1.numerator * 100, fobj1.dernumerator * h);
				break;
			}
			case 3:
			{
				int h = fmod(value, 1) * 1000;
				int y = value / 1;
				y *= 1000;
				h += y;
				return Fraction(fobj1.numerator * 1000, fobj1.dernumerator * h);
				break;
			}
			case 4:
			{
				int h = fmod(value, 1) * 10000;
				int y = value / 1;
				y *= 10000;
				h += y;
				return Fraction(fobj1.numerator * 10000, fobj1.dernumerator * h);
				break;
			}
			case 5:
			{
				int h = fmod(value, 1) * 100000;
				int y = value / 1;
				y *= 100000;
				h += y;
				return Fraction(fobj1.numerator * 100000, fobj1.dernumerator * h);
				break;
			}
			default:
			{
				int h = fmod(value, 1) * 100000;
				int y = value / 1;
				y *= 100000;
				h += y;
				return Fraction(fobj1.numerator * 100000, fobj1.dernumerator * h);
				break;
			}
			}
		}
	}
	static Fraction dic(Fraction& fobj1)
	{
		fobj1.numerator = fobj1.numerator - fobj1.dernumerator;
		return fobj1;
	}
	static Fraction cre(Fraction& fobj1)
	{
		fobj1.numerator = fobj1.numerator + fobj1.dernumerator;
		return fobj1;
	}

	static Fraction pow1(Fraction& fobj1)
	{

		return Fraction(fobj1.numerator * fobj1.numerator, fobj1.dernumerator * fobj1.dernumerator);;
	}
	static Fraction sqrt(Fraction& fobj1)
	{

		return Fraction(fobj1.numerator % 2, fobj1.dernumerator / 2);
	}
	static bool isEqual1(const Fraction& fobj1, const Fraction& fobj2)
	{
		if ((fobj1.numerator * fobj2.dernumerator) == (fobj2.numerator * fobj1.dernumerator) && (fobj1.dernumerator * fobj2.dernumerator) == (fobj1.dernumerator * fobj2.dernumerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	static bool isEqual2(const Fraction& fobj1, const Fraction& fobj2)
	{
		if ((fobj1.numerator * fobj2.dernumerator) > (fobj2.numerator * fobj1.dernumerator) && (fobj1.dernumerator * fobj2.dernumerator) == (fobj1.dernumerator * fobj2.dernumerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	static bool isEqual3(const Fraction& fobj1, const Fraction& fobj2)
	{
		if ((fobj1.numerator * fobj2.dernumerator) < (fobj2.numerator * fobj1.dernumerator) && (fobj1.dernumerator * fobj2.dernumerator) == (fobj1.dernumerator * fobj2.dernumerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	static bool isEqual4(const Fraction& fobj1, const Fraction& fobj2)
	{
		if ((fobj1.numerator * fobj2.dernumerator) > (fobj2.numerator * fobj1.dernumerator) || (fobj1.numerator * fobj2.dernumerator) == (fobj2.numerator * fobj1.dernumerator) && (fobj1.dernumerator * fobj2.dernumerator) == (fobj1.dernumerator * fobj2.dernumerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	static bool isEqual5(const Fraction& fobj1, const Fraction& fobj2)
	{
		if ((fobj1.numerator * fobj2.dernumerator) < (fobj2.numerator * fobj1.dernumerator) || (fobj1.numerator * fobj2.dernumerator) == (fobj2.numerator * fobj1.dernumerator) && (fobj1.dernumerator * fobj2.dernumerator) == (fobj1.dernumerator * fobj2.dernumerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	template < typename T1>
	friend Fraction operator+(T1 point1, const Fraction& point2)
	{
		return add(point1, point2);
	}
	template < typename T1>
	friend Fraction operator-(T1 point1, const Fraction& point2)
	{
		return sub(point1, point2);
	}
	template < typename T1>
	friend Fraction operator*(T1 point1, const Fraction& point2)
	{
		return mult(point1, point2);
	}
	template < typename T1>
	friend Fraction operator/(T1 point1, const Fraction& point2)
	{
		return div(point1, point2);
	}
	template < typename T1>
	friend Fraction operator/( const Fraction& point2,T1 point1)
	{
		return div(point1, point2);
	}
	friend Fraction operator--(Fraction& point1)
	{
		return dic(point1);
	}
	friend Fraction operator++(Fraction& point1)
	{
		return cre(point1);
	}
	friend Fraction pow(Fraction& point1)
	{
		return pow1(point1);
	}
	friend Fraction sqrt(Fraction& point1)
	{
		return sqrt(point1);
	}
	friend ostream& operator<<(ostream& output, const Fraction& point)
	{
		output << "(" << point.numerator << "/" << point.dernumerator << ")";
		return output;
	}
	friend bool operator==(const Fraction& point1, const Fraction& point2)
	{
		return isEqual1(point1, point2);
	}
	friend bool operator>(const Fraction& point1, const Fraction& point2)
	{
		return isEqual2(point1, point2);
	}
	friend bool operator<(const Fraction& point1, const Fraction& point2)
	{
		return isEqual3(point1, point2);
	}
	friend bool operator>=(const Fraction& point1, const Fraction& point2)
	{
		return isEqual4(point1, point2);
	}
	friend bool operator<=(const Fraction& point1, const Fraction& point2)
	{
		return isEqual5(point1, point2);
	}

};
int main()
{
	srand(time(NULL));
	Fraction drob1(1, 2);
	Fraction drob2(1, 4);
	cout << 0.3333334 + drob1 ;
	cout << 1.75 * drob1;
	cout << 1.75 - drob1;
	cout << drob1 / 0.75;

	return 0;
}