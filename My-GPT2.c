#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>
#include <assert.h>
#ifdef _OPENMP
#include <omp.h>
#endif
#include "helper.c"
#define SQRT_2_OVER_PI 0.7978845608028654
#define const1 0.5
#define const2 0.044715

struct Config
{
    int batch_size;
    int seq_len;
    int num_heads;
    int d_model;
    int vocab_size;
    int n_layers;
};

void ResidualLayer(float *input1, float *input2, float *output, int size)
{
    for (int i = 0; i < size; i++)
    {
        output[i] = input1[i] + input2[i];
    }
}

void next_batch(int *input, int *tokens, int *targets, int curr_pointer, int num_indices, int B, int T)
{
    if (curr_pointer + B * T + 1 >= num_indices)
    {
        curr_pointer = 0;
    }
    for (int i = 0; i < B * T; i++)
    {
        input[i] = tokens[curr_pointer + i];
        targets[i] = tokens[curr_pointer + i + 1];
    }
}
int *read_tokens_from_file(const char *filename, int *num_indices)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Failed to open file");
        return NULL;
    }

    // file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(file_size + 1);
    if (buffer == NULL)
    {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0';

    fclose(file);

    int estimated_size = file_size / 2;
    int *indices = (int *)malloc(estimated_size * sizeof(int));
    if (indices == NULL)
    {
        perror("Failed to allocate memory for indices");
        free(buffer);
        return NULL;
    }

    int index_count = 0;
    char *token = strtok(buffer, ", \n");
    while (token != NULL)
    {
        if (index_count >= estimated_size)
        {
            estimated_size *= 2;
            indices = (int *)realloc(indices, estimated_size * sizeof(int));
            if (indices == NULL)
            {
                perror("Failed to reallocate memory for indices");
                free(buffer);
                return NULL;
            }
        }
        indices[index_count++] = atoi(token);
        token = strtok(NULL, ", \n");
    }

    free(buffer);
    *num_indices = index_count;
    return indices;
}

int main()
{
    return 0;
}
