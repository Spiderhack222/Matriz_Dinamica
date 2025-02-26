//Matriz dinamica

/*
https://github.com/LingSc4r/MatrizDinamica/blob/main/MatrizDinamica.c

https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C/Matrices_Dinamicas

https://youtu.be/BfgQZaUoS6A?si=czitjRIPevLHQvDG

Link de calculadora de matrices
https://matrixcalc.org/es/#%7B%7B20,0,2,-3,-11,-4%7D,%7B12,-8,13,11,-13,10%7D,%7B11,4,15,3,18,2%7D%7D*%7B%7B20,11,-5%7D,%7B3,-14,4%7D,%7B10,-1,-13%7D,%7B-12,3,13%7D,%7B-1,-13,9%7D,%7B3,9,20%7D%7D

*/

//m es fila
//n es columna

//Codigo ya con numeros seudoaleatorios

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void llenar_matriz(int m, int n, double **matriz);
void mostrar_matriz(int m, int n, double **matriz);
double **crear_matriz(int filas, int columnas);
void liberar_matriz(double **matriz, int filas);
double **multiplicar_matrices(double **A, int fa, int ca, double **B, int fb, int cb);

int main() {
    srand(time(NULL)); // Inicializar semilla para números aleatorios
    int fa, ca, fb, cb;

    // Ingresar dimensiones de la matriz A
    printf("Ingrese filas y columnas de A: ");
    scanf("%d %d", &fa, &ca);

    // Ingresar dimensiones de la matriz B
    printf("Ingrese filas y columnas de B: ");
    scanf("%d %d", &fb, &cb);

    // Verificar si se pueden multiplicar
    if (ca != fb) {
        printf("Error: No se pueden multiplicar las matrices.\n");
        return 1;
    }

    // Crear y llenar matrices con valores aleatorios
    double **A = crear_matriz(fa, ca);
    double **B = crear_matriz(fb, cb);

    llenar_matriz(fa, ca, A);
    llenar_matriz(fb, cb, B);

    // Multiplicar matrices
    double **C = multiplicar_matrices(A, fa, ca, B, fb, cb);

    // Mostrar resultados
    printf("Matriz A:\n");
    mostrar_matriz(fa, ca, A);
    printf("Matriz B:\n");
    mostrar_matriz(fb, cb, B);
    printf("Matriz C (resultado de A x B):\n");
    mostrar_matriz(fa, cb, C);

    // Liberar memoria
    liberar_matriz(A, fa);
    liberar_matriz(B, fb);
    liberar_matriz(C, fa);

    return 0;
}

double **crear_matriz(int filas, int columnas) {
    double **matriz = (double **)calloc(filas, sizeof(double *));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (double *)calloc(columnas, sizeof(double));
    }
    return matriz;
}

void llenar_matriz(int m, int n, double **matriz) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = (rand() % 36) - 15; // Valores entre -15 y 20
        }
    }
}

void mostrar_matriz(int m, int n, double **matriz) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf\t", matriz[i][j]);
        }
        printf("\n");
    }
}

double **multiplicar_matrices(double **A, int fa, int ca, double **B, int fb, int cb) {
    double **C = crear_matriz(fa, cb);
    for (int i = 0; i < fa; i++) {
        for (int j = 0; j < cb; j++) {
            C[i][j] = 0;
            for (int k = 0; k < ca; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

void liberar_matriz(double **matriz, int filas) {
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}
