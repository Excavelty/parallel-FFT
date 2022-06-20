#include <stdio.h>
#include <stdlib.h>
#include "fft.h"
#include <own_complex.h>
#include "file_utils.h"
#include <upc.h>
#include <upc_collective.h>

shared Complex data[THREADS * BLOCK_SIZE];
shared Complex out[THREADS * BLOCK_SIZE];
shared size_t N[THREADS];

int main(int argc, char *argv[])
{
    // double complex *data;

    if (MYTHREAD == MASTER_PROC)
    {
        printf("[Info] Hello from master");
    }

    upc_barrier;

    /* Data readout from file */
    if (MYTHREAD == MASTER_PROC)
    {
        if (argc <= 1)
        {
            fprintf(stderr, "ERROR: The program requires an argument which is a path to data file.\n");
        }

        count_lines_in_file(argv[1], &N[MASTER_PROC]);
        for(int i = 0; i < THREADS; ++i)
        {
            N[i] = N[MASTER_PROC];
        }
        //printf("%d", N);
    }

    upc_barrier;

    if (MYTHREAD == MASTER_PROC)
    {
        read_data_lines(argv[1], N[MASTER_PROC], data);
    }

    upc_barrier;

    
    int i;
    upc_forall(int i = 0; i < N[MYTHREAD]; ++i; i)
    {
        printf("Watek %d: %lf\n", MYTHREAD, data[i].re);
    }

    fft_forward(data, out, N[MYTHREAD]);

    /*if (mpi_data.proc_rank == MPI_PROC_RANK_MASTER)
    {
        save_to_file("data/fft_data.csv", N, data);
    }

    #ifdef FFT_FLTER_THRESHOLD
        fft_filter(FFT_FLTER_THRESHOLD, data, N, mpi_data);
    #endif

    fft_backward(data, N, mpi_data);

    if (mpi_data.proc_rank == MPI_PROC_RANK_MASTER)
    {
        save_to_file("data/rev_fft_data.csv", N, data);
    } */
}