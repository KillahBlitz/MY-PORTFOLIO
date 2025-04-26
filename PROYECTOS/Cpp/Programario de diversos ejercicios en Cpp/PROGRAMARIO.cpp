//directivas al preprocesador
//tambien llamadas librerias
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<iomanip>
#include <windows.h>
#include<conio.h>
#include <locale.h>

//declaraciones globales y prototipos
void caratula(); //prototipo de la caratula
void gotoxy(int, int); //prototipo de la funcion que nos permite mover el texto de lugar
void menudeseleccion(); //prototipo del menu que nos permite seleccionar la actividad
void MatrizIdentidad(); //prototipo de la actividad que nos deja vizualizar una matriz identidad
void discos(); //prototipo de funcion sobre almacenar discos con informacion
void IMC(); //programa que nos hace calcular el IMC de una persona metiendo datos del usuario
void subpotencial(); //programa que apoya a potencia
void subfactorial(); //prototipo de subrutina donde se ingresa el numero factorial a ingresar
long factorial(int); //prototipo de factorial, donde se hace uso de funcion recursiva
int MultiplicacionMatricial(); //prototipo de la multiplicacion de dos matrices
int CuadradoMagico(); //prototipo del cuadrado magico tambien uso de funcion recursiva
int MatrizSimetrica(); //prototipo del calculo de una matriz simetrica
float Potencia(int, int);//prototipo de calculo de potencias




//tipo de datos, char, int, double, float 
int opc=1; //variable de seleccion
int i, j, k, n, m, f; //indices mientras que K funciona como estatico de cada numero
//f es una variable que recibe el valor de las subrutinas de tipo entero

//defino estructuras
struct Nombre_n{//struct que sera anidado para el programa de IMC
	char apaterno[15];
	char amaterno[15];
	char nombre[10];
};

struct Persona{//struct que sera anidado para el programa de IMC
	struct Nombre_n p;
	int edad;
	float estatura, peso, IMC;
	char hobbie[10];
}persona[2];

struct Fecha{//struct que sera anidado para el programa de discos
	int dia;
	char mes[10];
	char year[10];
};

struct Discos{//struct que sera anidado para el programa de discos
	struct Fecha F;
	int num_canciones;
	float precio;
	char artista[30];
	char titulo[30];
}Discos_CDs[100];

//sirve para no poner la pertenencia de las funciones std
using namespace std;

//funcion principal
int main(){
	//int main limpio de programas, llamando la funcion de menuseleccion para llamar los demas programas
	system("Title ALGORITHM PROGRAM");//funcion que cambia el titulo del programa
	system("COLOR 7D");//funcion que cambia los colores del programa
	while(opc!=0){
		    menudeseleccion();//llamada de la funcion funcion seleccion
	}
}








//funciones de usuario (definicion)
void menudeseleccion(){//cuerpo o definicion de la subrutina menu seleccion
	caratula();//llamada de la caratula
	//menu de seleccion dando la seleccion de cual programa pasar
    cout<<"BIENVENIDO AL PROGRAMARIO HECHO POR JACOBO MONROY Y JESSICA MARTINEZ"<<endl;
    cout<<"SELECCIONE EL PROBLEMA QUE DECIDA VISUALIZAR"<<endl;
	cout<<"1) Matriz Identidad"<<endl;
	cout<<"2) Multiplicacion de matrices"<<endl;
	cout<<"3) Cuadrado Magico"<<endl;
	cout<<"4) IMC"<<endl;
	cout<<"5) Discos"<<endl;
	cout<<"6) Matriz Simetrica"<<endl;
	cout<<"7) Factorial"<<endl;
	cout<<"8) Potencia"<<endl;
	cout<<"0) SALIR"<<endl;
	cin>>opc;
    switch(opc){
        case 0://este caso acaba el programa
        	system("PAUSE");
        	break;
        case 1://este caso te lleva al programa de matriz identidad
			MatrizIdentidad();//llamada de la matriz identidad
        	break;
        case 2://este caso te lleva al programa de la multiplicacion matricial
        	f=MultiplicacionMatricial();//llamada de la multiplicacion matricial
        	break;
        case 3://este caso te lleva al programa de cuadrado magico
        	CuadradoMagico();//llamada del cuadrado magico
        	break;
        case 4://este caso te lleva al programa de IMC
			IMC();//llamada de IMC
        	break;
        case 5://caso que te lleva al programa de discos
			discos();//llamada de discos
        	break;
        case 6://caso que te lleva al programa de matriz simetrica
		 	f=MatrizSimetrica(); //llamada de la matriz simetrica
        	break;
        case 7://caso que te lleva al factorial
			subfactorial();//llamada de subfactorial
        	break;
        case 8://caso que te lleva a potencia
			subpotencial();//llamada de subpotencial
        	break;
    }
}

