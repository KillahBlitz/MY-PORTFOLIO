#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
#include<windows.h>
#include<list>

#define TECLA_AR 72
#define TECLA_AB 80
#define ENTER 13


//using namespace std;


void gotoxy(int x, int y);
void inicio();
int retorno(int);
void Portada(); 
void menu();
void movimiento();
void ocultar();
void limites();


class Coordenadas{
	protected:
		int x, y;
	public:
	Coordenadas (int xx, int yy);
	~Coordenadas();
		int X(){ return x; }
		int Y(){ return y; }
};

class Personaje: public Coordenadas{
private:
		int corazones;
		int vidas;
public:
		
	Personaje(int xx, int yy, int cc, int vv);
	~Personaje();
		int VID(){ return vidas; }
		void COR();
		void pintar();
		void borrar();
		void mover();
		void vida();
		void muerte();
};

class Meteoro: public Coordenadas{
	private:
	public:
	Meteoro(int xx, int yy);
	~Meteoro();
		void crear();
		void dispersion();
		void colision(class Personaje &P1);	
};

class Bala: public Coordenadas{
	private:
	public:
	Bala(int xx, int yy);
	~Bala();
		void trayectoria();
		bool choque();
};


Coordenadas::Coordenadas(int xx, int yy){
	x = xx;
	y = yy;
}

Personaje::Personaje(int xx, int yy, int cc, int vv): Coordenadas(xx, yy){
	corazones = cc;
	vidas = vv;
}

Meteoro::Meteoro(int xx, int yy): Coordenadas(xx, yy){}
Bala::Bala(int xx, int yy): Coordenadas(xx, yy){}


Coordenadas::~Coordenadas(){}

Personaje::~Personaje(){
	limites();
	gotoxy(37,17);cout<<"Todos los jugadores han sido eliminados";
}

Meteoro::~Meteoro(){}

Bala::~Bala(){}





void Personaje::COR(){
	corazones--;
	Beep(1500, 100);
}



void Personaje::pintar(){
	ocultar();
	gotoxy(x,y-1);printf("%c%c%c%c%c",200,203,167,203,188);
	gotoxy(x,y);printf(" %c%c%c",200,206,188);
	gotoxy(x,y+1);printf(" %c%c%c",201,202,187);
	gotoxy(x,y+2);printf(" %c %c",207,207);
}



void Personaje::borrar(){
	gotoxy(x,y-1); printf("        ");
	gotoxy(x,y); printf("        ");
	gotoxy(x,y+1); printf("        ");
	gotoxy(x,y+2); printf("        ");
}



void Personaje::mover(){
	if(kbhit()){
			char tecla = getch();
			borrar();
			if(tecla == 'a' && x>3) x--;
			if(tecla == 'd' && x+5<115) x++;
			if(tecla == 'w' && y>5) y--;
			if(tecla == 's' && y+5<35) y++;
			pintar();
			vida();
	}
}



void Personaje::vida(){
	gotoxy(90,1);printf("VIDAS REST:%d",vidas);
	gotoxy(104,1);printf("SALUD:");
	gotoxy(110,1);printf("     ");
	for(int i = 0 ; i < corazones; i++){
		
		gotoxy(110+i,1);printf("%c",3);
	}
		
}



void Personaje::muerte(){
	if(corazones == 0){
		borrar();
		gotoxy(x,y-1); printf("  **  ");
		gotoxy(x,y); printf(" **** ");
		gotoxy(x,y+1); printf(" **** ");
		gotoxy(x,y+2); printf("  **  ");
		Sleep(200);
		
		borrar();
		gotoxy(x,y-1); printf("*  **  *");
		gotoxy(x,y); printf(" * ** * ");
		gotoxy(x,y+1); printf(" * ** * ");
		gotoxy(x,y+2); printf("*  **  *");
		Beep(200, 500);
		Sleep(200);
		borrar();
		
		vidas--;
		corazones = 5;
		vida();
		pintar();
	}
}



void Meteoro::crear(){
	gotoxy(x,y);printf("%c",184);
}



