#include <stdio.h>

int main(void){
// Declarar variables
float c_minimo, c_maximo, precio; // almacena los valores de ingreso
float precio_por_litro; // Precio por litro
float costo_por_km; // Costo por kilometro


//Entrada de datos
printf ("\nIngrese el valor minimo de consumo: ");
scanf("%f", &c_minimo);
printf("n\Ingrese el valor maximo de consumo: ");
scanf("%f", &c_maximo);
printf("n\Ingrese el precio de la gasolina por galon: ");
scanf("%f", &precio);

// Calcula el precio por litro ( 1 galon = 3.78541
precio_por_litro = precio/ 3.78541;

// Imprimime los encabezados en la tabla
printf("%-20s %-15s\n", "Consumo (L/100k)","Costo por km");
printf("--------------------------------------\n");

//Generar la tabla
for(float consumo = c_minimo; consumo <= c_maximo; consumo += 1){
costo_por_km = (precio_por_litro *(consumo /100));
printf("%-20.2f %-15.2f\n", consumo, costo_por_km);
}
    return 0;
}
