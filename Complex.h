#pragma once
#include <iostream>
using namespace std;
class Complex
{
public:

	Complex( double a = 0, double b = 0 );
	Complex( const Complex& z );

	inline void setRe( double a );
	inline void setIm( double b );
	void setComplex( double a, double b );

	inline double getRe() const;
	inline double getIm() const;

	double absolute(); //modu³
	friend const Complex conjugate( const Complex& z );

	friend const Complex operator + ( const Complex& z1, const Complex& z2 );
	friend const Complex operator - ( const Complex& z1, const Complex& z2 );
	friend const Complex operator * ( const Complex& z1, const Complex& z2 );
	friend const Complex operator / ( const Complex& z1, const Complex& z2 );
	friend const Complex operator - ( const Complex& z );

	Complex& operator += ( const Complex& z );
	Complex& operator -= ( const Complex& z );
	Complex& operator /= ( const Complex& z );
	Complex& operator *= ( const Complex& z );

	Complex& operator = ( const Complex& z ); //?

	friend bool operator == ( const Complex& z1, const Complex& z2 );
	friend bool operator != ( const Complex& z1, const Complex& z2 );

	friend istream& operator >> ( istream& in, Complex& z );
	friend ostream& operator << ( ostream& out, const Complex& z );

	inline operator double();
	inline operator int();

private:
	double m_Re;
	double m_Im;
	double sqr();
};

class CanonComplex : public Complex
{
	CanonComplex( const Complex& z );
	friend ostream& operator << ( ostream& out, const Complex& z );
};

inline void Complex::setRe(double a)
{
	m_Re = a;
}
inline void Complex::setIm(double b)
{
	m_Im = b;
}
inline double Complex::getRe() const
{
	return m_Re;
}
inline double Complex::getIm() const
{
	return m_Im;
}
inline Complex::operator double()
{
	return this->getRe();
}
inline Complex::operator int()
{
	return int(this->getRe());
}