void Meteoro::dispersion(){
	gotoxy(x,y);printf(" ");
	y++;
	if (y>32){
		x = rand()%110 + 4;
		y = 4;	
	}
	crear();
}

void Meteoro::colision(class Personaje &P1){
	if( x>=P1.X() && x<P1.X()+5 && y>=P1.Y() && y<=P1.Y()+3){
		P1.COR();
		P1.borrar();
		P1.pintar();
		P1.vida();
	x = rand()%110 + 4;
	y = 4;	
	}
}

void Bala::trayectoria(){
	gotoxy(x,y);printf(" ");
	y--;
	gotoxy(x,y);printf("%c",207);
}



bool Bala::choque(){
	if(y==3) 
	return true;
	return false;
} 






int main(){
system("Title SolidWorld32");
system("COLOR 0D");

	inicio();
	
	system("cls");
	limites();
	gotoxy(16,9);cout<<"Gracias por probar mi proyecto, espero puedas ganara mas puntos la siguiente ronda :D\n";
	gotoxy(37,10);cout<<"pulsa enter para continuar...";
	getch();

return 0;
}






void inicio(){
	bool repite = true;
	int opcion;
	Personaje P1(59,30,5,3);
	
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<"                       	______________________________________________________________ "<<endl;
				cout<<"                        |                                                              |"<<endl;
				cout<<"                        |                  INSTITUTO POLITECNICO NACIONAL              |"<<endl;
				cout<<"                        |      Escuela Superior de Ingeieria Mecanica y electronica    |"<<endl;
				cout<<"                        |                      	  Unidad Culhuacan                     |"<<endl;
				cout<<"                        |                  Monroy Cortines Jacobo Emiliano             |"<<endl;
				cout<<"                        |                 Programacion orientada a objetos             |"<<endl;
				cout<<"                        |                          Proyecto Final                      |"<<endl;
				cout<<"                        |                           Grupo: 2CV35                       |"<<endl;
				cout<<"                        |                   Profesor  Osorino Soto Roberto             |"<<endl;
				cout<<"                        |______________________________________________________________|"<<endl<<endl;
	
		
	cout<<"MENU DE INICIO\n"<<endl;
		
	cout<<"\t1. Jugar"<<endl;
	cout<<"\t2. Salir"<<endl;
	
	do{
	int n = 2;
	opcion = retorno(n);
	
	
	switch(opcion){
			case 1:
int op;
op = 1;
	while(op == 1){		
	system("cls");
		Portada();
		ocultar();
		limites();
		menu();
		limites();
	
P1.pintar();
P1.vida();

	movimiento();
	Beep(250, 1000);
	Beep(100, 1200);
	Sleep(200);
	
	system("cls");
	limites();
	gotoxy(37,10);cout<<"Deseas Reiniciar el juego?";
	gotoxy(37,11);cout<<"1.si";
	gotoxy(37,12);cout<<"2.no"<<endl;
	gotoxy(37,13);cout<<"Digita dos veces el numero de la opcion que deseas: "<<endl;
	getch();
	gotoxy(37,14);cin>>op;
	
}
	repite = false;
				break;
		
			case 2:
	system("cls");
		limites();
		gotoxy(37,9);cout<<"Gracias por probar mi proyecto \n";
		gotoxy(37,10);cout<<"pulsa enter para continuar...";
	getch();
	system("cls");
				repite = false;
					break;
		}
	}while(repite);
}

int retorno(int){
	cout<<"\n\t\t\t\t       Escoja la opcion que desea tomar";
	cout<<"\n\t\t\t muevase entre las opciones con las teclas de arriba y abajo";
	cout<<"\n\t\t\t\t para seleccionar una opcion, presione ENTER";
	int n = 2;
	bool repite2 = true;
	int opcionseleccionada = 1;
	int tecla;
	
	do{
	gotoxy(5, 20 + opcionseleccionada);cout<<"   ";
	gotoxy(5, 21 + opcionseleccionada);cout<<"==>";
	gotoxy(5, 22 + opcionseleccionada);cout<<"   ";
	do{
	tecla = getch();	
	}while(tecla != TECLA_AR &&  tecla != TECLA_AB && tecla != ENTER);
	
	switch(tecla){
		case TECLA_AR:
		opcionseleccionada--;
		
			if(opcionseleccionada < 1){
				opcionseleccionada = n;
			}
		break;
		
		case TECLA_AB:
		
			if(opcionseleccionada > n-1){
				opcionseleccionada = 0;
			}
		opcionseleccionada++;
		break;
		
		case ENTER:
		repite2 = false;
		break;
	}
	}while(repite2);


	return opcionseleccionada;
}