void MatrizIdentidad(){//definicion de MatrizIdentidad
	int MI[n][n];//declaracion de la variable
	system("cls");//limpia la pantalla
	
	cout<<"ingresa las dimensiones de la matriz: ";//ingresando las dimensiones de la matriz
	cin>>n;//recibe el tamaño
		
		//for aninados que llena la matriz de 0 para inicializarla
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		{
				MI[i][i]=0;
		}	
	}
	
	//for anidado que recorre los espacios de la matriz
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		{
			if(i==j){//if donde i=j (osea donde es la linea identidad) y los iguala a 1
				MI[i][i]=1;
			}else//caso contrario le vuelve a poner 0
			{
				MI[i][i]=0;
			}
			cout<<MI[i][j]<<" ";//impresion de espacios para la matriz
		}	
		cout<<endl<<endl;//impresion de espacios para la matriz
	}
	getch();//cualquier tecla para continuar
	system("cls");//limpia la pantalla y termina la subrutina 
}

int MultiplicacionMatricial(){	//definicion de MultiplicacionMatricial
	//pidiendo datos de la matriz A y matriz B
	int x, y, n, m;//datos de dimensiones de la matriz

	system("cls");//limpia la pantalla

	//ingresa las dimensiones de la matriz A
	cout<<"Ingresa las dimensiones de la matriz A"<<endl;
	cout<<"filas: "<<endl;
	cin>>x;
	cout<<"columnas: "<<endl;
	cin>>y;
	int A[x][y];//inicializa la matriz A con las dimensiones impuestas
	
	//ingesa las dimensiones de la matriz B
	cout<<"Ingresa las dimensiones de la matriz B"<<endl;
	cout<<"filas: "<<endl;
	cin>>n;
	cout<<"columnas: "<<endl;
	cin>>m;
	int B[n][m]; //inicializa la matriz B con las dimensiones impuestas
	int C[x][m]; //i,j //inizializa la matriz que esperamos para la multiplicacion
	
	//if que nos permite ver si se puede realizar la operacion de multiplicacion matricial
	if(y==n){
		cout<<"Se espera una matriz C"<<"["<<x<<"]"<<"["<<m<<"]"<<endl;//matriz esperada
	}else{
		//error en caso de no coincidir las dimensiones
		cout<<"ERROR, LAS DIMENSIONES NO COINCIDEN PARA LA MULTIPLICACION, VOLVIENDO AL PROGRAMA PRINCIPAL..."<<endl;
		getch();//cualquier tecla para continuar
		system("cls");//limpia la pantalla
		return 0;//termina la subrutina
	}
	
	//for anidado que nos deja poner los valores de A
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			cout<<"ingresa el dato "<<i<<j<<" de la matriz A: "<<endl;
			cin>>A[i][j];
		}
	}
	
	//LLENADO DE MATRIZ B
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cout<<"ingresa el dato "<<i<<j<<" de la matriz B: "<<endl;
			cin>>B[i][j];
		}
	}	
	
	system("cls");	//limpia la pantalla
	
	//imprime la matriz A
	cout<<"MATRIZ A: "<<endl;
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl<<endl;		
	}
	
	//imprime la matriz B
	cout<<"MATRIZ B: "<<endl;	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cout<<B[i][j]<<" ";
		}
		cout<<endl<<endl;		
	}
	
	//inicializa la matriz C en 0
	for(i=0;i<x;i++){
		for(j=0;j<m;j++){
			C[i][j]=0;
		}	
	}
	
	//MUlTIPLICACION DE MATRICES
	//imprime la matriz resultante
	for(i=0;i<x;i++){
		for(j=0;j<m;j++){
			for(k=0;k<y;k++){
				C[i][j]+=A[i][k]*B[k][j];
			}
			cout<<C[i][j]<<'\t';
			C[i][j]=0;
		}
		cout<<endl;
	}
	getch();//cualquier tecla para continuar
	system("cls");//limpia la pantalla y termina la subrutina
}

