#include <stdio.h>
#include <stdlib.h>
#include "funciones.h" 

int main() {
    Nodo* listaContactos = NULL;
    int opcion;

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
        getchar();

        switch(opcion) {
            case 1:
                agregarContacto(&listaContactos);
                break;
            case 2:
                eliminarContacto(&listaContactos);
                break;
            case 3:
                modificarContacto(listaContactos);
                break;
            case 4:
                buscarContacto(listaContactos);
                break;
            case 5:
                ordenarContactosAlfabeticamente(&listaContactos);
                break;
            case 6:
                mostrarContactos(listaContactos);
                break;
            case 7:
                guardarAgendaEnArchivo(listaContactos);
                liberarMemoria(listaContactos);
                printf("Agenda guardada. Saliendo...\n");
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
        }

    } while (opcion != 7);

    return 0;
}
