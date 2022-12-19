/* 
 * Proyecto: Archivos_de_texto
 * Archivo:  FuncionesAuxiliares.c
 * Autor:    Johan Carlo Amador Egoavil
 * Codigo:   20203350
 * 
 * Creado el 12 de abril de 2022, 08:39 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAuxiliares.h"
#define MAX_LINEA 100

void imprimirReporte(FILE *archRegistro, FILE *archReporte){
    
    double totalFacturas, totalNotasDeCredito, saldoFinal;
    totalFacturas = totalNotasDeCredito = saldoFinal = 0.0;
    
    //Impresión de cabecera.    
    fprintf(archReporte,"REGISTRO DE VENTAS\n");
    imprimirLinea(archReporte,'=',MAX_LINEA);
    fprintf(archReporte,"%s %17s %15s %16s %9s %12s %10s\n","FECHA","CLIENTE",
            "TIPO DE DOC.","SECUENCIA","SERIE","FACTURAS","N/C");    
    imprimirLinea(archReporte,'-',MAX_LINEA);    
    lecturaImpresionDeDatos(archRegistro,archReporte,&totalFacturas,
            &totalNotasDeCredito,&saldoFinal);    
    
    saldoFinal = totalFacturas-totalNotasDeCredito;
    imprimirTotalFacturasNC(archReporte,totalFacturas,totalNotasDeCredito,
            saldoFinal);
}

void lecturaImpresionDeDatos(FILE *archRegistro, FILE *archReporte,
                             double *totalFacturas, double *totalNotasDeCredito,
                             double *saldoFinal){
    
    int dd, mm, aaaa, cliente, serie, secuencia;
    char documento;
    double monto;
    
    while(1){ 
        
        fscanf(archRegistro,"%d",&dd);
        if(feof(archRegistro)) break;
        
        fscanf(archRegistro,".%d.%d",&mm,&aaaa);        
        fscanf(archRegistro,"%d %c %d-%d %lf",&cliente,&documento,&serie,
                &secuencia,&monto);
                        
        fprintf(archReporte,"%02d/%02d/%-10d %-10d",dd,mm,aaaa,cliente);

        if(documento=='F'){
            fprintf(archReporte,"%-22s","FACTURA");                       
            fprintf(archReporte,"%05d %5c %04d %12.2lf\n",serie,' ',
                    secuencia,monto);
            (*totalFacturas) += monto;
        }            
        else if(documento=='N'){
            fprintf(archReporte,"%-23s","NOTA DE CRÉDITO");
            fprintf(archReporte,"%05d %5c %04d %25.2lf\n",serie,' ',
                    secuencia,monto);        
            (*totalNotasDeCredito) += monto;
        }                
    }    
    imprimirLinea(archReporte,'=',MAX_LINEA);    
}

void imprimirTotalFacturasNC(FILE *archReporte, double totalFacturas, 
        double totalNotasDeCredito, double saldoFinal){    
    fprintf(archReporte,"TOTALES: %69.2lf %12.2lf\n",totalFacturas,
            totalNotasDeCredito);
    fprintf(archReporte,"SALDO FINAL: %7.2lf",saldoFinal);    
}

void imprimirLinea(FILE *archReporte, char caracter, int cantVeces){    
    for(int i=0; i<cantVeces; i++) fputc(caracter,archReporte);
    fputc('\n',archReporte);    
}

void cerrarArchivos(FILE *archRegistro, FILE *archReporte){
    fclose(archRegistro);
    fclose(archReporte);    
}