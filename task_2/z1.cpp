#include <iostream>
#include <cstdlib>
#include <omp.h>

using namespace std;

// Умножение матрицы на вектор
void matrix_vector_product_omp(double *a, double *b, double *c, int m, int n)
{
#pragma omp parallel for
    for (int i = 0; i < m; i++) {
        double sum = 0.0;

        for (int j = 0; j < n; j++) {
            sum += a[i * n + j] * b[j];
        }

        c[i] = sum;
    }
}

int main(int argc, char **argv)
{
    int m = 20000;
    int n = 20000;

    if (argc == 2) {
        m = atoi(argv[1]);
        n = m;
    }

    cout << "Matrix-vector product (c[m] = a[m,n] * b[n])" << endl;
    cout << "Matrix size: " << m << " x " << n << endl;

    long long memory = ((long long)m * n + m + n) * sizeof(double);
    cout << "Memory used: " << memory / (1024 * 1024) << " MB" << endl;

    // Выделение памяти
    double *a = (double*)malloc(sizeof(double) * m * n);
    double *b = (double*)malloc(sizeof(double) * n);
    double *c = (double*)malloc(sizeof(double) * m);

    if (!a || !b || !c) {
        cout << "Memory allocation failed!" << endl;
        return 1;
    }

    // Параллельная инициализация матрицы
#pragma omp parallel for
    for (long long i = 0; i < (long long)m * n; i++) {
        a[i] = (double)(i % 100);
    }

    // Параллельная инициализация вектора
#pragma omp parallel for
    for (int i = 0; i < n; i++) {
        b[i] = (double)i;
    }

    // Замер времени
    double start = omp_get_wtime();

    matrix_vector_product_omp(a, b, c, m, n);

    double end = omp_get_wtime();

    cout << "Elapsed time: " << end - start << " seconds" << endl;

    // Освобождение памяти
    free(a);
    free(b);
    free(c);

    return 0;
}