#pragma once
#include <iostream>

class Complex
{
private:
	double real, imaginary;
public:
	Complex();
	Complex(double r, double i);

	void setReal(const double r);
	void setImaginary(const double r);
	const double getReal() const;
	const double getImaginary() const;
	void print() const; // a + bi, a - bi

	Complex& operator=(const Complex& number);
	Complex operator+(const Complex number);
	Complex operator-(const Complex number);
	Complex operator*(const Complex number);
	Complex operator/(const Complex number);
	bool operator>(const Complex number) const;
	bool operator<(const Complex number) const;
	bool operator>=(const Complex number) const;
	bool operator<=(const Complex number) const;
	bool operator==(const Complex number) const;
	bool operator!=(const Complex number) const;
	Complex& operator+=(const Complex& number);
	Complex& operator-=(const Complex& number);
	Complex& operator*=(const Complex& number);
	Complex& operator/=(const Complex& number);
};