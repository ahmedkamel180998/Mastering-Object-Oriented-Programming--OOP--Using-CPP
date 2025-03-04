#pragma once
#include <iostream>
using namespace std;

class complex
{
public:
	void setReal(float r);
	void setImaginary(float i);

	float getReal();
	float getImaginary();

	void PrintComplex();

	complex add(complex c);
	complex subtract(complex c);
private:
	float real;
	float imaginary;
};

