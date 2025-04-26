#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

using namespace std;

void gotoxy(int x, int y); 
void escribir();

class Suma{
private:
	int a;
	int b;
public:
	void sumatoria (void){
		cout<<"Este programa suma dos enteros implementando clases:"<<endl;
	cout<<"Dame el valor de a:";	cin>>a;
	cout<<"Dame el valor de b:";	cin>>b;
		system("cls");
	cout<<"La suma es:"<<a+b<<endl;
	}
};


int main(){	
system("color 03");
	
escribir();	
		
	Suma s1;
	s1.sumatoria();
	
system("pause");
return(0);
}



void escribir(){
    gotoxy(45,11);cout<<"Instituto Politecnico Nacional";
    gotoxy(27,12);cout<<"Escuela Superior De Ingeneria Mecanica y Electrica UNIDAD CULHUACAN";
    gotoxy(44,13);cout<<"Monroy Cortines Jacobo Emiliano";
    gotoxy(43,14);cout<<"Programacion Orientada en Objetos";
    gotoxy(49,15);cout<<" Practica Numero 6";
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
