#include <iostream>
#include <conio.h>
#include <time.h>
#include <queue>
#include <locale.h>
using namespace std;

struct Nodo{
	int dato; //campo 1
	Nodo *enlace, *ant; //campo 2
	
};
void insertarDer(Nodo *);
Nodo* insertarIzq(Nodo *);
void imprimir(Nodo *);
void buscarYEliminarNodo(Nodo *&, int);
void Buscamodi(Nodo *, int);
void Eliminarultima(Nodo*&);
void Eliminarprim(Nodo*&);
bool buscarElemento(Nodo*, int);
Nodo* Agregaraleder(Nodo *, int );
Nodo* AgregaraleIz(Nodo *, int );
int suma(Nodo *);
bool ModificarElemento(Nodo* , int );
void insertarantesx(Nodo *, int);
void insertardespuesx(Nodo *, int);
Nodo* insertar101despues(Nodo *);
Nodo* insertarantespar(Nodo *);
Nodo* INantPAR(Nodo *);
void eliminarNodosEntreXY(Nodo *&,int,int);
void buscarYEliminarAnterior(Nodo *&, int);

int main(){
	Nodo *p=NULL;
	int opc, n, x, y;
	while(1){
		system("cls");
		cout<<"\t\t Bodoque´s List"<<endl;
		cout<<endl<<"0. Imprimir. "<<endl;
		cout<<"1. Insertar a la derecha. "<<endl;
		cout<<"2. Insertar a la Izquierda. "<<endl;
		cout<<"3. Aleatorios a la derecha."<<endl;
		cout<<"4. Aleatorios a la izquierda. "<<endl;
		cout<<"5. Sumar datos. "<<endl;
		cout<<"6. Buscar elemento. "<<endl;
		cout<<"7. Buscar y modificar"<<endl;
		cout<<"8. Insertar antes de x. "<<endl;
		cout<<"9. Insertar despues de x. "<<endl;
		cout<<"10. Insertar 101 antes de los pares."<<endl;
		cout<<"11. Insertar 101 despues de los pares."<<endl;
		cout<<"12. Eliminar primer nodo."<<endl;
		cout<<"13. Eliminar ultimo dato."<<endl;
		cout<<"14. Eliminar entre X y Y. "<<endl;
		cout<<"15. Eliminar antes de x."<<endl;
		cout<<"16. Eliminar despues de x."<<endl;
		cout<<"17. Buscar y eliminar. "<<endl;
	
	
		cout<<"Opcion: ";	cin>>opc;
		switch(opc){
			case 0:
				if(p==NULL){
					cout<<"Lista vacia. "<<endl;
				}else{
					imprimir(p);
				}
				getch();
				break;
			case 1:
				if(p==NULL){
					p=new(Nodo);
					cout<<"Ingrese el dato: ";
					cin>>p->dato;
					p->enlace=NULL;
				}else{
					insertarDer(p);
				}
				getch();
			case 2:
				if(p==NULL){
					p=new(Nodo);
					cout<<"Ingrese el dato: ";
					cin>>p->dato;
					p->enlace=NULL;
				}else{
					p=insertarIzq(p);
				}
				getch();
			case 3:
				cout<<"Cuantos datos desea agregar: ";	cin>>n;
            	p=AgregaraleIz(p, n);
            	getch();
				break;
			case 4:
          		cout<<"Cuantos datos desea agregar: ";	cin>>n;
            	p=Agregaraleder(p, n);
            	getch();
            	break;
            case 5:
            n=suma(p);
            	cout<<"	La suma es: "<<n;
            	getch();
            	break;
            case 6:
            	    if (p != NULL) {
        			cout << "Ingrese el elemento a buscar: ";
    			    cin >> n;
    		    	buscarElemento(p, n);
    				} else {
    				    cout << "La lista está vacía." << endl;
  					  }
  					getch();
            	break;
            case 7:
            	if (p != NULL) {
        			cout << "Ingrese el elemento a buscar: ";
    			    cin >> n;
					ModificarElemento(p, n);
					} else {
    					    cout << "La lista está vacía." << endl;
  						  }
  				getch();
            	break;
            case 8:
            	if (p != NULL) {
        			cout << "Ingrese el elemento a buscar: ";
    			    cin >> n;
					insertarantesx(p, n);
					} else {
    					    cout << "La lista está vacía." << endl;
  						  }
  					getch();
            	break;
            case 9:
            	if (p != NULL) {
        			cout << "Ingrese el elemento a buscar: ";
    			    cin >> n;
					insertardespuesx(p, n);
					} else {
    					    cout << "La lista está vacía." << endl;
  						  }
  					getch();
            	break;
            case 10:
            if (p != NULL) {
					p=INantPAR(p);
					} else {
    					    cout << "La lista está vacía." << endl;
  						  }
  				getch();
            	break;
            case 11:
            		if (p != NULL) {
					p=insertar101despues(p);
					} else {
    					    cout << "La lista está vacía." << endl;
  						  }
  				getch();
            	break;
            case 12:
            	if (p != NULL) {
                	Eliminarprim(p);
            		}
           			else {
           		     cout << "La lista esta vacia. " << endl;
            		}
            	getch();
            	break;
            case 13:
            		if (p != NULL) {
                	Eliminarultima(p);
            		}
           			else {
           		     cout << "La lista esta vacia. " << endl;
            		}
            	getch();
            	break;
            case 14:
            if (p != NULL) {
            		cout<<"Ingresa el valor de x: ";	cin>>x;
            		cout<<"Ingresa el valor de y: ";	cin>>y;
					eliminarNodosEntreXY(p,x,y);
					} else {
    					    cout << "La lista está vacía." << endl;
  						  }
  				getch();
            	break;
            case 15:
            	if (p != NULL) {
            		cout<<"Ingresa el valor a buscar: ";	cin>>n;
            	 buscarYEliminarAnterior(p,n);
            	 } else {
    					    cout << "La lista está vacía." << endl;
  						  }
  				getch();
            	break;
          //  case 16:
            //	if (p != NULL) {
            	//	cout<<"Ingresa el valor a buscar: ";	cin>>n;
            	// buscarYEliminarposterior(p,n);
            	 //} else {
    			//		    cout << "La lista está vacía." << endl;
  					//	  }
  		//		getch();
            //	break;
            	
            case 17:
            		if (p != NULL) {
            		cout<<"Ingresa el valor a buscar: ";	cin>>n;
            		buscarYEliminarNodo(p,n);
            		} else {
    					    cout << "La lista está vacía." << endl;
  						  }
  				getch();
        
            	
		}
	}
}

