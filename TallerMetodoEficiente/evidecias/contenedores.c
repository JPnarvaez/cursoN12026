

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONTENEDORES 30

void registrarPesos(int pesos[], int *cantidad);
void generarPesosAleatorios(int pesos[], int *cantidad);
void mostrarPesos(int pesos[], int cantidad);

void quickSort(int arreglo[], int inicio, int fin);
int particion(int arreglo[], int inicio, int fin);

int busquedaBinaria(int arreglo[], int cantidad, int valor);

int main()
{
int pesos[MAX_CONTENEDORES];
int cantidad = 0;
int opcion;
int ordenado = 0;

```
int pesoBuscar;
int posicion;

srand(time(NULL));

do
{
    printf("\n====================================\n");
    printf("  SISTEMA DE CONTENEDORES PORTUARIOS\n");
    printf("====================================\n");
    printf("1. Registrar pesos manualmente\n");
    printf("2. Generar pesos aleatorios\n");
    printf("3. Mostrar pesos\n");
    printf("4. Ordenar pesos (Quick Sort)\n");
    printf("5. Buscar peso (Busqueda Binaria)\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    switch(opcion)
    {
        case 1:

            registrarPesos(pesos, &cantidad);
            ordenado = 0;

            break;

        case 2:

            generarPesosAleatorios(pesos, &cantidad);
            ordenado = 0;

            break;

        case 3:

            mostrarPesos(pesos, cantidad);

            break;

        case 4:

            if(cantidad == 0)
            {
                printf("\nNo existen datos para ordenar.\n");
            }
            else
            {
                quickSort(pesos, 0, cantidad - 1);
                ordenado = 1;

                printf("\nArreglo ordenado correctamente.\n");
            }

            break;

        case 5:

            if(cantidad == 0)
            {
                printf("\nNo existen datos registrados.\n");
            }
            else if(ordenado == 0)
            {
                printf("\nDebe ordenar primero el arreglo.\n");
            }
            else
            {
                printf("\nIngrese el peso a buscar: ");
                scanf("%d", &pesoBuscar);

                posicion = busquedaBinaria(
                                pesos,
                                cantidad,
                                pesoBuscar
                            );

                if(posicion != -1)
                {
                    printf("\nPeso encontrado en la posicion %d\n",
                           posicion);
                }
                else
                {
                    printf("\nPeso no encontrado.\n");
                }
            }

            break;

        case 6:

            printf("\nPrograma finalizado.\n");

            break;

        default:

            printf("\nOpcion invalida.\n");
    }

} while(opcion != 6);

return 0;
```

}

void registrarPesos(int pesos[], int *cantidad)
{
int i;

```
printf("\nCantidad de contenedores (1 - 30): ");
scanf("%d", cantidad);

if(*cantidad < 1 || *cantidad > MAX_CONTENEDORES)
{
    printf("\nCantidad invalida.\n");
    *cantidad = 0;
    return;
}

for(i = 0; i < *cantidad; i++)
{
    printf("Peso del contenedor %d (kg): ", i + 1);
    scanf("%d", &pesos[i]);
}

printf("\nDatos registrados correctamente.\n");
```

}

void generarPesosAleatorios(int pesos[], int *cantidad)
{
int i;

```
printf("\nCantidad de contenedores (1 - 30): ");
scanf("%d", cantidad);

if(*cantidad < 1 || *cantidad > MAX_CONTENEDORES)
{
    printf("\nCantidad invalida.\n");
    *cantidad = 0;
    return;
}

for(i = 0; i < *cantidad; i++)
{
    pesos[i] = 1000 + rand() % 30001;
}

printf("\nPesos generados correctamente.\n");
```

}

void mostrarPesos(int pesos[], int cantidad)
{
int i;

```
if(cantidad == 0)
{
    printf("\nNo hay contenedores registrados.\n");
    return;
}

printf("\nLISTA DE PESOS\n");

for(i = 0; i < cantidad; i++)
{
    printf("Contenedor %d: %d kg\n",
           i + 1,
           pesos[i]);
}
```

}

int particion(int arreglo[], int inicio, int fin)
{
int pivote = arreglo[fin];
int i = inicio - 1;
int j;
int temp;

```
for(j = inicio; j < fin; j++)
{
    if(arreglo[j] <= pivote)
    {
        i++;

        temp = arreglo[i];
        arreglo[i] = arreglo[j];
        arreglo[j] = temp;
    }
}

temp = arreglo[i + 1];
arreglo[i + 1] = arreglo[fin];
arreglo[fin] = temp;

return i + 1;
```

}

void quickSort(int arreglo[], int inicio, int fin)
{
int pi;

```
if(inicio < fin)
{
    pi = particion(arreglo, inicio, fin);

    quickSort(arreglo, inicio, pi - 1);
    quickSort(arreglo, pi + 1, fin);
}
```

}

int busquedaBinaria(int arreglo[], int cantidad, int valor)
{
int izquierda = 0;
int derecha = cantidad - 1;
int medio;

```
while(izquierda <= derecha)
{
    medio = (izquierda + derecha) / 2;

    if(arreglo[medio] == valor)
    {
        return medio;
    }

    if(arreglo[medio] < valor)
    {
        izquierda = medio + 1;
    }
    else
    {
        derecha = medio - 1;
    }
}

return -1;
```

}
