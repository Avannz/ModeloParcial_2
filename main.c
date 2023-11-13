#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


typedef struct
{
    char nombreYapellido [30];
    int edad;
    int dni;
} personaje;

typedef struct
{
    personaje dato;
    struct nodoLista* anterior;
    struct nodoLista* siguiente;
} nodoLista;

typedef struct
{
    char nombreEspecie[20]; //vampiro, hombre lobo, hada, medium, cambia formas, humano
    int rankPeligrosidad; //1 el m�s peligroso, 6 el menos peligroso
    float promedioEdad; // 0
    nodoLista* personajes; //lista de personajes que pertencen a esta especie
} especie;

typedef struct
{
    especie aux[30];
    struct nodoArbol *der;
    struct nodoArbol *izq;
    
}nodoArbol;


/// PROTOTIPADO ///

void mostrar_lista(nodoLista* lista);
int agregar_contenido(especie arreglo[], int dimension, int validos);
int buscar_posicion(especie arreglo[], int dimension, char nuevaEspecie[]);
int buscar_rango(especie arreglo[], int dimension, int rango);
int agregar_especie(especie arreglo[], int validos, char nuevaEspecie[], int rango);
nodoLista* iniciar_nodo();
nodoLista* crear_nodo(personaje dato);
nodoLista* agregar_principio(nodoLista* lista, nodoLista* nuevoNodo);


int main()
{

    especie arreglo[6];
    int validos = 0;
    char especie[30];
    int pos = -1;

    validos = agregar_contenido(arreglo, 6, validos);

    printf("Que especie desea mostrar?: ");
    fflush(stdin);
    gets(&especie);

    pos = buscar_posicion(arreglo, 6, especie);

    mostrar_especie(arreglo, pos);


}


nodoLista* iniciar_nodo()
{

    return NULL;
}

nodoLista* crear_nodo(personaje dato)
{

    nodoLista*  aux = (nodoLista*)malloc(sizeof(nodoLista));

    aux->dato = dato;
    aux->anterior = NULL;
    aux->siguiente = NULL;

    return aux;
}

nodoLista* agregar_principio(nodoLista* lista, nodoLista* nuevoNodo)
{

    nuevoNodo->siguiente = lista;

    if(lista)
    {

        lista->anterior = nuevoNodo;
    }

    return nuevoNodo;
}

void mostrar_lista(nodoLista* lista)
{

    if(lista)
    {

        printf("\nNombre: %s", lista->dato.nombreYapellido);
        printf("\nEdad: %i", lista->dato.edad);
        printf("\nDni: %i", lista->dato.dni);

        mostrar_lista(lista->siguiente);
    }
}

int buscar_posicion(especie arreglo[], int dimension, char nuevaEspecie[])
{

    int pos = -1;
    int i = 0;

    while(i < dimension && pos == -1)
    {

        if(strcmp(arreglo[i].nombreEspecie, nuevaEspecie) == 0)
        {

            pos = i;
        }

        i++;
    }

    return pos;
}

int buscar_rango(especie arreglo[], int dimension, int rango)
{

    int flag = 0;
    int i = 0;

    while(i < dimension && flag == 0)
    {

        if(arreglo[i].rankPeligrosidad == rango)
        {

            flag = 1;
        }

        i++;
    }

    return flag;
}

int agregar_especie(especie arreglo[], int validos, char nuevaEspecie[], int rango)
{
    int flag = 0;

    strcpy(arreglo[validos].nombreEspecie, nuevaEspecie);
    arreglo[validos].rankPeligrosidad = rango;
    arreglo[validos].promedioEdad = 0;

    validos++;


    return validos;
}

