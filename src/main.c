// Includes
#include <upc.h>
#include <stdio.h>
#include <math.h>

// Defines
#define M_PI 3.14159265359
#define DTYPE double 
#define N (THREADS * 256)

// Global & shared variables
shared DTYPE data[2*N];
shared DTYPE data_cpy[2*N];

// Functions
void dft();
void dft_reverse();
void fft();
void fft_reverse();
void bit_reversal_copy();
void print_data(const char *filename);
int bit_reverse(int num);

// ---------------------------------------------------------------------------------

int main()
{
	// Populate data array and save to file
	upc_forall(int i=0; i<N; i++; i)
	{
		data[i] = sin(2 * M_PI * i/N);// + 2*cos(i) * cos(4*i-2);
		data[i+N] = 0;
	}
	upc_barrier;
	print_data("data/in_fft.csv");

	// Calculate transform on data and print results to file
	fft();
	print_data("data/out_fft.csv");
	
	// Calculate iversed transform and save results
	fft_reverse();
	print_data("data/out_ifft.csv");
	
	// Finalize
	upc_barrier;
	if (MYTHREAD == 0)
	{
		printf("Application executed successfully.\n");
	}
	return 0;
}

// ---------------------------------------------------------------------------------

void dft()
{
	upc_forall(int k=0; k<N; k++; k)
	{
		data_cpy[k] = 0;
		data_cpy[k+N] = 0;
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
			c[0] += data[n] * cos(arg) - data[n+N] * sin(arg);
			c[1] += data[n+N] * cos(arg) + data[n] * sin(arg);
		}
		data_cpy[k] = c[0];
		data_cpy[k+N] = c[1];
		upc_barrier;
	}
	upc_forall(int k=0; k<N; k++; k)
	{
		data[k] = data_cpy[k];
		data[k+N] = data_cpy[k+N];
	}
	upc_barrier;
}

void dft_reverse()
{
	int i;
	upc_forall(i=0; i<N; i++; i)
	{
		data[i+N] = -data[i+N];
	}
	upc_barrier;
	dft();
	upc_forall(i=0; i<N; i++; i)
	{
		data[i] /= N;
		data[i+N] = -data[i+N] / N;
	}
}

void fft()
{
	upc_forall(int i=0; i<N; i++; i)
	{
		data_cpy[i] = data[i];
		data_cpy[i+N] = data[i+N];
	}
	bit_reversal_copy();
	if (MYTHREAD == 0) {
	
	double t[2], u[2];
	double omega_m[2];
	double omega[2], tmp[2];

	for (int s = 1; s <= log2(N); s++)
	{
		int m = 1<<s;
		omega_m[0] = cos(-2. * M_PI / (double)m);
		omega_m[1] = sin(-2. * M_PI / (double)m);
		upc_forall (int k=0; k<N; k+=m; k)
//		for(int k=0; k<N; k+=m)
		{
			omega[0] = 1.;
			omega[1] = 0.;
			for (int j=0; j<m/2; j++)
			{
				t[0] = omega[0] * data_cpy[k+j+m/2] - omega[1] * data_cpy[k+j+m/2+N];
				t[1] = omega[0] * data_cpy[k+j+m/2+N] + omega[1] * data_cpy[k+j+m/2];
				u[0] = data_cpy[k+j];
				u[1] = data_cpy[k+j+N];
				
			upc_barrier;
				data_cpy[k+j] = u[0] + t[0];
				data_cpy[k+j+N] = u[1] + t[1];
				data_cpy[k+j+m/2] = u[0] - t[0];
				data_cpy[k+j+m/2+N] = u[1] - t[1];
				
			upc_barrier;
				tmp[0] = omega[0] * omega_m[0] - omega[1] * omega_m[1];
				tmp[1] = omega[1] * omega_m[0] + omega[0] * omega_m[1];
				omega[0] = tmp[0];
				omega[1] = tmp[1];
			}
			upc_barrier;
		}
	}}
	upc_barrier;

	upc_forall(int i=0; i<N; i++; i)
	{
		data[i] = data_cpy[i];
		data[i+N] = data_cpy[i+N];
	}
}

void fft_reverse()
{
	int i;
	upc_forall(i=0; i<N; i++; i)
	{
		data[i+N] = -data[i+N];
	}
	upc_barrier;
	fft();
	upc_forall(i=0; i<N; i++; i)
	{
		data[i] /= N;
		data[i+N] = -data[i+N] / N;
	}
}

int bit_reverse(int num)
{
	int N_bits = (int)log2(N);

	int num_rev = 0;
	for (int i=0; i<N_bits; i++)
	{
		int curr_bit = (num >> i) & 1;
		num_rev += (curr_bit << (N_bits - 1 - i));
	}
	return num_rev;
}

void bit_reversal_copy()
{
	upc_forall (int i=0; i<N; i++; i)
	{
		int i_rev = bit_reverse(i);
		data_cpy[i] = data[i_rev];
		data_cpy[i+N] = data[i_rev+N];
	}
	upc_barrier;
	upc_forall (int i=0; i<N; i++; i)
	{
		data[i] = data_cpy[i];
		data[i+N] = data_cpy[i+N];
	}
	upc_barrier;
}

void print_data(const char *filename)
{
	if (MYTHREAD == 0)
	{
		FILE *f = fopen(filename, "w");
		for (int i=0; i<N; i++) 
		{
			fprintf(f, "%d,\t%lf,\t%lf\n", i, data[i], data[i+N]);
		}
		fclose(f);
	}
}

