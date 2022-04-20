#include "Complex.h"
Complex::Complex( double a, double b )
{
	setComplex( a, b );
}
Complex::Complex( const Complex& z )
{
	*this = z;
}
void Complex::setComplex( double a, double b )
{
	setRe(a);
	setIm(b);
}

double Complex::absolute()
{
	return sqrt( sqr() );
}

const Complex conjugate( const Complex& z )
{
	Complex res( z.getRe(), -z.getIm() );
	return res;
}

const Complex operator + ( const Complex& z1, const Complex& z2 )
{
	Complex z3( z1 );
	return z3 += z2;
	//return z3;
}
const Complex operator - ( const Complex& z1, const Complex& z2 )
{
	Complex z3( z1 );
	z3 -= z2;
	return z3;
}
const Complex operator * ( const Complex& z1, const Complex& z2 )
{
	Complex z3( z1 );
	z3 *= z2;
	return z3;
}
const Complex operator / ( const Complex& z1, const Complex& z2 )
{
	Complex z3( z1 );
	z3 /= z2;
	return z3;
}
const Complex operator - ( const Complex& z )
{
	Complex res( z );
	res.setRe( -z.getRe() );
	res.setIm( -z.getIm() );
	return res;
}

Complex& Complex::operator += ( const Complex& z )
{
	/*m_Re += z.getRe();
	m_Im += z.getIm();*/
	this->setRe( this->getRe() + z.getRe() );
	this->setIm( this->getIm() + z.getIm() );
	return *this;
}
Complex& Complex::operator -= (const Complex& z)
{
	/*m_Re -= z.getRe();
	m_Im -= z.getIm();*/
	this->setRe( this->getRe() - z.getRe() );
	this->setIm( this->getIm() - z.getIm() );
	return *this;
}
Complex& Complex::operator /= ( const Complex& z )
{
	Complex temp(z);
	if( fabs( (double)temp ) < 1e-17 )
	{
		cerr << "Error - dividing by 0!" << endl;
		return *this;
	}
	//obie liczby razy sprzezenie drugiej i u³amek z tego
	double a = this->getRe();
	double b = this->getIm();
	/*m_Re=(a * z.getRe() + b * z.getIm()) / (z.getRe() * z.getRe() + z.getIm() * z.getIm());
	m_Im=(b * z.getRe() - a * z.getIm()) / (z.getRe() * z.getRe() + z.getIm() * z.getIm());*/
	this->setRe( (a * z.getRe() + b * z.getIm() ) / ( z.getRe() * z.getRe() + z.getIm() * z.getIm() ) );
	this->setIm( ( b * z.getRe() - a * z.getIm() ) / ( z.getRe() * z.getRe() + z.getIm() * z.getIm() ) );
	return *this;
}
Complex& Complex::operator *= ( const Complex& z )
{
	//z1=a+bi; z2=c+di; z1*z2=ac-bd+(ad+bc)i a=Re(z) c=m_Re b=Im(z) d=m_Im
	double temp = this->getRe();
	/*m_Re = m_Re * z.getRe() - m_Im * z.getIm();
	m_Im = m_Im * z.getRe() + temp * z.getIm();*/
	this->setRe( this->getRe() * z.getRe() - m_Im * z.getIm() );
	this->setIm( this->getIm() * z.getRe() + temp * z.getIm() );
	return *this;
}

istream& operator >> ( istream& in, Complex& z )
{
	double temp;
	in >> temp;
	z.setRe( temp );
	in >> temp;
	z.setIm( temp );
	return in;
}
double Complex::sqr()
{
	//return m_Re*m_Re+m_Im*m_Im;
	return this->getRe() * this->getRe() + this->getIm() * this->getIm();
}
Complex& Complex::operator = (const Complex& z)
{
	setComplex( z.getRe(), z.getIm() );
	return *this;
}

bool operator == ( const Complex& z1, const Complex& z2 )
{
	return !( z1 != z2 );
}
bool operator != ( const Complex& z1, const Complex& z2 )
{
	if( ( z1.getRe() != z2.getRe() ) || ( z1.getIm() != z2.getIm() ) ) return true;
	return false;
}
ostream& operator << ( ostream& out, const Complex& z )
{
	out << z.getRe() << " + " << z.getIm() << "i";
	return out;
}
CanonComplex::CanonComplex( const Complex& z ) : Complex(z)
{

}