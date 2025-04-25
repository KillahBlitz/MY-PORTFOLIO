#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<list>

#define ARRIBA       'w'
#define ABAJO        's'
#define IZQUIERDA    'a'
#define DERECHA      'd'
#define TECLA_AR     72
#define TECLA_AB     80
#define ENTER        13

using namespace std;

int backcolor=0;
int dir=0;
int x=39;
int y=22;
int anteriorpx,anteriorpy;
char tecla;
void gotoxy(int x, int y);
void setCColor(int color);
void ocultarcursor();
void caratula();
void menu();
int retorno(int);
int op;

long int puntos= -5;
int vidas=3;



int color[8]={
0x009,
0x00E,
0X00C,
0X002,
0X00B,
0X005,
0X00F,
0x00d,
};


char mapa[50][100]={
"                                                        ",
"                  AXXXXXXXXXXXXXXXXXXXB AXXXXXXXXXXXXXXXXXXXB",
"                  Y___________________Y Y___________________Y",
"                  Y_AXXXXXB_AXXXXXXXB_Y Y_AXXXXXXXB_AXXXXXB_Y",
"                  Y_Y     Y_Y       Y_Y Y_Y       Y_Y     Y_Y",
"                  Y_DXXXXXC_DXXXXXXXC_DXC_DXXXXXXXC_DXXXXXC_Y",
"                  Y________+_________+___+_________+________Y",
"                  Y_AXXXXXB_AXB_AXXXXXXXXXXXXXB_AXB_AXXXXXB_Y",
"                  Y_DXXXXXC_Y Y_DXXXXB   AXXXXC_Y Y_DXXXXXC_Y",
"                  Y_________Y Y______Y   Y______Y Y_________Y",
"                  DXXXXXXXB_Y DXXXXB_Y   Y_AXXXXC Y_AXXXXXXXC",
"                          Y_Y AXXXXC_DXXXC_DXXXXB Y_Y        ",
"                          Y_Y Y_________________Y Y_Y        ",
"                  XXXXXXXXC_DXC_AXXXXXX XXXXXXB_DXC_DXXXXXXXX",
"                  _________+____Y      *      Y____+_________",
"                  XXXXXXXXB_AXB_DXXXXXXXXXXXXXC_AXB_AXXXXXXXX",
"                          Y_Y Y_________________Y Y_Y        ",
"                          Y_Y Y_AXXXXXXXXXXXXXB_Y Y_Y        ",
"                  AXXXXXXXC_DXC_DXXXXB   AXXXXC_DXC_DXXXXXXXB",
"                  Y________+_________Y   Y_________+________Y",
"                  Y_AXXXXXB_AXXXXXXB_Y   Y_AXXXXXXB_AXXXXXB_Y",
"                  Y_DXXXB Y_DXXXXXXC_DXXXC_DXXXXXXC_Y AXXXC_Y",
"                  Y_____Y Y_________+_____+_________Y Y_____Y",
"                  DXXXB_Y Y_AXB_AXXXXXXXXXXXXXB_AXB_Y Y_AXXXC",
"                  AXXXC_DXC_Y Y_DXXXXB   AXXXXC_Y Y_DXC_DXXXB",
"                  Y_________Y Y______Y   Y______Y Y_________Y",
"                  Y_AXXXXXXXC DXXXXB_Y   Y_AXXXXC DXXXXXXXB_Y",
"                  Y_DXXXXXXXXXXXXXXC_DXXXC_DXXXXXXXXXXXXXXC_Y",
"                  Y_________________+_____+_________________Y",
"                  DXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXC",
};


