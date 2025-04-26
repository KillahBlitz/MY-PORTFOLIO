#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>


using namespace std;


class Operacion{
	private:
		float x;
		float y;
	public:
		void mul();
		Operacion(float a=5, float b=9);
		~Operacion(){};
};

Operacion::Operacion(float a, float b){
	x=a;
	y=b;
}
void Operacion::mul(){
	cout<<"El resultado de la multiplicacion es: "<<(x*y)<<"\n"<<endl;
}

void gotoxy(int x, int y); 
void escribir();


int main(){
	
	system("COLOR 03");
	escribir();
	getch();
	system("cls");
	Beep(500, 100);
	
	Operacion s1;
	
	s1.mul();
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