#include<iostream>
#include<time.h>
#include <stdlib.h>
#include<windows.h>
#include<mmsystem.h>
using namespace std;

struct nodo
{
int dato;
nodo*sig,*ant;
};

void imprimirIzqDer(nodo*);
void imprimirDerIzq(nodo*);
nodo*insertarDer(nodo*);
nodo*insertarIzq(nodo*);
nodo*insertarAleDer(nodo*,int);
nodo*insertarAleIzq(nodo*,int);
nodo*insertarAleIzq(nodo*,int);
bool Buscardato(nodo*, int);
nodo*Modificar(nodo*,int);
nodo*AgregarentreXyY(nodo*, int, int);
void Agregarantesx(nodo*,int,int);
void Agregardespuesx(nodo*,int,int);
void Eliminarprimer(nodo*&);
void Eliminarultimo(nodo*&);
void eliminarNodosEntreXY(nodo*&,int,int);
bool esprimo(int);
void Eliminarprimos(nodo*&);
nodo* Edx(nodo*,nodo*);
void Exy(nodo*);
void burbuja(nodo *);
void shaker(nodo *, nodo *);
void Seledi(nodo *);
void Selebi(nodo *);
void Inbi(nodo *);
void IB(nodo*,nodo*);
void EliminarLista(nodo*&);

