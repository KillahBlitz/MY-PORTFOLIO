#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include<string.h>

using namespace std;


class Persona {
public:
	Persona(char *n){ strcpy(nombre, n);}
	Persona(const Persona &p);
	virtual char *VerNombre(char *n){ strcpy(n, nombre); return n;}
	virtual Persona* Clonar(){ return new Persona(*this);}
protected:
	char nombre[30];
};

Persona::Persona(const Persona &p){
	strcpy(nombre, p.nombre);
	cout<<"Per: constructor copia."<<endl;
}

class Empleado : public Persona{
	public:
Empleado(char *n) : Persona(n){}
Empleado(const Empleado &e);

char *VerNombre(char *n){ strcpy(n, "Emp: "); strcat(n, nombre); return n;}
virtual Persona* Clonar(){return new Empleado(*this);}
};

Empleado::Empleado(const Empleado &e): Persona(e){
cout<<"Emp: constructor copia."<<endl;
}

class Estudiante : public Persona{
public:
	Estudiante(char *n): Persona(n){}
	Estudiante(const Estudiante &e);
	char *VerNombre(char *n){ strcpy(n, "Est: "); strcat(n, nombre); return n;}
	virtual Persona* Clonar(){ return new Estudiante(*this);}
};

Estudiante::Estudiante(const Estudiante &e) : Persona(e){
cout<<"Est: cosntructor copia."<<endl;
}

void gotoxy(int x, int y); 
void escribir();

int main(){
	
	system("COLOR 03");
	escribir();
	getch();
	system("cls");
	Beep(500, 100);
	
	
	char n[40];
	Persona *Emanuelito = new Estudiante("Emanuel");
	Persona *Roberto = new Estudiante("Roberto");
	Persona *Gente[2];
	cout<<Roberto->VerNombre(n)<<endl;
	cout<<Emanuelito->VerNombre(n)<<endl;
	Gente[0] = Roberto->Clonar();
	cout<<Gente[0]->VerNombre(n)<<endl;
	Gente[1] = Emanuelito->Clonar();
	cout<<Gente[1]->VerNombre(n)<<endl;
	
	delete Emanuelito;
	delete Roberto;
	delete Gente[0];
	delete Gente[1];
	
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