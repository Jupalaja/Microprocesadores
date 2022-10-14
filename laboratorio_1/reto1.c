#include <stdio.h>
#include <stdlib.h>

/*
    Declaración de la función usando un puntero para que pueda ser definida después de main.
*/
void leerDatos(int* n, double** nums_x, double** nums_y);
void minimosCuadrados(int n, const double* nums_x, const double* nums_y, double *m, double *b, double *r);

int main() {
    printf("Reto 1 en progreso...\n");
    int a;
    double *numbersX, *numbersY;
    double sumx, sumy, sumxy;
    /*
        Llamada a la función por referencia usando punteros para retornar multiples valores
        y para trabajar sobre las variables originales sin copiarlas, ahorrando memoria.
    */
    leerDatos(&a, &numbersX, &numbersY);
    for (int i = 0; i < a; ++i) {
        printf("x%d: %.4f    y%d: %.4f\n", i, numbersX[i], i, numbersY[i]);
    }
    minimosCuadrados(a, numbersX, numbersY, &sumx, &sumy, &sumxy);
    printf("%.4f\n", sumx);
    printf("%.4f\n", sumy);
    printf("%.4f\n", sumxy);
    return 0;
}

/*
    Para la función leerDatos utilizamos un puntero [int* n] para obtener el valor del tamaño de los
    arreglos, y punteros [double** nums_x] y [double** nums_y] para asignar memoria variable y hacer
    llamadas por referencia en la función main.
*/
void leerDatos(int* n, double** nums_x, double** nums_y) {
    char num_in[sizeof(double)]; // Variable para recibir en formato texto desde la consola

    printf("Ingrese la longitud de los arreglos X y Y: \n");
    scanf("%d", n); // Escaneamos el valor de n: el tamaño de los arreglos a usar
    printf("Ingreso %d números. \n", *n);

    /*
        Debemos asignar suficiente memoria para los vectores X y Y, a saber: n x [Tamaño de double].
    */
    *nums_x = malloc(*n * sizeof(double));
    *nums_y = malloc(*n * sizeof(double));

    /*
        Guardamos el valor almacenado en la variable temporal [num_in] en la posición correspondiente
        a nuestros punteros/arreglos [*nums_x] y [*nums_y].
    */
    for(int i=0; i<*n;i=i+1) {
        printf("Ingrese el valor de x%d: ", i);
        scanf("%s",num_in);
        *(*nums_x+i) = strtod(num_in, NULL);
        printf("Ingrese el valor de y%d: ", i);
        scanf("%s",num_in);
        *(*nums_y+i) = strtod(num_in, NULL);
        printf("\n"); // Salto de linea
    }
}

void minimosCuadrados(int n, const double* nums_x, const double* nums_y, double* m, double* b, double* r){
    double sumX = 0;
    double sumY = 0;
    double sumXY = 0;

    for (int i = 0; i < n; ++i) {
        sumX += *(nums_x+i);
    }
    for (int i = 0; i < n; ++i) {
        sumY += *(nums_y+i);
    }
    for (int i = 0; i < n; ++i) {
        sumXY += (*(nums_x+i))*(*(nums_y+i));
    }
    *m = sumX;
    *b = sumY;
    *r = sumXY;
}


