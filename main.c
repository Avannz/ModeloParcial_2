#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Estructuras

typedef struct {
     int legajo;
     char nombre[20];
     int edad;
}persona;

typedef struct nodoArbol {
     persona dato;
     struct nodoArbol * izq;
     struct nodoArbol * der;
}nodoArbol;


/// Prototipado

nodoArbol* insertar (nodoArbol* arbolito, persona dato);
nodoArbol* inicNodoArbol();
void preorder(nodoArbol* arbolito);





int main()
{

    nodoArbol* arbolito = inicNodoArbol();
    char letra = 's';
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

    preorder(arbolito);

    return 0;
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


