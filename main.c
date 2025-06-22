#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición del struct Contacto
typedef struct {
    char nombre[50];
    char telefono[20];
    char email[50];
} Contacto;

// Nodo para lista dinámica
typedef struct Nodo {
    Contacto contacto;
    struct Nodo* siguiente;
} Nodo;


int main() {
    Nodo* listaContactos = NULL;
    int opcion;

    // Cargar contactos desde archivo al iniciar
    cargarAgendaDesdeArchivo(&listaContactos);

    do {
        printf("\n=== AGENDA DE CONTACTOS ===\n");
        printf("1. Agregar contacto\n");
        printf("2. Eliminar contacto\n");
        printf("3. Modificar contacto\n");
        printf("4. Buscar contacto\n");
        printf("5. Ordenar alfabéticamente\n");
        printf("6. Mostrar todos los contactos\n");
        printf("7. Guardar y salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpia buffer del salto de línea

    } while (opcion != 7);

    return 0;
}
