#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Estructuras

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
} persona;

typedef struct nodoArbol
{
    persona dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;

typedef struct nodo
{
    persona dato;
    struct nodo * sig;
} nodo;


/// Prototipado

nodoArbol* insertar (nodoArbol* arbolito, persona dato);
nodoArbol* inicNodoArbol();
nodoArbol* buscarEnArbol(nodoArbol* arbolito, int legajo);
nodoArbol* buscarEnArbolNombre(nodoArbol* arbolito, char nombre[]);
nodo* crearNodo (persona aux);
nodo* inicNodo ();
nodo* agregarPpio (nodo* lista, nodo* nuevoNodo);
nodo* cargarAlista (nodoArbol *arbolito, nodo* lista);

void preorder(nodoArbol* arbolito);
void inorder(nodoArbol *arbolito);
void recorrerLista (nodo* lista);
void recorrer(nodoArbol *arbolito);





int main()
{
    nodo* lista = inicNodo();
    nodoArbol* arbolito = inicNodoArbol();
    char letra = 's';
    char nombre[30];
    int legajo;
    persona dato;

    while(letra == 's')
    {

        printf("Ingresa un leg al arbol: ");
        fflush(stdin);
        scanf("%i", &dato.legajo);

        printf("Ingresa un ed al arbol: ");
        fflush(stdin);
        scanf("%i", &dato.edad);

        printf("Ingresa un n al arbol: ");
        fflush(stdin);
        gets(dato.nombre);

        arbolito = insertar(arbolito, dato);

        printf("Ingresa 's' para continuar: ");
        fflush(stdin);
        scanf("%c", &letra);

    }


    printf("MOSTRAR ARBOL: \n");
    inorder (arbolito);

    printf("\nMOSTRAR LISTA: \n");
    lista = cargarAlista(arbolito, lista);
    recorrerLista(lista);

    ///PUNTO CUATRO///


    printf("Ingrese el legajo a buscar: ");
    fflush(stdin);
    scanf("%i", &legajo);

    nodoArbol* rta = buscarEnArbol(arbolito, legajo);
    inorder(rta);

    printf("Ingrese el nombre a buscar: ");
    fflush(stdin);
    gets(nombre);

    rta = buscarEnArbolNombre(arbolito, nombre);
    inorder(rta);
}

nodoArbol* inicNodoArbol()
{
    return NULL;
}


nodoArbol* crearNodoArbol (persona dato)
{
    nodoArbol* aux = malloc(sizeof(nodoArbol));
    aux->dato= dato;
    aux->der = NULL;
    aux->izq = NULL;

    return aux;
}

nodoArbol* insertar (nodoArbol* arbolito, persona dato)
{

    if(!arbolito)
    {

        arbolito = crearNodoArbol(dato);
    }
    else
    {
        if(dato.legajo > arbolito->dato.legajo)
        {
            arbolito->der = insertar(arbolito->der, dato);

        }
        else
        {

            arbolito->izq = insertar(arbolito->izq, dato);
        }

    }

    return arbolito;
}

void preorder(nodoArbol* arbolito)
{

    if(arbolito != NULL)
    {

        printf("/ %d /", arbolito->dato.legajo);
        preorder(arbolito->izq);
        preorder(arbolito->der);
    }
}

void inorder(nodoArbol *arbolito)
{

    if(arbolito)
    {
//        inorder(arbolito->izq);
        printf("/ %d /", arbolito->dato.legajo);
//        inorder(arbolito->der);

    }
}

nodo* crearNodo (persona aux)
{

    nodo* auxN = (nodo*) malloc(sizeof(nodo));
    auxN->dato = aux;
    auxN->sig = NULL;

    return auxN;
}

nodo* inicNodo ()
{

    return NULL;
}

nodo* agregarPpio (nodo* lista, nodo* nuevoNodo)
{

    if(!lista)
    {

        lista = nuevoNodo;
    }
    else
    {

        nuevoNodo->sig = lista;
        lista = nuevoNodo;
    }


    return lista;
}

nodo* cargarAlista (nodoArbol* arbolito, nodo* lista)
{

    nodo* nuevoNodo = inicNodo();

    if(arbolito)
    {
        lista = cargarAlista(arbolito->izq, lista);

        nuevoNodo = crearNodo(arbolito->dato);
        lista = agregarPpio(lista, nuevoNodo);

        lista = cargarAlista(arbolito->der, lista);
    }

    return lista;
}

void recorrerLista (nodo* lista)
{

    if(lista)
    {
        printf(".........................\n");
        printf("Legajo: %d \n", lista->dato.legajo);
        printf("Edad: %d \n", lista->dato.edad);
        printf("Nombre: %s \n\n", lista->dato.nombre);

        lista = lista->sig;

        recorrerLista(lista);
    }
}



nodoArbol* buscarEnArbol(nodoArbol* arbolito, int legajo)
{

    nodoArbol* rta = arbolito;

    if(arbolito && arbolito->dato.legajo != legajo)
    {
        rta= buscarEnArbol(arbolito->izq, legajo);
        if(!rta)
            rta= buscarEnArbol(arbolito->der, legajo);
    }

    return rta;
}

nodoArbol* buscarEnArbolNombre(nodoArbol* arbolito, char nombre[])
{

    nodoArbol* rta = inicNodoArbol();

    if(arbolito)
    {
        if(strcmp(arbolito->dato.nombre, nombre) == 0)
            rta = arbolito;
        else
        {
                rta = buscarEnArbolNombre(arbolito, nombre);
                rta = buscarEnArbolNombre(arbolito, nombre);
        }
    }

    return rta;
}


