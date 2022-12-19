/* 
 * Proyecto: Archivos_de_texto
 * Archivo:  main.c
 * Autor:    Johan Carlo Amador Egoavil
 * Codigo:   20203350
 * 
 * Creado el 12 de abril de 2022, 07:49 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {

    FILE *archRegistro, *archReporteDeVentas;
    
    archRegistro = fopen("Registro.txt","r");
    if(archRegistro==NULL){
        printf("ERROR: No se pudo abrir el archivo \"Registro.txt\"\n");
        exit(1);        
    }
    archReporteDeVentas = fopen("ReporteDeVentas.txt","w");
    if(archReporteDeVentas==NULL){
        printf("ERROR: No se pudo abrir el archivo \"ReporteDeVentas.txt\"\n");
        exit(1);        
    }    
    imprimirReporte(archRegistro,archReporteDeVentas);
    cerrarArchivos(archRegistro,archReporteDeVentas);   

    return (EXIT_SUCCESS);
}