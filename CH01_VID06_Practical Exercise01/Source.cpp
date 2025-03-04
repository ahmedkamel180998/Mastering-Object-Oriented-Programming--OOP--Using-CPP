#include "complex.h"

int main() {
    complex myComplex1, myComplex2, resultComplex;

    // Set values for first complex number
    myComplex1.setReal(7);
    myComplex1.setImaginary(2);

    // Set values for second complex number
    myComplex2.setReal(5);
    myComplex2.setImaginary(3);

    // Add complex numbers
    resultComplex = myComplex1.add(myComplex2);
    // Print result
    resultComplex.PrintComplex();  // Output: 12 + 5i
    
    // subtract complex numbers
    resultComplex = myComplex1.subtract(myComplex2);
    // Print result
    resultComplex.PrintComplex();  // Output: 2 - 1i


    return 0;
}