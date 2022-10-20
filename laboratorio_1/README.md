## RETO NO. 1: REGRESIÓN LINEAL MEDIANTE MÍNIMOS CUADRADOS
***Actividad 1.2:***  Modifique el programa anterior de la siguiente manera que cumpla las siguientes especificaciones:

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

- El día de la presentación se proporcionarán los datos para hacer la prueba tanto de ingreso manual, como mediante el archivo csv.
- Para leer archivos de entrada, se deben llevar a la carpeta laboratorio_1/data.
- Los csv exportados se encuentran en la carpeta build del projecto: /cmake-build-debug.