void Portada(){
	HANDLE consola=GetStdHandle(STD_OUTPUT_HANDLE);
	char progreso=char(219);
	
	char barra[17]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
					,' ',' ',' ',' ',' ',' ',0};
	int tiempoFaltante=10;

	for(int contador=0;contador<10;contador++){
		limites();
		barra[contador]=progreso;
		#ifdef _WIN32
		Sleep(1000);
		system("cls");
		#else
		sleep(1000);
		clrscr();
		#endif
		tiempoFaltante--;
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<"                          ______________________________________________________________ "<<endl;
				cout<<"                          |                                                             |"<<endl;
				cout<<"                          |                      Cargando videojuego                    |"<<endl;
				cout<<"                          |                        Espere Porfavor                      |"<<endl;
				cout<<"                          |                 El autor de este programa es:               |"<<endl;
				cout<<"                          |                Monroy Cortines Jacobo Emiliano              |"<<endl;
				cout<<"                          |_____________________________________________________________|"<<endl<<endl;
				cout<<setw(40)<<"Faltan "<<tiempoFaltante<<" segundos para que desaparesca la portada"<<endl<<endl;
				cout<<setw(70)<<barra<<endl;
			
		if(tiempoFaltante==5){
				#ifdef _WIN32
				system("cls");
				#else
				clrscr();
				#endif
				
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<"                           ______________________________________________________________ "<<endl;
				cout<<"                          |                                                              |"<<endl;
				cout<<"                          |                      Teclas de movimiento                    |"<<endl;
				cout<<"                          |                 W = hacia arriba S = hacia abajo             |"<<endl;
				cout<<"                          |            A = hacia la izquierda D = hacia la derecha       |"<<endl;
				cout<<"                          |                       Teclas Adicionales                     |"<<endl;
				cout<<"                          |                           E = disparar                       |"<<endl;
				cout<<"                          |______________________________________________________________|"<<endl<<endl;
				cout<<"                                   	SOLIDWORK EL VIDEOJUEGO DE NAVES RETRO"<<endl;
				cout<<setw(40)<<"Faltan "<<tiempoFaltante<<" segundos para que desaparesca la portada"<<endl<<endl;
				cout<<setw(70)<<barra<<endl;
		}
		
		if(tiempoFaltante==4){
				#ifdef _WIN32
				system("cls");
				#else
				clrscr();
				#endif
				
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<"                           ______________________________________________________________ "<<endl;
				cout<<"                          |                                                              |"<<endl;
				cout<<"                          |                      Teclas de movimiento                    |"<<endl;
				cout<<"                          |                 W = hacia arriba S = hacia abajo             |"<<endl;
				cout<<"                          |            A = hacia la izquierda D = hacia la derecha       |"<<endl;
				cout<<"                          |                       Teclas Adicionales                     |"<<endl;
				cout<<"                          |                           E = disparar                       |"<<endl;
				cout<<"                          |______________________________________________________________|"<<endl<<endl;
				cout<<"                                   	SOLIDWORK EL VIDEOJUEGO DE NAVES RETRO"<<endl;
				cout<<setw(40)<<"Faltan "<<tiempoFaltante<<" segundos para que desaparesca la portada"<<endl<<endl;
				cout<<setw(70)<<barra<<endl;
		}
		
		if(tiempoFaltante==3){
				#ifdef _WIN32
				system("cls");
				#else
				clrscr();
				#endif
				
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<"                           ______________________________________________________________ "<<endl;
				cout<<"                          |                                                              |"<<endl;
				cout<<"                          |                      Teclas de movimiento                    |"<<endl;
				cout<<"                          |                 W = hacia arriba S = hacia abajo             |"<<endl;
				cout<<"                          |            A = hacia la izquierda D = hacia la derecha       |"<<endl;
				cout<<"                          |                       Teclas Adicionales                     |"<<endl;
				cout<<"                          |                           E = disparar                       |"<<endl;
				cout<<"                          |______________________________________________________________|"<<endl<<endl;
				cout<<"                                   	SOLIDWORK EL VIDEOJUEGO DE NAVES RETRO"<<endl;
				cout<<setw(40)<<"Faltan "<<tiempoFaltante<<" segundos para que desaparesca la portada"<<endl<<endl;
				cout<<setw(70)<<barra<<endl;
		}
		
		if(tiempoFaltante==2){
				#ifdef _WIN32
				system("cls");
				#else
				clrscr();
				#endif
				
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<"                           ______________________________________________________________ "<<endl;
				cout<<"                          |                                                              |"<<endl;
				cout<<"                          |                      Los asteroides son mas                  |"<<endl;
				cout<<"                          |                      faciles de esquivar si                  |"<<endl;
				cout<<"                          |                 te mueves de izquiera a derecha              |"<<endl;
				cout<<"                          |______________________________________________________________|"<<endl<<endl;
				cout<<"                                   	SOLIDWORK EL VIDEOJUEGO DE NAVES RETRO"<<endl;
				cout<<setw(40)<<"Faltan "<<tiempoFaltante<<" segundos para que desaparesca la portada"<<endl<<endl;
				cout<<setw(70)<<barra<<endl;
		}
		
		if(tiempoFaltante==1){
				#ifdef _WIN32
				system("cls");
				#else
				clrscr();
				#endif
				
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<"                           ______________________________________________________________ "<<endl;
				cout<<"                          |                                                              |"<<endl;
				cout<<"                          |                      Los asteroides son mas                  |"<<endl;
				cout<<"                          |                      faciles de esquivar si                  |"<<endl;
				cout<<"                          |                 te mueves de izquiera a derecha              |"<<endl;
				cout<<"                          |______________________________________________________________|"<<endl<<endl;
				cout<<"                                   	SOLIDWORK EL VIDEOJUEGO DE NAVES RETRO"<<endl;
				cout<<setw(40)<<"Faltan "<<tiempoFaltante<<" segundos para que desaparesca la portada"<<endl<<endl;
				cout<<setw(70)<<barra<<endl;
		}
		
		if(tiempoFaltante==0){
				#ifdef _WIN32
				system("cls");
				#else
				clrscr();
				#endif
				
				
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<"                           ______________________________________________________________ "<<endl;
				cout<<"                          |                                                              |"<<endl;
				cout<<"                          |                      Preparate para triunfar                 |"<<endl;
				cout<<"                          |______________________________________________________________|"<<endl<<endl;
				cout<<"                                   	SOLIDWORK EL VIDEOJUEGO DE NAVES RETRO"<<endl;
				cout<<setw(40)<<"Faltan "<<tiempoFaltante<<" segundos para que desaparesca la portada"<<endl<<endl;
				cout<<setw(70)<<barra<<endl;
		}
		
	}
	#ifdef _WIN32
	Sleep(1000);
	system("cls");
	#else
	sleep(1000);
	clrscr();
	#endif
}



