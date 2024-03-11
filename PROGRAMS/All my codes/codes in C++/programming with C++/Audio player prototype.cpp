#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h> 

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;

//STRUCT DONDE GUARDAMOS TODOS LOS DATOS DE LAS CANCIONES	
struct nodo{
	string nombre;
	string genero;
	nodo *sig,*ant;
	nodo *favoritos;
};

//ESTOS DOS PROTOTIPOS SON PURA IMPRESION, UNA SIRVE PARA UBICAR EN COORDENADAS EL TEXTO Y EL OTRO
//FUNCIONA COMO CARATULA DEL PROGRAMA
void gotoxy(int x, int y);
void escribir();
void advertencia();

//ESTAS SON LOS PROTOTIPOS MAS ELEMENTALES QUE NOS PERMITEN VER LAS CANCIONES, INSERTAR CANCIONES
//Y ELIMINAR CANCIONES
void MostrarLista(nodo *);
nodo *Insertar(nodo *, nodo *);
nodo *Eliminar(nodo *, nodo *,int);

//PROTOTIPOS EXTRA QUE SON PARTE DE UN SPOTIFY
void Letra(nodo *, int);
void Favorito(nodo *, nodo *);

//ESTOS SON LOS PROTOTIPOS DE REPRODUCCION DONDE DEFINIMOS EL TIPO DE REPRODUCCION QUE SE PUEDE
//HACER, DE FORMA ALEATORIA, LINEAL, GENERO, ETC
void ReproduccionS(nodo *);
void ReproduccionA(nodo *);
void Controlreproduccion(nodo *p);
void ControlreproduccionAnt(nodo *f);
void BuscYrep(nodo *);
void RepGenero(nodo *);


//AQUI SE DECLARAN LOS TIPOS DE GENEROS QUE EXISTEN PARA NUESTRAS CANCIONES
nodo *actual=NULL;
string direccionRock;
string direccionHipHop;
string direccionReggaeton;
string direccionBanda;
string direccionGracia;

