#include <stdio.h>
#include <stdlib.h>


#define MAX_NOMBRE 50
#define MAX_TELEFONO 20
#define MAX_EMAIL 50

typedef struct {
    char nombre[MAX_NOMBRE];
    char telefono[MAX_TELEFONO];
    char email[MAX_EMAIL];
} Contacto;

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
        printf("5. Ordenar alfabeticamente\n");
        printf("6. Mostrar todos los contactos\n");
        printf("7. Guardar y salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpia el salto de línea después de scanf

    } while (opcion != 7);

    return 0;
}