void imprimir(struct Nodo *aux){
	cout<<"contenido de la lista. "<<endl;
	while(aux!=NULL){
		cout<<aux->dato<<" "<<endl;
		aux=aux->enlace;
	}
}


void insertarDer(struct Nodo *p){
	struct Nodo *f, *aux;
	f=p;
	while(f->enlace!=NULL){
		f=f->enlace;
		
	}
	aux=new(Nodo);
		cout<<"Ingresa el dato: "<<endl;
		cin>>aux->dato;
		aux->enlace=NULL;
		f->enlace=aux;
		f=aux;
	
}

Nodo* insertarIzq(struct Nodo *p){
	struct Nodo *aux;
	aux=new(Nodo);
	cout<<"Ingresa el dato: ";	cin>>aux->dato;
	aux->enlace=p;
	p=aux;
	return p;
}

void buscarYEliminarNodo(Nodo *&p, int elementoBuscado) {
    Nodo *anterior = NULL;
    Nodo *actual = p;

    while (actual != NULL && actual->dato != elementoBuscado) {
        anterior = actual;
        actual = actual->enlace;
    }

    if (actual == NULL) {
        cout << "Elemento no encontrado en la lista." << endl;
        return;
    }

    if (anterior != NULL) {
        Nodo *borrar = actual;
        anterior->enlace = actual->enlace;
        delete borrar;
    } else {
        Nodo *borrar = p;
        p = p->enlace;
        delete borrar;
    }

    cout << "Elemento " << elementoBuscado << " eliminado." << endl;
    imprimir(p);
}

void Eliminarprim(Nodo*& p) {
    if (p != NULL) {
        Nodo* borra = p;
        p = p->enlace;
        delete borra;
    }
    else {
        cout << "La lista esta vacia :(" << endl << endl;
    }
}

void Eliminarultima(Nodo*& p) {
    if (p != NULL) {
        if (p->enlace == NULL) {
            delete p;
            p = NULL;
        }
        else {
            Nodo* anterior = NULL;
            Nodo* actual = p;

            while (actual->enlace != NULL) {
                anterior = actual;
                actual = actual->enlace;
            }

            anterior->enlace = NULL;
            delete actual;
        }
    }
    else {
        cout << "La lista esta vacia :(" << endl << endl;
    }
}

bool buscarElemento(Nodo* p, int n) {
    Nodo* actual = p;
    while (actual != NULL) {
        if (actual->dato == n) {
            cout << "Elemento encontrado: " << n << endl;
            return true;
        }
        actual = actual->enlace;
    }
    cout << "Elemento no encontrado: " << n << endl;
    return false;
}

