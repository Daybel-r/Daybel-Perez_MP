#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Alumno {
    char nombre[50];
    float promedio;
    char carrera[50];
};

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
        mostrarMenu();
        printf("Selecciona una opcion: ");
        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n'); 
            printf("Opcion no valida, vuelve a intentarlo\n");
            continue;
        }

        switch (opcion) {
            case 1: crearArchivo(); break;
            case 2: abrirArchivo(); break;
            case 3: renombrarArchivo(); break;
            case 4: buscarAlumno(); break;
            case 5: agregarRegistro(); break;
            case 6: printf("Saliendo...\n"); break;
            default: printf("Opcion no valida.\n");
        }
    } while (opcion != 6);

    return 0;
}

void mostrarMenu() {
    printf("\n---MENU---\n");
    printf("1. Crear un archivo\n");
    printf("2. Ver registros de un archivo\n");
    printf("3. Renombrar archivo\n");
    printf("4. Buscar un alumno\n");
    printf("5. Agregar un registro\n");
    printf("6. Salir\n");
}

void crearArchivo() {
    char nombre[100];
    printf("Introduce el nombre del archivo a crear: ");
    scanf("%99s", nombre);

    FILE *archivo = fopen(nombre, "w");
    if (archivo == NULL) {
        perror("Error al crear archivo");
        return;
    }
    fclose(archivo);
    printf("Archivo '%s' creado\n", nombre);
}

void abrirArchivo() {
    char nombre[100];
    printf("Introduce el nombre del archivo a abrir: ");
    scanf("%99s", nombre);

    if (!archivoExiste(nombre)) {
        printf("El archivo no existe\n");
        return;
    }

    mostrarRegistros(nombre);
}

void renombrarArchivo() {
    char nombreOriginal[100], nombreNuevo[100];
    printf("Introduce el nombre del archivo a renombrar: ");
    scanf("%99s", nombreOriginal);

    if (!archivoExiste(nombreOriginal)) {
        printf("El archivo no existe\n");
        return;
    }

    printf("Introduce el nuevo nombre: ");
    scanf("%99s", nombreNuevo);

    if (rename(nombreOriginal, nombreNuevo) == 0) {
        printf("Archivo renombrado a '%s'.\n", nombreNuevo);
    } else {
        perror("Error al renombrar el archivo");
    }
}

void buscarAlumno() {
    char nombreArchivo[100], nombreBuscado[50];
    printf("Introduce el nombre del archivo: ");
    scanf("%99s", nombreArchivo);

    if (!archivoExiste(nombreArchivo)) {
        printf("El archivo no existe\n");
        return;
    }

    printf("Introduce el nombre del alumno a buscar: ");
    scanf("%49s", nombreBuscado);

    FILE *archivo = fopen(nombreArchivo, "r");
    struct Alumno alumno;
    int encontrado = 0;

    while (fscanf(archivo, "%49s %f %49s", alumno.nombre, &alumno.promedio, alumno.carrera) == 3) {
        if (strstr(alumno.nombre, nombreBuscado)) {
            printf("Alumno encontrado: %s, Promedio: %.2f, Carrera: %s\n", alumno.nombre, alumno.promedio, alumno.carrera);
            encontrado = 1;
            break;
        }
    }

    fclose(archivo);
    if (!encontrado) {
        printf("No se encontro al alumno '%s'\n", nombreBuscado);
    }
}

void agregarRegistro() {
    char nombreArchivo[100];
    printf("Introduce el nombre del archivo: ");
    scanf("%99s", nombreArchivo);

    if (!archivoExiste(nombreArchivo)) {
        printf("El archivo no existe.\n");
        return;
    }

    FILE *archivo = fopen(nombreArchivo, "a");
    struct Alumno alumno;
    printf("Introduce el nombre del alumno: ");
    scanf("%49s", alumno.nombre);
    printf("Introduce el promedio: ");
    scanf("%f", &alumno.promedio);
    printf("Introduce la carrera: ");
    scanf("%49s", alumno.carrera);

    fprintf(archivo, "%s %.2f %s\n", alumno.nombre, alumno.promedio, alumno.carrera);
    fclose(archivo);
    printf("Registro agregado con exito\n");
}

int archivoExiste(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) return 0;
    fclose(archivo);
    return 1;
}

void mostrarRegistros(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");
    struct Alumno alumno;

    printf("Registros en el archivo:\n");
    while (fscanf(archivo, "%49s %f %49s", alumno.nombre, &alumno.promedio, alumno.carrera) == 3) {
        printf("Nombre: %s, Promedio: %.2f, Carrera: %s\n", alumno.nombre, alumno.promedio, alumno.carrera);
    }

    fclose(archivo);
}
