#include <iostream>
#include <climits>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

// Estructura para un nodo de la lista
struct producto {
    string Nproducto;
    int id;
    int cantidad;
	producto *sig,*ant;
};

// Prototipos de funciones
void caratula(); //prototipo de caratula
void gotoxy(int x, int y);


// Funciones principales de los nodos
void Insertar(producto*& p, int g);
void AgregarNodo(producto*& p);
void EliminarPorID(producto*& p);
void ImprimirProductos(producto* p);

//funciones para el ordenamiento por Quicksort
void Intercambiar(producto* a, producto* b);
producto* Particion(producto* izq, producto* der, bool ordenarPorCantidad);
void QuicksortLista(producto* izq, producto* der, bool ordenarPorCantidad);
void OrdenarPorId(producto*& p);
void OrdenarPorCantidad(producto*& p);

//Funciones de ficheros
void GuardarProductosEnFichero(producto* p, const string& nombreFichero);
void CargarProductosDesdeFichero(producto*& p, const string& nombreFichero);





int main(){
	
	producto* p = NULL;
    int cantidad = 0;
    int opc = 0;
    
	system("Title ALGORITHM PROYECT");//funcion que cambia el titulo del programa
	system("COLOR 7D");//funcion que cambia los colores del programa
	caratula();//llamada de caratula
	
    
    cout << "Cuantos productos vas a ingresar? (0 para no ingresar productos): ";
    cin >> cantidad;
    for (int g = 0; g < cantidad; g++) {
        Insertar(p, g);
    }
	system("cls"); 
    
    
    do{
    	system("cls"); 
    	cout << "Que te gustaria hacer ahora?" << endl;
    	cout << "1.Agregar un producto" << endl;
    	cout << "2.Eliminar Producto" << endl;
    	cout << "3.Imprimir Productos" << endl;
    	cout << "4.Ordenar Productos por Indice" << endl;
    	cout << "5.Ordenar Productos por Cantidad" << endl;
    	cout << "6.Guardar productos en fichero" << endl;
    	cout << "7.Cargar Productos del fichero" << endl;
    	cout << "0.SALIR" << endl;
    	cout << ">>"; cin>>opc;
    	system("cls"); 
    	switch(opc){
    		case 1:
    			AgregarNodo(p);
    			break;
    		case 2:
    			EliminarPorID(p);
    			getch();
    			break;
    		case 3:
    			ImprimirProductos(p);
    			getch();
    			break;
    		case 4:
    			OrdenarPorId(p);
    			system("cls");
    			cout << "Productos correctamente ordenados por ID" << endl;
    			cout << "Consulta:" << endl;
    			ImprimirProductos(p);
    			getch();
    			break;
    		case 5:
    			 OrdenarPorCantidad(p);
    			cout << "Productos correctamente ordenados por Cantidad" << endl;
    			cout << "Consulta:" << endl;
    			ImprimirProductos(p);
    			getch();
    			break;
        case 6:
            GuardarProductosEnFichero(p, "productos.txt"); // Guardar en un archivo
            getch();
            break;
        case 7:
            CargarProductosDesdeFichero(p, "productos.txt"); // Cargar desde un archivo
            getch();
            break;
    		case 0:
    			break;
    	default:
    		cout<<"ERROR: Opcion no disponible, no existe, vuelve a seleccionar otra opcion";
    		getch();
    		break;
		}	
	}while(opc!=0);

    return 0;
}






// Función para insertar un nodo en la lista
void Insertar(producto*& p, int g) {
    producto* nuevo = new producto;
    cout << "Ingrese el nombre del producto " << g + 1 << ": ";
    cin >> nuevo->Nproducto;
    
    // Validación de la cantidad para que sea un número entero
    while (true) {
        cout << "Ingrese la cantidad de productos: ";
        cin >> nuevo->cantidad;

        // Verifica si la entrada es válida
        if (cin.fail()) {
            cin.clear(); // Limpia el error
            cin.ignore(INT_MAX, '\n'); // Ignora la entrada incorrecta
            cout << "Error: Por favor ingrese un numero valido para la cantidad." << endl;
        } else {
            break; // Si es válido, termina el ciclo
        }
    }
    
    nuevo->id = g+1;
    nuevo->sig = NULL;
    nuevo->ant = NULL;


    if (p == NULL) { // La lista está vacía
        p = nuevo;
    } else { // Insertar al final de la lista
        producto* actual = p;
        while (actual->sig != NULL) {
            actual = actual->sig;
        }
        actual->sig = nuevo;
        nuevo->ant = actual;
    }
}


