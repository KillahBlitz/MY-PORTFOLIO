#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<iomanip>
#include <windows.h>
#include<conio.h>

using namespace std;

const double PI=2.0*asin(1.0);

class Circulo{
protected:
	double radio;
public:
	Circulo(double=1.0);
	double calcval();
};

Circulo::Circulo(double r){

radio = r;

}

double Circulo::calcval(void){

	return(PI*radio*radio);
	
}

class Cilindro:public Circulo{
protected:		
	double largo;
public:
	Cilindro(double r=1.0, double l = 1.0):Circulo(r), largo(l){}
	double calcval();
};
double Cilindro::calcval(void)
{
	return (largo*Circulo::calcval());
}

void gotoxy(int x, int y); 
void escribir();

int main()
{
	system("COLOR 03");
	escribir();
	getch();
	system("cls");
	Beep(500, 100);
	
	
	
	Circulo circulo_1, circulo_2(2);
	Cilindro cilindro_1(3,4);
	cout<<"\n EL AREA DE CIRCULO_1 ES:" <<circulo_1.calcval()<<endl;
	cout<<"EL AREA DEL CIRCULO_2 ES:"<<circulo_2.calcval()<<endl;
	cout<<"EL VOLUMEN DEL CILINDRO_1 ES:"<<cilindro_1.calcval()<<endl;
	
	getch();
	system("cls");
	Beep(500, 100);
	
	circulo_1=cilindro_1;
	cout<<"\n EL AREA DEL CIRCULO ES AHORA:"<<circulo_1.calcval()<<endl;
	
	getch();
	system("pause");
	return (0);
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