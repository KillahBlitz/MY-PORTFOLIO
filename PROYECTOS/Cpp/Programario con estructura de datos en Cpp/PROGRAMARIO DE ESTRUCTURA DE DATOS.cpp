#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>


using namespace std;


//Prototipos de las funciones usuario
void caratula(); //prototipo de caratula
void gotoxy(int x, int y); //prototipo de coordenadas para ordenar menus
void ingresoDD(int []); //prototipo de ingreso de datos
void consulta(int []); //prototipo de consulta del orden del arreglo
int aleatoriedad(int []); //prototipo que ordena los numeros de manera aleatoria
void OrdenamientoSeleccion(int [], int); //Ordenamiento por seleccion
void OrdenamientoIntercambio(int [], int); //Ordenamiento por Intercambio
void OrdenamientoBurbuja(int [], int); //Ordenamiento por metodo Burbuja
void OrdenamientoQuicksort(int [], int, int); //Ordenamiento rapido Quicksort
int BusquedaSecuencial(int [], int); //Busqueda secuencial
int BusquedaBinaria(int [], int); //Busqueda Binaria 

//variables Globales
int n=0;
int opc=0;


int main(){
	system("Title ALGORITHM PROGRAM");//funcion que cambia el titulo del programa
	system("COLOR 7D");//funcion que cambia los colores del programa
	caratula();//llamada de caratula
	
	cout<<"Ingresa de que tamanio es el arreglo de numeros: ";
	cin>>n;
	int A[n]; //Creo y declaro el arreglo con los datos
	ingresoDD(A);//llamada de ingreso de datos
	
	
	    do {
        cout << "BIENVENIDO AL PROGRAMARIO HECHO POR JACOBO MONROY Y JESSICA MARTINEZ" << endl;
        cout << "SELECCIONE EL METODO QUE DECIDA VISUALIZAR" << endl;
        cout << "METODOS DE ORDENAMIENTO" << endl;
        cout << "1) Revolver datos" << endl;
        cout << "2) Ordenamiento Seleccion" << endl;
        cout << "3) Ordenamiento Intercambio" << endl;
        cout << "4) Ordenamiento Burbuja" << endl;
        cout << "5) Ordenamiento rapido (Quicksort)" << endl;
        cout << "METODOS DE BUSQUEDA" << endl;
        cout << "7) Busqueda Secuencial" << endl;
        cout << "8) Busqueda Binaria" << endl;
        cout << "9) Consulta de arreglo" << endl;
        cout << "0) SALIR" << endl;
        cin >> opc;

        switch (opc) {
            case 0: // Este caso acaba el programa
                cout << "Saliendo del programa..." << endl;
                system("PAUSE");
                break;
            case 1:
                aleatoriedad(A); // Aquí llamas a la función para revolver los datos
                break;
            case 2:
                OrdenamientoSeleccion(A, n);// Llamar a la función de ordenamiento por selección
                break;
            case 3:
                OrdenamientoIntercambio(A, n);// Llamar a la función de ordenamiento por intercambio
                break;
            case 4:
                OrdenamientoBurbuja(A,n);// Llamar a la función de ordenamiento burbuja
                break;
            case 5:
            	system("cls");
            	cout<<"ORDENAMIENTO QUICKSORT"<<endl;
                OrdenamientoQuicksort(A, 0, n-1);// Llamar a la función de ordenamiento rápido (quicksort)
                getch();
				system("cls");
                break;
            case 7:
            	BusquedaSecuencial(A,n);// Llamar a la función de búsqueda secuencial
                break;
            case 8:
                BusquedaBinaria(A,n);// Llamar a la función de búsqueda binaria
                break;
            case 9:
                consulta(A);// Llamar a la función de Consulta de datos
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
                break;
        }
    } while (opc != 0); // Repite el bucle mientras opc no sea 0

    return 0;
}




