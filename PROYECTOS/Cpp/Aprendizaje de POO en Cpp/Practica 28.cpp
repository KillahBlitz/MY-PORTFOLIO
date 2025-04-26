#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<iomanip>
#include<conio.h>

using namespace std;

template<class t1, class t2>
long double mayor(t1 a, t2 b){
	 if(a>b)
	 return a;
	 else
	 return b;
	 
}

void gotoxy(int x, int y); 
void caratula();

int main()
{
	system("color 03");
	caratula();
	getch();
	system("cls");

	
	int c=5, d=58;
	float e=32.2, f=20.5;
	long i=23233235, g=672823;
	long double k=2938.9898, l=5678.3245;
	
	
cout<<"EL VALOR MAYOR DE LOS ENTEROS ES:          "<<mayor(c,d)<<endl;
cout<<"EL VALOR MAYOR DE LOS FLOTANTES ES:        "<<mayor(e,f)<<endl;
cout<<"EL VALOR MAYOR DE LOS DOBLES ES:           "<<mayor(k,l)<<endl;
cout<<"EL VALOR MAYOR DE LOS DE LOS FLOTANTES LARGOS ES:     "<<mayor(k,d)<<endl;

system("pause");
return 0;
	
}
void caratula()
{
    gotoxy(45,11);cout<<"Instituto Politecnico Nacional";
    gotoxy(27,12);cout<<"Escuela Superior De Ingeneria Mecanica y Electrica UNIDAD CULHUACAN";
    gotoxy(44,13);cout<<"Monroy Cortines Jacobo Emiliano";
    gotoxy(43,14);cout<<"Programacion Orientada en Objetos";
    gotoxy(49,15);cout<<" Practica Numero 8";
    gotoxy(51,16);cout<<"  Grupo 2CV35";
    gotoxy(45,17);cout<<"Profesor Osornio Soto Roberto \n\n";  
}

void gotoxy(int x, int y)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