int main() {
    int opcion, pos=3, d;
	nodo *p=NULL, *f=NULL;
	nodo *p2=NULL, *f2=NULL;
    
        system("Title SPOTIFY CASERO");
		system("COLOR 0D");
    	escribir();
    	getch();
    	system("cls");
    	advertencia();
    	getch();
    	system("cls");
	
    do {

    	
    	
    	system("COLOR FD");
		system("cls");
		gotoxy(45,1);cout<<"\tMENU DE SPOTIFY\n";
		gotoxy(45,2);cout<<"1. Mostrar lista de canciones \n";
		gotoxy(45,3);cout<<"2. Mostrar lista de canciones favoritas\n";
		gotoxy(45,4);cout<<"3. Reproducir cancion aleatoria \n";
		gotoxy(45,5);cout<<"4. Reproducir cancion secuencial \n";
		gotoxy(45,6);cout<<"5. Ingresar cancion \n";
		gotoxy(45,7);cout<<"6. Eliminar cancion \n";
		gotoxy(45,8);cout<<"7. Ver letra de la cancion \n";
		gotoxy(45,9);cout<<"8. Ingresar cancion a favoritos \n";
		gotoxy(45,10);cout<<"10. Reproducir siguiente cancion\n";
		gotoxy(45,11);cout<<"11. Reproducir cancion anterior\n";
		gotoxy(45,12);cout<<"12. Buscar por nombre\n";
		gotoxy(45,13);cout<<"13. Reproducir por genero\n";
		gotoxy(45,14);cout<<"9. Salir \n";
		cout << "\nSeleccionar una opcion: ";
		cin >> opcion;
		cout <<"\n";

switch (opcion) {
    case 1:
        if (p == NULL){
				cout << "Lista vacia\n\n";
				getch();
			}
			else{
				MostrarLista(p);
				getch();
		}
break;
    case 2:
		if (p2 == NULL){
				cout << "Lista vacia\n\n";
				getch();
			}
			else{
				MostrarLista(p2);
		}
break;
    case 3:
    			cout<<"Ingrese la lista de reproduccion que desea reproducir (0. Principal, 1. Favoritos): ";
				cin>>d;
		if (d==0){
				if (p == NULL){
					cout << "Lista vacia\n\n";
					getch();
				}
				else{
					ReproduccionA(p);
				}
		}
		if (d==1){
				if (p2 == NULL){
					cout << "Lista vacia\n\n";
					getch();
				}
				else{
					ReproduccionA(p2);
				}
		}
break;
    case 4:
				cout<<"Ingrese la lista de reproduccion que desea reproducir (0. Principal, 1. Favoritos): ";
				cin>>d;
		if (d==0){
				if (p == NULL){
					cout << "Lista vacia\n\n";
					getch();
				}
				else{
					ReproduccionS(p);
				}
		}
		if (d==1){
				if (p2 == NULL){
					cout << "Lista vacia\n\n";
					getch();
				}
				else{
					ReproduccionS(p2);
				}
		} 
break;
    case 5:
		if(p==NULL){
				p=new(nodo);
				cout<<"Escribe el nombre de la cancion: ";
				//cin>>p->nombre;
				cin.ignore();
				getline(cin,p->nombre);	
				cout<<"\n";
				cout<<"La cancion "<<p->nombre<<" ha sido ingresada exitosamente \n\n";
				getch();
				p->sig=p;
				p->ant=p;
				f=p;
			}
			else{
				f=Insertar(p,f);
		}
break;
    case 6:
    	if(p==NULL){
				cout<<"Lista vacia\n\n";
				getch();
			}
			else{
				MostrarLista(p);
				cout<<"Escribe la posicion de la cancion que deseas eliminar: ";
   				cin>>pos;
    			cout<<"\n\n";
				p=Eliminar(p,f,pos);	
		}
break;
    case 7:
				cout<<"Ingrese la lista de reproduccion de la que desea ver la letra (0. Principal, 1. Favoritos): ";
				cin>>d;
		if (d==0){
				if(p==NULL){
					cout << "Lista vacia\n\n";
					getch();
				}
				else{
					Letra(p,pos);	
				}
		}	
		if (d==1){
				if(p2==NULL){
					cout << "Lista vacia\n\n";
					getch();
				}
				else{
					Letra(p2,pos);	
				}
		} 
break;
    case 8:
    	if(p==NULL){
				cout << "Lista vacia\n\n";
				getch();
		}
			else{
				if(p2==NULL){
					p2=new(nodo);
					p2->nombre=p->nombre;
					p->sig->ant=p->ant;
					p->ant->sig=p->sig;
					p=p->sig;
					p2->sig=p2;
					p2->ant=p2;
					f2=p2;
				}
				else{
					Favorito(p,p2);
				}
		}
break;
    case 9:
    	cout << "GRACIAS POR PROBAR NUESTRO SPOTIFY CASERO\n\n";
		cout << "Cerrando...\n\n";
		exit(-1); 
break; 
    case 10:
		if(p==NULL){
				cout << "Lista vacia\n\n";
				getch();
		}else{
				Controlreproduccion(p);	
		}
break;	
    case 11:
		if(p==NULL){
				cout << "Lista vacia\n\n";
				getch();
		}else{
			ControlreproduccionAnt(f);
		}
 
break;
    case 12:
		if(p==NULL){
				cout << "Lista vacia\n\n";
				getch();
		}else{
				BuscYrep(p); 		
		}
break;
    case 13:
		if(p==NULL){
				cout << "Lista vacia\n\n";
				getch();
		}else{
				RepGenero(p);	
		}

break;



default:
            	system("cls");
                gotoxy(35,13);cout << "Operacion Por favor, elija una opcion del 1 al 13." << endl;
                getch();
                system("cls");
        }
} while (opcion != 9);

    return 0;
}















void Reproducir(){
	string direccion="D:\\Windows 64\\Escritorio\\BASE\\TODAS_LAS_CANCIONES\\"+actual->nombre+".mp3";
	ShellExecute(NULL,"open",direccion.c_str(),NULL,NULL,SW_SHOW);
	Sleep(20000);
	string comando="start "+direccion;
	
	
	
}


//CASE 1
//CASE 2
void MostrarLista(nodo *p){
	nodo *aux;
	aux=p;
	int num=1;
	do{
		cout<<num<<". "<<aux->nombre<<"\n";
		aux=aux->sig;
		num++;
	}
	while(aux!=p);
	cout << "\n\n";
	cout << "-----------------------------------\n";
}


