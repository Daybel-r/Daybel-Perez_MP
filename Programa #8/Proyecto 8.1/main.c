#include <stdio.h>
#include <string.h>

/* Estructura -1.
El programa muestra la manera en que se declara una estructura, asi como la
forma en que se tiene acceso a los campos de las variables de tipo estructura
tanto para asignacion de valores como la lectura y estructura. */

struct alumno                           /* Declaracion de la estructura. */
{
    int matricula;
    char nombre[20];
    char carrera[20];                  /* Campos de la estructura. */
    float promedio;
    char direccion[20];
};            /* Obserca que la declaracion de una estructura termina con un punto y
                coma. */

void main(void)
{/* Observa que las variables de tipo estructura se declaran como cualquer otra
    variable. a1, a2, a3 son variables de tipo  estructura de alumno. */
    struct alumno a1 = {120, "Maria", "Contabilidad", 8.9, "Queretaro"}, a2, a3;

char nom[20], car[20], dir[20];
int mat;
float pro;

/* Los campos de a2 reciben valores por medio de una lectura. */
printf("\nIngrese la matricula del almuno 2: "); scanf("%d", &a2.matricula);
fflush(stdin);
printf("\nIngrese el nombre del alumno 2: ");
gets(a2.nombre);
printf("\nIngrese la carrera del alumno 2: ");
gets(a2.carrera);
printf("\nIngrese el promedio del alumno 2: ");
scanf("%f", &a2.promedio);
fflush(stdin);
printf("\nIngrese la dirreccion del alumno 2: ");
gets(a2.direccion);

/* Los campos de a3 reciben valores por medio de asignaciones.*/
printf("\nIngrese la matricula del alumno 3: ");
scanf("%d", &mat);
a3.matricula = mat;
fflush(stdin);
printf("\nIngrese el nombre del alummno 3: ");
gets(nom);
strcpy(a3.nombre, nom);
printf("\nIngrese la carrera del alumno 3: ");
gets(car);
strcpy(a3.carrera, car);
printf("\nIngrese el promedio del alumno 3: ");
scanf("%f", &pro);
fflush(stdin);
printf("\nIngrese la dirrecion del alumno 3: ");
gets(dir);
strcpy(a3.direccion, dir);


/*Observa la forma en que se imprime los campos de a1 y a2. */
printf("\nDatos del alumno 1\n");
printf("\%d\n", a1. matricula);
puts(a1. nombre);
puts("%.2f\n, a1. promedio");
puts(a2.direccion);

printf("\nDatos del alumno 2\n");
printf("\n%d\n", a2.matricula);
puts(a2.nombre);
puts(a2. carrera);
puts("%.2f\n", a2.promedio);
puts(a2.direccion);

/* Observa otra forma de escribir los campos de la variable de tipo estructura
a3. */
printf("\nDatos del alumno 3\n");
printf("d \t %s \t %s \t %.2f \t %s", a3.matricula, a3.nombre, a3. carrera,
            a3.promedio, a3.direccion);
}

