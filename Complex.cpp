#include "Complex.h"

// Constructors
Complex::Complex()
{
	_real = 0.0;
	_imag = 0.0;
}

Complex::Complex( double re, double im)
{
	_real = re;
	_imag = im;

}

Complex::Complex ( const Complex& z)
{
	_real = z._real;
	_imag = z._imag;
}

// access values

double Complex::imag() const
{
	return _imag;
}

double Complex:: real() const
{
	return _real;
}

// assignment
Complex& Complex::operator=(double r)
{
	_real = r; 
	_imag = 0;

	return *this;
}

Complex& Complex::operator=(const Complex& z) 
{
	_real = z.real();
	_imag = z.imag();

	return *this;	
}
Complex& Complex::operator+=(const Complex& z) 
{
	_real += z.real();
	_imag += z.imag();
	
	return *this;
}
Complex& Complex::operator-=(const Complex& z) 
{
	_real -= z.real();
	_imag -= z.imag();

	return *this;
}
Complex& Complex::operator*=(const Complex& z) 
{
	Complex rep;

	rep._real = (_real * z.real() - _imag * z.imag());
	rep._imag = (_real * z.imag() + _imag * z.real());
	
	*this = rep; 
	return *this;

}
Complex& Complex::operator/=(const Complex& z) 
{
	Complex rep;

	rep._real = ((_real * z.real()) + (_imag * z.imag())) / ( norm(z) );
        rep._imag = ((_imag * z.real()) - (_real * z.imag())) / ( norm(z) );

	*this = rep;
	return *this;

}

// basic math operations
Complex operator+(const Complex& a, const Complex& b)
{

	Complex res(a.real() + b.real(), a.imag() + b.imag());
	return res;
}

Complex operator-(const Complex& a, const Complex& b)
{

	return Complex(a.real() - b.real(), a.imag() - b.imag());

}

Complex operator*(const Complex& a, const Complex& b)
{
	
	return Complex ((a.real() * b.real()) - (a.imag() * b.imag()) , (a.imag() * b.real()) + (a.real() * b.imag()));

}

Complex operator/(const Complex& a, const Complex& b)
{
	
	return Complex ((a * conj(b) / norm(b)) , (a * conj(b) / norm(b)));

}

double operator/(const Complex& a, const double r )
{
	double z1,z2;

	z1 = a.real() / r;
	z2 = a.imag() / r;
	
	return z1 + z2;

}

double norm( const Complex& z)
{
	return ( ( z.real() * z.real()) + ( z.imag() * z.imag()) );
}

Complex conj(const Complex& z)
{

	return Complex ( z.real(), (-1) * z.imag() );

}

bool operator==(const Complex& a, const Complex& b)
{

	if( a.real() == b.real() && a.imag() == b.imag() )
		return true;
	return false;

}

bool operator==(const Complex& a, double r)
{
	if( a.real() == r && a.imag() == 0)
		return true;
	return false;
}

bool operator!=(const Complex& a, const Complex& b)
{
	if( a.real() != b.real() || a.imag() != b.imag() )
		return true;
	return false;
}

bool operator!=(const Complex& a, double r)
{

	if( a.real() != r || a.imag() != r )
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& out, const Complex& z)
{

	out << "("
	    << z.real()
	    << ")"
	    << (z.imag() > 0 ? "+" : "") 
            << "("
            << z.imag()
            << ")"
	    << std::endl;
	
	return out;
}
