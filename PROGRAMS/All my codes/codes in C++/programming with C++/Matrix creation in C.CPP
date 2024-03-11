//inclusion de librerias

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
//definicion de variables F y C, donde F es filas y C son Columnas
#define F 20
#define C 20

//declaracion de las variables
void CREAR_MATRIZ(int[][C],int &, int &);
void IMPRIMIR_MATRIZ(int[][C],int &, int &);
void MAXIMO_COLUMNA(int[][C],int &, int &);
void MAXIMO_FILA(int[][C],int &, int &);


void main(){
//funciones printf para el inicio del programa, nada que afecte al programa
   printf("Este programa recibe una matriz con dimenciones determinadas por el usuario\n");
	printf("que se rellena con valores aleatorios, y encuentra el valor maximo de la fila o columna\n");
   printf("introducida por el usuario\n\n");
	printf("Creado por: Mejia Castaneda Bryan Emmanuel, ");
   printf("Monroy Cortines Jacobo Emiliano y ");
   printf("Pali Guzman Samuel Alonso\n");
	printf("Recuerda que si puedes imaginarlo, puedes programarlo.\n\n");
//terminan las funciones printf

//este seria nuestro programa principal el que llama la subrutina de crear e imprimir, tambien la funcion de NxM
int N,M,MATRIZ[F][C];
   printf("Numero de Filas:");
    scanf("%d",&N);
   printf("Numero de columnas:");
    scanf("%d",&M);
  CREAR_MATRIZ(MATRIZ,N,M);
  IMPRIMIR_MATRIZ(MATRIZ,N,M);

//poniendo el switch selector que nos indica si el usuario quiere trabajar con filas o columnas
int RES;
	printf("si quiere calcular numero maximo de COLUMNAS, ingrese 0, para FILAS ingrese 1:");
		scanf("%d",&RES);
  switch (RES){
  case 0: MAXIMO_COLUMNA(MATRIZ,N,M); break;
  case 1: MAXIMO_FILA(MATRIZ,N,M); break;
  }
getch();
}

//subrutinas, empezando por CREAR_MATRIZ e IMPRIMIR_MATRIZ
void CREAR_MATRIZ(int matriz[][C], int &n, int &m){
	int i,j;
	srand(time(NULL));
  	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			matriz[i][j]=1+rand()%101;
		}
	}
}

//subrutina de impresion de la matriz
void IMPRIMIR_MATRIZ(int matriz[][C], int &n, int &c){
	int i,j;
	srand(time(NULL));
	for(i=0;i<n;i++){
		for(j=0;j<c;j++){
		  printf("%d\t",matriz[i][j]);
		}
      printf("\n\n");
	}
}

//subrutinas para calcular el maximo de columnas y filas
void MAXIMO_COLUMNA(int matriz[][C],int &f, int &c){
	int pos,i=0,mayor=0;
	  printf("\nnumero de columna que quieres su mayor [%d-%d]:\n ", 0, c -1);
        scanf("%d", &pos);
        mayor = matriz[0][pos];
        for (i = 1; i < f; i++) {
            if (mayor <= matriz[i][pos]){
                mayor = matriz[i][pos];
            }
        }
        printf("El mayor es: %d\n\n",mayor);
}

//subrutina para filas
void MAXIMO_FILA(int matriz[][C],int &f, int &c){
	int pos,j=0,mayor=0;
	printf("\nnumero de fila que quieres su mayor [%d-%d]:\n ", 0, f -1);
        scanf("%d", &pos);
        mayor = matriz[pos][0];
        for (int i = 1; i < c; i++) {
            if (mayor <= matriz[pos][i]) {
                mayor = matriz[pos][i];
            }
        }
        printf("El mayor es: %d\n\n",mayor);
}