int CuadradoMagico(){
	system("cls");
	
    int num;
    int contador = 0;
    // Variables para determinar la posición x e y en la matriz
    int x = 0, y = 0, vx = 0, vy = 0;
    
    cout<<"CUADRADO MAGICO DE ORDEN IMPAR"<< endl;
	cout<<"==============================="<< endl;

    cout<< "Introduce un numero impar: ";
    cin>>num;

    // Verifica si el número es impar
    if (num % 2) {
        cout << "El numero " << num << " es impar." << endl;

        // Inicializa la matriz después de obtener el valor de num
        int Matriz[num][num];
        int limite = num * num;
        int limitex = num - 1;
        int limitey = num - 1;

        // Llena la matriz inicialmente con ceros
        for (x = 0; x < num; x++) {
            for (y = 0; y < num; y++) {
                Matriz[x][y] = 0;
            }
        }
        
        // Algoritmo para colocar los números en la matriz
        x = num / 2;
        y = 0;
        for (contador = 1; contador <= limite; contador++) {
            Matriz[y][x] = contador;
            vx = x;
            vy = y;
            
            // Mover a la posición diagonal superior derecha
            x++;
            if (x > limitex) x = 0;
            y--;
            if (y < 0) y = limitey;
            
            // Si la posición ya está ocupada, colocar abajo de la anterior
            if (Matriz[y][x] > 0) {
                x = vx;
                y = vy + 1;
            }
        }

        // Visualiza la matriz
        for (x = 0; x < num; x++) {
            for (y = 0; y < num; y++) {
                cout << "| " << Matriz[x][y] << " |";
            }
            cout << endl;
        }
        getch();
    } else if (num == 0) {
        cout<<"El numero cero no es aceptable."<< endl;
        getch();
        CuadradoMagico();
    } else {
        cout<<"El numero " << num << " es par y no es aceptable."<< endl;
        getch();
        CuadradoMagico();
    }
	system("cls");
	return 0;	
}

int MatrizSimetrica(){//definicion de MatrizSimetrica
	system("cls");//limpia la pantalla
	bool band=false;//bandera indicadora para terminar el programa si la matriz no es simetrica
		//ingresa las dimensiones de la matriz
	cout<<"Ingresa el valor de la dimension de la matriz"<<endl;
	cin>>n;//recibe las dimensiones
	int MatrizA[n][n]; //inicializacion de la matriz 
	
	//ingreso de los datos de la matriz
	for(i=0;i<n;i++){
	for(j=0;j<n;j++){
			cout<<"ingresa el dato "<<i<<j<<" de la matriz A: "<<endl;
			cin>>MatrizA[i][j];
		}
	}
	
	system("cls");//limpia la pantalla
		
		//imprime la matriz
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<MatrizA[i][j]<<" ";
		}
		cout<<endl<<endl;		
	}
	
	//compara los espacios para saber si es simetrica o no lo es
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			
			//este if compara esos mismos casos donde sea simetrica
		if(MatrizA[i][j]!=MatrizA[j][i]){
			cout<<"No es Simetrica"<<endl;//si no es simetrica termina el prgrama
			band=true;//activa la bandera para no imprimir que es simetrica
			getch();
			system("cls");
			return 0;//termina el programa
		}
		
		}		
	}
	
	if(band==false){//if donde busca que nunca se haya activado la bandera
	cout<<"Es Simetrica"<<endl;//imprime que es simetrica
	}
	
	getch();
	system("cls");//limpia la pantalla y termina la subrutina
}

void IMC(){
	
	system("cls");
		
	for(int i=0;i<2;i++){ //vaciar el buffer y permitir digitar valores
	cout<<"NOMBRE: ";
	cin>>persona[i].p.nombre,'\n';
	cout<<"APELLIDO PATERNO: ";
	cin>>persona[i].p.apaterno,'\n';
	cout<<"APELLIDO MATERNO: ";
	cin>>persona[i].p.amaterno,'\n';
	cout<<"EDAD: ";
	cin>>persona[i].edad,'\n';
	cout<<"ESTATURA: ";
	cin>>persona[i].estatura,'\n';
	cout<<"PESO: ";
	cin>>persona[i].peso,'\n';
	cout<<"HOBBIE: ";
	cin>>persona[i].hobbie,'\n';
	//Calcula el IMC DE las personas
	persona[i].IMC=persona[i].peso/(persona[i].estatura*persona[i].estatura);
	
 }
 
 
    //imprimiendo datos
    for(int i=0;i<2;i++)
	{
       cout<<endl;
	   cout<<"Nombre completo: "<<persona[i].p.apaterno<<" "<<persona[i].p.amaterno<<" "<<persona[i].p.nombre<<endl;
       cout<<"Edad: "<<persona[i].edad<<endl;
       cout<<"Estatura: "<<persona[i].estatura<<endl;
       cout<<"Peso: "<<persona[i].peso<<endl;
	   cout<<"Hobbie: "<<persona[i].hobbie<<endl;
	   
	    cout<<"Tu IMC es de :   "<<persona[i].IMC<<endl;
	    
	    //comparando resultado del imc
	    if(persona[i].IMC<18.4){
	    	cout<<"!!ESTAS BAJO EN PESO!!"<<endl;
		}
		
		if(persona[i].IMC>=18.5&persona[i].IMC<24.4){
	    	cout<<"!!ESTAS NORMAL!!"<<endl;
		}
		
		if(persona[i].IMC>24.5){
	    	cout<<"!!TIENES SOBRE PESO!!"<<endl;
		}
		
	}
	
	getch();
	system("cls");
}