int main()
{
int opc, busca;
int ale,n, pp,x,y;
nodo *p=NULL,*f=NULL;

while (1)
{
	cout<<"\x1b[48;2;255;0;0mLista doblemente enlazada\x1b[0m \n\n";
	cout<<"0.-Imprimir de P a F\n";
	cout<<"1.-Imprimir de F a P\n";
	cout<<"2.-Insertar al final\n";
	cout<<"3.-Insertar al inicio\n";	
	cout<<"4.-Insertar aleatorios al final\n";
	cout<<"5.-Insertar aleatorios al inicio\n";
	cout<<"6.-Buscar\n";
	cout<<"7.-Modificar\n";
	cout<<"8.-Aleatorios entre X y Y\n";
	cout<<"9.-Insertar aleatorios antes de la referencia\n";
	cout<<"10.-Insertar aleatorios despues de los aleatorios\n";
	cout<<"11.-Eliminar primer nodo\n";
	cout<<"12.-Eliminar ultimo nodo\n";
	cout<<"13.-Eliminar entre X y Y\n";
	cout<<"14.-Eliminar todos los primos\n";
	cout<<"15.-Eliminar N despues de X\n";
	cout<<"16.-Ordenamiento por metodo burbuja\n";
	cout<<"17.-Ordenamiento por shaker sort\n";
	cout<<"18.-Ordenamiento por seleccion directa\n";
	cout<<"19.-Ordenamiento por seleccion binaria\n";
	cout<<"20.-Ordenamiento por insercion directa\n";
	cout<<"21.-Eliminar todos los datos\n\n";
	
	cout<<"Selecciona una opcion: ";
	cin>>opc;
	
	switch (opc)
	{
	
	case 0:
		system("cls");
		cout<<"Se selecciono: \x1b[48;2;0;0;255mImprimir de izquierda a derecha la lista\x1b[0m\n\n";
		if(p==NULL)
		cout<<"Lista vacia :,v\n\n";
		else
		imprimirIzqDer(p);
	break;
			
	case 1:
		system("cls");
		cout<<"Se selecciono: \x1b[48;2;0;0;255mImprimir de derecha a izquierda la lista\x1b[0m\n\n";
		if(p==NULL)
		cout<<"Lista vacia :,v\n\n";
		else
		imprimirDerIzq(f);
	break;
	
	case 2:
		system("cls");
		cout<<"Se selecciono: \x1b[48;2;0;0;255mInsertar a la derecha de la lista\x1b[0m\n\n";
		if(p==NULL)
		{
			p=new(nodo);
			cout<<"Ingresa el dato: ";
			cin>>p->dato;
			cout<<"\n";
			p->sig=NULL;
			p->ant=NULL;
			f=p;
		}	
		else
		f=insertarDer(f);
	break; 
	
	case 3:
		system("cls");
		cout<<"Se selecciono: \x1b[48;2;0;0;255mInsertar a la izquierda de la lista\x1b[0m\n\n";
		if(p==NULL)
		{
			p=new(nodo);
			cout<<"Ingresa el dato: ";
			cin>>p->dato;
			cout<<"\n";
			p->sig=NULL;
			p->ant=NULL;
			f=p;
		}
		else
		p=insertarIzq(p);
	break;	
	
	case 4:
		system("cls");
		cout<<"Se selecciono: \x1b[48;2;0;0;255mInsertar aleatorios a la derecha de la lista\x1b[0m\n\n";
		cout<<"Ingrese el numero de datos aleatorios a generar: ";
		cin>>ale;
		if(p==NULL)
		{
			p=new(nodo);
			p->dato=1+rand()%100;
			cout<<"\n";
			p->sig=NULL;
			p->ant=NULL;
			f=p;
			f=insertarAleDer(f,ale);
		}
		else
		f=insertarAleDer(f,ale+1);
	break;
	
	case 5:
		system("cls");
		cout<<"Se selecciono: \x1b[48;2;0;0;255mInsertar aleatorios a la izquierda de la lista\x1b[0m\n\n";
		cout<<"Ingrese el numero de datos aleatorios a generar: ";
		cin>>ale;	
		if(p==NULL)
		{
			p=new(nodo);
			p->dato=1+rand()%100;
			cout<<"\n";
			p->sig=NULL;
			p->ant=NULL;
			f=p;
			p=insertarAleIzq(p,ale);
		}
		else
		p=insertarAleIzq(p,ale+1);
	break;	
	
	case 6:
		system("cls");
		cout<<"Se selecciono: \x1b[48;2;0;0;255mBuscar dato\x1b[0m\n\n";
		cout<<"Ingresa el dato a buscar: ";	cin>>busca;
		if(p==NULL){
			cout<<"La lista esta vacia :("<<endl;
		}else{
			Buscardato(p,busca);
		}
	break;
	
	case 7:
		system("cls");
		cout<<"Se selecciono: \x1b[48;2;0;0;255mBuscar dato\x1b[0m\n\n";
		cout<<"Ingresa el dato a buscar: ";	cin>>busca;
		if(p==NULL){
			cout<<"La lista esta vacia :("<<endl;
		}else{
			p=Modificar(p,busca);
		}
	break;
	
	case 8:
		system("cls");
		cout<<"Se selecciono: \x1b[48;2;0;0;255mAgregar datos entre X y Y\x1b[0m\n\n";
		cout<<"Ingresa el dato a buscar: ";	cin>>busca;
		cout<<"Cuantos desea generar?: ";	cin>>n;
		
		if(p==NULL){
			cout<<"La lista esta vacia. "<<endl<<endl;
		}else{
			p=AgregarentreXyY(p,busca,n);
		}
		
	break;
	
	case 9:
		system("cls");
		cout<<"Se selecciono: \x1b[48;2;0;0;255mAgregar datos antes de X\x1b[0m\n\n";
		cout<<"Ingresa el dato a buscar: ";	cin>>busca;
		cout<<"Cuantos desea generar?: ";	cin>>n;
		if(p==NULL){
			cout<<"La lista esta vacia. "<<endl<<endl;
		}else{
			Agregarantesx(p,busca,n);
			cout<<"Datos generados antes de "<<busca<<endl;
		}
	break;
	
	case 10:
		system("cls");
		cout<<"Se selecciono: \x1b[48;2;0;0;255mAgregar datos despues de X\x1b[0m\n\n";
		cout<<"Ingresa el dato a buscar: ";	cin>>busca;
		cout<<"Cuantos desea generar?: ";	cin>>n;
		if(p==NULL){
			cout<<"La lista esta vacia. "<<endl<<endl;
		}else{
			Agregardespuesx(p,busca,n);
			cout<<"Datos generados despues de "<<busca<<endl;
		}
	break;
	
	case 11:
		system("cls");
		cout<<"Se selecciono: \x1b[48;2;0;0;255mEliminar primer nodo\x1b[0m\n\n";
		if(p==NULL){
			cout<<"La lista esta vacia :("<<endl;
		}else{
			Eliminarprimer(p);
		}
	break;
	
	case 12:
		system("cls");
		cout<<"Se selecciono: \x1b[48;2;0;0;255mEliminar ultimo nodo\x1b[0m\n\n";
		if(p==NULL){
			cout<<"La lista esta vacia :("<<endl;
		}else{
			Eliminarultimo(p);
		}
	break;
	
	case 13:
		system("cls");
		cout<<"Se selecciono: \x1b[48;2;0;0;255mEliminar entre X y Y\x1b[0m\n\n";
		 if(p==NULL){
			 cout<<"Lista vacia \n";
			 
			 }
			 else{
			 Exy(p);
			}
  	break;
  	
  	case 14:
  		system("cls");
  		cout<<"Se selecciono: \x1b[48;2;0;0;255mEliminar todos los primos\x1b[0m\n\n";
  		if(p==NULL){
  			cout<<"La lista esta vacia :("<<endl;
		  }else{
		  	Eliminarprimos(p);
		  }
  	break;
  	
  	case 15:
  		system("cls");
  		cout<<"Se selecciono: \x1b[48;2;0;0;255mEliminar despues de x\x1b[0m\n\n";
  		if(p==NULL){
 		cout<<"Lista vacia \n";
 
		 }
 		else{
 			f=Edx(p,f);
 			}
  	break;
  	
  	case 16:
		system("cls");
		cout<<"Se selecciono: \x1b[48;2;0;0;255mOrdenar lista por metodo de  burbuja\x1b[0m\n\n";
		burbuja(p);
	break;

	case 17:
		system("cls");
		cout<<"Se selecciono: \x1b[48;2;0;0;255mOrdenar lista por metodo de shaker sort\x1b[0m\n\n";
		shaker(p, f);
	break;

	case 18:
	system("cls");
	cout<<"Se selecciono: \x1b[48;2;0;0;255mOrdenar lista por metodo de seleccion directa\x1b[0m\n\n";
	Seledi(p);
	break;

	case 19:
		system("cls");
		cout<<"Se selecciono: \x1b[48;2;0;0;255mOrdenar lista por metodo de seleccion binaria\x1b[0m\n\n";
		IB(p,f);
	break;

	case 20:
		system("cls");
		cout<<"Se selecciono: \x1b[48;2;0;0;255mOrdenar lista por metodo de insercion directa\x1b[0m\n\n";
		Inbi(p);
	break;
	
	case 21:
	    system("cls");
	    cout << "Se selecciono: \x1b[48;2;0;0;255mEliminar toda la lista\x1b[0m\n\n";
	    if (p == NULL) {
	        cout << "La lista ya está vacía." << endl;
	    } else {
	        EliminarLista(p);
	        f = NULL;  // Aseguramos que el puntero al final de la lista también sea NULL
	    }
    break;
}
}
}

