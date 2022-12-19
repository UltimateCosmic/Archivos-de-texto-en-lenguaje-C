/* 
 * Proyecto: Archivos_de_texto
 * Archivo:  FuncionesAuxiliares.h
 * Autor:    Johan Carlo Amador Egoavil
 * Codigo:   20203350
 * 
 * Creado el 12 de abril de 2022, 08:39 PM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void imprimirReporte(FILE *, FILE *);
void lecturaImpresionDeDatos(FILE *, FILE *, double *, double *, double *);
void imprimirTotalFacturasNC(FILE *, double, double, double);
void imprimirLinea(FILE *, char, int);
void cerrarArchivos(FILE *, FILE *);

#endif /* FUNCIONESAUXILIARES_H */