//CASE 3
void ReproduccionA(nodo *p){
	srand(time(NULL));
	nodo *aux=p;
	int num=0;
	
	do{
		num++;
		aux=aux->sig;
	}
	while(aux!=p);
	
	for(int i=0;i<num;i++){
		int random=rand()%num;
		aux=p;
		
		for(int j=0;j<random;j++){
			aux=aux->sig;
		}
		cout << "Reproduciendo la cancion: "<<aux->nombre<<"\n";
        string direccion="D:\\Windows 64\\Escritorio\\BASE\\TODAS_LAS_CANCIONES\\"+aux->nombre+".mp3";
        ShellExecute(NULL,"open",direccion.c_str(),NULL,NULL,SW_SHOW);
        Sleep(20000);
	}
	aux=aux->sig;
	
}


//CASE 4
void ReproduccionS(nodo *p){
	nodo *aux; 
	aux=p;

    do
    {
        cout << "Reproduciendo la cancion: "<<aux->nombre<<"\n";
        string direccion="D:\\Windows 64\\Escritorio\\BASE\\TODAS_LAS_CANCIONES\\"+aux->nombre+".mp3"; //WILLIAM, TIENES QUE CAMBIAR ESTE DIRECTIORIO
        ShellExecute(NULL,"open",direccion.c_str(),NULL,NULL,SW_SHOW);
        Sleep(20000);
        aux=aux->sig;
    }
	while (aux!=p);
}


//CASE 5	
nodo *Insertar(nodo *p,nodo *f){
	nodo *aux,*auxGen;
	aux=new(nodo);
	cout<<"Escribe el nombre de la cancion: ";
	//cin>>aux->nombre;
	cin.ignore();
	getline(cin,aux->nombre);
	cout<<"\n";
	auxGen=aux;
	aux->sig=p;
	aux->ant=f;
	f->sig=aux;
	p->ant=aux;
	f=aux;
	
	cout<<"La cancion "<<aux->nombre<<" ha sido ingresada exitosamente \n\n";
	getch();
	return f;
}


//CASE 6
nodo *Eliminar(nodo *p, nodo *f,int pos){	
	nodo *aux;
	aux=p;
    if(pos==1){
        if(p->sig==p){
            delete p;
            return NULL;
        }
        p=p->sig;
        f->sig=p;
        p->ant=f;
        delete aux;
        return p;
    }
    int cont=1;
    while(cont<pos && aux->sig!=p) {
        aux=aux->sig;
        cont++;
    }
    if (cont<pos) {
    	MostrarLista(p);
        cout<<"El numero de la cancion que busca no esta en esta lista\n\n";
        return p;
    }
    aux->ant->sig=aux->sig;
    aux->sig->ant=aux->ant;
    if (aux==f){
        f=aux->ant;
    }
    cout<<"La cancion "<<aux->nombre<<" ha sido eliminada de la lista\n\n";
    getch();
    delete aux;
    return p;
}


//CASE 7
void Letra(nodo *p, int pos){
    nodo *aux; 
	aux=p;
	MostrarLista(p);
    cout<<"Escribe la posicion de la cancion de la que desee ver su letra: ";
    cin>>pos;

    if(pos<1){
        cout<<"El numero de la cancion que busca no esta en esta lista\n\n";
        return;
    }

    for(int i=1;i<pos;i++) {
        if (aux==NULL) {
            cout<<"El numero de la cancion que busca no esta en esta lista\n\n";
            return;
        }
        aux=aux->sig;
    }

    string direccion="D:\\Windows 64\\Escritorio\\BASE\\LETRAS\\"+aux->nombre+".txt";
    string comando="start "+direccion;

    system(comando.c_str());
}


