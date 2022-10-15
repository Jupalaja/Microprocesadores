#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void leerDatos(int* n, double** nums_x, double** nums_y);
void minimosCuadrados(int N, const double* nums_x, const double* nums_y, double *m, double *b, double *r);
void modoManual(int* n, double** nums_x, double** nums_y);

int main() {
    printf("Reto 1 en progreso...\n");
    /*
        Declaración de variables a usar:
        [N]: Tamaño de los vectores X y Y
        [modo]: Variable para obtener el tipo de ingreso de datos
        [*numbersX] y [*numbersX]: Punteros/Arreglos para almacenar los vectores
        [m]: Pendiente de la recta
        [b]: Corte con el eje Y
        [r]: Correlación de Pearson
    */
    int N, modo;
    double *numbersX, *numbersY;
    double m = 0, b = 0, r = 0;

    printf("Seleccione un Modo de Ingreso de datos: "
           "\n·)  Ingrese 1 para Ingreso Manual de datos"
           "\n·)  Ingrese 2 para Ingreso de datos desde Archivo\n\t");
    scanf("%d", &modo);
    if (modo == 1) {
        printf("Seleccionó Modo Manual\n");
        /*
           Llamada a las funciones pasando parámetros por referencia [&parámetro] usando punteros para
           retornar multiples valores y trabajar sobre las variables originales, ahorrando memoria.
       */
        modoManual(&N, &numbersX, &numbersY);
        minimosCuadrados(N, numbersX, numbersY, &m, &b, &r);
    } else if (modo == 2) {
        printf("Modo archivo en progreso...");
    } else {
        printf("Opción no valida");
    }
    return 0;
}
void modoManual(int* n, double** nums_x, double** nums_y){
    leerDatos(n, nums_x, nums_y);
    printf("Valores Iniciales:\n");
    for (int i = 0; i < *n; ++i) {
        printf("x%d: %.2f\t\ty%d: %.2f\n", i, *(*nums_x+i), i, *(*nums_y+i));
    }
}
/*
    En esta función utilizamos un puntero [*n] para obtener el valor del tamaño de los arreglos
    y punteros dobles [**nums_x] y [**nums_y] para asignar memoria variable y hacer llamadas por
    referencia en la función main.
*/
void leerDatos(int* n, double** nums_x, double** nums_y) {
    /*
        Escaneamos el valor de n: el tamaño de los arreglos a usar y lo almacenamos en [num_in].
    */
    char num_in[sizeof(double)];
    printf("Ingrese la longitud de los arreglos X y Y: \n");
    scanf("%d", n); //
    printf("Ingreso %d números. \n", *n);

    /*
        Asignamos suficiente memoria para los vectores X y Y, a saber: n x [Tamaño de double].
    */
    *nums_x = malloc(*n * sizeof(double));
    *nums_y = malloc(*n * sizeof(double));

    /*
        Escaneamos los valores de entrada en la variable temporal [num_in] y obtenemos los valores de
        X y Y por parejas almacenándolos en nuestros punteros/arreglos [*nums_x] y [*nums_y].
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
/*
    Esta función recibe como parámetros de entrada el valor de [N], y los vectores [nums_x] y [nums_y]
    para calcular los valores de [m], [b], y [r] en punteros que serán pasados por referencia.
*/
void minimosCuadrados(int N, const double* nums_x, const double* nums_y, double* m, double* b, double* r){
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, sumY2 = 0;
    /*
        Mediante un ciclo for obtenemos todas las variables necesarias para calcular las variables de
        salida, luego reemplazamos dichos valores según la regresión lineal de mínimos cuadrados.
    */
    for (int i = 0; i < N; ++i) {
        sumX += *(nums_x+i);
        sumY += *(nums_y+i);
        sumXY += (*(nums_x+i))*(*(nums_y+i));
        sumX2 += pow(*(nums_x+i),2);
        sumY2 += pow(*(nums_y+i),2);
    }
    *m = (N*sumXY - sumX*sumY)/(N*sumX2 - (pow(fabs(sumX),2)));
    *b = (sumY*sumX2 - sumX*sumXY)/(N*sumX2 - (pow(fabs(sumX),2)));
    *r = (N*sumXY - sumX*sumY)/(sqrt((N*sumX2 - pow(sumX,2))*(N*sumY2 - pow(sumY,2))));

    /*
        Verificación de valores indefinidos cuando alguno de los valores resultantes es igual a +∞ o -∞.
    */
    if(isnan(*m) || isnan(*b) || isnan(*r)) {
        printf("\nError: se han obtenido valores indeterminados, verifique los parámetros iniciales.\n");
    } else {
        printf("\nParámetros de salida:\n");
        printf("m = %f\n", *m);
        printf("b = %f\n", *b);
        printf("r = %f\n", *r);
        printf("\nFunción resultante: \t");
        printf("y = %.4f*x + %.4f, Correlación: %.4f \n", *m,*b,*r);
    }
}



