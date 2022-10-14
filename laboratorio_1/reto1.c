#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    Declaración de la función usando un puntero para que pueda ser definida después de main.
*/

void leerDatos(int* n, double** nums_x, double** nums_y);
void minimosCuadrados(int N, const double* nums_x, const double* nums_y, double *m, double *b, double *r);

int main() {
    printf("Reto 1 en progreso...\n");
    int n;
    double *numbersX, *numbersY;
    double m = 0, b = 0, r = 0;

    /*
        Llamada a la función por referencia usando punteros para retornar multiples valores
        y para trabajar sobre las variables originales sin copiarlas, ahorrando memoria.
    */
    
    leerDatos(&n, &numbersX, &numbersY);
    printf("Valores Iniciales:\n");
    for (int i = 0; i < n; ++i) {
        printf("x%d: %.4f\ty%d: %.4f\n", i, numbersX[i], i, numbersY[i]);

    }
    minimosCuadrados(n, numbersX, numbersY, &m, &b, &r);

    if(isnan(m) || isnan(b) || isnan(r)) {
        printf("\nError: se han obtenido valores indeterminados, verifique los parámetros iniciales.\n");
    } else {
        printf("\nParámetros de salida:\n");
        printf("m = %.4f\n", m);
        printf("b = %.4f\n", b);
        printf("r = %.4f\n", r);
        printf("\nFunción resultante: \t");
        printf("y = %.4f*x + %.4f, Correlación: %.4f \n", m,b,r);
    }

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

void minimosCuadrados(int N, const double* nums_x, const double* nums_y, double* m, double* b, double* r){
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, sumY2 = 0;

    for (int i = 0; i < N; ++i) {
        sumX += *(nums_x+i);
        sumY += *(nums_y+i);
        sumXY += (*(nums_x+i))*(*(nums_y+i));
        sumX2 += (*(nums_x+i))*(*(nums_x+i));
        sumY2 += (*(nums_y+i))*(*(nums_y+i));
    }
    *m = (N*sumXY - sumX*sumY)/(N*sumX2 - (pow(fabs(sumX),2)));
    *b = (sumY*sumX2 - sumX*sumXY)/(N*sumX2 - (pow(fabs(sumX),2)));
    *r = (N*sumXY - sumX*sumY)/(sqrt((N*sumX2 - pow(sumX,2))*(N*sumY2 - pow(sumY,2))));
}



