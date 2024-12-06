#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar información de un alumno
struct Alumno {
char nombre[50];      // Nombre del alumno
float promedio;       // Promedio del alumno
char carrera[50];     // Carrera del alumno
};

// Declaración de funciones
void mostrarMenu();
void crearArchivo();
void abrirArchivo();
void renombrarArchivo();
void buscarAlumno();
void agregarRegistro();
int archivoExiste(const char *nombreArchivo);
void mostrarRegistros(const char *nombreArchivo);

int main() {
    int opcion;

    do {
mostrarMenu(); // Muestra el menú principal
printf("Selecciona una opcion: ");

// Validar entrada del usuario
if (scanf("%d", &opcion) != 1) {
while (getchar() != '\n'); // Limpia el buffer en caso de entrada inválida
printf("Opcion no valida, vuelve a intentarlo\n");
            continue;
        }

// Ejecutar la opción seleccionada
switch (opcion) {
case 1: crearArchivo(); break;          // Crear un archivo
case 2: abrirArchivo(); break;          // Ver registros de un archivo
case 3: renombrarArchivo(); break;      // Renombrar archivo
case 4: buscarAlumno(); break;          // Buscar un alumno por nombre
case 5: agregarRegistro(); break;       // Agregar un registro al archivo
case 6: printf("Saliendo...\n"); break; // Salir del programa
default: printf("Opcion no valida.\n");
        }
    } while (opcion != 6); // El programa sigue corriendo hasta que se elige salir

    return 0;
}

// Muestra el menú principal
void mostrarMenu() {
printf("\n---MENU---\n");
printf("1. Crear un archivo\n");
printf("2. Ver registros de un archivo\n");
printf("3. Renombrar archivo\n");
printf("4. Buscar un alumno\n");
printf("5. Agregar un registro\n");
printf("6. Salir\n");
}

// Crea un archivo vacío con el nombre proporcionado por el usuario
void crearArchivo() {
char nombre[100];
printf("Introduce el nombre del archivo a crear: ");
scanf("%99s", nombre); // Leer el nombre del archivo

FILE *archivo = fopen(nombre, "w"); // Crear archivo en modo escritura
if (archivo == NULL) { // Verificar si hubo un error
perror("Error al crear archivo");
return;
    }
fclose(archivo); // Cerrar el archivo después de crearlo
printf("Archivo '%s' creado\n", nombre);
}

// Abre un archivo y muestra sus registros
void abrirArchivo() {
char nombre[100];
printf("Introduce el nombre del archivo a abrir: ");
scanf("%99s", nombre);

if (!archivoExiste(nombre)) { // Verificar si el archivo existe
printf("El archivo no existe\n");
return;
    }

mostrarRegistros(nombre); // Mostrar los registros del archivo
}

// Renombra un archivo existente
void renombrarArchivo() {
char nombreOriginal[100], nombreNuevo[100];
printf("Introduce el nombre del archivo a renombrar: ");
scanf("%99s", nombreOriginal);

if (!archivoExiste(nombreOriginal)) { // Verificar si el archivo existe
printf("El archivo no existe\n");
return;
    }

printf("Introduce el nuevo nombre: ");
scanf("%99s", nombreNuevo);

if (rename(nombreOriginal, nombreNuevo) == 0) { // Renombrar archivo
printf("Archivo renombrado a '%s'.\n", nombreNuevo);
} else {
perror("Error al renombrar el archivo");
    }
}

// Busca un alumno por nombre dentro de un archivo
void buscarAlumno() {
char nombreArchivo[100], nombreBuscado[50];
printf("Introduce el nombre del archivo: ");
scanf("%99s", nombreArchivo);

if (!archivoExiste(nombreArchivo)) { // Verificar si el archivo existe
printf("El archivo no existe\n");
return;
    }

printf("Introduce el nombre del alumno a buscar: ");
scanf("%49s", nombreBuscado);

FILE *archivo = fopen(nombreArchivo, "r"); // Abrir archivo en modo lectura
struct Alumno alumno;
int encontrado = 0;

// Leer registros y buscar coincidencias
while (fscanf(archivo, "%49s %f %49s", alumno.nombre, &alumno.promedio, alumno.carrera) == 3) {
if (strstr(alumno.nombre, nombreBuscado)) { // Comparar con el nombre buscado
printf("Alumno encontrado: %s, Promedio: %.2f, Carrera: %s\n", alumno.nombre, alumno.promedio, alumno.carrera);
            encontrado = 1;
            break;
        }
    }

fclose(archivo); // Cerrar archivo
if (!encontrado) {
printf("No se encontro al alumno '%s'\n", nombreBuscado);
    }
}

// Agrega un nuevo registro de alumno a un archivo
void agregarRegistro() {
char nombreArchivo[100];
printf("Introduce el nombre del archivo: ");
scanf("%99s", nombreArchivo);

if (!archivoExiste(nombreArchivo)) { // Verificar si el archivo existe
printf("El archivo no existe.\n");
return;
    }

FILE *archivo = fopen(nombreArchivo, "a"); // Abrir archivo en modo añadir
struct Alumno alumno;
printf("Introduce el nombre del alumno: ");
scanf("%49s", alumno.nombre);
printf("Introduce el promedio: ");
scanf("%f", &alumno.promedio);
printf("Introduce la carrera: ");
scanf("%49s", alumno.carrera);

// Escribir el nuevo registro en el archivo
fprintf(archivo, "%s %.2f %s\n", alumno.nombre, alumno.promedio, alumno.carrera);
fclose(archivo); // Cerrar archivo
printf("Registro agregado con exito\n");
}

// Comprueba si un archivo existe
int archivoExiste(const char *nombreArchivo) {
FILE *archivo = fopen(nombreArchivo, "r"); // Intentar abrir en modo lectura
if (archivo == NULL) return 0; // Retorna 0 si no existe
fclose(archivo); // Cerrar el archivo si existe
return 1; // Retorna 1 si existe
}

// Muestra todos los registros de un archivo
void mostrarRegistros(const char *nombreArchivo) {
FILE *archivo = fopen(nombreArchivo, "r"); // Abrir archivo en modo lectura
struct Alumno alumno;

printf("Registros en el archivo:\n");
// Leer y mostrar cada registro
while (fscanf(archivo, "%49s %f %49s", alumno.nombre, &alumno.promedio, alumno.carrera) == 3) {
printf("Nombre: %s, Promedio: %.2f, Carrera: %s\n", alumno.nombre, alumno.promedio, alumno.carrera);
    }

fclose(archivo); // Cerrar archivo
}
