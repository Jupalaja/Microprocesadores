#include<stdio.h>
//TODO: Replace <conio.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANIO 9

int  w,h,matrix [ 9 ] [ 9 ];
void  print_sudoku ()
{
    int  i , j ;
    for ( i = 0 ; i < TAMANIO ; i++ ){
        for (j = 0; j < TAMANIO; j++){
            printf("%d \t ", matrix[i][j]);
        }
        printf("\n \n");
    }
}
// función para verificar si todas las celdas están asignadas o no
// si hay alguna celda no asignada
// entonces esta función cambiará los valores de
// row y col en consecuencia

int IngresoManual(){
    /*int sudoku[9][9];*/
    int i,j,valor;
    for (i=0;i<TAMANIO;i++){
        for (j=0;j<TAMANIO;j++){
            do{
                printf("Ingrese numero en fila %d columna %d\n",(i+1),(j+1));
                scanf("%d",&valor);
                if (valor>=0 && valor <=9)
                    matrix[i][j]=valor;
                else
                    printf ("\nDebe ingresar un valor entre 1 y 9\n");

            }while(valor < 0 || valor > 9);
        }
    }
    printf("\n");
    for (i=0;i<TAMANIO;i++){
        for(j=0;j<TAMANIO;j++){
            /*printf("%d\t",matrix[i][j]);*/
            printf("%d \t ", matrix[i][j]);
        }
        printf("\n \n");
    }
    return matrix[i][j];

}
int getmatrix() {
    FILE *file;
    char *nombre_archivo;

    printf("Ingrese el nombre del archivo (Incluya la extensión):\n");
    scanf("%s",nombre_archivo);
    file = fopen(nombre_archivo, "r");
    if (file==NULL){
        perror("unable bla bla");
        exit(1);
    }
    char line[200];
    h=0;
    while(fgets(line,sizeof (line),file))
    {
        w=0;
        char *number;
        number=strtok(line,",");
        while(number!=NULL)
        {
            matrix[h][w]=atoi(number);
            w++;
            number = strtok(NULL,",");
        }

        h++;

    }return matrix[h][w];

}
void printMatrix()
{
    int i,j;
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++){
            printf("%d\t",matrix[i][j]);
        }
        printf("\n \n");
    }
}
int  number_unassigned ( int  * row ,  int  * col)
{

    int  num_unassign  =  0 ;
    int  i , j ;
    for ( i = 0 ; i < TAMANIO ; i ++ )
    {
        for ( j = 0 ; j < TAMANIO ; j ++ )
        {
            // la celda no está asignada
            if ( matrix [ i ] [ j ]  ==  0 )
            {
                // cambiando los valores de row y col
                * row  =  i ;
                * col  =  j ;
                // hay una o más celdas sin asignar
                num_unassign  =  1 ;
                return  num_unassign ;
            }
        }
    }
    return  num_unassign ;
}
int  is_safe ( int  n ,  int  r ,  int  c )
{
    int  i , j ;
    // revisando en la fila
    for( i = 0 ; i < TAMANIO ; i ++ )
    {
        // hay una celda con mismo valor
        if ( matrix [ r ] [ i ]  ==  n )
            return  0 ;
    }
    // comprobando la columna
    for ( i = 0 ; i < TAMANIO ; i ++ )
    {
        // hay una celda con el valor igual a i
        if ( matrix [ i ] [ c ]  ==  n )
            return  0 ;
    }
    // comprobación de  submatriz
    int  row_start  =  ( r / 3 ) * 3 ;
    int  col_start  =  ( c / 3 ) *3 ;
    for ( i = row_start ; i < row_start + 3 ; i ++ )
    {
        for ( j = col_start ; j < col_start + 3 ; j ++ )
        {
            if ( matrix [ i ] [ j ] == n )
                return  0 ;
        }
    }
    return  1 ;
}
int  solve_sudoku ()
{
    int  row ;
    int  col ;
    // si todas las celdas están asignadas, el sudoku ya está resuelto
    // pasar por referencia porque number_unassigned cambiará los valores de row y col
    if ( number_unassigned ( & row ,  & col )  ==  0 )
        return  1 ;
    int  i ;
    // número entre 1 y 9
    for ( i = 1 ;i <= TAMANIO ; i ++ )
    {
        // si podemos asignar i a la celda o no
        // la celda es matriz [fila] [col]
        if (is_safe ( i ,  row ,  col ))
        {
            matrix [ row ] [ col ]  =  i ;
            // retroceso
            if ( solve_sudoku ())
                return  1 ;
            // si no podemos proceder con esta solución
            // reasignar la matriz de celda
            matrix [row ] [ col ] =0 ;
        }
    }

    return  0 ;
}

int main() {
    int valor;

    do {
        /*int valor;*/
        printf("ingrese como quiere ingresar los datos 1.manual 2.archivo 3.salir:");
        scanf("%d", &valor);

        switch (valor) {
            case 1:
                printf("Ingreso Manual\n");
                IngresoManual();
                print_sudoku();
                printf("\n");
                printf("solucion:\n");
                if (solve_sudoku())
                    print_sudoku ();
                else
                    printf ( "Sin solución \n " );
                /*number_unassigned(matrix[i][j],&row,&col);*/
                break;
            case 2:
                printf("Ingreso Archivo:\n");
                getmatrix();
                printMatrix();
                printf("\n");
                printf("solucion:\n");
                if (solve_sudoku())
                    printMatrix();
                break;
            case 3:
                printf("salir");
                break;

            default:
                printf("El valor esta fuera de rango");
        }
        //TODO: Replace getch function
        getch();
        return 0;

    }while(valor!=0);
}