void pintar_mapa()
{
	for(int i=0;i<78;i++){
	   for(int j=0;j<30;j++){
    	gotoxy(i,j);
	
        	if(mapa[j][i]=='X'){setCColor(color[0]);printf("%c",205);}
        	if(mapa[j][i]=='_'){setCColor(color[1]);printf("%c",250);}
        	else if(mapa[j][i]=='Y'){setCColor(color[0]);printf("%c",186);}
        	else if(mapa[j][i]=='A'){setCColor(color[0]);printf("%c",201);}
        	else if(mapa[j][i]=='B'){setCColor(color[0]);printf("%c",187);}
        	else if(mapa[j][i]=='C'){setCColor(color[0]);printf("%c",188);}
    	    else if(mapa[j][i]=='D'){setCColor(color[0]);printf("%c",200);}
    	}
	}

}


void pacman(int x,int y){
	setCColor(color[1]);
	gotoxy(x,y);printf("%c",1);
}


void borrar_pacman(int x, int y){
	gotoxy(x,y);printf(" ");
	if(mapa[y][x]=='_'){mapa[y][x]=' ';puntos+=5;}
}


void teclear()
{
	if(kbhit()){
		tecla = getch();
		switch(tecla){
			case ARRIBA:
			dir=0;
			break;
			
			case ABAJO:
			dir=1;
			break;
			
			case IZQUIERDA:
			dir=3;
			break;
			
			case DERECHA:
			dir=2;
			break;
		}
	}
}


class posicion{

 protected:
    int _x;
    int _y;
 public:
    posicion(int xx, int yy);
 };

 
class fantasma:public posicion
{
	private:
	    int fdir;
    	int col;
	public:
		fantasma(int x,int y, int color);
		void dibujar_fantasma() const;
		void borrar_fantasma() const ;
		void mover_fantasma();
		void choque_pacman();
	
};


posicion::posicion(int xx, int yy){
 _x=xx;
_y=yy;
}


fantasma::fantasma(int xx, int yy, int color):posicion(xx,yy)
{
	
	col=color;
	fdir=rand()%4;
}


void fantasma::dibujar_fantasma()const
{
	setCColor(color[col]);
	gotoxy(_x,_y);printf("%c",254);
}


void fantasma::borrar_fantasma()const
{
	gotoxy(_x,_y);printf(" ");
}


void fantasma::choque_pacman()
{
	if(y==_y && x==_x||(fdir==0 && dir==1 || fdir==1 && dir==0||fdir==2 && dir==3||fdir==3 && dir==2)&&(_y==anteriorpy && _x==anteriorpx)){
		x=39;
		y=22;
		dir=4;
		vidas--;
		
	}
}


void fantasma::mover_fantasma()
{
	borrar_fantasma();
	choque_pacman();
	int bolx=_x,boly=_y;
	
	if(mapa[_y][_x]=='+'){
		fdir=rand()%4;
	}
	if(mapa[_y][_x]=='*'){
		fdir=0;
	}
	if(fdir==2){
		if(mapa[_y][_x+1] !='X'&&mapa[_y][_x+1] !='A' && mapa[_y][_x+1]!='Y' 
		&& mapa[_y][_x+1] !='B' &&mapa[_y][_x+1]!='C' && mapa[_y][_x+1]!='D')_x++;
		else fdir=rand()%4;
		
	}
	if(fdir==3){
		if(mapa[_y][_x-1]!='X'&&mapa[_y][_x-1]!='A'&&mapa[_y][_x-1]!='Y' 
		&& mapa[_y][_x-1] !='B' &&mapa[_y][_x-1]!='C' && mapa[_y][_x-1]!='D')_x--;
		else fdir=rand()%4;
		
	}
	if(fdir==0){
		if(mapa[_y-1][_x]!='X'&&mapa[_y-1][_x]!='A'&&mapa[_y-1][_x]!='Y'
		&&mapa[_y-1][_x]!='B'&&mapa[_y-1][_x]!='C'&&mapa[_y-1][_x]!='D')_y--;
		else fdir=rand()%4;
		
	}
	if(fdir==1){
		if(mapa[_y+1][_x]!='X'&&mapa[_y+1][_x]!='A'&&mapa[_y+1][_x]!='Y'
		&&mapa[_y+1][_x]!='B'&&mapa[_y+1][_x]!='C'&&mapa[_y+1][_x]!='D')_y++;
		else fdir=rand()%4;

	}
	if(mapa[boly][bolx]=='_'){setCColor(color[1]);gotoxy(bolx,boly);printf("%c",250);}
	
	if(_x<=17)_x=61;
	 else if(_x>=62)_x=18;
	dibujar_fantasma();

}