Nodo* Agregaraleder(Nodo *p, int n){
	Nodo *aux, *f;
	srand(time(NULL));
	if(p==NULL){
			p=new(Nodo);
			p->dato=1+rand()%100;
			p->enlace=NULL;
			f=p;
			for(int i=2;i<=n; i++){
			aux=new(Nodo);
			aux->dato=60+rand()%100;
			aux->enlace=NULL;
			f->enlace=aux;
			f=aux;
			
		}
	
	}else{
	
		f=p;
		while(f->enlace!=NULL){
		f=f->enlace;	
	}
		for(int i=1;i<=n; i++){
			aux=new(Nodo);
			aux->dato=1+rand()%100;
			aux->enlace=NULL;
			f->enlace=aux;
			f=aux;
		
		}		
	}
	cout<<"Valores agregados: "<<endl;
	return p;
}

Nodo* AgregaraleIz(Nodo *p, int n){
	Nodo *aux, *f;
	int a=0;
	srand(time(NULL));
	if(p==NULL){
			p=new(Nodo);
			p->dato=1+rand()%100;
			p->enlace=NULL;
			f=p;
			for(int i=2;i<=n; i++){
			aux=new(Nodo);
			aux->dato=30+rand()%100;
			aux->enlace=p;
			p=aux;
		
		}
	}else{

		for(int i=1;i<=n;i++){
			aux=new(Nodo);
			aux->dato=1+rand()%100;
			aux->enlace=p;
			p=aux;
		
				
		}
		
	}
		cout<<"Valores agregados: "<<endl;
	return p;
}

int suma(Nodo *p){
	Nodo  *f;
	int suma=0;
	f=p;
	while(f!=NULL){
		suma+=f->dato;
		f=f->enlace;
	}
	return suma;	
}

bool ModificarElemento(Nodo* p, int n) {
    Nodo* actual = p;
    while (actual != NULL) {
        if (actual->dato == n) {
            cout << "Elemento encontrado: " << n << endl;
            cout<<" Ingresa el nuevo valor: ";
            cin>>actual->dato;
            cout<<"Dato modificado :)"<<endl;
            return true;
        }
        actual = actual->enlace;
    }
    cout << "Elemento no encontrado: " << n << endl;
    return false;
}

void insertarantesx(Nodo *p, int elementoBuscado) {
    if (p != NULL) {
        Nodo *nuevoNodo = new Nodo;
        nuevoNodo->enlace = NULL;

        if (p->dato == elementoBuscado) {
        	
            nuevoNodo->enlace = p;
            p = nuevoNodo;
            return;
        }

        Nodo *actual = p;
        while (actual->enlace != NULL) {
            if (actual->enlace->dato == elementoBuscado) {
            	cout<<"Dato encontrado "<<elementoBuscado<<endl;
            	cout<<"Ingrese el valor: "<<endl;
            	cin>>nuevoNodo->dato;
            	 cout<<"Elemento creado antes de x :)"<<endl;
                nuevoNodo->enlace = actual->enlace;
                actual->enlace = nuevoNodo;
                return;
            }
            actual = actual->enlace;
        }
        if(actual->dato!=elementoBuscado){
        	cout<<"Elemento no encontrado :("<<endl;
		}
    }
}

void insertardespuesx(Nodo *p, int elementoBuscado) {
    if (p != NULL) {
        Nodo *nuevoNodo = new Nodo;
        nuevoNodo->enlace = NULL;

        Nodo *actual = p;
        while (actual != NULL) {
            if (actual->dato == elementoBuscado) {
            	cout<<"Dato encontrado "<<elementoBuscado<<endl;
            	cout<<"Ingrese el valor: "<<endl;
            	cin>>nuevoNodo->dato;
            	cout<<"Elemento creado despues de x :)"<<endl;
                nuevoNodo->enlace = actual->enlace;
                actual->enlace = nuevoNodo;
                return;
            }
            actual = actual->enlace;
        }
        if(actual->dato!=elementoBuscado){
        	cout<<"Elemento no encontrado :("<<endl;
		}
    }
}


Nodo* insertarantespar(Nodo *p){
	Nodo *actual=p;
        while (actual!= NULL) {
            if (actual->dato%2==0) {
            	Nodo *nuevoNodo = new Nodo;
      			nuevoNodo->dato=101;
        		nuevoNodo->enlace = NULL;
            	cout<<"Elemento creado antes del par :)"<<endl;
                nuevoNodo->enlace = actual->enlace;
                actual->enlace = nuevoNodo;
                if (actual->enlace != NULL) 
				{
				actual->enlace->ant = nuevoNodo;
				}
				actual->enlace = nuevoNodo;
				actual= actual->enlace;
				}
				actual =actual->enlace;
				}
				return p;

            actual = actual->enlace;}