//CASE 8
void Favorito(nodo *p,nodo *p2){
	int pos, num=1;
	nodo *aux;
	aux=p;
	cout<<"Ingresa la posicion de la cancion que desea agregar a favoritos: ";
	cin>>pos;
	while(num<pos){
		aux=aux->sig;
		num++;
	}
	if(aux==p){
		p=p->sig;
	}
	if(aux->ant!=NULL){
		aux->ant->sig=aux->sig;
	}
	if(aux->sig!=NULL){
		aux->sig->ant=aux->ant;
	}
	aux->ant=p2->ant;
	aux->sig=p2;
	p2->ant->sig=aux;
	p2->ant=aux;
	cout<<"La cancion "<<aux->nombre<<" ha sido agregada a favoritos\n\n";
}


//CASE 10
void Controlreproduccion(nodo *p){
	if(p==NULL){
		cout<<"\nLista vacia ";
		return;
	}
	nodo *aux = p;
	int opcion;
	
	do{
		cout<<"Reproduciendo la cancion: "<<aux->nombre<<"\n";
		string direccion="D:\\Windows 64\\Escritorio\\BASE\\TODAS_LAS_CANCIONES\\"+aux->nombre+".mp3";
        ShellExecute(NULL,"open",direccion.c_str(),NULL,NULL,SW_SHOW);
        Sleep(20000);
        
        cout<<"\n1. Siguiente cancion";
        cout<<"\n2. Salir";
        cout<<"\nSeleccione una opcion: ";
        cin>>opcion;
        
        switch(opcion){
        	case 1:
        		aux=aux->sig;
        		break;
        	
        	case 2:
        		break;
        		
        	default: 
        	cout<<"\nOpc no valida. Reproduciendo la sig cancion";
        	aux=aux->sig;
        	break;
		}
		
	}while(opcion !=2);
	
}


//CASE 11
void ControlreproduccionAnt(nodo *f){
	if(f==NULL){
		cout<<"\nLista vacia ";
		return;
	}
	nodo *aux = f;
	int opcion;
	
	do{
		cout<<"Reproduciendo la cancion: "<<aux->nombre<<"\n";
		string direccion="D:\\Windows 64\\Escritorio\\BASE\\TODAS_LAS_CANCIONES\\"+aux->nombre+".mp3";
        ShellExecute(NULL,"open",direccion.c_str(),NULL,NULL,SW_SHOW);
        Sleep(20000);
        
        cout<<"\n1. Cancion anterior";
        cout<<"\n2. Salir";
        cout<<"\nSeleccione una opcion: ";
        cin>>opcion;
        
        switch(opcion){
        	case 1:
        		aux=aux->ant;
        		break;
        	
        	case 2:
        		break;
        		
        	default: 
        	cout<<"\nOpc no valida. Reproduciendo la sig cancion";
        	aux=aux->ant;
        	break;
		}
		
	}while(opcion !=2);
	
}


//CASE 12
void BuscYrep(nodo *p){
	if(p==NULL){
		cout<<"\nLista vacia";
		return;
	}
	string nombreBuscado;
	cout<<"\nIngrese el nombre de la cancion que desea buscar: ";
	cin.ignore();
	getline(cin, nombreBuscado);
	
	nodo *aux=p;
	bool encontrada=false;
	
	do{
		if (aux->nombre ==nombreBuscado){
			encontrada=true;
			cout<<"\nReproduciendo cancion: "<<aux->nombre<<"\n";
			string direccion="D:\\Windows 64\\Escritorio\\BASE\\TODAS_LAS_CANCIONES\\"+aux->nombre+".mp3";
        ShellExecute(NULL,"open",direccion.c_str(),NULL,NULL,SW_SHOW);
        Sleep(20000);
        
        break;
        }
        aux=aux->sig;
	}while (aux!=p);
	
	if(!encontrada){
		cout<<"\nCancion no encontrada";
	}
}


