#include<iostream>
#include<iomanip>
#include<conio.h>
#include <windows.h>

using namespace std;

class fecha{
private:
	int mes;
	int dia;
	int anio;

public:
	fechas(int, int, int);
	void ensenarfechas(void);
};

fecha::fechas(int m, int d, int a){
	mes = m;
	dia = d;
	anio = a;
}

void fecha::ensenarfechas(void){
	cout << "la fecha propuesta para nuestro objeto es: ";
	cout << setfill('0')
				<< setw(2) << mes << "/"
				<< setw(2) << dia << "/"
				<< setw(2) << anio<< endl;
	cout << endl;
	return;
}

void gotoxy(int x, int y); 
void escribir();

int main(){
	fecha a,b, c, d, e, f, g, h;
	
	system("COLOR 03");
	escribir();
	getch();
	system("cls");
	
	a.fechas(8,01,2003);
	b.fechas(28,01,2003);
	c.fechas(10,06,2003);
	d.fechas(16,11,2010);
	e.fechas(22,10,1976);
	f.fechas(27,02,2014);
	g.fechas(14,02,2019);
	h.fechas(30,07,2008);
	
	a.ensenarfechas();
	getch();
	b.ensenarfechas();
	getch();
	c.ensenarfechas();
	getch();
	d.ensenarfechas();
	getch();
	e.ensenarfechas();
	getch();
	f.ensenarfechas();
	getch();
	g.ensenarfechas();
	getch();
	h.ensenarfechas();
	getch();
}



void escribir(){
    gotoxy(45,11);cout<<"Instituto Politecnico Nacional";
    gotoxy(27,12);cout<<"Escuela Superior De Ingeneria Mecanica y Electrica UNIDAD CULHUACAN";
    gotoxy(44,13);cout<<"Monroy Cortines Jacobo Emiliano";
    gotoxy(43,14);cout<<"Programacion Orientada en Objetos";
    gotoxy(49,15);cout<<" Practica Numero 7";
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
