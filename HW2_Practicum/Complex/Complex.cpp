#include "Complex.h"

Complex::Complex()
{
	real = 0;
	imaginary = 0;
}

Complex::Complex(double r, double i)
{
	real = r;
	imaginary = i;
}

void Complex::setReal(const double r)
{
	real = r;
}

void Complex::setImaginary(const double r)
{
	imaginary = r;
}

const double Complex::getReal() const
{
	return real;
}

const double Complex::getImaginary() const
{
	return imaginary;
}

void Complex::print() const // a + bi, a - bi
{
	std::cout << real;
	if (imaginary >= 0)
	{
		std::cout << "+";
	}
	
	std::cout << imaginary << "i" << std::endl;
}

Complex& Complex::operator=(const Complex& number)
{
	real = number.real;
	imaginary = number.imaginary;

	return *this;
}

Complex Complex::operator+(const Complex number)
{
	Complex result;
	result.real = real + number.real; 
	result.imaginary = imaginary + number.imaginary; 
	return result;
}

Complex Complex::operator-(const Complex number) 
{
	Complex result;
	result.real = real - number.real;
	result.imaginary = imaginary - number.imaginary;
	return result;
}

Complex Complex::operator*(const Complex number) // (a+bi)(c+di) = (ac - bd) + (bc + ad)
{
	Complex result;
	result.real = real * number.real - imaginary * number.imaginary; // a*c - b*d
	result.imaginary = real * number.imaginary + number.real * imaginary; // a*d + c*b
	return result;
}

Complex Complex::operator/(const Complex number)
{
	Complex result; // a * c			b * d		/ c*c + d*d
	result.real = (real * number.real + imaginary * number.imaginary) 
		/ (number.real * number.real + number.imaginary * number.imaginary); 
						// a * d				-		c * b
	result.imaginary = (real * number.imaginary - number.real * imaginary)
		/ (number.real * number.real + number.imaginary * number.imaginary);
	return result;
}

bool Complex::operator>(const Complex number) const
{
	if (real == number.real)
	{
		return imaginary > number.imaginary;
	}
	return real > number.real;
}

bool Complex::operator<(const Complex number) const
{
	if (real == number.real)
	{
		return imaginary < number.imaginary;
	}
	return real < number.real;
}

bool Complex::operator>=(const Complex number) const
{
	return real >= number.real;
}

bool Complex::operator<=(const Complex number) const
{
	return real <= number.real;
}

bool Complex::operator==(const Complex number) const
{
	return real == number.real && imaginary == number.imaginary;
}

bool Complex::operator!=(const Complex number) const
{
	return real != number.real && imaginary != number.imaginary;
}

Complex& Complex::operator+=(const Complex& number)
{
	real += number.real;
	imaginary += number.imaginary;
	return *this;
}

Complex& Complex::operator-=(const Complex& number)
{
	real -= number.real;
	imaginary -= number.imaginary;
	return *this;
}

Complex& Complex::operator*=(const Complex& number)
{
	double real2 = real * number.real - imaginary * number.imaginary; // a*c - b*d
	double imaginary2 = real * number.imaginary + number.real * imaginary; // a*d + c*b
	real = real2;
	imaginary = imaginary2;

	return *this;
}
Complex& Complex::operator/=(const Complex& number)
{
	double real2 = (real * number.real + imaginary * number.imaginary)
		/ (number.real * number.real + number.imaginary * number.imaginary);
	// a * d				-		c * b
	double imaginary2 = (real * number.imaginary - number.real * imaginary)
		/ (number.real * number.real + number.imaginary * number.imaginary);
	real = real2;
	imaginary = imaginary2;
	
	return *this;
}