//CASE 13
void RepGenero(nodo *p){
		if(p==NULL){
		cout<<"\nLista vacia ";
		return;
	}
	nodo *aux=p;
	int opcGen;
	
	do{
		cout<<"Reproduciendo la cancion: "<<aux->nombre<<"\n";
		string direccion="D:\\Windows 64\\Escritorio\\BASE\\TODAS_LAS_CANCIONES\\"+aux->nombre+".mp3";
        ShellExecute(NULL,"open",direccion.c_str(),NULL,NULL,SW_SHOW);
        Sleep(20000);
        
        cout<<"\n1.ROCK";
        cout<<"\n2.HIPHOP";
        cout<<"\n3.BANDA";
        cout<<"\n4.REGGAETON";
        cout<<"\n5.GRACIA";
        cout<<"\nSeleccione el genero que desea reproducir: ";
        cin>>opcGen;
        
        switch(opcGen){
        	case 1:
        		 cout<<"Reproduciendo el genero ROCK: "<<aux->nombre<<"\n";
		         direccionRock="D:\\Windows 64\\Escritorio\\BASE\\GENEROS\\ROCK\\"+aux->nombre+".mp3";
                 ShellExecute(NULL,"open",direccionRock.c_str(),NULL,NULL,SW_SHOW);
                 Sleep(20000);
        		 aux=aux->sig;
        		 break;
        	
        	case 2:
        		 cout<<"Reproduciendo el genero HIPHOP: "<<aux->nombre<<"\n";
		         direccionHipHop="D:\\Windows 64\\Escritorio\\BASE\\GENEROS\\HIPHOP\\"+aux->nombre+".mp3";
                 ShellExecute(NULL,"open",direccionHipHop.c_str(),NULL,NULL,SW_SHOW);
                 Sleep(20000);
        		 aux=aux->sig;
        		 break;
        		 
        	case 3:
        		 cout<<"Reproduciendo el genero BANDA: "<<aux->nombre<<"\n";
		         direccionBanda="D:\\Windows 64\\Escritorio\\BASE\\GENEROS\\BANDA\\"+aux->nombre+".mp3";
                 ShellExecute(NULL,"open",direccionBanda.c_str(),NULL,NULL,SW_SHOW);
                 Sleep(20000);
        		 aux=aux->sig;
        		 break;
        		 
        	case 4:
        		 cout<<"Reproduciendo el genero REGGAETON: "<<aux->nombre<<"\n";
		         direccionReggaeton="D:\\Windows 64\\Escritorio\\BASE\\GENEROS\\REGGAETON\\"+aux->nombre+".mp3";
                 ShellExecute(NULL,"open",direccionReggaeton.c_str(),NULL,NULL,SW_SHOW);
                 Sleep(20000);
        		 aux=aux->sig;
        		 break;
        		 
        	case 5:
        		 cout<<"Reproduciendo el genero GRACIA: "<<aux->nombre<<"\n";
		         direccionGracia="D:\\Windows 64\\Escritorio\\BASE\\GENEROS\\GRACIA	\\"+aux->nombre+".mp3";
                 ShellExecute(NULL,"open",direccionGracia.c_str(),NULL,NULL,SW_SHOW);
                 Sleep(20000);
        		 aux=aux->sig;
        		 break;
        	
        		
        	default: 
        	cout<<"\nOpc no valida. Reproduciendo la sig cancion";
        	break;
		}
		
		aux=aux->sig;
		
	}while(aux!=p);
	
	
	
}








void escribir(){
    gotoxy(45,11);cout<<"Instituto Politecnico Nacional";
    gotoxy(27,12);cout<<"Escuela Superior De Ingeneria Mecanica y Electrica UNIDAD CULHUACAN";
    gotoxy(47,13);cout<<"Cruz Hernandez William";
    gotoxy(44,14);cout<<"Monroy Cortines Jacobo Emiliano";
    gotoxy(44,15);cout<<"San Pedro Texis Emanuel Tristan";
    gotoxy(50,16);cout<<"Estructura de Datos";
    gotoxy(46,17);cout<<"PROYECTO: SPOTIFY CASERO ";
    gotoxy(51,18);cout<<"  Grupo 3CV25 \n\n";
}
void advertencia(){
    gotoxy(47,11);cout<<"ANTES DE CONTINUAR...";
    gotoxy(35,12);cout<<"Para poder anadir una cancion a la playlist";
    gotoxy(30,13);cout<<"solo se debe anadir el nombre de la cancion sin artista";
    gotoxy(38,14);cout<<"debe ser sin espacios y en mayusculas";
    gotoxy(40,15);cout<<"y en vez de usar espacios se usa _";
    gotoxy(50,16);cout<<"por ejemplo";
    gotoxy(50,17);cout<<"OJOS_LINDOS";	
}
void gotoxy(int x, int y){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
