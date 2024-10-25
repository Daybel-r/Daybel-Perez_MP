#include <stdio.h>

void convertir(int entero, int centavos){

printf("El numero es %d con %d centavos\n",
entero, centavos);
}

int main(){
    float numero;
    int entero,centavos;

do{
printf("\nIntroduce un numero decimal
(ejemplo 150.10)o -1 para salir:");
scanf("%f", &numero);

if(numero == -1){
   break;
}
entero = (int)numero;
centavos = (int)((numero - entero)* 100);
convertir(entero, centavos);

}while (1);

printf("Programa finalizando.\n");
return 0;
}
