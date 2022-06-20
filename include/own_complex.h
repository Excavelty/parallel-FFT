#ifndef COMPLEX_H
#define COMPLEX_H

#define MASTER_PROC 0
#define BLOCK_SIZE 32

typedef struct {
    double re;
    double im;
} Complex;

Complex sum_complex(Complex first, Complex second)
{
    Complex complex = {.re = first.re + second.re, .im = first.im + second.im};

    return complex;
}

Complex subtract_complex(Complex first, Complex second)
{
    Complex complex = {.re = first.re - second.re, .im = first.im - second.im};

    return complex;
}

Complex multiply_complex(Complex first, Complex second)
{
    Complex complex = {.re = first.re * second.re - first.im * second.im, .im = first.re * second.im + first.im * second.re};

    return complex; 
}

#endif