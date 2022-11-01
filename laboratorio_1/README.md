## RETO NO. 1: REGRESIÓN LINEAL MEDIANTE MÍNIMOS CUADRADOS



Mínimos cuadrados es una técnica de análisis numérico enmarcada dentro de la optimización matemática, en la que, dados un conjunto de pares ordenados —variable independiente, variable dependiente— y una familia de funciones, se intenta encontrar la función continua, dentro de dicha familia, que mejor se aproxime a los datos (un "mejor ajuste"), de acuerdo con el criterio de mínimo error cuadrático.

Cuando la función para aproximar los datos es una línea recta de la forma:

<p align="center">
  <img
    width="200"
    src="https://user-images.githubusercontent.com/82126880/196839691-a55083c6-0199-4e50-9191-8defb7f3df71.png"
  >

Donde m es la pendiente y b el intercepto con el eje Y, el método de mínimos cuadrados establece que:

<p align="center">
  <img
    width="500"
    src="https://user-images.githubusercontent.com/82126880/196840423-38cbd980-b62e-40cc-9917-a644b27078c0.png"
  >





Donde N es el número de parejas de datos x,y de la serie y r es el coeficiente de correlación de Pearson, el cual es una media estadística de la correlación entre dos conjuntos de datos. El valor de rangos del coeficiente es de 1 (correlación perfecta) y -1 (correlación negativa).
 
***Actividad 1.2:*** Modifique el programa anterior de la siguiente manera que cumpla las siguientes especificaciones:

|    | Tarea            | Descripción                                                                                                                                                                                                                                                                                                                                                                                        | Puntaje |
| -- | ---------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------- |
| 1. | Ingreso de datos | Agregue un menú para el ingreso de datos que tenga dos opciones: (1) Manual (2) Archivo.                                                                                                                                                                                                                                                                                                           | 10p     |
|    |                  | b. En (1) Manual, primero se debe ingresar el número N de parejas y luego cada pareja de datos en formato (x,y). Almacene la información en variables y arreglos de tipo double.                                                                                                                                                                                                                   | 10p     |
|    |                  | c. En (2) Archivo, se debe ingresar el nombre del archivo con extensión csv y una función debe leer el archivo y debe devolver el número de parejas N y el arreglo de tamaño Nx2 con los datos. Estas variables deben ser de tipo double. Tenga en cuenta que mediante este método no se conoce a priori la cantidad de puntos.                                                                    | 20p     |
| 2. | Procesamiento    | Genere una Función que permita calcular los parámetros de la regresión lineal por el método de mínimos cuadrados del conjunto de datos (x,y) ingresados: m, b y r. Los parámetros de entrada deben ser el número de datos (N), los vectores de datos (x,y) y las variables que almacenaran el resultado del cálculo. Dichos parámetros de estrada deben ser definidos como apuntadores de memoria. | 40p     |
| 3. | Salida           | Muestre en pantalla los parámetros de la regresión con cuatro cifras de precisión.                                                                                                                                                                                                                                                                                                                 | 10p     |
|    |                  | Desarrolle una función que permita guardar en el disco del computador los datos de entrada x,y así como el resultado de la operación. Esta función debe ser llamada desde la función principal.                                                                                                                                                                                                    | 10p     |
|    |                  |                                                                                                                                                                                                                                                                                                                                                                                            | 100p    |

El programa debe ser lo más modular posible (impleméntelo usando funciones y punteros), por lo tanto, esto hará parte de la evaluación de la implementación del programa.

Utilice el conjunto de datos de la Tabla 1 para probar el programa:
***ENTRADAS:***
<div align="center">

| ***X***  | ***Y***   | 
| -- | -- |
| 14 | 2  |                  
| 16 | 5  |                  
| 27 | 7  |                  
| 42 | 9  |                  
| 39 | 10 |                  
| 50 | 13 |                  
| 83 | 20 |                  

</div>
<p align = "center">
Tabla 1: datos de entrada del programa.
</p>

El día de la presentación se proporcionarán los datos para hacer la prueba tanto de ingreso manual, como mediante el archivo csv.


## RETO NO. 2: SUDOKU
***Actividad 2.1*** Implemente un programa que solucione SUDOKUS [2] y que cumpla con las siguientes especificaciones:

|    | Tarea            | Descripción                                                                                                                                                                                                                                                                                                          | Puntaje |
| -- | ---------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------- |
| 1. | Ingreso de datos | a. Agregue un menú para el ingreso de datos que tenga dos opciones: (1) Manual (2) Archivo.                                                                                                                                                                                                                          | 10p     |
|    |                  | b. En (1) Manual, el Sudoku a solucionar se va a ingresar como una matriz de 9x9 donde los números a encontrar van a tener el valor 0 en la matriz. Usted define la forma que considere más eficiente para hacer el ingreso. La matriz de los datos se debe almacenar en memoria para ser accedida mediante punteros | 10p     |
|    |                  | c. En (2) Archivo, se debe ingresar el nombre del archivo con extensión csv, el cual contiene la matriz de 9x9 donde los números a encontrar van a tener el valor 0 en la matriz. La matriz de los datos se debe almacenar en memoria para ser accedida mediante punteros.                                           | 20p     |
| 2. | Procesamiento    | d. Genere la función (o funciones) que permitan solucionar el Sudoku ingresado. La matriz de los datos se debe acceder mediante punteros.                                                                                                                                                                            | 40p     |
|    |                  | Considere situaciones en las que el programa no logre encontrar una solución.                                                                                                                                                                                                                                        | 5p      |
| 3. | Salida           | Muestre en pantalla el Sudoku solucionado y el tiempo que le llevó al programa encontrar la solución. ¿Se podrá determinar la complejidad del Sudoku tomando en cuenta el tiempo que el programa tarda en resolverlo?                                                                                                | 10p     |
|    |                  | Si no logró solucionarlo, también debe indicarlo en pantalla.                                                                                                                                                                                                                                                        | 5p      |
|    |                  |                                                                                                                                                                                                                                                                                                                      | 100p    |

El programa debe ser lo más modular posible (impleméntelo usando funciones y punteros), por lo tanto, esto hará parte de la evaluación de la implementación del programa.

Tenga en cuenta que los Sudokus tienen diferentes niveles de dificultad. En la figura 1 se muestra un Sudoku de nivel principiante y en la figura 2 se muestra un Sudoku de nivel intermedio.

<p align="center">
  <img 
    width="300"
    height="300"
    src="https://user-images.githubusercontent.com/82126880/195931208-94dca66b-cb5b-41ad-bd4a-0afac65d8e09.png"
  >
</p>
<p align = "center">
Figura 1: Sudoku nivel principiante.
</p>

<p align="center">
  <img 
    width="300"
    height="300"
    src="https://user-images.githubusercontent.com/82126880/195931321-a73201d2-0d3c-4c21-a195-0011c5e337d2.png"
  >
</p>
<p align = "center">
Figura 2: Sudoku nivel Intermedio.
</p>

El programa debe ser capaz de resolver Sudokus de estos dos niveles.


## RETO NO. 3: JUEGO DEL AHORCADO
***Actividad 3.1:*** Implemente un programa que permita jugar al AHORCADO y que cumpla con las siguientes especificaciones:

1. (10p) Se deben tener guardados en memoria los nombres de 5 películas.

2. (20p) Al iniciar el juego, el programa debe escoger de manera aleatoria cuál de los nombres va a utilizar y debe indicar el número de palabras, la cantidad de letras y mostrar las líneas correspondientes. Por ejemplo, si el título de la película es IRON MAN, el programa debe mostrar:

   >Dos palabras y 7 letras:
   >`_ _ _ _`  ` _ _ _`

3. (10p) EL programa pide una letra y el jugador la ingresa (por defecto en minúsculas, pero el programa debería poder manejar el ingreso en mayúsculas).

   > Ingrese una letra: A

4. (20p) El programa debe determinar si la letra pertenece al título. En caso afirmativo, se debe mostrar la letra en el lugar correspondiente:

   > `_ _ _ _`  ` _ A _`

5. (20p) En caso de que la letra no corresponda, se debe mostrar por partes el dibujo del ahorcado. En la figura 3 se muestra una sugerencia del dibujo del ahorcado completo (usted lo puede modificar).
<p align="center">
  <img 
    width="200"
    height="200"
    src="https://user-images.githubusercontent.com/82126880/195929936-01937a9c-be5c-4adc-be64-9a37187eecff.png"
  >
</p>
<p align = "center">
Figura 3. Dubujo del ahorcado completo.
</p>

- Tenga en cuenta que cada vez que el jugador falla, se debe mostrar una nueva parte del dibujo del ahorcado. El número
  total de fallos es 6 y cuando este número se complete, se debe mostrar el dibujo completo y un letrero indicando que
  perdió y debe preguntar si desea volver a jugar. En caso afirmativo, se debe escoger de forma aleatoria el nombre de
  otra película y empezar de nuevo el juego.

6. (20p) En caso de adivinar todas las letras, debe mostrar un mensaje indicando que ganó y debe preguntar si desea volver a jugar. En caso afirmativo, se debe escoger de forma aleatoria el nombre de otra película y empezar de nuevo el juego.

El programa debe ser lo más modular posible (impleméntelo usando funciones y punteros), por lo tanto, esto hará parte de la evaluación de la implementación del programa, además use su creatividad para que la parte visual y la experiencia de juego sea lo mejor posible.

* Para leer archivos de entrada, se deben llevar a la carpeta laboratorio_1/data.
* Los archivos csv exportados se encuentran en la carpeta `build` del projecto: /cmake-build-debug.