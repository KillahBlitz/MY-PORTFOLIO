#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>

using namespace std;


class Operaciones{
	private: 
		int n;
	public:
		Operacion(int _n);
		~Operaciones();
		void calificaciones();
};

Operaciones::Operacion(int _n){
	n=_n;
}

Operaciones::~Operaciones(){
	
}

void Operaciones::calificaciones(){
	int sum=0,res=0;
	cout<<"Ingrese la cantidad de calificaciones a evaluar: ";
	cin>>n;
	int *cal=new int[n];
	
	for(int c=0;c<=n;c++){
		cout<<"Ingrese la calificaci¢n "<<c+1<<": ";
		cin>>cal[c];
	
	for(int d=0;d<=n;d++){
		sum+=cal[d];
	}
	
	res=sum/n;
	cout<<"El promedio es de: "<<res<<endl<<endl;
	
	delete cal;
}
}

void gotoxy(int x, int y); 
void escribir();

int main(){
Operaciones s1;

system("COLOR 03");
	escribir();
	getch();
	system("cls");
	Beep(500, 100);

s1.calificaciones();

	system("pause");
	return 0;

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