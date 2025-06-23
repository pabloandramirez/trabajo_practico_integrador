# 📒 Agenda de Contactos en C

Este proyecto es una agenda digital de contactos desarrollada en lenguaje **C**, utilizando estructuras dinámicas (listas enlazadas), archivos para persistencia, y un menú interactivo por consola.

Permite:

- Agregar contactos
- Eliminar contactos
- Modificar datos
- Buscar por nombre
- Ordenar alfabéticamente
- Guardar automáticamente en un archivo (`agenda.txt`)

---

## 👥 Integrantes del Proyecto

| Nombre Completo     | Rol                      |
|---------------------|--------------------------|
| Lautaro Hofer       | Programador |
| Luciano Yague       | Programador |
| Pablo Ramírez       | Programador |

---

## 🧩 Archivos del Proyecto

| Archivo         | Descripción                                                |
|----------------|------------------------------------------------------------|
| `main.c`        | Función principal y menú de opciones                      |
| `funciones.c`   | Implementación de funciones: agregar, buscar, etc.        |
| `funciones.h`   | Definiciones de estructuras y prototipos de funciones     |
| `agenda.txt`    | Archivo que guarda los contactos en formato texto plano   |

---

## 🖥️ Instrucciones para compilar y ejecutar

### ✅ Requisitos

- Un compilador de C instalado:
  - **Linux**: GCC
  - **Windows**: [TDM-GCC](https://jmeubank.github.io/tdm-gcc/) o usar MinGW / WSL
- Editor de texto o IDE (Visual Studio Code, Dev-C++, Code::Blocks, etc.)

---

### En Linux y Windows

1. Abrí una terminal.
2. Navegá hasta la carpeta del proyecto.
3. Ejecutá:

```bash
gcc main.c funciones.c -o agenda
.\agenda
```

## ⚠️ Observaciones

- El programa funciona únicamente con caracteres en el alfabeto inglés (ASCII básico).  
  Por lo tanto, **no se muestran correctamente letras con tilde** (á, é, í, ó, ú, ñ, etc.) en la consola.
- Esto se debe a que muchas consolas en C no manejan correctamente codificaciones como UTF-8 por defecto.
- Para evitar errores, se recomienda **no usar tildes ni eñes** en nombres o correos.

## ⚠️ Aclaraciones del trabajo
- Durante el desarrollo del proyecto, los tres integrantes trabajamos de forma colaborativa en tiempo real mediante Discord, compartiendo pantalla y código simultáneamente. Esto permitió una revisión y construcción total del programa, pero como resultado, la mayoría de los commits fueron realizados desde un solo usuario.

- Por este motivo, los commits en el repositorio no reflejan de manera equitativa la participación real de todos los miembros. La distribución de tareas, decisiones de lógica y desarrollo del código fue compartida y pensada en conjunto.