// Includes
#include <upc.h>
#include <stdio.h>
#include <math.h>

// Defines
#define M_PI 3.1415
#define DTYPE double 
#define N (THREADS * 8)

// Global & shared variables
shared [2] DTYPE data[2*N];
shared [2] DTYPE data_cpy[2*N];

// Functions
void dft()
{
	upc_forall(int k=0; k<2*N; k++; k)
	{
		data_cpy[k] = 0;
	}
	upc_barrier;

	double c[2];
	
	upc_forall(int k=0; k<N; k++; k)
	{
		c[0] = 0;
		c[1] = 0;
		for (int n=0; n<N; n++)
		{
			double arg = -2 * M_PI * k * n / N;
			c[0] += data[2*n] * cos(arg) - data[2*n+1] * sin(arg);
			c[1] += data[2*n+1] * cos(arg) + data[2*n] * sin(arg);
		}
		data_cpy[2*k] = c[0];
		data_cpy[2*k+1] = c[1];
		upc_barrier;
	}
	upc_forall(int k=0; k<2*N; k++; k)
	{
		data[k] = data_cpy[k];
	}
	upc_barrier;
}

int bit_reverse(int num)
{
	int N_bits = (int)log2(N);

	int num_rev = 0;
	for (int i=0; i<N_bits; i++)
	{
		int curr_bit = (num >> i) & 1;
		num_rev += (curr_bit << (N_bits -1 - i));
	}
	return num_rev;
}

void bit_reversal_copy()
{
	upc_forall (int i=0; i<N; i++; i)
	{
		int i_rev = bit_reverse(i);
		data_cpy[2*i_rev] = data[2*i];
		data_cpy[2*i_rev+1] = data[2*i+1];
	}
	upc_barrier;
	upc_forall (int i=0; i<N; i++; i)
	{
		data[i] = data_cpy[i];
		data[i+N] = data_cpy[i+N];
	}
	upc_barrier;
}

void dft_reverse()
{
	int i;
	upc_forall(i=0; i<N; i++; i)
	{
		data[2*i+1] = -data[2*i+1];
	}
	upc_barrier;
	dft();
	upc_forall(i=0; i<N; i++; i)
	{
		data[2*i] /= N;
		data[2*i+1] = -data[i+N] / N;
	}
}

void print_data(const char *filename)
{
	if (MYTHREAD == 0)
	{
		FILE *f = fopen(filename, "w");
		for (int i=0; i<N; i++) 
		{
			fprintf(f, "%d,\t%lf,\t%lf\n", i, data[2*i], data[2*i+1]);
		}
		fclose(f);
	}
}

int main()
{
	// Populate data array
	upc_forall(int i=0; i<N; i++; i)
	{
		data[2*i] = sin(.2*i);
		data[2*i+1] = 0;
	}
	upc_barrier;

	dft();
	print_data("data/out_fft.csv");
	
	dft_reverse();
	print_data("data/out_ifft.csv");
	
	upc_barrier;
	if (MYTHREAD == 0)
	{
		printf("Application executed successfully.\n");
	}
	return 0;
}

