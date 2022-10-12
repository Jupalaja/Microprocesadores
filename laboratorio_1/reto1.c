#include <stdio.h>
#include <stdlib.h>

double *leerDatos();

int main() {
    printf("Reto 1 en progreso...\n");
    double *numbers = leerDatos(); //Leemos 2 datos
    for(int i=0; i<sizeof(numbers); i=i+1)     {
        printf("%lu",sizeof(numbers));
        printf("%.4f", numbers[i]); //Cálculo de raíz Cuadrada
        printf("\n");
    }
    return 0;
}

// Función para ingresar los datos iniciales
double *leerDatos() {
    char num_par_char[2]; //Variable para recibir el número de parejas de datos
    char num_in[8]; //Variable para recibir los datos de consola
    double *nums_x; //Variable para almacenar los valores de

    printf("Ingrese la longitud de los arreglos X y Y: \n");
    scanf("%s", num_par_char); //Escaneo de la entrada del teclado
    int num_par = atoi(num_par_char);

    nums_x = (double *) malloc(2*num_par*sizeof(double));


    printf("Ingrese Los valores de x: \n");
    for(int i=0; i<num_par;i=i+1)     {
        scanf("%s",num_in); //Escaneo de la entrada del teclado
        nums_x[i]=atof(num_in); //Conversión de string a double
    }

    printf("Ingrese Los valores de y: \n");
    for(int j=num_par; j < num_par * 2; j= j + 1)     {
        scanf("%s",num_in); //Escaneo de la entrada del teclado
        nums_x[j]=atof(num_in); //Conversión de string a double
    }
    return nums_x;
}


