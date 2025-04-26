#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<iomanip>
#include <windows.h>
#include<conio.h>

using namespace std;

class Producto{
public:
	Producto(char);
	~Producto();
	char LeerProducto();
protected:
	char DatoA;
};

class ProductoB : public Producto{
public:
	ProductoB(char, char);
	~ProductoB();
	char LeerProductoB();
protected:
	char DatoB;
};

Producto::Producto(char _DatoA){
	
	cout<<"Se creo un dato A"<<endl;
	DatoA = _DatoA;
}

Producto::~Producto(){
	cout<<"Se elimino el dato A"<<endl;
}

char Producto::LeerProducto(){

	cout<<"ingresa el Producto A:"<<endl; cin>>DatoA;
	return DatoA;
	Beep(500, 300);
	getch();
}

ProductoB::ProductoB(char _DatoA, char _DatoB) : Producto(_DatoA){
	
	cout<<"Se creo un dato B"<<endl;
	DatoB = _DatoB;
}

ProductoB::~ProductoB(){
	cout<<"Se elimino el dato B"<<endl;
	
}

char ProductoB::LeerProductoB(){
	
	cout<<"ingresa el Producto B:"<<endl; cin>>DatoB;
	return DatoB;
	Beep(500, 300);
	getch();
}

void gotoxy(int x, int y); 
void escribir();

int main(){
	
	system("COLOR 03");
	escribir();
	getch();
	system("cls");
	Beep(500, 100);
	
	ProductoB objeto(1, 2);
	cout<<"A = "<<objeto.LeerProducto()<<endl;
	cout<<"B = "<<objeto.LeerProductoB()<<endl;
	
	getch();
	system("cls");
	Beep(500, 100);
	return 0;
	Beep(500, 100);
	getch();
	system("pause");
}


void escribir(){
    gotoxy(45,11);cout<<"Instituto Politecnico Nacional";
    gotoxy(27,12);cout<<"Escuela Superior De Ingeneria Mecanica y Electrica UNIDAD CULHUACAN";
    gotoxy(44,13);cout<<"Monroy Cortines Jacobo Emiliano";
    gotoxy(43,14);cout<<"Programacion Orientada en Objetos";
    gotoxy(49,15);cout<<" Practica Numero 8";
    gotoxy(51,16);cout<<"  Grupo 2CV35";
    gotoxy(45,17);cout<<"Profesor Osornio Soto Roberto \n\n";  
}



void gotoxy(int x, int y){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