void imprimirIzqDer(nodo*p)
{
	nodo*aux;
	aux=p;
	while(aux!=NULL)
	{
		cout<<aux->dato<<" ";
		aux=aux->sig;
	}
	cout<<"\n\n";
}

void imprimirDerIzq(nodo*f)
{
	nodo *aux;
	aux=f;
	while(aux!=NULL)
	{
		cout<<aux->dato<<" ";
		aux=aux->ant;
	}
	cout<<"\n\n";
}

nodo*insertarDer(nodo *f)
{
	nodo*aux;
	aux=new(nodo);
	cout<<"Ingresa el dato: ";
	cin>>aux->dato;
	cout<<"\n";
	aux->sig=NULL;
	aux->ant=f;
	f->sig=aux;
	f=aux;

	return f;		
}

nodo*insertarIzq(nodo *p)
{
	nodo*aux;
	aux=new(nodo);
	cout<<"Ingresa el dato: ";
	cin>>aux->dato;
	cout<<"\n";
	aux->sig=p;
	aux->ant=NULL;
	p->ant=aux;
	p=aux;

	return p;
}
nodo* insertarAleDer(nodo*f,int ale)
{
	nodo *aux;
	srand(time(NULL));
	for (int i=2;i<=ale;i++)
	{
		aux=new(nodo);
		aux->dato=1+rand()%100;
		aux->ant=f;
		aux->sig=NULL;
		f->sig=aux;
		f=aux;
	}
	cout<<"\n";
	return f;
}

