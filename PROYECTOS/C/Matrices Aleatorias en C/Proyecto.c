///////////////////////////////
//Inclusión de librerias
#ifdef _WIN32
#include <windows.h>
#endif

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
/*Incluye las librerías específicadas*/
///////////////////////////////

/////////////////////////////////////////
//declaración de variables globales
	int f=0,c=0,numerosF,numerosC;
	/*f se utilizará para las filas
	c se utilizará para las columnas*/
////////////////////////////////////////

/////////////////////////////////////
//prototipado de funciones
int ALEATORIOS(int ,int);
/*Hace el prototipo de la función llamada ALEATORIOS así como los parámetros que recibirá*/
int LLENADO(int, int, int[f][c],int, int);
/*Hace el prototipo de la función llamada LLENADO, así como los parámetros que recibirá*/
void LIMPIAR_PANTALLA(void);
//void MAXIMO_VALOR(int[f][c]);
////////////////////////////////////

//////////////////////////////
//inicio del código principal del programa
int main(){
	/////////////////////////////
	//inicio del programa
	printf("Este programa recibe una matriz con dimenciones determinadas por el usuario\n");
	printf("que se rellena con valores aleatorios, y encuentra el valor maximo de la fila o columna\n");
	printf("introducida por el usuario\n\n");
	printf("Creado por: Mejia Castaneda Bryan Emmanuel, ");
	printf("Monroy Cortines Jacobo Emiliano y ");
	printf("Pali Guzman Samuel Alonso\n");
	printf("Recuerda que si puedes imaginarlo, puedes programarlo.\n\n");
	/////////////////////////////

	/////////////////////////////
	//Declaración de variables locales

	
	////////////////////////////
	
	////////////////////////////
	//declaración de arreglos(vectores unidimencionales)
	
	///////////////////////////
	
	////////////////////////////////
	//declaración de matriz o tablas(vectores bidimencionales)
	
	///////////////////////////////
	int matriz[f][c];
	/*declara la matriz llamada matriz*/
	/////////////////////////////// 
	//declaración de cadenas
	
	///////////////////////////////

	//////////////////////////////
	//delcaración de punteros
	
	//////////////////////////////
	
	//////////////////////////////
	//Cuerpo del programa
	printf("\nIngrese la cantidad de filas de la matriz\n");
	/*solicita al usuario que ingrese la cantidad de filas que tendrá la matriz*/
	scanf("%i",&f);
	/*asigna a la variable m el valor ingresado por el usuario, el cual se usara para las filas
	de la matriz*/
	printf("Ingrese la cantidad de columnas de la matriz\n");
	/*solicita al usario la cantidad de columnas que tendrá la matriz*/
	scanf("%i",&c);
	/*asigna a la variable n el valor ingresado por el usuario, el cual se usará para las columnas
	de la matriz*/
	
	LIMPIAR_PANTALLA();
	/*Invoca la función llamada LIMPIAR_PANTALLA*/
	
	//Para depuración
	printf("********************************\n");
	printf("*La cantidad de filas son %i    *\n",f);
	/*imprime la cantidad de columnas ingresadas por el usuario*/
	printf("*La cantidad de columnas son %i *\n",c);
	/*imprime la cantidad de columnas igresadas por el usuario*/
	printf("********************************\n\n");
	//Fin de la depuración
	
	ALEATORIOS(f,c);
	/*invoca a la funcion llamada ALEATORIOS*/
	LLENADO(f,c,matriz,numerosF,numerosC);
	LIMPIAR_PANTALLA();
	//MAXIMO_VALOR(matriz);
	//////////////////////////////
	
	//////////////////////////////
	//parte final del código	
	system("pause");
	/*espera a recibir un caracter*/
	return 0;
	/*regresa el valor de 0*/
	//////////////////////////////
}
//fin del código principal del programa
//////////////////////////////

//////////////////////////////////////////
//definición de funciones
int ALEATORIOS(int f, int c){
	int i=0,j=0;
	/*declaro las variables a utilizar*/
	srand(time(NULL));
	/*genero la semilla para generar los números aleatorios, con los atributos específicados*/
	for(i;i<f;i++){
	/*se utiliza para las filas*/
		for(j;j<c;j++){
		/*se utiliza para las columnas*/
			numerosC=1+rand()%100;
			/*guarda los números generados para las columnas en la variable numerosM*/
		}
		numerosF=1+rand()%100;
		/*guarda los números generados para las filas en la variable numerosN*/
	}
	return numerosF,numerosC;
	/*regresa los valores de las variables numerosN y numerosM para que otra función o proceso trabaje con ellas*/
}
int LLENADO(int f,int c,int matriz[][c],int numerosF,int numerosC){
int i,j,T=0;
for(i=0;i<f;i++){
	for(j=0;j<c;j++){
		matriz[i][j]=numerosF,numerosC;
		printf("En la posicion [%i][%i] esta el numero: %i\n",i+1,j+1,&matriz[i][j]);
		}
	
	}
	Sleep(20000);
	return matriz[i][j];
	
}

void LIMPIAR_PANTALLA(void){
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
	/*comprueba si el sistema donde se ejecuta es windows para limpiar la pantalla con el comando 
	correspondiente para el sistema windows, en caso contrario ejecuta el código correspondiente
	para linux*/
	printf("Este programa recibe una matriz con dimenciones determinadas por el usuario\n");
	printf("que se rellena con valores aleatorios, y encuentra el valor maximo de la fila o columna\n");
	printf("introducida por el usuario\n\n");
	printf("Creado por: Mejia Castaneda Bryan Emmanuel, ");
	printf("Monroy Cortines Jacobo Emiliano y ");
	printf("Pali Guzman Samuel Alonso\n");
	printf("Recuerda que si puedes imaginarlo, puedes programarlo.\n\n");
}
/*MAXIMO_VALOR(int matriz[][c]){
	int MValor=0,i=0;
	for(){
		
	}
}*/
/////////////////////////////////////////

////////////////////////////////
/*
Si tienes alguna duda sobre la realización sobre cosas busca en 
Programación ATS o en cualquier video de internet, o páginas de documentación sobre 
programación en C++
*/
///////////////////////////////
