#ifndef FUNCIONES_H
#define FUNCIONES_H

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


void cargarAgendaDesdeArchivo(Nodo** lista);
void guardarAgendaEnArchivo(Nodo* lista);
void agregarContacto(Nodo** lista);
void eliminarContacto(Nodo** lista);
void modificarContacto(Nodo* lista);
void buscarContacto(Nodo* lista);
void ordenarContactosAlfabeticamente(Nodo** lista);

#endif