void menu(){
	limites();	
	gotoxy(37,9);cout<<"En un futuro lejano, durante 6 millones de lustros\n";
		gotoxy(37,10);cout<<"pulsa enter para continuar\n";
	getch();
	gotoxy(34,10);cout<<"el planeta tierra fue raptado hacia otro sistema solar\n";
	gotoxy(35,11);cout<<"hacia otro sistema que esta a punto de ser colapsado\n";
		gotoxy(39,12);cout<<"pulsa enter para continuar\n";
	getch();
	gotoxy(38,12);cout<<"un mundo hacia el futuro, la paz queda incierta\n";
		gotoxy(37,13);cout<<"pulsa enter para continuar\n";
	getch();
	gotoxy(32,13);cout<<"los mejores soldados son reunidos para protejer un legado\n";
	gotoxy(32,14);cout<<"donde los humanos luchamos para permanecer en el universo\n";
		gotoxy(37,15);cout<<"pulsa enter para continuar\n";
	getch();
	gotoxy(32,15);cout<<"un equipo de 4 personas intentan salvar a la raza humana\n";
	gotoxy(39,16);cout<<"su unico objetivo es cazar a los tetradimons\n";
		gotoxy(37,17);cout<<"pulsa enter para continuar\n";
	getch();
	gotoxy(36,17);cout<<"para asi poder conseguir el nucleo de dimensiones\n";
	gotoxy(35,18);cout<<"y llevar a la raza humana de nuevo al sistema solar\n";
	getch();
	system("cls");
	
	limites();
	gotoxy(50,10);cout<<"Teclas de movimiento\n";
	gotoxy(25,11);cout<<"W = hacia arriba S = hacia abajo A = hacia la izquierda D = hacia la derecha\n";
		gotoxy(51,12);cout<<"Teclas Adicionales\n";
	gotoxy(54,13);cout<<"E = disparar\n";
		gotoxy(44,14);cout<<"pulsa enter para continuar...\n";
	getch();
	system("cls");
}