nodo*insertarAleIzq(nodo*p,int ale)
{
	nodo* aux;
	srand(time(NULL));
	for (int i=2;i<=ale;i++)
	{
		aux=new(nodo);
		aux->dato=1+rand()%100;
		aux->ant=NULL;
		aux->sig=p;
		p->ant=aux;
		p=aux;
	}
	cout<<"\n";
	return p;
}

nodo* AgregarentreXyY(nodo *p, int n, int m){
	int y;
	nodo *aux;
	aux=p;
	while(aux!=NULL){
		
		if(aux->dato==n){
				cout<<"Ingrese Y: ";	cin>>y;
				if(aux->sig->dato==y){
					cout<<"Datos generados entre "<<aux->dato<<" y "<<aux->sig->dato<<endl;
				for(int i=0;i<=m;i++){
				nodo *nuevo=new(nodo);
				nuevo->dato=1+rand()%100;
				nuevo->sig=aux->sig;
				nuevo->ant=aux;
				if(aux->sig!=NULL){
					aux->sig->ant=nuevo;
				}
				aux->sig=nuevo;
				aux=nuevo;
				}
			}else{
				cout<<"No se generaron los datos entre "<<n<<" y "<<y<<endl;
			}
			
		}
		aux=aux->sig;
	}
	cout<<"No se puede agregar los datos entre "<<n<<" y "<<y<<endl;
	return p;
}

bool Buscardato(nodo *f, int n){
	nodo* actual = f;
    while (actual != NULL) {
        if (actual->dato == n) {
            cout << "Elemento encontrado: " << n << endl<<endl;
            return true;
        }
        actual = actual->sig;
    }
    cout << "Elemento no encontrado: " << n << endl<<endl;
    return false;
}

nodo* Modificar(nodo *f, int n){
	nodo* actual = f;
	int opp;
    while (actual != NULL) {
        if (actual->dato == n) {
            cout << "Elemento encontrado: " << n << endl<<endl;
            cout<<"Desea asignar un valor:"<<endl<<"1.- Manual."<<endl<<"2.- Aleatorio."<<endl<<"opcion: ";	cin>>opp;
            switch(opp){
            	case 1:
            		cout<<"Ingrese el nuevo valor: ";	cin>>actual->dato;
            		break;
            	case 2:
            		actual->dato=1+rand()%100;
            		cout<<"Dato generado automaticamente :)"<<endl;
            		break;
			}
        }
        actual = actual->sig;
    }
    
    return f;
}

void Agregarantesx(nodo *p, int n, int m){
	nodo *f;
	f=p;
	while(f!=NULL){
		if(f->dato==n){
			for(int i=0;i<m;i++){
				nodo *k=new(nodo);
				k->dato=1+rand()%100;
				k->sig=f;
				k->ant=f->ant;
				if(f->ant!=NULL){
					f->ant->sig=k;
				}else{
					p=k;
				}
				f->ant=k;
			}
			return;
		}
		f=f->sig;
	}
	cout<<"Dato no encontrado."<<endl<<endl;
	
}

void Agregardespuesx(nodo *p, int n, int m){
	nodo *aux;
	aux=p;
	while(aux!=NULL){
		if(aux->dato==n){
			for(int i=0;i<m;i++){
				nodo *nn=new(nodo);
				nn->dato=1+rand()%100;
				nn->sig=aux->sig;
				nn->ant=aux;
				if(aux->sig!=NULL){
					aux->sig->ant=nn;
				}
				aux->sig=nn;
				aux=nn;
			}
			return;
		}
		aux=aux->sig;
	}
	cout<<"No se encontro el dato :("<<endl<<endl;
}