//ingreso de datos
void ingresoDD(int A[]){

	cout<<"Ingresa los datos"<<endl; 
	for(int i=0; i<n; i++){
		cout<<"Ingresa el dato "<<i+1<<": ";
		cin>>A[i];
	} //ingresamos los datos  
		
	cout<<"Lista de datos"<<endl;
	for(int i=0; i<n; i++){
		cout<<A[i]<<" ";
	} // imprimimos los datos
	getch();
	
	system("cls");
}

void consulta(int A[]){
	system("cls");	
	
	cout<<"Lista de datos"<<endl;
	for(int i=0; i<n; i++){
		cout<<A[i]<<" ";
	} // imprimimos los datos
	
	getch();
	system("cls");
}


int aleatoriedad(int A[]){
	system("cls");
	srand(static_cast<unsigned>(time(0))); // Semilla para la aleatoriedad
	
	cout<<"ALEATORIEDAD"<<endl;
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Índice aleatorio entre 0 y i
        // Intercambiar A[i] con A[j]
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    
    cout<<"Lista de datos"<<endl;
	for(int i=0; i<n; i++){
		cout<<A[i]<<" ";
	} // imprimimos los datos
		
	getch();
	system("cls");
}

void OrdenamientoSeleccion(int A[], int n){
	int minIndex, temp;
	system("cls");
	    
	    cout<<"ORDENAMIENTO POR SELECCION"<<endl;
    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        cout << "Pasada " << i + 1 << endl;
        
        for (int j = i + 1; j < n; j++) {
            cout << A[minIndex] << ">" << A[j];
            
            if (A[j] < A[minIndex]) {
                cout << " --> V  "; // Verdadera
                minIndex = j;
            } else {
                cout << " --> F  "; // Falsa
            }

            // Imprimir el arreglo en cada paso
            for (int k = 0; k < n; k++) {
                cout << A[k] << " ";
            }
            cout << endl;
        }

        // Realiza el intercambio solo si minIndex ha cambiado
        if (minIndex != i) {
            temp = A[i];
            A[i] = A[minIndex];
            A[minIndex] = temp;
        }
    }  
    getch();
	system("cls");
}

void OrdenamientoIntercambio(int A[], int n){
    system("cls"); // Limpiar la pantalla al inicio de la función
    int temp;
    
    	cout<<"ORDENAMIENTO POR INTERCAMBIO"<<endl;

    // Ciclo para las pasadas
    for(int i = 0; i < n - 1; i++) {
        cout << "\n\nPasada " << i + 1 << endl;

        // Ciclo para comparar cada elemento con los siguientes
        for(int j = i + 1; j < n; j++) {
            if(A[i] > A[j]) {
                cout << A[i] << " > " << A[j] << " --> V  ";
                
                // Intercambiar A[i] y A[j]
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            } else {
                cout << A[i] << " > " << A[j] << " --> F  ";
            }

            // Imprimir el estado actual del arreglo después de cada comparación
            for(int k = 0; k < n; k++) {
                cout << A[k] << " ";
            }
            cout << endl;
        }
    }
    getch();
	system("cls");

}

void OrdenamientoBurbuja(int A[], int n){
    int x, y, imp;
	system("cls");
		
		
	cout<<"ORDENAMIENTO POR BURBUJA"<<endl;	
    for (int p = 0; p < n - 1; p++) {
        cout << "Pasada " << p + 1 << endl;

        for (int c = 0; c < n - p - 1; c++) {
            if (A[c] > A[c + 1]) {
                cout << A[c] << " > " << A[c + 1] << " --> V  ";
                
                // Intercambio de valores
                x = A[c + 1];
                y = A[c];
                A[c] = x;
                A[c + 1] = y;

                // Imprimir el arreglo después del intercambio
                for (imp = 0; imp < n; imp++) {
                    cout << A[imp] << " ";
                }
                cout << endl;
            } else {
                cout << A[c] << " > " << A[c + 1] << " --> F  ";
                
                // Imprimir el arreglo sin intercambio
                for (imp = 0; imp < n; imp++) {
                    cout << A[imp] << " ";
                }
                cout << endl;
            }
        }
    }
    getch();
	system("cls");
}