void movimiento(){
Personaje P1(59,30,5,3);
Meteoro M1(10,5);
Meteoro M2(30,20);
Meteoro M3(50,9);
Meteoro M4(65,8);
Meteoro M5(70,14);

	list<Meteoro*> A;
	list<Meteoro*>::iterator itA;

	list<Bala*> B;
	list<Bala*>::iterator it;
	for(int i=0; i<5; i++){
		A.push_back(new Meteoro(rand()%75+3, rand()%5+4));
	}
	
	bool game_over = false;
	int puntos = 0;
	while(!game_over){
		
		gotoxy(4,1);printf("PUNTOS: %d", puntos);
		if(kbhit()){
		char tecla = getch();
		if(tecla == 'e')
		B.push_back(new Bala(P1.X()+2, P1.Y()-1));
		}
		for(it = B.begin(); it != B.end(); it++){
			(*it)->trayectoria();
			if((*it)->choque()){
				gotoxy((*it)->X(), (*it)->Y()); printf(" ");
				delete(*it);
				it = B.erase(it);
			}
		}
		
		M1.dispersion(); M1.colision(P1);
		M2.dispersion(); M2.colision(P1);
		M3.dispersion(); M3.colision(P1);
		M4.dispersion(); M4.colision(P1);
		M5.dispersion(); M5.colision(P1);
		for(itA=A.begin(); itA!=A.end(); itA++){
			(*itA)->dispersion();
			(*itA)->colision(P1);
		}
		
		for(itA=A.begin(); itA!=A.end(); itA++){
			for(it=B.begin(); it!=B.end(); it++){
			if((*itA)->X() == (*it)->X() && ((*itA)->Y()+1==(*it)->Y() || (*itA)->Y()==(*it)->Y() )){
				gotoxy((*it)->X(),(*it)->Y());printf(" ");
				delete(*it);
				it = B.erase(it);
				
				A.push_back(new Meteoro(rand()%75+3, 4));
				gotoxy((*itA)->X(),(*itA)->Y());printf(" ");
				delete(*itA);
				itA = A.erase(itA);
				
				puntos+=5;
				}
			}
		}
		if(P1.VID() == 0) game_over = true;
		Sleep(30);
		P1.muerte();
		P1.mover();
		
	}
}



void ocultar(){
	HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = FALSE;
	
	SetConsoleCursorInfo(hcon,&cci);
}



void limites(){
	for(int i = 2 ; i<118 ; i++){
		gotoxy(i,2);printf("%c",205);
		gotoxy(i,33);printf("%c",205);
	}
	
	for(int i = 3 ; i<33 ; i++){
		gotoxy(2,i);printf("%c",186);
		gotoxy(118,i);printf("%c",186);
	}
	
	gotoxy(2,2);printf("%c",201);
	gotoxy(2,33);printf("%c",200);
	gotoxy(118,2);printf("%c",187);
	gotoxy(118,33);printf("%c",188);
}



void gotoxy(int x, int y){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
