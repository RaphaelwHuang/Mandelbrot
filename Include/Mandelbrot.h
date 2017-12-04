#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <iostream>
#include <complex>
#include <fstream>

using namespace std;

// The Window Size
typedef struct {
    long double xMin; // a min real value
    long double xMax; // a max real value
    long double yMin; // a min imaginary value
    long double yMax; // a max imaginary value
    int width; // the screen width
    int height; // the screen height
} window;

typedef struct
{
    long double real;  // real component
    long double imag;  // imaginary component
} complexNum;

// The multiply method
complexNum operator * (complexNum x, complexNum y){
    complexNum result;
    result.real = x.real * y.real - x.imag * y.imag;
    result.imag = x.imag * y.real + x.real * y.imag;
    return result;
}

// The add method
complexNum operator + (complexNum x, complexNum y){
    complexNum result;
    result.real = x.real + y.real;
    result.imag = x.imag + y.imag;
    return result;
}

#endif