Nodo* insertar101despues(Nodo* p)
{
Nodo* aux = p;
while (aux!=NULL) 
{
if (aux->dato%2==0) 
{ // Si el dato es par
Nodo* nuevo = new Nodo();
nuevo->dato = 101;
nuevo->ant = aux;
nuevo->enlace = aux->enlace;
cout<<"Elemento creado despues del par :)"<<endl;
if (aux->enlace != NULL) 
{
aux->enlace->ant = nuevo;
}
aux->enlace = nuevo;
aux = aux->enlace;
}
aux = aux->enlace;
}
return p;
}

Nodo* Agregarantespar(Nodo *p){
	Nodo *actual=p;
	Nodo *anterior=NULL;
	while(actual!=NULL){
		if(actual->dato%2==0){
			Nodo *nuevo=new Nodo;
			nuevo->dato=101;
			nuevo->enlace=nuevo;
			if(anterior==NULL){
				p=nuevo;
			}else{
				anterior->enlace=nuevo;
			}
			anterior=nuevo;
		}
		anterior=actual;
		actual=actual->enlace;
	}
	return p;
}

Nodo* INantPAR(Nodo *p){

                Nodo *aux,*aux2,*nuevo;

                int band=0,i;

                aux=p;

                if(aux==NULL){

                               cout<<"**la lista esta vacia**";

                }else{

                               while(aux!=NULL){

                                               if(aux->dato%2==0){

                                                              

                                               if(aux==p){

                                                     ///en caso de que sea par

                                                   band=1;

                                                               nuevo=new(Nodo);

                                                               nuevo->dato=101;

                                                               nuevo->enlace=aux;

                                                               p=nuevo;

                                                              

                                               }

                                              

                                               else{

                                                              nuevo=new(Nodo);

                                                              nuevo->dato=101;

                                                              aux2->enlace=nuevo;

                                                              nuevo->enlace=aux;

                                               }

                               }

                               aux2=aux;

                               aux=aux->enlace;           

                                                               ///// en caso de que no sea par                                             

                               }

                              

                }if(band==0)

                cout<<"dato no encontrado";

                return p;             

}

void buscarYEliminarAnterior(Nodo *&p, int elementoBuscado) {
    Nodo *anterior = NULL;
    Nodo *actual = p;

    while (actual != NULL && actual->dato != elementoBuscado) {
        anterior = actual;
        actual = actual->enlace;
    }

    if (actual == NULL) {
        cout << "Elemento no encontrado en la lista." << endl;
        return;
    }

    if (anterior != NULL) {
        Nodo *borrar = anterior->enlace;
        anterior->enlace = actual->enlace;
        delete borrar;
    } else {
        Nodo *borrar = p;
        p = p->enlace;
        delete borrar;
    }

    cout << "Nodo anterior al elemento " << elementoBuscado << " eliminado." << endl;
    imprimir(p);
}


void eliminarNodosEntreXY(Nodo *&p, int X, int Y) {
    Nodo *anterior = NULL;
    Nodo *actual = p;

    // Busca el nodo con valor X
    while (actual != NULL && actual->dato != X) {
        anterior = actual;
        actual = actual->enlace;
    }

    if (actual == NULL) {
        cout << "El elemento X no se encuentra en la lista." << endl;
        return;
    }

    // Guarda una referencia al nodo con valor X
    Nodo *nodoX = actual;

    // Restablece el puntero actual al nodo X
    actual = nodoX;

    // Busca el nodo con valor Y
    while (actual != NULL && actual->dato != Y) {
        anterior = actual;
        actual = actual->enlace;
    }

    if (actual == NULL) {
        cout << "El elemento Y no se encuentra en la lista después de X." << endl;
        return;
    }

    // Ahora, en este punto, tenemos el nodo X y el nodo Y en la lista.
    // Eliminamos los nodos entre X y Y, sin incluir X ni Y.
    actual = nodoX->enlace; // Comenzamos desde el nodo siguiente a X

    while (actual->dato != Y) {
        Nodo *borrar = actual;
        actual = actual->enlace;
        delete borrar;
    }

    nodoX->enlace = actual; // Enlaza el nodo X con el nodo Y

    cout << "Nodos entre " << X << " y " << Y << " eliminados." << endl;
    imprimir(p);
}


