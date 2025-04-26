#include <iostream>
#include <iomanip> 
#include <conio.h>
#include <windows.h>

using namespace std;

class Binario{
	private:
		int num;
		int i;
		int j;
		int a;
		int b;
		int x[17];
	public:                                                
		Binario(int num=1, int i=1, int j=1, int a=1, int b=1);   
		Binario(const Binario &);                                
		~Binario();                                                 
		void menu();
		void numeros();
}

Binario::Binario(int v, int w, int x, int y, int z){
num = v;
i = w;
j = x;
a = y;
b = z;
}


Binario::Binario(const Binario &nuevo){
num = nuevo.num;
a = nuevo.a;
b = nuevo.b;
i = nuevo.i;
j = nuevo.j;
}

Binario::~Binario(){
cout<<"Objeto destruido\n";
}


void Binario::menu(){
cout<<"\nPROGRAMA QUE CONVIERTE UN NUMERO DECIMAL ENTERO DECIMAL";
cout<<"\nBINARIO EL RANGO DE NUEMRO A CONVERTIR SERA DE 0 A 65535";
cout<<"\nUSANDO UN ARREGLO UNIDIMENSIONAL";
}

void Binario::numeros(){
	
	cout<<"\n\nDE EL NUMERO A CONVERTIR";
	cin>>num;
		if(num>0&&num<65535){
			a=num;
			while(b!=0){
				b=num/2;
				x[i]=num%2;
				num=b;
			i++;
			
		cout<<"EL NUMERO BINARIO ES:";
		for(j=i-1; j<=1; j--){
			cout<<x[j];
		}
		cout<<endl;
		}
	else
		cout<<"\n VALOR FUERA DE RANGO FIN DEL PROGRAMA";
	}

void gotoxy(int x, int y); 
void escribir();



int main(){
	
	system("COLOR 03");
	escribir();
	getch();
	system("cls");
	
	Binario dato (20).datonuevo;
	datonuevo = dato;
	datonuevo.menu();
	datonuevo.numeros();
	system("pause");
	return(0);
}


void escribir(){
    gotoxy(45,11);cout<<"Instituto Politecnico Nacional";
    gotoxy(27,12);cout<<"Escuela Superior De Ingeneria Mecanica y Electrica UNIDAD CULHUACAN";
    gotoxy(44,13);cout<<"Monroy Cortines Jacobo Emiliano";
    gotoxy(43,14);cout<<"Programacion Orientada en Objetos";
    gotoxy(49,15);cout<<" Practica Numero 3";
    gotoxy(51,16);cout<<"  Grupo 2CV32";
    gotoxy(45,17);cout<<"Profesor Osornio Soto Roberto \n\n";  
}



void gotoxy(int x, int y){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}