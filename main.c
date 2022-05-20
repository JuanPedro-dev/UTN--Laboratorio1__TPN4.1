#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

/** 1.Hacer una función que reciba como parámetro una matriz de números enteros y permita que el
    usuario ingrese valores al mismo por teclado. La función debe cargar la matriz por completo. */
void cargarMatriz_3x3(int arreglo[][3])
{
    for (int i = 0; i < 3 ; i++)
    {
        for(int j = 0; j < 3 ; j++)
        {
            printf("Ingrese el valor para el elemento [%d][%d]: ", i,j);
            fflush(stdin);
            scanf("%d", &arreglo[i][j]);
        }
    }
}

/** 2. Hacer una función que reciba como parámetro una matriz de números enteros y la muestre
    por pantalla (en formato matricial). */
void mostrarMatriz_ix10(const int arreglo[][10], const int validosI, const int validosJ)

{
    for (int i = 0; i < validosI ; i++)
    {
        printf("|");
        for(int j = 0; j < validosJ ; j++)
        {
            printf("\t%d\t", arreglo[i][j]);
        }
        printf("|\n");
    }
}
/** 3. Hacer una función que reciba como parámetro una matriz de números enteros y que cargue la misma
    con números aleatorios (sin intervención del usuario). La función debe cargar la matriz por completo. */
void matrizRandom_ix10(int arreglo[][10], const int validosI, const int validosJ)
{
    for (int i = 0; i < validosI ; i++)
    {
        for(int j = 0; j < validosJ ; j++)
        {
            arreglo[i][j] = rand() %100;
        }
    }
}
/** 4.Hacer una función tipo int que sume el contenido total de una matriz de números enteros.  */
int sumatoriaMatriz(const int arreglo[][10], const int validosI, const int validosJ)
{
    int acumulador = 0;
    for(int i = 0; i< validosI; i++)
    {
        for(int j = 0; j < validosJ; j++)
        {
            acumulador += arreglo[i][j];
        }
    }
    return acumulador;
}
/** 5. Hacer una función tipo float que calcule el promedio de una matriz de números enteros. */
float promedioMatriz(const int arreglo[][10], const int validosI,const int validosJ)
{
    int cantidad = validosI * validosJ;

    if (validosI != 0)
    {
        float promedio = sumatoriaMatriz(arreglo, validosI, validosJ)* 1.0 / cantidad;
        return promedio;
    }
}

/** 6. Hacer una función que determine si un elemento se encuentra dentro de una matriz
    de números enteros. La función recibe la matriz y el dato a buscar*/
void buscarDato(const int arreglo[][10], const int validosI,const int validoJ,const int dato)
{
    int flag = 0;
    for(int i=0; i<validosI; i++)
    {
        for(int j=0 ; j< validoJ && flag == 0; j++)
        {
            if (arreglo[i][j] == dato)
            {
                printf("El dato se encuentra en la posición: [%d][%d].\n", i, j);
                flag = 1;
            }
        }
    }
    if (flag==0)
    {
        printf("El dato NO se encuentra en la matriz.\n");
    }
}

/** 7. Hacer una función que cargue un arreglo de palabras (strings). La función
    debe retornar cuantas palabras se cargaron.  */
int cargarStr(char arreglo[][30], int* validosI)
{
    int contador = 0;
    char opcion = 's';
    printf("validos: %d\n\n", validosI);
    while (opcion == 's' || opcion == 'S')
    {
        printf("Ingrese una palabra: ");
        fflush(stdin);
        scanf("%s", arreglo[validosI]);

        printf("¿Desea cargar otro? s/n: ");
        fflush(stdin);
        scanf("%c", &opcion);
        validosI++;
        contador++;
    }
    return contador;
}




int main()
{
    setlocale(LC_ALL,"");
    srand(time(NULL));
    /////////////////////////////////////////////   Ejercicio 1     ///////////////////////////////////////////////////////////
    int matrix_3x3[3][3];
    printf("                                Ejercicio 1 - Cargar matriz.\n\n");
//    cargarMatriz_3x3(matrix_3x3);

    /////////////////////////////////////////////   Ejercicio 2     ///////////////////////////////////////////////////////////
    printf("\n                                Ejercicio 2 - Mostrar matriz.\n\n");
    int matrix_10x10[10][10] =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {0,11,12}
    };

    mostrarMatriz_ix10(matrix_10x10, 4, 3);
    /////////////////////////////////////////////   Ejercicio 3     ///////////////////////////////////////////////////////////

    printf("\n                                Ejercicio 3 - Generar matriz random.\n\n");

    int matrix_6x6[6][6];
    matrizRandom_ix10(matrix_6x6, 6,6);
    mostrarMatriz_ix10(matrix_6x6, 6, 6);
    /////////////////////////////////////////////   Ejercicio 4     ///////////////////////////////////////////////////////////

    printf("\n                                Ejercicio 4 - Sumar elementos matriz.\n\n");
    printf(">> La sumatoria de valores de la matriz random es: %d\n", sumatoriaMatriz(matrix_6x6,6,6));
    /////////////////////////////////////////////   Ejercicio 5     ///////////////////////////////////////////////////////////

    printf("\n                                Ejercicio 5 - Promedio matriz.\n\n");
    printf(">> El promedio de valores de la matriz random es: %.2f\n", promedioMatriz(matrix_6x6,6,6));

    /////////////////////////////////////////////   Ejercicio 6     ///////////////////////////////////////////////////////////

    printf("\n                                Ejercicio 6 - Buscar dato en matriz.\n\n");

    /////////////////////////////////////////////   Ejercicio 7     ///////////////////////////////////////////////////////////

    printf("\n                                Ejercicio 7 - Buscar dato en matriz.\n\n");

    printf(">> Busquemos el valor 8 en la matriz random.\n");
    buscarDato(matrix_6x6,6,6,8);

    /////////////////////////////////////////////   Ejercicio 8     ///////////////////////////////////////////////////////////

    char matriz_palabras[30][30];
    int palabrasCargadas = 0;
    printf("\n                                Ejercicio 8 - Carga palabras, retorna cantidad .\n\n");
    cargarStr(matriz_palabras, palabrasCargadas);
    // mostrar matriz
//    for (int i = 0; i < palabrasCargadas ; i++)
//    {
//        printf("%s", matriz_palabras[i]);
//    }


    printf("\n\n\n                              Fin Programa!\n");
    system("pause");
    return 0;
}