void marcador()
{
	gotoxy(5,4);printf("PUNTOS");
	gotoxy(5,6);printf("      ");
	setCColor(color[1]);
	gotoxy(5,6);printf("%ld",puntos);
	
	setCColor(color[1]);
	gotoxy(65,4);printf("VIDAS");
	for(int i=0;i<=vidas;i++){
		gotoxy(65,i+6);printf(" ");
	}
	for(int i=0;i<vidas;i++){
		gotoxy(65,i+6);printf("%c",2);
	}

}





int main()
{
		system("color 0d");
		ocultarcursor();
		menu();
		
      
	
	system("pause>null");
	return 0;
}







void menu(){
	
	bool repite=true;
	int opcion;
	fantasma A(41,14,2);
	fantasma B(43,14,3);
	fantasma C(40,14,4);
	fantasma D(39,14,5);
	do{
        cout<<"\n\t\t\tMENU PRINCIPAL\n";
        
        cout<<"\n\t1.-INICIA JUEGO\n";
        cout<<"\n\t2.-CIERRA JUEGO\n";
		
		cout<<"\n\tOPCION: ";
		cin>>opcion;
		system("cls");
		switch(opcion){
			
			case 1:
				int op;
				op=1;
				while(op==1){
				system("cls");
				caratula();
					pintar_mapa();
	
	while(vidas>0&&puntos<1950)
	{  
		marcador();
		borrar_pacman(x,y);
		anteriorpx=x;
		anteriorpy=y;
		
		teclear();
		if(dir==0 && mapa[y-1][x]!='X'&&mapa[y-1][x]!='A'&&mapa[y-1][x]!='Y'&&mapa[y-1][x]!='B'&&mapa[y-1][x]!='C'&&mapa[y-1][x]!='D')y--;
		
		else if(dir==1&&mapa[y+1][x]!='X'&&mapa[y+1][x]!='A'&&mapa[y+1][x]!='Y'&&mapa[y+1][x]!='B'&&mapa[y+1][x]!='C'&&mapa[y+1][x]!='D')y++;
		
		pacman(x,y);
		Sleep(40);
		borrar_pacman(x,y);
		
		A.choque_pacman();
		B.choque_pacman();
		C.choque_pacman();
		D.choque_pacman();
		
		
		anteriorpx=x;
		anteriorpy=y;
		teclear();
		
		if(dir==2&&mapa[y][x+1]!='X'&&mapa[y][x+1]!='A'&&mapa[y][x+1]!='Y'&&mapa[y][x+1]!='B'&&mapa[y][x+1]!='C'&&mapa[y][x+1]!='D')    x++;
	 
	 	else if(dir==3&&mapa[y][x-1]!='X'&&mapa[y][x-1]!='A'&&mapa[y][x-1]!='Y'&&mapa[y][x-1]!='B'&&mapa[y][x-1]!='C'&&mapa[y][x-1]!='D') x--;
		
		A.mover_fantasma();
		B.mover_fantasma();
		C.mover_fantasma();
		D.mover_fantasma();
		
		pacman(x,y);
		Sleep(40);
	 
	 	if(x<19){
			borrar_pacman(x,y);
			x=61;
		}
		else if(x>62){
			borrar_pacman(x,y);
			x=18;
		}
		
	    if(vidas==0){
	    	system("pause");
	    	system("cls");
	    	gotoxy(40,14);cout<<"\t\tGAME OVER\n\n"<<endl;
	    	gotoxy(33,16);cout<<"\t\tGRACIAS POR JUGAR\n\n"<<endl;
	    
		}
		else if(puntos==1950){
			system("pause");
	    	system("cls");
			gotoxy(34,14);cout<<"\t\tGANASTE\n\n"<<endl;
			gotoxy(32,16);cout<<"\tGRACIAS POR JUGAR\n\n"<<endl;
			getch();
		
	  	  }  
	   
	    }
	    
	    gotoxy(32,18);cout<<"Deseas Reiniciar el juego?";
	    gotoxy(32,20);cout<<"1.si";
	    gotoxy(32,22);cout<<"2.no"<<endl;
    	gotoxy(32,24);cout<<"Digita dos veces el numero de la opcion que deseas: "<<endl;
    	getch();
	    gotoxy(32,26);cin>>op;
	    system("cls");
      	}
    		repite=false;
				break;
			
			case 2:
			cout<<"              ESPERO TE VUELVA A VER PRONTO"  <<endl;
			cout<<"             JUEGO INSPIRADO EN EL LEGENDARIO"<<endl;
			cout<<" 	                       PACMAN	        "<<endl;
		//system("cls");
				repite=false;
				break;
			
		}  
	}while (repite);
	

    
}


