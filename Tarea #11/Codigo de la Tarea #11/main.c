#include <stdio.h>
#include <stdlib.h>

// Usamos pragma para evitar el relleno de bytes en las estructuras
#pragma pack(push, 1)
typedef struct {
    unsigned char  bfType[2];  // Tipo de archivo, debe ser "BM"
    unsigned int   bfSize;     // Tamaño del archivo en bytes
    unsigned short bfReserved1; // Reservado, debe ser 0
    unsigned short bfReserved2; // Reservado, debe ser 0
    unsigned int   bfOffBits;  // Offset hasta los datos de la imagen
} BITMAPFILEHEADER;

typedef struct {
    unsigned int   biSize;         // Tamaño de este encabezado
    int            biWidth;        // Ancho de la imagen
    int            biHeight;       // Alto de la imagen
    unsigned short biPlanes;       // Siempre 1
    unsigned short biBitCount;     // Bits por píxel, debe ser 24 para este ejemplo
    unsigned int   biCompression;  // Tipo de compresión (0 = sin compresión)
    unsigned int   biSizeImage;    // Tamaño de los datos de la imagen
    int            biXPelsPerMeter;// Resolución horizontal
    int            biYPelsPerMeter;// Resolución vertical
    unsigned int   biClrUsed;      // Número de colores usados
    unsigned int   biClrImportant; // Número de colores importantes
} BITMAPINFOHEADER;
#pragma pack(pop)

// Convierte un píxel de color (BGR) a escala de grises
unsigned char convertirAGris(unsigned char b, unsigned char g, unsigned char r) {
    return (unsigned char)(0.3 * r + 0.59 * g + 0.11 * b);
}

// Función principal que convierte un BMP a escala de grises
void convertirBMPBlancoNegro(const char *input_filename, const char *output_filename) {
FILE *input_file = fopen(input_filename, "rb"); // Abrimos el archivo de entrada en modo binario
if (input_file == NULL) {
fprintf(stderr, "No se puede abrir el archivo %s\n", input_filename);
return;

}

// Leer los encabezados del archivo BMP
BITMAPFILEHEADER fileHeader;
fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, input_file);

BITMAPINFOHEADER infoHeader;
fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, input_file);

// Verificar si es un archivo BMP de 24 bits
if (fileHeader.bfType[0] != 'B' || fileHeader.bfType[1] != 'M' || infoHeader.biBitCount != 24) {
fprintf(stderr, "El archivo no es un BMP de 24 bits\n");
fclose(input_file);
return;

}

// Crear el archivo de salida
FILE *output_file = fopen(output_filename, "wb");
if (output_file == NULL) {
fprintf(stderr, "No se puede crear el archivo %s\n", output_filename);
fclose(input_file);
return;

}

// Escribir los encabezados en el archivo de salida
fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, output_file);
fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, output_file);

// Calcular el padding (relleno) de cada fila
int padding = (4 - (infoHeader.biWidth * 3) % 4) % 4;

// Procesar píxel por píxel
for (int i = 0; i < infoHeader.biHeight; i++) {
for (int j = 0; j < infoHeader.biWidth; j++) {
unsigned char bgr[3]; // Leer píxel en formato BGR
fread(bgr, 3, 1, input_file);

// Convertir a escala de grises
unsigned char gris = convertirAGris(bgr[0], bgr[1], bgr[2]);

// Escribir el píxel gris en el archivo de salida
unsigned char gris_pixel[3] = {gris, gris, gris};
fwrite(gris_pixel, 3, 1, output_file);

}

// Saltar el relleno del archivo original
fseek(input_file, padding, SEEK_CUR);

// Añadir el relleno necesario en el archivo de salida
unsigned char padding_bytes[3] = {0, 0, 0};
fwrite(padding_bytes, padding, 1, output_file);

}

// Cerrar los archivos
fclose(input_file);
fclose(output_file);

printf("Imagen convertida a blanco y negro y guardada en %s\n", output_filename);
}

int main(int argc, char *argv[]) {
const char *archivo_entrada = "avion.bmp";   // Archivo original
const char *archivo_salida = "avion_bn.bmp"; // Archivo convertido

convertirBMPBlancoNegro(archivo_entrada, archivo_salida); // Llama a la función de conversión

return 0;
}