// Función para agregar un nuevo nodo a la lista
void AgregarNodo(producto*& p) {
    producto* nuevo = new producto;
    int g = 0;
    cout << "Ingrese el nombre del nuevo producto: ";
    cin >> nuevo->Nproducto;

    // Validación de la cantidad para que sea un número entero
    while (true) {
        cout << "Ingrese la cantidad de productos: ";
        cin >> nuevo->cantidad;

        // Verifica si la entrada es válida
        if (cin.fail()) {
            cin.clear(); // Limpia el error
            cin.ignore(INT_MAX, '\n'); // Ignora la entrada incorrecta
            cout << "Error: Por favor ingrese un número válido para la cantidad." << endl;
        } else {
            break; // Si es válido, termina el ciclo
        }
    }
    
    producto* contador = p;
    while (contador != NULL) {
        g++;
        contador = contador->sig;
    }

    nuevo->id = g+1;
    nuevo->sig = NULL;
    nuevo->ant = NULL;
    
	// Insertar al final de la lista
    if (p == NULL) { // La lista está vacía
        p = nuevo;
    } else { // Insertar al final de la lista
        producto* actual = p;
        while (actual->sig != NULL) {
            actual = actual->sig;
        }
        actual->sig = nuevo;
        nuevo->ant = actual;
    }
}


void EliminarPorID(producto*& p) {
	int id = 0;
	
    if (p == NULL) {
        cout << "La lista esta vacia." << endl;
        return;
    }
	
	ImprimirProductos(p);
	cout<<"Ingresa el ID del producto que quiere eliminar: ";
	cin>>id;
	
    producto* actual = p;
    // Buscar el nodo con el ID dado
    while (actual != NULL && actual->id != id) {
        actual = actual->sig;
    }
    // Si no se encontró el nodo
    if (actual == NULL) {
        cout << "ERROR: No se encontró el ID " << id << "." << endl;
        return;
    }
    
    // Si el nodo a eliminar es el primero
    if (actual == p) {
        p = actual->sig;
        if (p != NULL) {
            p->ant = NULL;
        }
    } else {
        // Si el nodo a eliminar está en el medio o al final
        actual->ant->sig = actual->sig;
        if (actual->sig != NULL) {
            actual->sig->ant = actual->ant;
        }
    }

    // Eliminar el nodo de la memoria
    delete actual;
    cout << "Producto " << id << " eliminado correctamente." << endl;
}


// Función para imprimir los productos
void ImprimirProductos(producto* p) {
    producto* actual = p;

    // Imprime la cabecera con ancho fijo para cada columna
    cout << "\n" << setw(8) << left << "INDICE"
         << setw(20) << left << "PRODUCTO"
         << setw(10) << left << "CANTIDAD"
         << "GRAFICO" << endl;
    cout << string(50, '-') << endl;

    while (actual != NULL) {
        // Asegura que cada columna tenga un formato uniforme
        cout << setw(8) << left << actual->id
             << setw(20) << left << actual->Nproducto
             << setw(10) << left << actual->cantidad;
    	for (int i = 0; i < actual->cantidad; i++) {
        	cout << "*";
    	}
        cout << endl;
        actual = actual->sig;
    }
}


// Función de intercambio entre dos nodos
void Intercambiar(producto* a, producto* b) {
    string tempNombre = a->Nproducto;
    int tempId = a->id;
    int tempCantidad = a->cantidad;

    a->Nproducto = b->Nproducto;
    a->id = b->id;
    a->cantidad = b->cantidad;

    b->Nproducto = tempNombre;
    b->id = tempId;
    b->cantidad = tempCantidad;
}