void Eliminarprimer(nodo *&aux){
	if(aux!=NULL){
		nodo *borra;
		borra=aux;
		aux=aux->sig;
		aux->ant=NULL;
		delete borra;
	}
	cout<<"Dato eliminado :)"<<endl;
}

void Eliminarultimo(nodo *&p){
	if (p != NULL) {
        if (p->sig == NULL) {
            delete p;
            p = NULL;
            cout<<"Dato eliminado con exito :)"<<endl;
        }
        else {
            nodo* anterior = NULL;
            nodo* actual = p;

            while (actual->sig != NULL) {
                anterior = actual;
                actual = actual->sig;
            }

            anterior->sig = NULL;
            delete actual;
            cout<<"Dato eliminado con exito :)"<<endl;
        }
    }
}

void eliminarNodosEntreXY(nodo *&p, int X, int Y) {
    nodo *anterior = NULL;
    nodo *actual = p;
    // Busca el nodo con valor X
    while (actual != NULL && actual->dato != X) {
        anterior = actual;
        actual = actual->sig;
    }
    if (actual == NULL) {
        cout << "El elemento X no se encuentra en la lista." << endl;
        return;
    }
    // Guarda una referencia al nodo con valor X
    nodo *nodoX = actual;
    // Restablece el puntero actual al nodo X
    actual = nodoX;
    // Busca el nodo con valor Y
    while (actual != NULL && actual->dato != Y) {
        anterior = actual;
        actual = actual->sig;
    }
    if (actual == NULL) {
        cout << "El elemento Y no se encuentra en la lista después de X." << endl;
        return;
    }
    // Ahora, en este punto, tenemos el nodo X y el nodo Y en la lista.
    // Eliminamos los nodos entre X y Y, sin incluir X ni Y.
    actual = nodoX->sig; // Comenzamos desde el nodo siguiente a X
    while (actual->dato != Y) {
        nodo *borrar = actual;
        actual = actual->sig;
        delete borrar;
    }
	actual->ant=nodoX;
    nodoX->sig = actual; // Enlaza el nodo X con el nodo Y
    cout << "Nodos entre " << X << " y " << Y << " eliminados." << endl;
}

bool esprimo(int num){
	if(num<=1){
		return false;
	}
	for(int i=2;i*i<=num;++i){
		if(num%i==0){
			return false;
		}
	}
	return true;
}

void Eliminarprimos(nodo *&cabeza){
	if(cabeza==NULL){
		return;
	}
	nodo *actual;
	actual=cabeza;
	while(actual!=NULL){
		if(esprimo(actual->dato)){
			if(actual->ant!=NULL){
				actual->ant->sig=actual->sig;
			}else{
				cabeza=actual->sig;
			}
			if(actual->sig!=NULL){
				actual->sig->ant=actual->ant;	
			}
				nodo *temp;
				temp=actual;
				actual=actual->sig;
				delete temp;
				cout<<"Numero primo eliminado con exito :))"<<endl;
		}else{
			actual=actual->sig;
		}
		
	}

}

nodo* Edx(nodo *p,nodo *f){
nodo *aux,*aux1,*aux2,*auxf;
                int r,n,i;
				aux=p;
				auxf=p;	
   cout<<"ingresa la referencia: ";
cin>>r;
while(aux!=NULL && aux->dato!=r){

aux=aux->sig;
}

if(aux!=NULL){

cout<<"Cuantos decea borrar: ";
cin>>n;

aux2=aux->sig;
for(i=0;i<n;i++){

if(aux->sig==NULL){
   cout<<"LOADING";
}
else{
if(aux2->sig!=NULL){
	aux1=aux2->sig;
aux->sig=aux2->sig;
aux1->ant=aux;


delete(aux2);  

aux2=aux->sig;
}
else{	
auxf=f->ant;
	auxf->sig=NULL;
	delete(f);
	f=auxf;	
}
}
}
}
else{
	cout<<"Compruebe la referencia \n";
}
return f;
}                