void discos(){
		int N;
		
	system("cls");
	//introduce la cantidad de discos que desea ingresar 
	cout<<"Cuantos discos quieres ingresar: ";
	cin>>N;
	
	for(int i=0;i<N;i++){ //vaciar el buffer y permitir digitar valores
	cout<<"TITULO: ";
	cin>>Discos_CDs[i].titulo,'\n';
	cout<<"Nombre del artista: ";
	cin>>Discos_CDs[i].artista,'\n';
	cout<<"Numero de cancion: ";
	cin>>Discos_CDs[i].num_canciones,'\n';
	cout<<"--FECHA--"<<endl;
	cout<<"Dia:";
	cin>>Discos_CDs[i].F.dia,'\n';
	cout<<"Mes: ";
	cin>>Discos_CDs[i].F.mes,'\n';
	cout<<"Año: ";
	cin>>Discos_CDs[i].F.year,'\n';
	cout<<"Precio: ";
	cin>>Discos_CDs[i].precio,'\n';
	
 }
    //imprimiendo datos
    for(int i=0;i<N;i++)
	{
       cout<<endl;
       cout<<"TITULO: "<<Discos_CDs[i].titulo<<endl;
	   cout<<"Nombre del artista: "<<Discos_CDs[i].artista<<endl;
	   cout<<"Numero de cancion: "<<Discos_CDs[i].num_canciones<<endl;
	   cout<<"Fecha: "<<Discos_CDs[i].F.dia<<" - "<<Discos_CDs[i].F.mes<<" - "<<Discos_CDs[i].F.year<<endl;
	   cout<<"Precio: "<<Discos_CDs[i].precio<<endl;
		
	}
	
	getch();
	system("cls");
}





// Subrutina para manejar la entrada y salida del factorial
void subfactorial() {
    int numero;
	system("cls");   
    cout << "Ingrese un numero para calcular su factorial: ";
    cin >> numero;

    // Validación de entrada
    if (numero < 0) {
        cout << "El factorial no está definido para números negativos." << endl;
    } else {
        long resultado = factorial(numero); // Llama a la función factorial
        cout << "El factorial de " << numero << " es: " << resultado << endl;
    }
    
    getch();
	system("cls");
}

// Función recursiva para calcular el factorial
long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Caso base
    } else {
        return n * factorial(n - 1); // Llamada recursiva
    }
}

void subpotencial(){
	    system("cls");  // Limpiamos la pantalla

        // Variables para la base y el exponente
        int base, exponente;

        // Solicitar la base y el exponente
        cout << "Ingrese la base: ";
        cin >> base;
        cout << "Ingrese el exponente: ";
        cin >> exponente;

        // Mostrar el resultado del cálculo de la potencia
        cout << "El resultado es: " << Potencia(base, exponente);
        getch();
        system("cls");  // Limpiamos la pantalla
}

float Potencia(int base, int expo)
{
    if(expo == 0)
        return 1;
    else if(expo > 0)
        return base * Potencia(base, expo - 1);
    else
        return 1.0 / Potencia(base, -expo);  // Para exponentes negativos
}



void caratula(){//caratula de presentacion para la evaluacion
		system("cls");
		
    gotoxy(45,11);cout<<"Instituto Politecnico Nacional";
    gotoxy(27,12);cout<<"Escuela Superior De Ingeneria Mecanica y Electrica UNIDAD CULHUACAN";
    gotoxy(44,13);cout<<"Monroy Cortines Jacobo Emiliano";
    gotoxy(44,14);cout<<"  Martinez Martinez Jessica";
    gotoxy(43,15);cout<<"     Analisis de Algoritmos";
    gotoxy(44,16);cout<<"Programas de Primer Parcial";
    gotoxy(51,17);cout<<"  Grupo 5CM13";
    gotoxy(45,18);cout<<"Profesora Azorin Vega Claudia \n\n"; 
	
		getch();
	system("cls"); 
}

//funcion gotoxy que nos ayuda a poscicionar el texto en donde nosotros querramos
//usamos la libreria windows.h
void gotoxy(int x, int y){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
