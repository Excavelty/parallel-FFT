#include "file_utils.h"

void count_lines_in_file(const char *filename, shared size_t *N)
{
    char *current_line = NULL;
    size_t len = 0;
    FILE *fp = fopen(filename, "r");

    while (getline(&current_line, &len, fp) != -1)
    {
        (*N)++;
    }

    fclose(fp);
    if (current_line)
        free(current_line);
}


void read_data_lines(const char *filename, size_t N, shared Complex *data_buff)
{
    char *current_line = NULL;
    size_t len = 0;
    FILE *fp = fopen(filename, "r");

    for (int i =0; i < N; i++)
    {
        getline(&current_line, &len, fp);
        double realis = (double )atof(current_line);
        data_buff[i].re = realis;
        data_buff[i].im = 0.;
    }
    fclose(fp);
    if (current_line)
        free(current_line);
}



void save_to_file(const char* filename, size_t N, shared Complex *data)
{
    FILE *fp = fopen(filename, "w");
    for (int i =0; i<N; i++)
    {
        fprintf(fp, "%d, %.4lf, %.4lf\n", i, data[i].re, data[i].im);
    }
    fclose(fp);
}