int agregar_contenido(especie arreglo[], int dimension, int validos)
{

    char especie[30];
    char letra2 = 's';
    char letra = 's';
    int flag = 1;
    int rango = 0;

    personaje aux;
    while(letra == 's')
    {


        printf("Ingresa una especie: ");
        fflush(stdin);
        gets(&especie);

        int pos = buscar_posicion(arreglo, 6, especie);

        flag = 1;
        letra = 's';
        letra2 = 's';

        while(flag == 1)
        {

            printf("\n * Por favor, ingresar un rango que no este en uso...\n");

            printf("Ingresa un rango a la especie: ");
            fflush(stdin);
            scanf("%i", &rango);

            flag = buscar_rango(arreglo,6, rango);

        }

        if(pos == -1)
        {

            validos = agregar_especie(arreglo, validos, especie, rango);
            pos = validos-1;
            arreglo[pos].personajes = iniciar_nodo();
        }

        while(letra2 == 's')
        {

            system("cls");

            printf("Ingresale un nombre: ");
            fflush(stdin);
            gets(&aux.nombreYapellido);

            printf("Ingresa la edad del personaje: ");
            fflush(stdin);
            scanf("%i", &aux.edad);

            printf("Ingresa el DNI: ");
            fflush(stdin);
            scanf("%i", &aux.dni);

            nodoLista* nuevoNodo = crear_nodo(aux);

            arreglo[pos].personajes = agregar_principio(arreglo[pos].personajes, nuevoNodo);

            printf("Ingresa 's' para seguir agregando personajes a esta especie: ");
            fflush(stdin);
            scanf("%c", &letra2);
        }

        printf("Ingresa 's' para agregar otra especie: ");
        fflush(stdin);
        scanf("%c", &letra);
    }
    return validos;
}

void mostrar_especie(especie arreglo[], int pos)
{

    printf("\nNombre de la especie: %s", arreglo[pos].nombreEspecie);
    printf("\nRank #%i", arreglo[pos].rankPeligrosidad);
    printf("\nEdad promedio: %.2f", arreglo[pos].promedioEdad);

    mostrar_lista(arreglo[pos].personajes);

}

nodoArbol* iniciar_arbol()
{
    
    return NULL;
}

nodoArbo* insertar (nodoArbol* arbolito, int pos)
{
    
    if(!arbolito)
    {
        
        arbolito->dato = aux;
    }
    else if(arbolito-> < personaje.edad)
    {
        
        arbolito->izq = insertar(arbolito->izq, aux);
    }
    else
    {
        
        arbolito->der = insertar(arbolito->der, aux);
    }
    
    return arbolito;
}


    return cantNodos;
}

nodoArbol* nodo_mas_derecha (nodoArbol* arbolito)
{
    nodoArbol* aux = inicNodoArbol();

    if(arbolito->der)
    {

        aux =   nodo_mas_derecha(arbolito->der);
    }

    return aux;
}

nodoArbol* nodo_mas_izquierda (nodoArbol* arbolito)
{

    nodoArbol* aux = inicNodoArbol();

    if(arbolito->izq)
    {

        aux = nodo_mas_izquierda(arbolito->izq);
    }

    return aux;
}

nodoArbol * borrar_arbol (nodoArbol * arbolito, int dato)
{

    if(arbolito)
    {
        if(dato == arbolito->dato.legajo)
        {

            if(arbolito->izq != NULL)
            {
                nodoArbol* masDer = nodo_mas_derecha(arbolito->izq);
                arbolito->dato = masDer->dato;
                arbolito->izq = borrar_arbol(arbolito->izq, masDer->dato.legajo);
            }
            else if (arbolito->izq != NULL){

                nodoArbol* masIzq = nodo_mas_izquierda(arbolito->der);
                arbolito->dato = masIzq->dato;
                arbolito->der = borrar_arbol(arbolito->der, masIzq->dato.legajo);

            }
            else
            {
                free(arbolito);
                arbolito = NULL;
            }
        }

        if(dato > arbolito->dato.legajo)
        {
            arbolito->der = borrar_arbol(arbolito->der,dato);
        }

        if(dato < arbolito->dato.legajo)
        {
            arbolito->izq = borrar_arbol(arbolito->izq,dato);
        }
    }
    if(arbolito == NULL)
    {

    }

    return arbolito;
}