void caratula(){

    gotoxy(45,11);cout<<"Instituto Politecnico Nacional";
    gotoxy(27,12);cout<<"Escuela Superior De Ingeneria Mecanica y Electrica UNIDAD CULHUACAN";
    gotoxy(44,13);cout<<"San Pedro Texis Emanuel Tristan";
    gotoxy(43,14);cout<<"Programacion Orientada en Objetos";
    gotoxy(49,15);cout<<" PROYECTO FINAL";
    gotoxy(51,16);cout<<"  Grupo 2CV35";
    gotoxy(45,17);cout<<"Profesor Osornio Soto Roberto \n\n";
	getch();
	system("cls");
	
    gotoxy(55,8);cout<<"PACMAN\n";
    gotoxy(30,14);cout<<"HABIA UN ANCIANO PACMAN AL QUE NO LE GUSTABA DIA DE MUERTOS\n";
    gotoxy(39,16);cout<<"PUES NO RECIBIA A QUIEN TOCABA LA PUERTA\n";
    gotoxy(19,18);cout<<"TIRABA TODOS LOS DUCES QUE VEIA POR LO QUE UNOS FANTASMAS QUISIERON DARLE UNA LECCION\n";
    gotoxy(34,20);cout<<"ASI EN LA NOCHE DECIDIERON LLEVARLO A UN LABERINTO\n";
    gotoxy(17,22);cout<<"PARA OBLIGARLO A RECOGER TODOS LOS DULCES YA QUE DE LO CONTRARIO NUNCA LO DEJARIAN\n";
    gotoxy(45,24);cout<<"PRESIONA ENTER PARA CONTINUAR \n";
    getch();
	system("cls");

	gotoxy(35,11);cout<<"\tLOS CONTROLES PARA MOVERTE SON LOS SIGUIENTES:\t";
    gotoxy(52,13);cout<<"\tARRIBA USA LA TECLA W\t";
    gotoxy(54,15);cout<<"\tABAJO LA TECLA S\t";
    gotoxy(54,17);cout<<"\tIZQUIERDA LA TECLA A\t";
    gotoxy(53,19);cout<<"\tDERECHA LA TECLA D\t";
    gotoxy(40,21);cout<<"\tRECOGE TODOS LOS DULCES QUE PUEDAS \t";
    gotoxy(40,23);cout<<"\tPRESIONA ENTER PARA CONTINUAR\t";
    getch();
	system("cls");
}


void setCColor(int color)
{
	static HANDLE hConsole;
	hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,color|(backcolor*0x10+0x100));
}


void gotoxy(int x, int y)
{
	HANDLE hCon;
	COORD dwPos;
	
	dwPos.X=x;
	dwPos.Y=y;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
}


void ocultarcursor(){
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize=2;
	cci.bVisible=FALSE;
	
	SetConsoleCursorInfo(hCon, &cci);
}