// Función de partición que decide si se ordena por id o cantidad
producto* Particion(producto* izq, producto* der, bool ordenarPorCantidad) {
    producto* pivote = der;
    producto* i = izq;
    producto* j = der;

    while (true) {
        // Mover i hacia la derecha hasta encontrar un valor mayor que el pivote
        while ((ordenarPorCantidad ? i->cantidad : i->id) < (ordenarPorCantidad ? pivote->cantidad : pivote->id) && i != der)
            i = i->sig;

        // Mover j hacia la izquierda hasta encontrar un valor menor que el pivote
        while ((ordenarPorCantidad ? j->cantidad : j->id) > (ordenarPorCantidad ? pivote->cantidad : pivote->id) && j != izq)
            j = j->ant;

        // Si los punteros se cruzan, terminamos
        if (i == j || i->sig == j) break;

        // Intercambiamos los nodos i y j
        Intercambiar(i, j);
    }

    // Colocamos el pivote en su posición correcta
    Intercambiar(i, pivote);
    return i;
}


// Función recursiva para realizar el Quicksort en la lista
void QuicksortLista(producto* izq, producto* der, bool ordenarPorCantidad) {
    if (izq == NULL || der == NULL || izq == der || izq == der->sig)
        return;

    producto* pivote = Particion(izq, der, ordenarPorCantidad);

    QuicksortLista(izq, pivote->ant, ordenarPorCantidad);
    QuicksortLista(pivote->sig, der, ordenarPorCantidad);
}


// Función para ordenar por ID
void OrdenarPorId(producto*& p) {
    if (p == NULL) return;

    // Obtener el último nodo
    producto* der = p;
    while (der->sig != NULL) {
        der = der->sig;
    }

    QuicksortLista(p, der, false);
}


// Función para ordenar por Cantidad
void OrdenarPorCantidad(producto*& p) {
    if (p == NULL) return;

    // Obtener el último nodo
    producto* der = p;
    while (der->sig != NULL) {
        der = der->sig;
    }

    QuicksortLista(p, der, true);
}


// Función para guardar productos en un archivo de texto
void GuardarProductosEnFichero(producto* p, const string& nombreFichero) {
    ofstream archivo(nombreFichero.c_str());

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para guardar los productos." << endl;
        return;
    }

    producto* actual = p;
    while (actual != NULL) {
        archivo << actual->id << ","
                << actual->Nproducto << ","
                << actual->cantidad << endl;
        actual = actual->sig;
    }

    archivo.close();
    cout << "Productos guardados exitosamente en " << nombreFichero << endl;
}


// Función para cargar productos desde un archivo de texto
void CargarProductosDesdeFichero(producto*& p, const string& nombreFichero) {
    ifstream archivo(nombreFichero.c_str());

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para cargar los productos." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        producto* nuevo = new producto;
        string temp;

        // Leer los datos de cada línea y asignarlos a los campos del nuevo nodo
        getline(ss, temp, ',');
        stringstream(temp) >> nuevo->id; //el ID
        getline(ss, nuevo->Nproducto, ','); // Nombre del producto
        getline(ss, temp, ',');
        stringstream(temp) >> nuevo->cantidad; //la cantidad

        // Insertar el nuevo nodo al final de la lista
        nuevo->sig = NULL;
        nuevo->ant = NULL;

        if (p == NULL) {
            p = nuevo;
        } else {
            producto* actual = p;
            while (actual->sig != NULL) {
                actual = actual->sig;
            }
            actual->sig = nuevo;
            nuevo->ant = actual;
        }
    }

    archivo.close();
    cout << "Productos cargados exitosamente desde " << nombreFichero << endl;
}






void caratula(){//caratula de presentacion para la evaluacion
		system("cls");
		
    gotoxy(45,11);cout<<"Instituto Politecnico Nacional";
    gotoxy(27,12);cout<<"Escuela Superior De Ingeneria Mecanica y Electrica UNIDAD CULHUACAN";
    gotoxy(44,13);cout<<"Monroy Cortines Jacobo Emiliano";
    gotoxy(44,14);cout<<"  Martinez Martinez Jessica";
    gotoxy(43,15);cout<<"     Analisis de Algoritmos";
    gotoxy(47,16);cout<<"Proyecto 3er Parcial";
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
