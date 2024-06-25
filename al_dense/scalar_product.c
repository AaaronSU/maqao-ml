#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <immintrin.h>

#define f64 double
#define u64 __uint64_t
#define ascii __uint8_t
#define ALIGN64 64

void init_f64(f64 *restrict a, u64 n, const ascii m)
{
    // Random value per entry
    if (m == 'r' || m == 'R')
    {
#pragma omp parallel for simd
        for (u64 i = 0; i < n; i++)
            a[i] = (f64)RAND_MAX / (f64)rand();
    }
    else // Zeroing up the array
        if (m == 'z' || m == 'Z')
        {
#pragma omp parallel for simd
            for (u64 i = 0; i < n; i++)
                a[i] = 0.0;
        }
        else // Same value per entry
            if (m == 'c' || m == 'C')
            {
                f64 c = (f64)RAND_MAX / (f64)rand();
#pragma omp parallel for simd
                for (u64 i = 0; i < n; i++)
                    a[i] = c;
            }
}

void print_f64(f64 *restrict a, u64 n)
{
    for (u64 i = 0; i < n; i++)
        printf("%lf ", a[i]);
    printf("\n");
}

/// @brief calculate scalar product of a and b and store in the c.
/// @param a pointer of list of double
/// @param b pointer of list of double
/// @param c resultat of scalar product which is a double
// void scalar_product(double *a, double *b, double *c, u64 n)
// {
//     double sum = 0.0;
// #pragma omp parallel
//     {
//         double local_sum = 0.0;
// #pragma omp for
//         for (u64 i = 0; i < n; i += 1)
//         {
//             double prod = a[i] * b[i];
//             local_sum += prod;

//             //*c += a[i] + b[i];
//             // *c += a[i + 4] + b[i + 4];
//             // *c += a[i + 5] + b[i + 5];
//             // *c += a[i + 6] + b[i + 6];
//             // *c += a[i + 7] + b[i + 7];
//         }
// #pragma omp critical
//         {
//             sum += local_sum;
//         }
//     }
// }
void scalar_product(double *a, double *b, double *c, u64 n)
{
    __m512d sum = _mm512_setzero_pd();
#pragma omp parallel
    {
        __m512d local_sum = _mm512_setzero_pd();
#pragma omp for
        for (u64 i = 0; i < n; i += 8)
        {
            __m512d vec_a = _mm512_load_pd(&a[i]);
            __m512d vec_b = _mm512_load_pd(&b[i]);
            __m512d prod = _mm512_mul_pd(vec_a, vec_b);
            local_sum = _mm512_add_pd(local_sum, prod);
        }
#pragma omp critical
        {
            sum = _mm512_add_pd(sum, local_sum);
        }
    }
    double result[8];
    _mm512_storeu_pd(result, sum);

    double dot_product = 0.0;
    for (int i = 0; i < 8; i++)
    {
        dot_product += result[i];
    }
    *c = dot_product;
}

int main(int argc, char *argv[argc + 1])
{
    // if (argc != 2)
    // {
    //     printf("The commanmad must be form ./scalar_product [vector_size]");
    // }
    u64 size = 100000000;
    u64 iteration = 300;
    f64 *restrict a = aligned_alloc(ALIGN64, size * sizeof(f64));
    f64 *restrict b = aligned_alloc(ALIGN64, size * sizeof(f64));
    f64 *restrict c = aligned_alloc(ALIGN64, sizeof(f64));

    init_f64(a, size, 'c');
    init_f64(b, size, 'c');

    // struct timespec t1, t2;
    for (u64 i = 0; i < iteration; i++)
    {
        // clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
        scalar_product(a, b, c, size);
        // clock_gettime(CLOCK_MONOTONIC_RAW, &t2);
    }

    // print_f64(a, size);
    // print_f64(b, size);
    // print_f64(c, 1);
    printf("%lf\n", *c);

    free(a);
    free(b);
    free(c);
    return 0;
}