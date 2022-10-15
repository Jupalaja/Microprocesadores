#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define MAXCHAR 1000


void modoManual(int* n, double** nums_x, double** nums_y);
void modoArchivo(int* n, double** nums_x, double** nums_y);
void minimosCuadrados(int N, const double* nums_x, const double* nums_y, double *m, double *b, double *r);

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
    int N, modo=0;
    double *numbersX, *numbersY;
    double m = 0, b = 0, r = 0;

    /*
        Menú para Seleccionar el tipo de entrada de datos, la llamada a las funciones se realiza
        pasando parámetros por referencia utilizando punteros, optimizando el uso de la memoria.
    */
    do {
        printf("\nSeleccione un Modo de Ingreso de datos: "
               "\n·)  Ingrese 1 para Ingreso Manual de datos"
               "\n·)  Ingrese 2 para Ingreso de datos desde Archivo"
               "\n·)  Ingrese 3 para salir\n\t");
        scanf("%d", &modo);
        switch (modo) {
            case 1:
                printf("Seleccionó Modo Manual\n");
                modoManual(&N, &numbersX, &numbersY);
                minimosCuadrados(N, numbersX, numbersY, &m, &b, &r);
                break;
            case 2:
                printf("Seleccionó Modo Archivo\n");
                modoArchivo(&N, &numbersX, &numbersY);
                minimosCuadrados(N, numbersX, numbersY, &m, &b, &r);
                break;
            case 3:
                printf("Hasta Pronto :)");
                break;
            default:
                printf("Opción no valida");
        }
    } while (modo != 3);
    return 0;
}

/*
    Esta función utiliza un puntero [*n] para obtener el valor del tamaño de los arreglos
    y punteros dobles [**nums_x] y [**nums_y] para crear vectores que pasaremos por referencia.
*/
void modoManual(int* n, double** nums_x, double** nums_y){
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
        printf("\n");
    }
    printf("Valores Iniciales:\n");
    for (int i = 0; i < *n; ++i) {
        printf("x%d: %.2f\t\ty%d: %.2f\n", i, *(*nums_x+i), i, *(*nums_y+i));
    }
}

/*
    Esta función recibe un los mismos parámetros que modoManual; sin embargo, utilizamos funciones
    de la librería [<string.h>] para leer renglones en el archivo csv y obtener los valores desde alli.
*/
void modoArchivo(int* n, double** nums_x, double** nums_y){
    /*
        Declaramos las variables a usar:
        [*fp]: Variable para almacenar nuestro archivo csv de entrada
        [row]: Arreglo que contiene un renglón leído completo.
        [token]: Variable para separar y obtener los valores individuales de X y Y de cada renglón
        [count]: variable para contar los renglones leídos y hallar el valor de n
    */
    FILE* fp;
    char row[MAXCHAR];
    char nombreArchivo[20];
    char* token;
    int count = 0;

    /*
        Solicitamos al usuario el nombre del archivo a leer, ubicado en la sub-carpeta [/data]
        para ser almacenado.
    */
    printf("Ingrese el nombre del archivo (Incluya la extensión):\n");
    scanf("%s", nombreArchivo);

    /*
        Abrimos la primera vez los datos en nuestro archivo para conocer el número de
        vectores dado, después asignamos la memoria correspondiente a nuestros vectores [nums_x] y [num_y].
    */
    fp = fopen(nombreArchivo,"r");
    if (!fp){
        printf("No se pudo abrir el archivo\n");
    }
    while (feof(fp) != true) {
        fgets(row, MAXCHAR, fp);
        count ++;
    }
    *n = count;
    *nums_x = malloc(*n * sizeof(double));
    *nums_y = malloc(*n * sizeof(double));

    /*
        Recorremos una segunda vez los datos en nuestro archivo para obtener los valores de X y Y de
        cada renglón y pasarlos a los vectores [nums_x] y [num_y].
    */
    fp = fopen(nombreArchivo,"r");
    int i = 0;
    while (feof(fp) != true) {
        fgets(row, MAXCHAR, fp);
        token = strtok(row, ",");
        *(*nums_x+i) = strtod(token, NULL);
        token = strtok(NULL, ",");
        *(*nums_y+i) = strtod(token, NULL);
        i ++;
    }
}

/*
    Esta función recibe como parámetros de entrada el valor de [N], y los vectores [nums_x] y [nums_y]
    para calcular los valores de [m], [b], y [r] en punteros que serán pasados por referencia.
*/
void minimosCuadrados(int N, const double* nums_x, const double* nums_y, double* m, double* b, double* r){
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, sumY2 = 0;
    /*
        Mediante un ciclo for obtenemos todas los valores necesarios para calcular las variables de
        salida, luego reemplazamos dichos valores según la función de regresión lineal de mínimos cuadrados.
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



