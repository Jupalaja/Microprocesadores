#include <stdio.h>
#include <stdlib.h>

double *leerDatos();

int main() {
    printf("Reto 1 en progreso...\n");
    double *numbers = leerDatos(); //Leemos 2 datos
    printf("The elements of the array are: ");
    for (int i = 0; i < sizeof numbers; ++i) {
        printf("%f, ", numbers[i]);
    }
    return 0;
}

// Función para ingresar los datos iniciales
double *leerDatos() {
    int n; //Variable para recibir el número de parejas de datos
    char num_in[5]; //Variable para recibir los datos de consola
    double *nums_x; //Variable para almacenar los valores de

    printf("Ingrese la longitud de los arreglos X y Y: \n");
    scanf("%d", &n); //Escaneo de la entrada del teclado
    printf("Ingreso %d números. \n", n);

    double *p = (double *)malloc(n * sizeof(double));
    printf("%lu\n",sizeof(*p));

    printf("Ingrese Los valores de x: \n");
    for(int i=0; i<n;i=i+1)     {
        scanf("%s",num_in); //Escaneo de la entrada del teclado
        nums_x[i]=atof(num_in); //Conversión de string a double
    }

//    printf("Ingrese Los valores de y: \n");
//    for(int j=num_par; j < num_par * 2; j= j + 1)     {
//        scanf("%s",num_in); //Escaneo de la entrada del teclado
//        nums_x[j]=atof(num_in); //Conversión de string a double
//    }
    return nums_x;
}


