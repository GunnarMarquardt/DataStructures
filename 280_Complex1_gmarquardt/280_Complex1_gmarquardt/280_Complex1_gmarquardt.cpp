/*
280
Complex1
gmarquardt
*/

#include <iostream>
using namespace std;

class Complex
{
private:
	double realCoef, imaginaryCoef;
public:
	//constructors
	Complex();
	Complex(double, double);

	//getters/accessors
	double getReal();
	double getImaginary();

	//setters/mutators
	void set(double, double);
	void setReal(double);
	void setImaginary(double);

	//utility
	bool equal(const Complex);
	friend bool equal(const Complex, const Complex);
	friend bool operator == (const Complex, const Complex);
	void display();
	void load();
	friend ostream& operator << (ostream&, const Complex);
	friend istream& operator >> (istream&, Complex);

	//arithmetic
	void add(Complex);
	friend Complex add(const Complex, const Complex);
	friend Complex operator + (const Complex, const Complex);
	void sub(const Complex);
	friend Complex sub(const Complex, const Complex);
	friend Complex operator - (const Complex, const Complex);
	void mult(const Complex);
	friend Complex mult(const Complex, const Complex);
	friend Complex operator * (const Complex, const Complex);
};

Complex::Complex() 
{
	realCoef = imaginaryCoef = 0;
} //Complex

Complex::Complex(double r, double i) 
{
	realCoef = r;  imaginaryCoef = i;
} //Complex

//getters
double Complex::getReal()
{
	return realCoef;
} //getReal

double Complex::getImaginary()
{
	return imaginaryCoef;
} //getImaginary

//setters
void Complex::set(double r, double i) 
{
	realCoef = r;  imaginaryCoef = i;
} //set

void Complex::setReal(double r)
{
	realCoef = r;
} //setReal

void Complex::setImaginary(double i)
{
	imaginaryCoef = i;
} //setImaginary


//utility
bool Complex::equal(const Complex c)
{
	if (realCoef == c.realCoef && imaginaryCoef == c.imaginaryCoef)
	{
		return true;
	}
	return false;
} // equal

bool equal(const Complex c1, const Complex c2)
{
	if (c1.realCoef == c2.realCoef && c1.imaginaryCoef == c2.imaginaryCoef)
	{
		return true;
	}
	return false;
} // equal friend

bool operator == (const Complex c1, const Complex c2)
{
	return equal(c1, c2);
} // ==

void Complex::load() 
{
	cout << "Enter real coefficient and imaginary coefficient: ";
	cin >> realCoef >> imaginaryCoef;
} // load

void Complex::display()
{
	cout << realCoef;
	if (imaginaryCoef >= 0) cout << " + " << imaginaryCoef;
	else cout << " - " << -imaginaryCoef;
	cout << "i" << endl;
} //display


ostream& operator << (ostream& os, const Complex c)
{
	os << c.realCoef << " ";
	if (c.imaginaryCoef < 0)
	{
		os << "- " << -c.imaginaryCoef;
	}
	else
	{
		os << "+ " << c.imaginaryCoef;
	}
	os << "i";
	return os;
} //<<

istream& operator >> (istream& is, Complex c)
{
	is >> c.realCoef >> c.imaginaryCoef;
	return is;
} //>>

//math
void Complex::add(const Complex c) 
{
	realCoef += c.realCoef;
	imaginaryCoef += c.imaginaryCoef;
} //add

Complex add(const Complex c1, const Complex c2) 
{
	Complex t = Complex();
	t.realCoef = c1.realCoef + c2.realCoef;
	t.imaginaryCoef = c1.imaginaryCoef + c2.imaginaryCoef;
	return t;
} //add friend

Complex operator + (const Complex c1, const Complex c2)
{
	return add(c1, c2);
} //+

void Complex::sub(const Complex c)
{
	realCoef -= c.realCoef;
	imaginaryCoef -= c.imaginaryCoef;
} //sub

Complex sub(const Complex c1, const Complex c2)
{
	Complex t = Complex();
	t.realCoef = c1.realCoef - c2.realCoef;
	t.imaginaryCoef = c1.imaginaryCoef - c2.imaginaryCoef;
	return t;
} //sub friend

Complex operator - (const Complex c1, const Complex c2)
{
	return sub(c1, c2);
} //-

void Complex::mult(const Complex c)
{
	realCoef = realCoef * c.realCoef - imaginaryCoef * c.imaginaryCoef;
	imaginaryCoef = realCoef * c.imaginaryCoef + imaginaryCoef * c.realCoef;
} //mult

Complex mult(const Complex c1, const Complex c2)
{
	Complex t = Complex();
	t.realCoef = c1.realCoef * c2.realCoef - c1.imaginaryCoef * c2.imaginaryCoef;
	t.imaginaryCoef = c1.realCoef * c2.imaginaryCoef + c2.realCoef * c1.imaginaryCoef;
	return t;
} //mult friend

Complex operator * (const Complex c1, const Complex c2)
{
	return mult(c1, c2);
} // *

int main()
{
	Complex c1 = Complex();
	c1.display();
	c1 = Complex(1, 2);
	c1.display();
	c1.load();
	c1.display();
	cout << "enter components" << endl;
	Complex c2;
	cin >> c2;
	cout << c2 << endl;
	cout << "c1: " << c1.getReal() << " " << c1.getImaginary() << endl;
	c2.set(3, 4);
	c1.setReal(5);
	c1.setImaginary(6);
	cout << "c1: " << c1 << endl;
	cout << "c2: " << c2 << endl;
	cout << c1.equal(c2) << endl << equal(c1, c1) << endl << (c2 == c2) << endl;
	c1.add(c2);
	c1.sub(c2);
	cout << add(c1, c2) << endl << (c1 + c2) << endl;
	cout << sub(c1, c2) << endl << (c1 - c2) << endl;
	cout << mult(c1, c2) << endl << (c1 * c2) << endl;
	c1.mult(c2);
} //main

