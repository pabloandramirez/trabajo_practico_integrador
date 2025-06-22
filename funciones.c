#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


void cargarAgendaDesdeArchivo(Nodo** lista) {
    FILE* archivo = fopen("agenda.txt", "r");
    if (!archivo) {
        return; 
    }

    Contacto c;
    while (fscanf(archivo, "%49[^;];%19[^;];%49[^\n]\n", c.nombre, c.telefono, c.email) == 3) {
        Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
        nuevo->contacto = c;
        nuevo->siguiente = *lista;
        *lista = nuevo;
    }

    fclose(archivo);
    printf("Agenda cargada desde archivo.\n");
}


void guardarAgendaEnArchivo(Nodo* lista) {
    FILE* archivo = fopen("agenda.txt", "w");
    if (!archivo) {
        printf("Error al guardar el archivo.\n");
        return;
    }

    while (lista != NULL) {
        fprintf(archivo, "%s;%s;%s\n", lista->contacto.nombre, lista->contacto.telefono, lista->contacto.email);
        lista = lista->siguiente;
    }

    fclose(archivo);
}


void agregarContacto(Nodo** lista) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo) {
        printf("Error al asignar memoria.\n");
        return;
    }

    printf("Nombre: ");
    fgets(nuevo->contacto.nombre, MAX_NOMBRE, stdin);
    nuevo->contacto.nombre[strcspn(nuevo->contacto.nombre, "\n")] = '\0';

    printf("Telefono: ");
    fgets(nuevo->contacto.telefono, MAX_TELEFONO, stdin);
    nuevo->contacto.telefono[strcspn(nuevo->contacto.telefono, "\n")] = '\0';

    printf("Email: ");
    fgets(nuevo->contacto.email, MAX_EMAIL, stdin);
    nuevo->contacto.email[strcspn(nuevo->contacto.email, "\n")] = '\0';

    nuevo->siguiente = *lista;
    *lista = nuevo;

    printf("Contacto agregado.\n");
}


void eliminarContacto(Nodo** lista) {
    char nombre[MAX_NOMBRE];
    printf("Nombre del contacto a eliminar: ");
    fgets(nombre, MAX_NOMBRE, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    Nodo* actual = *lista;
    Nodo* anterior = NULL;

    while (actual != NULL && strcmp(actual->contacto.nombre, nombre) != 0) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("Contacto no encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        *lista = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
    printf("Contacto eliminado.\n");
}


void modificarContacto(Nodo* lista) {
    char nombre[MAX_NOMBRE];
    printf("Nombre del contacto a modificar: ");
    fgets(nombre, MAX_NOMBRE, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    while (lista != NULL) {
        if (strcmp(lista->contacto.nombre, nombre) == 0) {
            printf("Nuevo telefono: ");
            fgets(lista->contacto.telefono, MAX_TELEFONO, stdin);
            lista->contacto.telefono[strcspn(lista->contacto.telefono, "\n")] = '\0';

            printf("Nuevo email: ");
            fgets(lista->contacto.email, MAX_EMAIL, stdin);
            lista->contacto.email[strcspn(lista->contacto.email, "\n")] = '\0';

            printf("Contacto modificado.\n");
            return;
        }
        lista = lista->siguiente;
    }

    printf("Contacto no encontrado.\n");
}


void buscarContacto(Nodo* lista) {
    char nombre[MAX_NOMBRE];
    printf("Nombre del contacto a buscar: ");
    fgets(nombre, MAX_NOMBRE, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    while (lista != NULL) {
        if (strcmp(lista->contacto.nombre, nombre) == 0) {
            printf("Nombre: %s\n", lista->contacto.nombre);
            printf("Telefono: %s\n", lista->contacto.telefono);
            printf("Email: %s\n", lista->contacto.email);
            return;
        }
        lista = lista->siguiente;
    }

    printf("Contacto no encontrado.\n");
}


void ordenarContactosAlfabeticamente(Nodo** lista) {
    if (*lista == NULL || (*lista)->siguiente == NULL)
        return;

    int cambiado;
    do {
        cambiado = 0;
        Nodo* actual = *lista;
        Nodo* anterior = NULL;
        Nodo* siguiente = NULL;

        while (actual->siguiente != NULL) {
            siguiente = actual->siguiente;
            if (strcmp(actual->contacto.nombre, siguiente->contacto.nombre) > 0) {
                
                Contacto temp = actual->contacto;
                actual->contacto = siguiente->contacto;
                siguiente->contacto = temp;
                cambiado = 1;
            }
            actual = actual->siguiente;
        }
    } while (cambiado);

    printf("Contactos ordenados alfabeticamente.\n");
}


void mostrarContactos(Nodo* lista) {
    if (lista == NULL) {
        printf("Agenda vacía.\n");
        return;
    }

    printf("\n--- Lista de Contactos ---\n");
    while (lista != NULL) {
        printf("Nombre: %s\n", lista->contacto.nombre);
        printf("Teléfono: %s\n", lista->contacto.telefono);
        printf("Email: %s\n", lista->contacto.email);
        printf("--------------------------\n");
        lista = lista->siguiente;
    }
}


void liberarMemoria(Nodo* lista) {
    Nodo* actual;
    while (lista != NULL) {
        actual = lista;
        lista = lista->siguiente;
        free(actual);
    }
}