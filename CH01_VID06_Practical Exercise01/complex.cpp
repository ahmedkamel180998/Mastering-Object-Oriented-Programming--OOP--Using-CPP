#include "complex.h"

void complex::setReal(float r)
{
	real = r;
}

void complex::setImaginary(float i)
{
	imaginary = i;
}

float complex::getReal()
{
	return real;
}

float complex::getImaginary()
{
	return imaginary;
}

void complex::PrintComplex()
{
	if (imaginary >= 0)
		std::cout << real << " + " << imaginary << "i" << std::endl;
	else
		std::cout << real << " - " << -imaginary << "i" << std::endl;
}

complex complex::add(complex c)
{
	complex result;
	result.real = real + c.getReal();
	result.imaginary = imaginary + c.getImaginary();
	return result;
}

complex complex::subtract(complex c)
{
	complex result;
	result.real = real - c.getReal();
	result.imaginary = imaginary - c.getImaginary();
	return result;
}