#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double *leerDatos(int n);
double imprimiendo(double *num_out);

int main(void) {
    double *num_out = leerDatos(2); //Leemos 2 datos
    imprimiendo(num_out); //Imprimimos datos
    return 0;
}

//Este devuelve un vector
double *leerDatos(int n) {
    char num_in[8]; //Variable para recibir los datos de consola
    double *num_out; //Variable para almacenar los números
    num_out = (double *) malloc(sizeof(double)*2);

    printf("Ingrese dos numeros: \n");
    int i;
    for(i=0; i<2;i=i+1)     {
        scanf("%s",num_in); //Escaneo de la entrada del teclado
        num_out[i]=atof(num_in); //Conversión de string a double
        }
    return num_out;
}

//Este recibe un vector
double imprimiendo(double *num_out) {
    double *numero = num_out;
    printf("Potencia: %4.2f\n", pow(numero[0], 2)); //Cálculo de potencia al cuadrado
    printf("Raiz: %4.2f\n", sqrt(numero[1])); //Cálculo de raíz Cuadrada
    return 0;
}