void Exy(nodo *p){
       nodo *aux,*aux1,*aux2;
                int x,y,r,i;
aux=p;
aux1=p;
cout<<"ingresa el valor de x: ";
cin>>x;
cout<<"ingresa el valor de y: ";
cin>>y;
while(aux!=NULL && aux->dato!=x){    
aux=aux->sig;
}
while(aux1!=NULL && aux1->dato!=y){
aux1=aux1->sig;
}
if(aux==NULL || aux1==NULL){
cout<<"Verifique sus datos\n";
}
   else{
aux2=aux->sig;

if(aux2->sig==aux1){
aux->sig=aux1;
aux1->ant=aux;

delete(aux2);
}
else if(aux->sig==aux1)  
cout<<"No hay rango\n";   
else{
cout<<"es mas de un dato desea eliminar  0) si\n";        
cin>>r;
if(r==0){
while(aux2!=aux1){
aux->sig=aux1;
aux1->ant=aux;
delete(aux2);  
aux2=aux->sig;
}
}
} 
}	
}

void burbuja(nodo *p)
{
char comp;
int total=0;
int i, j;
int temp;
nodo *aux, *aux2;
aux=p;
cout<<"\n";
while(aux!=NULL)
{
total++;
aux=aux->sig;
}
for(i=0;i<total-1;i++)
{
cout<<"\x1b[48;2;252;186;3;38;2;0;0;0mPasada "<<i+1<<"\x1b[0m\n";
cout<<"\n";
aux=p;
aux2=aux->sig;
for(j=0;j<total-1;j++)
{
if(aux->dato > aux2->dato)
{
cout<<"\x1b[38;2;52;229;235mLista actual: \x1b[0m";
imprimirIzqDer(p);
comp='V';
cout<<aux->dato<<" > "<<aux2->dato<<" = "<<"\x1b[38;2;0;0;0;48;2;3;252;86m"<<comp<<"\x1b[0m ";
temp=aux->dato;
aux->dato=aux2->dato;
aux2->dato=temp;
imprimirIzqDer(p);
cout<<"\n";
}
cout<<"\x1b[38;2;52;229;235mLista actual: \x1b[0m";
imprimirIzqDer(p);
comp='F';
cout<<aux->dato<<" > "<<aux2->dato<<" = "<<"\x1b[38;2;0;0;0;48;2;166;50;168m"<<comp<<"\x1b[0m ";
imprimirIzqDer(p);
aux=aux2;
aux2=aux2->sig;
cout<<"\n";
}
}
cout<<"\x1b[48;2;212;84;49mLista ordenada:\x1b[0m"" ";
imprimirIzqDer(p);
cout<<"\n";
}



void Seledi(nodo*p)
{
	nodo*aux,*aux2,*aux3,*aux4;
	int total;
	int menor=0;
	if(p==NULL)
	{
		cout<<"Lista vacia :,v\n\n";
	}
	else
	{	
		total=0;
		aux=p;
		while(aux!=NULL)
		{
			total++;
			aux=aux->sig;
		}
        aux=p;
		 for (int i=1;i<total;i++)
        	{
                cout << "\nPasada Numero..." <<i;
                aux2=aux->sig;
                menor=aux->dato;
                cout << "\nDato: ["<<menor<<"]";
                while (aux2!=NULL)
                {
                    if(menor>aux2->dato)
                    {
                        aux3=aux2;
                        menor=aux2->dato;
                    }
                    aux2=aux2->sig;
                }
                cout << "\tMenor: ["<<menor<<"]\n\n";
                aux3->dato=aux->dato;
                aux->dato=menor;
                aux4=p;
                while (aux4!=NULL)
                {
                    cout <<"["<< aux4->dato << "]";
                    aux4=aux4->sig;
                }
                cout << "\n-------------------------------------\n";
                aux=aux->sig;
            }	
	}
}

