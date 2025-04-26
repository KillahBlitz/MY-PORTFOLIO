#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>

using namespace std;

void gotoxy(int x, int y);
void caratula(void);
void suma(void);

int main(){
	
	caratula();
	
	printf("\n SUMA DE 2 ENTEROS POR FUNCIONES DEL USUARIO \n\n");
	
	suma();
	system("PAUSE");
    getch();
    return 0;
}


void caratula(void){
	gotoxy(45,11);printf("Instituto Politecnico Nacional");
    gotoxy(27,12);printf("Escuela Superior De Ingeneria Mecanica y Electrica UNIDAD CULHUACAN");
    gotoxy(44,13);printf("Monroy Cortines Jacobo Emiliano");
    gotoxy(43,14);printf("Programacion Orientada en Obejtos");
    gotoxy(49,15);printf(" Practica Numero 1");
    gotoxy(51,16);printf("  Grupo 2CV32");
    gotoxy(45,17);printf("Profesor Osornio Soto Roberto \n\n");
    getch();
}

void suma(void){
	int a,b;
	
	printf("deme el valor de a: ");
		scanf("%d",&a);
	printf("\ndeme el valor de b: ");
		scanf("%d",&b);
	printf("\nla suma entre a y b es de: %d\n",a+b);
	getch();
}

void gotoxy(int x, int y){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
