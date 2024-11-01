#include <stdio.h>
#include <string.h>

/* Vendedores.
El programa maneja informacion sobre las ventas que realizan los vendedores de
articulos domesticos de una importante empresa de la ciudad de Mexico. */
typedef struct                  /* Declaracion de la estructura banco. */
{
char noba[10];                  /*Nombre del banco. */
char nucu[10];                  /* Numero de cuenta. */
}banco;

typedef union                   /* Declaracion de la union fpago. */
{
    banco che;                  /* Cheque. Campo de tipo estructura banco. */
    banco nomi;                 /* Comina. Campo de tipo estructura banco. */
    char venta;                 /* Ventanilla. */
}fpago;

typedef struct                       /* Declaracion de la estructura domicilio. */
{
   char cnu[20];                /* Calle y numero. */
   char col[20];                /* Colina. */
   char cp[5];                  /* Codigo Postal. */
   char ciu[15];                /* Ciudad. */
}domicilio;

typedef struct                         /* Declaracion de la estructura vendedor. */
{
int num                        /* Numero de vendedor. */
char nom[20];                  /* Nombre del vendedor. */
float ven[12]                  /* Ventas del años. Areglo unidimensional de tipo real. */
domicilio domi;               /* domi es de tipo estructura domicilio. */
float sal;                      /* Salario mensual. */
fpago pago;                    /* pago es de tipo union fpago. */
int cla;                       /* Clave forma de pago. */
}vendedor;

void  Lectura(vendedor *,int);
void F1(vendedor *, int);
void F2(vendedor *, int);       /* Prototipo de funciones. */
void F3(vendedor *, int);
void F4(vendedor *, int);

void main(void)
{
vendedor VENDEDORES[100];
/*Declaracion del arreglo unidimensional de tipo estructura vendedor. */
int TAM;
do
{
   printf("Ingrese el numero de vendedores: ");
   scanf("%d", &TAM);
}
while (TAM > 100 || TAM < 1);
/* Se verifica que el numero de elementos del arreglo sea correcto. */
Lectura (VENDEDORES, TAM);
F1 (VENDEDORES, TAM);
F2 (VENDEDORES, TAM);
F3 (VENDEDORES, TAM);
F4 (VENDEDORES, TAM);
printf("\n\tFIN DEL PROGRAMA");
{
    printf("\n\tIngrese datos del vendedor %d", I+1);
    printf("\nNumero de vendedores: ");
    scanf("%d", &A[I].num);
    printf("Nombre del vendedor: ");
    fflush(stdin);
    gets(A[I].nom);
    printf("Ventas del año: \n");
    for (J=0; J,12; J++)
    {
    printf("\tMes %d: ", J+1);
    scanf("%f", &A[I].ven[J]);

}
printf("Domicilio del vendedor: \n");
printf("\tCalle y número: "");
fflush(stdin);
gets(A[I].domi.cnu);
printf("\tColonia: ");
fflush(stdin);
gets(A[I].domi.col);
printf("\tCódigo Postal: ");
fflush(stdin);
gets(A[I].domi.cp);
printf("\tCiudad: "S);
fflush(stdin);
gets(A[I].domi.ciu);
printf("Salario del vendedor: "S);
scanf("S%f"S, &A[I].sal);
printf("Forma de Pago (Banco-1 Nómina-2 Ventanilla-3): ");
scanf("%d", &A[I].cla);
switch (A[I].cla)
{

    case 1:{
            printf("\tNombre del banco: ");
            fflush(stdin);
            gets(A[I].pago.che.noba);
            printf("\tNúmero de cuenta: ");
            fflush(stdin);
            gets(A[I].pago.che.nucu);
            }

            break;
        case 2;{
                    printf("\tNombre del banco: ");
                    fflush(stdin);
                    gets(A[I].pago.nomi.noba);
                    printf("\tNumero de cuenta: ");
                    fflush(stdin);
                    gets(A[I].pago.nomi.nucu);
        }
        break;
      case 3: A[I].pago.venta = 's';
        break;

    }
}
}

void F1(vendedor A[], int T)
/* Esta funcion se utiliza para generar las ventas totales anuales de cada uno
de los vendedores de la empresa. */
{
int I, J;
float SUM;
printf("\n\t\tVentas totales de los vendedores");
for (I=0; I<T; I++)
{
printf("\nVendedor: %d", A[I].num);
SUM = 0.0;
for (J=0; J<12; J++)
    SUM += A[I].Ven[j];
printf("\nVentas: %2f\n", SUM);
}
}

void F2(vendedor A[], int T)
/* Esta funcion se utiliza para incrementar 5% el salario de todos los aquellos
vendedores cuyas ventas anuales superaron $1,500,000. */
for (I=0; I<T; I++)
{

SUM = 0.0;
for (J=0; J<12; J++)
    SUM += A[I].Ven[J];
if (SUM > 1500000.00)
{
    A[I].Sal = A[I].sal * 1.05;
    printf("\nNumero de empleado: %d\nVentas: %.2f\nNuevo salario: %.2f",
            A[I].num, SUM, A[I]. sal);
}
}

void F3(vendedor A[], int T)
/* Esta funcion se utiliza para generar un listado de todos aquellos
vendedores que en el año vendieron menos  de $300,000. */
{
int I, J;
float SUM;
printf("\n\t\tVendores con Ventas < 300,000");
for (I=0; I<T; I++)
{

SUM = 0.0;
for (J=0; J<12; J++)
    SUM += A[I].ven[J];
if (SUM < 300000.00)
   printf("\nNumeros de empleado: %d\nNombre: %s\nVentas: %.2f", A[I].num,
          A[I].nom, SUM);
}
}
void F4(vendedores A[], int T)
/* Esta funcion se usa para imprimir el numero de empleado , al nombre del
banco y el numero de cuenta de todos aquellos empleados a quienes se les
deposita su sueldo en cuenta de cheques. */
{
int I;
float
printf("\n\t\tVendedores con Cuenta en Banco);
for (I=0; I<T; I++)
    if (A[I].cla == 1)
          printf("\nNumero de vendedor: %d\n Banco: %s\nCuenta: %S");
          A[I].num,
                A[I].pago.che.noba, A[I].pago.che.nucu);
}