void Selebi(nodo *p) {
   nodo *aux, *aux2, *aux3, *aux4;
    int total;
    int con = 0;
    if (p == NULL)
    {
        cout << "Lista vacia :,v\n\n";
    }
    else
    {
        total = 0;
        aux = p;
        while (aux != NULL)
        {
            total++;
            aux = aux->sig;
        }
        aux = p;
        for (int i = 1; i < total; i++)
        {
            cout << "\nPasada Numero..." << i << "\n";
            aux2 = aux->sig;
            aux3 = aux2;
            con = 0;
            while ((aux != NULL) && (con == 0))
            {
                if (aux2->dato < aux->dato)
                {
                    cout << aux2->dato << " < " << aux->dato;
                    cout << "\t[V]\t";
                    int temp = aux->dato;
                    aux->dato = aux2->dato;
                    aux2->dato = temp;

                    aux4 = p;
                    while (aux4 != NULL)
                    {
                        cout << "[" << aux4->dato << "]";
                        aux4 = aux4->sig;
                    }

                    cout << "\n";
                }
                else
                {

                    cout << aux2->dato << " < " << aux->dato;
                    cout << "\t[F]\t";

                    aux4 = p;
                    while (aux4 != NULL)
                    {
                        cout << "[" << aux4->dato << "]";
                        aux4 = aux4->sig;
                    }
                    cout << "\n";
                    con = +1;
                }
                aux2 = aux2->ant;
                aux = aux->ant;
            }
            aux = aux3;
        }
    }
}

void Inbi(nodo*p)
{
	nodo*aux,*aux2,*aux3,*aux4;
	int total;
	int con=0 ;
    if (p==NULL)
            {
                cout << "Lista vacia";
            }
            else
            {
                total=0;
                aux=p;
                while (aux!=NULL)
                {
                    total++;
                    aux=aux->sig;
                }
                aux=p;
                for (int i=1;i<total;i++)
                {
                    cout << "\nPasada Numero..."<<i<<"\n";
                    aux2=aux->sig;
                    aux3=aux2;
                   	con=0;	
                    while((aux!=NULL)&&(con==0))
                    {
                        
                        if (aux2->dato < aux->dato)
                        {
                            cout << aux2->dato << " < " << aux->dato;
                            cout << "\t[V]\t";
                            int temp=aux->dato;
                            aux->dato=aux2->dato;
                            aux2->dato=temp;
                            aux4=p;
                            while (aux4!=NULL)
                            {
                                cout<<"["<< aux4->dato<<"]";
                                aux4=aux4->sig;
                            }
                            cout << "\n";
                        }
                        else
                        {
                        
                            cout << aux2->dato << " < " << aux->dato;
                            cout << "\t[F]\t";
                            
                            
                            aux4=p;
                            while (aux4!=NULL)
                            {
                                cout<<"["<< aux4->dato<<"]";
                                aux4=aux4->sig;
                            }
                            cout << "\n";
                           	con=+1;
                        }
                        aux2=aux2->ant;
                        aux=aux->ant;
                       
							
                    }
                    aux=aux3;
                    	
                
                }
    		}
}

