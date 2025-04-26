#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>

using namespace std;

void gotoxy(int x, int y); 
void escribir();
void programa();

struct agenda
{
char nombre[20];
char telefono[15];
int edad;
}x;


int main(){
	
	escribir();
	programa();

system("PAUSE");
getch();
return(0);
}



void escribir(){
    gotoxy(45,11);cout<<"Instituto Politecnico Nacional";
    gotoxy(27,12);cout<<"Escuela Superior De Ingeneria Mecanica y Electrica UNIDAD CULHUACAN";
    gotoxy(44,13);cout<<"Monroy Cortines Jacobo Emiliano";
    gotoxy(43,14);cout<<"Programacion Orientada en Obejtos";
    gotoxy(49,15);cout<<" Practica Numero 1";
    gotoxy(51,16);cout<<"  Grupo 2CV32";
    gotoxy(45,17);cout<<"Profesor Osornio Soto Roberto \n\n";
    getch();    
}

void programa(){
	cout<<"Programa que registra el nombre, edad y telefono de 1 persona";
	cout<<"\n\n¿Cual es tu nombre?:";
		cin>>x.nombre;
	cout<<"¿Cual es tu edad?:";
		cin>>x.edad;
	cout<<"¿Cual es tu telefono?:";
		cin>>x.telefono;

	cout<<"\nLos datos de la persona son:\n";
	cout<<"nombre: "<<x.nombre<<endl;
	cout<<"edad: "<<x.edad<<endl;
	cout<<"telefono: "<<x.telefono;
		cout<<"\n";
		getch();
}

void gotoxy(int x, int y){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
