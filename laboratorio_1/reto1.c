#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXCHAR 1000

char *trim(char *s);
void modoManual(int* n, double** nums_x, double** nums_y);
void modoArchivo(int* n, double** nums_x, double** nums_y);
void minimosCuadrados(int N, const double* nums_x, const double* nums_y, double *m, double *b, double *r);
void guardarArchivo(int *modo, int N, const double* nums_x, const double* nums_y, double m, double b, double r);
struct Dato leerDatosDouble(char* character, bool isDouble);
struct Dato{
    double num_out;
    char char_out[20];
};

int main() {
    printf("Reto 1 Terminado\n");
    /*
        Declaración de variables a usar:
        [N]: Tamaño de los vectores X y Y
        [modo]: Variable para obtener el tipo de ingreso de datos
        [*numbersX] y [*numbersX]: Punteros/Arreglos para almacenar los vectores
        [m]: Pendiente de la recta
        [b]: Corte con el eje Y
        [r]: Correlación de Pearson
        [guardar]: variable para determinar si se exportan los datos
    */
    int N, modo=0;
    double *numbersX, *numbersY;
    double m, b, r;
    char modoChar[sizeof(double)];

    /*
        Menú para Seleccionar el tipo de entrada de datos, la llamada a las funciones se realiza
        pasando parámetros por referencia utilizando punteros, optimizando el uso de la memoria.
    */
    do {
        N = 0, m = 0, b = 0, r = 0;
        numbersY = NULL, numbersX = NULL;

        printf("\nSeleccione un Modo de Ingreso de datos: "
               "\n·)  Ingrese 1 para Ingreso Manual de datos"
               "\n·)  Ingrese 2 para Ingreso de datos desde Archivo"
               "\n·)  Ingrese 3 para salir\n\t");

        modo = (int) leerDatosDouble(modoChar, true).num_out;
        switch (modo) {
            case 1:
                printf("Seleccionó Modo Manual\n");
                modoManual(&N, &numbersX, &numbersY);
                minimosCuadrados(N, numbersX, numbersY, &m, &b, &r);
                guardarArchivo(&modo, N, numbersX, numbersY, m, b, r);
                break;
            case 2:
                printf("Seleccionó Modo Archivo\n");
                modoArchivo(&N, &numbersX, &numbersY);
                minimosCuadrados(N, numbersX, numbersY, &m, &b, &r);
                guardarArchivo(&modo,N, numbersX, numbersY, m, b, r);
                break;
            case 3:
                printf("Hasta Pronto :)");
                break;
            default:
                printf("Opción no valida");
                break;
        }
    } while (modo != 3);
    return 0;
}

/*
    Función para leer datos de entrada sin errores, evitando la función [scanf]
*/

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
    *n = (int) leerDatosDouble(num_in, true).num_out;
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
        *(*nums_x+i) = leerDatosDouble(num_in, true).num_out;
        printf("Ingrese el valor de y%d: ", i);
        *(*nums_y+i) = leerDatosDouble(num_in, true).num_out;
        printf("\n");
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
    char* nombreArchivo;
    char* token;
    int count = 0;

    /*
        Solicitamos al usuario el nombre del archivo a leer, ubicado en la sub-carpeta [/data]
        para ser almacenado.
    */
    printf("Ingrese el nombre del archivo (Incluya la extensión):\n");
    nombreArchivo = leerDatosDouble(nombreArchivo, false).char_out;
    printf("\n%s\n", nombreArchivo);
    /*
        Abrimos la primera vez los datos en nuestro archivo para conocer el número de
        vectores dado, después asignamos la memoria correspondiente a nuestros vectores [nums_x] y [num_y].
    */
    fp = fopen(trim(nombreArchivo),"r");
    if (!fp){
        printf("No se pudo abrir el archivo\n");
        return;
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
    fp = fopen(trim(nombreArchivo),"r");
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
        Verificación de casos indefinidos cuando alguno de los valores resultantes es igual a +∞ o -∞.
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

void guardarArchivo(int* modo ,int N, const double* nums_x, const double* nums_y, double m, double b, double r){
    /*
        Declaramos las variables a usar:
        [*fp]: Variable [FILE] para almacenar nuestro archivo csv de entrada
        [nombreArchivo]: Arreglo que contiene el nombre de nuestro archivo a crear
        [nombreArchivo]: variable usada para decidir la exportación de los datos
    */
    FILE *fp;
    char* nombreArchivo;
    char *exportar = NULL;
    printf("\nDesea exportar los datos?"
           "\n\t Presione (Y) para exportar"
           "\n\t Presione otra tecla para continuar\n");
    /*
        Lectura de entrada en la variable exportar y asignación a variable [nombreArchivo].
    */
    exportar = leerDatosDouble(exportar, false).char_out;
    if (*exportar == 'y'){
        printf("\nIngrese el nombre del archivo de salida (No incluya la extensión): ");
        nombreArchivo = trim(leerDatosDouble(exportar,false).char_out);
        printf("\nCreando archivo...");
        strcat(nombreArchivo,".csv");

        /*
            Creación de nuestro archivo usando la función [fopen] con el parámetro "w+".
        */
        fp=fopen(nombreArchivo,"w+");
        fprintf(fp,"\nValores Iniciales:,\n");
        for (int i = 0; i < N; ++i) {
            fprintf(fp,"x%d: %=.2f, y%d: %.2f\n", i, *(nums_x+i), i, *(nums_y+i));
        }
        /*
            Verificación de casos indefinidos cuando alguno de los valores resultantes es igual a +∞ o -∞.
        */
        if(isnan(m) || isnan(b) || isnan(r)) {
            fprintf(fp,"\nError: se han obtenido valores indeterminados, verifique los parametros iniciales.\n");
        } else {
            fprintf(fp,"\nParametros de salida:\n"
                       "m = %f\n"
                       "b = %f\n"
                       "r = %f\n"
                       "\nFuncion resultante: \t"
                       "y = %.4f*x + %.4f, Correlacion: %.4f \n", m, b, r, m, b, r);
        }
        fclose(fp);
        printf("\n Archivo \'%s\'  creado exitosamente.\n", nombreArchivo);
    }
}

struct Dato leerDatosDouble(char *character, bool isDouble) {
    char* t;
    struct Dato salida;
    char* end = NULL;
    if (isDouble){
        while(fgets(character, sizeof(character),stdin)) {
            salida.num_out = strtod(character, &end);
            if (end == character || *end != '\n') {
                printf("Opcion no valida, intente nuevamente\n");
            } else break;
        }
    } else {
        fgets(salida.char_out, sizeof(salida.char_out), stdin);
    }
    return salida;
}

char *trim(char *s) {
    char *ptr;
    if (!s)
        return NULL;   // handle NULL string
    if (!*s)
        return s;      // handle empty string
    for (ptr = s + strlen(s) - 1; (ptr >= s) && isspace(*ptr); --ptr);
    ptr[1] = '\0';
    return s;
}