void IB(nodo *p,nodo *f){

nodo *aux, *aux2, *aux3, *aux4;
int total=0,bandera=1;
int i, j,p1,k,j1;
int temp;
int div1;
int c1=0;
int c2=0;
int c3=0;
int c4=0;
aux=p;

aux3=p;
while(aux!=NULL)//Contamos el numero de datos en nuestra lista(nodos)
{
total++;
aux=aux->sig;
}
aux=p;
cout<<"Lista inicial \n";
imprimirIzqDer(p);
for(p1=1;p1<total;p1++){
	
        cout<<"\n Pasada "<<p1<<"\n";
        aux=aux->sig;//el siguiente
c1++;
         for(i=1+c2;i>0+c2;i--){
div1=(1+i)/2;  
   aux2=p;
for(k=1;k<div1;k++){
aux2=aux2->sig;//punto medio
}
 aux4=aux2;
   
if(aux->dato<aux2->dato)
{

cout<<"pm"<<i+1<<"=";
         cout<<i+1<<"/2="<<div1<<"\n";
             if(p1>1)
         cout<<aux->dato<<"<"<<aux2->dato<<"    v    \n";
    aux3=p;     
 while(aux3->sig!=aux->sig)
{
      if(aux->dato<aux3->dato){    
     cout<<aux->dato<<"<"<<aux3->dato<<"    v    ";        
temp=aux3->dato;
aux3->dato=aux->dato;
aux->dato=temp;
imprimirIzqDer(p);
}
    else if(aux->dato>aux3->dato){
   cout<<aux->dato<<"<"<<aux3->dato<<"    f    "; 
imprimirIzqDer(p); 
}
aux3=aux3->sig;
}
}
   //      

else if(aux->dato>aux2->dato){
cout<<"pm"<<i+1<<"=";
         cout<<i+1<<"/2="<<div1<<"\n";
        
 while(aux4->sig!=aux->sig)
{
  if(aux->dato<aux4->dato){ 
  cout<<aux->dato<<"<"<<aux4->dato<<"    v   ";
temp=aux4->dato;
aux4->dato=aux->dato;
aux->dato=temp;
imprimirIzqDer(p);
}
 else if(aux->dato>aux4->dato){
    cout<<aux->dato<<"<"<<aux4->dato<<"    f   ";
    imprimirIzqDer(p);
   } 

aux4=aux4->sig;

}
}
///

}

    c2++;
    
}



}

void shaker(nodo *p,nodo *f){
    
nodo *aux, *aux2, *aux3, *aux4;
int total=0,bandera=1;
int i, j,p1,k;
int temp;

int c1=0;
int c2=0;
aux=p;
aux3=p->sig;
aux4=aux3->sig;
while(aux!=NULL)//Contamos el numero de datos en nuestra lista(nodos)
{
total++;
aux=aux->sig;
}


cout<<"Lista : \n";
imprimirIzqDer(p);

for(p1=0;bandera!=0;p1++){
    
        bandera=0;
       cout<<"Pasada "<<p1+1<<"\n";
cout<<"\n";
cout<<"Vamos de derecha a izquierda: \n";

aux=f;
for(k=0;k<c1;k++){
aux=aux->ant; 
}
aux2= aux->ant;

aux3=p->sig;
for(k=0;k<c1;k++){
aux3=aux3->sig; 
}
aux4= aux3->sig;



for(i=0;i<total-1-(2*c1);i++)
{
if(aux2->dato>aux->dato)
{


cout<<aux2->dato<<" > "<<aux->dato<<" = V ";
temp=aux->dato;
aux->dato=aux2->dato;
aux2->dato=temp;
imprimirIzqDer(p);
cout<<"\n";

aux=aux2;

aux2=aux2->ant;


bandera++;
}
else
{

cout<<aux2->dato<<" > "<<aux->dato<<" = F ";
imprimirIzqDer(p);
cout<<"\n";
aux=aux2;

aux2=aux2->ant;

}



}





cout<<"Vamos de izquierda a derecha: \n";

for(j=1;j<total-1-(2*c1);j++)
{
if(aux3->dato > aux4->dato)
{

cout<<aux3->dato<<" > "<<aux4->dato<<" = V ";
temp=aux4->dato;
aux4->dato=aux3->dato;
aux3->dato=temp;
imprimirIzqDer(p);
cout<<"\n";

aux3=aux4;
aux4=aux4->sig;

bandera++;
}
else
{

cout<<aux3->dato<<" > "<<aux4->dato<<" = F ";
imprimirIzqDer(p);
cout<<"\n";
aux3=aux4;
aux4=aux4->sig;

}

}
c1++;
}
cout<<"Lista ordenada:";
imprimirIzqDer(p);
cout<<"\n";
}

void EliminarLista(nodo *&p) {
    while (p != NULL) {
        nodo *borrar = p;
        p = p->sig;
        delete borrar;
    }
    cout << "Todos los nodos han sido eliminados." << endl;
}
