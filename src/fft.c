#include "fft.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static int rev(unsigned int num, size_t N);
static void bit_reversal_copy(shared Complex* result, shared Complex* input, size_t N);
static void fft_radix2_iter(shared Complex *in, shared Complex *out, size_t N);

/* ------------------------------------------------------------------------- */

// Implementacja z: https://www.geeksforgeeks.org/write-an-efficient-c-program-to-reverse-bits-of-a-number/: 
static int rev(unsigned int num, size_t N)
{
    int Nbits = (int)log2(N);

    int x_rev = 0;
    for (int i=0; i<Nbits; i++)
    {
        int curr_bit = (num >> i) & 1;
        x_rev += (curr_bit << (Nbits - 1 - i)); 
    }
        
    return x_rev;
}

static void bit_reversal_copy(shared Complex* result, shared Complex* input, size_t N)
{
    for(unsigned int k = 0; k < N; k++)
    {
        result[rev(k, N)] = input[k];
    }
}

// procedura licząca tranformatę Fouriera.
void fft_forward(shared Complex *data, shared Complex* out, size_t N)
{
    // dft_naive(data, out, N, mpi_data);
    fft_radix2_iter(data, out, N);

    for (int i=0; i<N; i++)
    {
        data[i] = out[i];
    }
}

static void fft_radix2_iter(shared Complex *in, shared Complex *out, size_t N)
{
    bit_reversal_copy(out, in, N);

    const int idx_per_proc = N / THREADS;

    int *recv_counts = malloc(sizeof(int) * THREADS);
    int *displacements = malloc(sizeof(int) * THREADS);
    for (int proc_rank=0; proc_rank< THREADS; proc_rank++)
    {
        recv_counts[proc_rank] = idx_per_proc;
        displacements[proc_rank] = idx_per_proc * proc_rank;
    }

    Complex *tmp = malloc(sizeof(Complex) * idx_per_proc);

    for(int s = 1; s <= log2(N); s++)
    {
        int m = 1 << s;
        Complex omega_m = {.re = cos(-2. * M_PI / m), .im = sin(-2. * M_PI / m)};

        if (s <= log2(N) - log2(MYTHREAD))
        {
            // Parallel
            for (int k=0; k < idx_per_proc; k++)
            {
                int global_k = k + MYTHREAD * idx_per_proc;
                tmp[k] = out[global_k];
            }
            for(int k = 0; k < idx_per_proc; k += m)
            {
                Complex omega = {.re = 1., .im = 0.};

                for(int j = 0; j < m/2; j++)
                {
                    Complex t = multiply_complex(omega, tmp[k + j + m / 2]);
                    Complex u = tmp[k + j];
                    tmp[k + j] = sum_complex(u, t);
                    tmp[k + j + m/2] = subtract_complex(u, t);
                    omega = multiply_complex(omega, omega_m);
                } 
            }
  //          MPI_Allgatherv(tmp, idx_per_proc, MPI_C_DOUBLE_COMPLEX, out, recv_counts, displacements, MPI_C_DOUBLE_COMPLEX, mpi_data.comm);
        }
        else //if (mpi_data.proc_rank == MPI_PROC_RANK_MASTER)
        {
            // Sequential
            for(int k = 0; k < N; k += m)
            {
                Complex omega = {.re = 1., .im = 0.};

                for(int j = 0; j < m/2; j++)
                {
                    Complex t = multiply_complex(omega, out[k + j + m / 2]);
                    Complex u = out[k + j];
                    out[k + j] = sum_complex(u, t);
                    out[k + j + m/2] = subtract_complex(u, t);
                    omega = multiply_complex(omega, omega_m);
                } 
            }
        }
    }

    free(tmp);
}

// procedura licząca tranformatę odwrtoną Fouriera.
void fft_backward(shared Complex *data, size_t N)
{

}

void fft_filter(double threshold, shared Complex *data, size_t N)
{

}