void OrdenamientoQuicksort(int a[], int izq, int der) {
    if (izq >= der) return; // Caso base: el subarreglo es de tamaño 0 o 1

    int pivote = a[izq];
    int m = izq;
    int n = der;

    cout << "\nPivote elegido: " << pivote << " en la posicion " << izq << endl;

    while (true) {
        // Encuentra el primer elemento mayor o igual al pivote desde la izquierda
        do {
            m++;
        } while (a[m] < pivote && m <= der);

        // Encuentra el primer elemento menor o igual al pivote desde la derecha
        do {
            n--;
        } while (a[n] > pivote && n >= izq);

        if (m >= n) break; // Si los índices se cruzan, se termina el ciclo

        // Intercambio de a[m] y a[n]
        int aux = a[m];
        a[m] = a[n];
        a[n] = aux;

        cout << "Intercambio: a[" << m << "] = " << a[m] << " y a[" << n << "] = " << a[n] << " --> ";
        for (int i = izq; i <= der; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    // Colocar el pivote en su posición correcta
    a[izq] = a[n];
    a[n] = pivote;

    cout << "Pivote colocado en indice " << n << " --> ";
    for (int i = izq; i <= der; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Llamadas recursivas para las sublistas izquierda y derecha
    OrdenamientoQuicksort(a, izq, n - 1);
    OrdenamientoQuicksort(a, n + 1, der);
}

int BusquedaSecuencial(int A[], int n){
	int aux;
	system("cls");
	cout<<"BUSQUEDA SECUENCIAL"<<endl;
	cout<<"Ingresa el numero a buscar: ";
	cin>>aux;
	for(int i=0; i<n; i++){
		if(aux==A[i]){
			cout<<"Dato Encontrado: "<<A[i]<<" en la posicion: "<<i<<endl;
			getch();
			system("cls");
			return 0;
		}else{
			cout<<"Dato No Encontrado: "<<A[i]<<" en la posicion: "<<i<<endl;
		}
	}
	
	cout<<"Dato No Encontrado volviendo al programa principal..."<<endl;
	getch();
	system("cls");
}

int BusquedaBinaria(int A[], int n) {	
    int aux, medio, inicio = 0, fin = n - 1;
    system("cls");
    cout<<"BUSQUEDA BINARIA"<<endl;
    cout << "RECUERDE QUE ESTE METODO SOLO FUNCIONA SI LA LISTA ESTA ORDENADA"<<endl;
    cout << "Ingresa el numero a buscar: ";
    cin >> aux;
    
    while (inicio <= fin) {
    	
        medio = (inicio + fin)/2; 
		cout << "Comparando con: " << A[medio] << " en la posicion: " << medio << endl;
		       
        if (A[medio] == aux) {
            cout << "Dato Encontrado: " << A[medio] << " en la posicion: " << medio << endl;
            getch();
    		system("cls");
            return 0;
        } else if (A[medio] < aux) {
            cout << "Dato No Encontrado, buscando en la mitad derecha..." << endl;
            inicio = medio + 1;
        } else {
            cout << "Dato No Encontrado, buscando en la mitad izquierda..." << endl;
            fin = medio - 1;
        }
    }
    
	cout << "Dato No Encontrado volviendo al programa principal..." << endl;
    
    getch();
    system("cls");
}


void caratula(){//caratula de presentacion para la evaluacion
		system("cls");
		
    gotoxy(45,11);cout<<"Instituto Politecnico Nacional";
    gotoxy(27,12);cout<<"Escuela Superior De Ingeneria Mecanica y Electrica UNIDAD CULHUACAN";
    gotoxy(44,13);cout<<"Monroy Cortines Jacobo Emiliano";
    gotoxy(44,14);cout<<"  Martinez Martinez Jessica";
    gotoxy(43,15);cout<<"     Analisis de Algoritmos";
    gotoxy(47,16);cout<<"Programas de 2do Parcial";
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
