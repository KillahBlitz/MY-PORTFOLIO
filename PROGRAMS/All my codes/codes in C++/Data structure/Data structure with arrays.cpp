//Librerias
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//prototipos de funciones
void VerArreglo(int []);
int AsignarManual(int [], int);
int AsignarAleatorios(int [], int);
int iniN(int [], int, int);
int ini1aN(int [], int);
int sumaarr(int [], int);
void max(int [], int);
void min(int [], int);
float promedios(int [],int);
int buscar(int [],int);
void Buscarposicion(int [],int);
int Inserpos0(int [],int);
int InsertarUltpos(int [], int);
int insertarbloque(int [],int);
int BloqueUp(int [], int);
int Eliminarbloqueinicio(int [], int, int);
int Eliminarbloquefinal(int [], int, int);
int Bloquesubindice(int [], int,int);
int EliminarBloqueSubX(int [], int);
int Eliminarpares(int [],int);
int Buscareliminar(int [],int);
bool EsPrimo(int);
void EliminarPrimos(int[], int&);
void burbuja(int [], int);
int eliminarprimos(int [],int);
void seleccion(int [], int);
void sort(int [], int);
void binaria(int[], int);
void ShakerSort(int [], int);


//
void shaker(int[],int);
void ins(int [],int);
void insb(int [],int);


//Cuerpo del programa
int main(void){
	int datos[20]={0}, opc, n, up=-1, valor, suma, dato; 
	float promedio;
	while(1){
		cout<<"\t\t MENU\t\t"<<endl;
		cout<<"0. Imprimir. "<<endl;
		cout<<"1. Ingresar datos manualmente."<<endl;
		cout<<"2. Ingresar datos aleatorios."<<endl;
			cout<<"3. Inicializacion con N"<<endl;
		cout<<"4. Inicializacion de 1 a N"<<endl;
		cout<<"5. Sumatoria del contenido del arreglo"<<endl;
		cout<<"6. Valor maximo y posicion"<<endl;
		cout<<"7. Valor minimo y posicion"<<endl;
		cout<<"8. Promedio"<<endl;
		cout<<"9. Busqeda"<<endl;
		cout<<"10. Colocar posicion 0."<<endl;
		cout<<"11. ultima posicion"<<endl;
		cout<<"12. Insertar bloque"<<endl;
		cout<<"13.Up Bloque"<<endl;
		cout<<"14. Colocar en N posicion"<<endl;
		cout<<"15. Eliminar bloque al inicio."<<endl;
		cout<<"16. Eliminar bloque final."<<endl;
		cout<<"17. Eliminar bloque en subindice N"<<endl;
		cout<<"18. Eliminar pares"<<endl;
		cout<<"19. Buscar y eliminar"<<endl;
		cout<<"20. Elimar numeros primos."<<endl;
		cout<<"21. Metodo de la burbuja"<<endl;
		cout<<"22. Seleccion directa"<<endl;
		cout<<"23. Shaker sort "<<endl;
		cout<<"24. Ordenacion binaria"<<endl;
		cout<<"25. Insercion directa"<<endl;
		
		cout<<"Seleccione una opcion: ";	cin>>opc;
		switch(opc){
			case 0:
				VerArreglo(datos);
				break;
			case 1:
				up=AsignarManual(datos,up);
				break;
			case 2:
				cout<<"Cuantos desea generar? ";	cin>>n;
				up=AsignarAleatorios(datos,n);
				break;
			case 3:
				cout<<"Ingrese el total de datos";
				cin>>n;
				cout<<"Ingresa el valor";	cin>>valor;
				up=iniN(datos, n, valor);
				break;
			case 4:
				cout<<"Ingrese el total de datos";
				cin>>n;
				cout<<"Ingresa el valor";	cin>>valor;
				up=ini1aN(datos, valor);
				break;
			case 5:
				suma=sumaarr(datos,n);
				cout<<"la suma es: "<<suma<<endl;
			break;
			case 6:
				max(datos,up);
				break;
			case 7:
				min(datos,up);
				break;
			case 8:
				promedio=promedios(datos, up);
				cout<<"el promedio es :"<<promedio<<endl;
				break;
			case 9:
				Buscarposicion(datos,up);
				break;
			case 10:
				up=Inserpos0(datos,up);
				break;
			case 11:
				up=InsertarUltpos(datos,n);
				break;
			case 12:
				up=insertarbloque(datos,up);
				break;
			case 13:
				up=BloqueUp(datos,up);
				break;
			case 14:
				cout<<"Ingrese el tamaño del bloque: ";	cin>>n;
				up=Bloquesubindice(datos,up,n);
				break;
			case 15:
				cout<<"Ingresa el tamaño del bloque: ";	cin>>n;
				up=Eliminarbloqueinicio(datos,up, n);
				break;
			case 16:
				cout<<"Ingresa el tamaño del bloque: ";	cin>>n;
				up=Eliminarbloquefinal(datos,up,n);
				break;
			case 17:	
				up=EliminarBloqueSubX(datos,up);
				break;
			case 18:
				up=Eliminarpares(datos,up);
				break;
			case 19:
				up=Buscareliminar(datos,up);
				break;	
			case 20:
				 EliminarPrimos(datos,up);
				break;
			case 21:
				burbuja(datos, up);
				break;
			case 22:
				seleccion(datos,up);
				break;
			case 23:
				shaker(datos, up);
				break;
			case 24:
				insb(datos,up);
				break;
			case 25:
				ins(datos,up);	
				break;
					}
	}
}
//case 0:
void VerArreglo(int d[20]){
	int i;
	cout<<"Subindice \t Dato"<<endl;
	for(i=0;i<=19;i++){
		cout<<i<<"\t\t"<<d[i]<<endl;
	}
}
//case 1:
int AsignarManual(int d[20], int up){
	int i, numero;
	cout<<"Cuantos datos desea iniciar? ";	cin>>numero;
	for(i=0;i<numero;i++){
		cout<<"Ingrese el valor en la posicion "<<i<<" ";	cin>>d[i];
	}
	up=i-1;
	return up;
}
//case 2:
int AsignarAleatorios(int d[20], int n){
	int i, up;
	srand(time(NULL));
	for(i=0;i<n;i++){
		d[i]=1+rand()%100;
	}
	up=n-1;
	return up;
}

//funcion iniciar con N
//case3 :
int iniN(int d[20],int n, int v){
	int i, up;
	for(i=0;i=n;i++){
		d[i]=v;
		up=i-1;
	}
		return up;
}
//funcion iniciar de 1 a N
//case 4:
int ini1aN(int d[20],int n){
int i,up;
cout<<"Ingrese el total de datos";
cin>>n;
for(i=0;i<=19;i++){
	d[i]=i+1;
	up=i-1;
}
		return up;
}
//funcion sumatoria del arreglo
//case 5:
int sumaarr(int d[20], int n){
	int i,up;
	float sumaaaa=0, prome=0;
	for(i=0;i<=19;i++){
		sumaaaa+=d[i];
	}
	return sumaaaa;
}
//funcion de busqueda mayor
//case 6:
void max(int d[20], int upos){
	int i, max=0, pmax;
	max=d[0];
	for(i=0;i<=19; i++){
		if(d[i]>max){
			max=d[i];
			pmax=i;
		}
	}
	cout<<"El valor maximo es : "<<max<<" la posicion es "<<pmax<<endl;
}
//funcion de busqueda menor 
//case 7:
void min(int d[20], int upos){
	int i, mini, pmini;
	mini=d[0];
	for(i=0;i<=19; i++){
		if(d[i]<mini){
			mini=d[i];
			pmini=i;
		}
	}
	cout<<"El valor mini es : "<<mini<<" la posicion es "<<pmini<<endl;
}
//funcion de promedio
//case 8:
float promedios(int d[20], int upos){
	int i;
	float sumaaa=0, prome=0;
	for(i=0;i<=upos;i++){
		sumaaa+=d[i];
	}
	prome=sumaaa/upos;
	return prome;
}
 //buscar
int buscar(int d[20], int up){
	int i,da,dat,indice;
	da=d[0];
	cout<<"ingresa el numero a buscar:";
	cin>>dat;
	for(i=0;i<=up;i++){
		if(dat==d[i]){
			da=d[i];
		}	}
		return da;
}

//case 9:
void Buscarposicion(int d[20],int up){
	int i,da,dat,psicion1;
	da=buscar(d,up);
	for(i=0;i<=up;i++){
		if(da==d[i]){
			psicion1=i;
		}	}
		if(da==d[i]){
			cout<<"El dato es "<<da<<" y esta en la posicion "<<psicion1<<endl;
		}
	
}

//case 10:
//up=Inserpos0(Datos,up);
//break;
int Inserpos0(int d[20],int ups){
	int i;
	if(ups==-1){
		ups++;
		cout<<"Ingrese el dato: ";	cin>>d[0];
	}
	else{
		ups++;
		if(ups<=19){
			for(i=ups;i>0;i--){
				d[i]=d[i-1];}
				cout<<"Ingresa el dato "<<i;	cin>>d[0];
		}else{
			cout<<"El arreglo esta lleno :("<<endl;
		}
	}
	return ups;
}

//case 11:
//up=InsertarUltpos(datos,n);
//break;
int InsertarUltpos(int d[0], int n){
	int i, ups;
	ups=n-1;
	if(ups<19){
		cout<<"Ingresa el dato ";	cin>>d[ups];
	}else{
		cout<<"El arreglo esta lleno :("<<endl;
	}
	return ups;
}

//case 12:
//up=insertarbloqueinnicio(datos,up);
//break;
int insertarbloque(int d[20],int upos){
	int i, bloq, tempo;
	cout<<"De que tamaño es el bloque: ";	cin>>bloq;
	if(upos==-1){
		upos=AsignarAleatorios(d,bloq);
	
	}else{
		tempo=upos+bloq;
		if(upos<=19){
			upos=tempo;
			for(i=upos; i>=bloq; i--){
				d[i]=d[i-bloq];}
				tempo=AsignarAleatorios(d,bloq);
				
		}else{
			cout<<"El bloque excede el tamaño del arreglo :("<<endl;
		}
	}
	return upos;
}

//case 13:
//up=BloqueUp(datos,up);
//break;
int BloqueUp(int d[20], int upos){
	int i, temppo,bloque,aux;
	cout<<"Ingrese el tamaño del bloque ";	cin>>bloque;
	if(upos==-1){
		upos=AsignarAleatorios(d,bloque);
	}else{
		temppo=upos+bloque;
		if(temppo<=19){
		temppo=upos+bloque;
				for(i=upos; i<=temppo; i++){
			d[i]=AsignarAleatorios(d,bloque);
		}
		upos=temppo;		
		}else{
			cout<<"El arreglo esta lleno :(";
		}
	}
	return upos;
	
}

//case 14 chido:
//cout<<"Ingrese el tamaño del bloque: ";	cin>>n;
//up=Insertarbloquex(datos,up,n);
//break;
int Bloquesubindice(int d[20],int upos, int N){
	int i, subindi, aux, temporal, opcc;
	cout<<"Ingrese subindice: ";	cin>>subindi;
	if(upos==-1){		//condicional siempre y cuando el arreglo este vacio
		cout<<"El arreglo esta vacio:("<<endl<<"Creando arreglo :)"<<endl;
		upos=subindi;
		for(i=upos;i<=(upos+N-1); i++){
			d[i]=AsignarAleatorios(d,N);
		}
		for(i=0;i<subindi;i++){
			d[i]=0;
		}
		cout<<"Arreglo creado con exito :3"<<endl;
	}else{
		aux=upos+N;
		srand(time(NULL));
		if(aux<=19){
			upos=aux;
			temporal=subindi;
			for(i=upos;i>=N;i--){
				d[i]=d[i-N];
			}
			cout<<endl<<"Como desea los nuevos valores?"<<endl<<"1.Aleatorios"<<endl<<"2.Manuales"<<endl<<"opc: ";	cin>>opcc;
			switch(opcc){
				case 1: 
					for(i=subindi;i<(subindi+N);i++){
						d[i]=1+rand()%100; //Generar numeros aleatorios
					}
					break;
				case 2:
					for(i=subindi;i<(subindi+N);i++){
					cout<<"Ingrese el nuevo valor en la posicion "<<i<<" ";
					cin>>d[i];}
					break;
			}
		
		}else{
			cout<<"No caben los datos en el arreglo :("<<endl;
		}
	}
	return upos;
}


//case 15:
//up=Eliminarbloqueinicio(dato,up);
int Eliminarbloqueinicio(int d[20], int upos, int bloqu){
	int i, tempo;
	if(upos==-1){		//condicional siempre y cuando el arreglo este vacio
		cout<<"El arreglo esta vacio (:"<<endl;
	}else{
		tempo=upos-bloqu;
		for(i=0;i<=tempo; i++){
				d[i]=d[i+bloqu];}
		for(i=(tempo+1); i<=upos; i++){
			d[i]=0;
		}
		upos=tempo;
	}
	return upos;
}

//case 16:
//up=Eliminarbloquefin(dato,up, n);
//break;
int Eliminarbloquefinal(int d[20], int upos, int bloqu){
	int i, tempo;
	if(upos==-1){	//condicional siempre y cuando el arreglo este vacio 
		cout<<"El arreglo esta vacio (:"<<endl;
	}else{
		tempo=upos-bloqu;
		for(i=(tempo+1);i<=upos; i++){
				d[i]=0;}
		upos=tempo;
	}
	return upos;
}


//case 17:
int EliminarBloqueSubX(int d[20], int up)
{
	int i, b, da, di;
	if(up == -1)
	{
		up++;
		cout << "El bloque está vacío ";
	}
	else
	{
		up++;
		cout << "¿En qué posición desea eliminar el bloque?: ";
		cin >> b;
		cout << "Ingresa hasta donde quieres eliminar: ";
		cin >> da;
		
		if(b <= 19)
		{
			if(d[b] != 0)
			{
				di = da-b;
				for(i=b;i<= up; i++)
				{
		    		d[i]=d[i+di];

				}
				for(i=da+1+di;i<=up; i++)
				{
					d[i]=0;
				}
				
			}
			else
			{
				cout << "La posición: " << b << " está vacia, introduzca un dato antes de realizar está acción";
			}
			
		}
		else
			cout << "Escoge una posición menor igual a 19 \n";
			
		
	}
	return up;
}

//case 18:
//up=Eliminarpares(datos,up);
//break;
int Eliminarpares(int d[20],int upos){
	int i=0, j;
	while(i<=upos){
		if(d[i]%2==0){
			for(j=i;j<upos;j++){
				d[j]=d[j+1];
			}
			d[upos]=0;
			upos--;
		}else{
			i++;
		}
	}
	return upos;
}

//case 19:
//up=Buscareliminar(datos,up);
//break;
int Buscareliminar(int d[20],int up){
	int i,da,dat,psicion1,indice;
	da=d[0];
	cout<<"ingresa el numero a buscar:";
	cin>>dat;
	for(i=0;i<=19;i++){
		if(dat==d[i]){
			da=d[i];
			psicion1=i;
		}	}
		if(da==dat){
				cout<<"el dato es "<<dat<<" y se encuentra en la posicion "<<psicion1<<endl;
				indice=i;
		}else{
			cout<<"No existe el dato :3"<<endl;
		}
	for(i=psicion1;i<=up;i++){
		d[i]=d[i+1];
	}
	return up;
}


bool EsPrimo(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}

void EliminarPrimos(int datos[], int &up) {
    int i, j = 0;
    
    
    for (int i = 0; i <= up; i++) {
        if (!EsPrimo(datos[i])) {
            datos[j] = datos[i];
            j++;
        }
    }
    
    up = j - 1;
    for(int i=up;i<=19;i++){
    	datos[i]=0;
	}
    
    cout << "Números primos eliminados." << endl;
}


//case 21:
//burbuja(datos,up);
//break;
void burbuja(int d[20], int up){
	int p=up,c=up,x,y, imp;
	for(p=0;p<up-1;p++)
	{	
		cout<<"\n\nPasada "<<p+1<<"\n\n";
		for(c=0;c<up;c++)
		{
			if(d[c]>d[c+1])
			{
				cout<<d[c]<<">"<<d[c+1]<<"--V  ";
				x=d[c+1];
				y=d[c];
				d[c]=x;
				d[c+1]=y;
				for(imp=0;imp<=up;imp++){
					cout<<d[imp]<<" ";	
				}
				cout<<"\n";
			}
			else
			{
				cout<<d[c]<<">"<<d[c+1]<<"--F  ";
				for(imp=0;imp<=up;imp++){
					cout<<d[imp]<<" ";	
				}
				cout<<"\n";	
			}
		}
	}
	cout<<"\n";
}


//case 22:
void seleccion(int d[20], int up)
{
	int min, i, r, x, y,imp,pos;
	for(r=0;r<up;r++)
	{
		min=d[r];
		for(i=r;i<=up;i++)
		{
			if(d[i]<min)
			{
				min=d[i];
				pos=i;
			}
		}
		cout<<"\n\nComparacion "<<r+1<<"\n";
		cout<<"Dato: "<<d[r]<<", Posicion: "<<r<<"	Menor: "<<min<<", Posicion: "<<pos<<"\n";
		if(d[r]>min)
		{
			cout<<"Intercambio....\n";
			x=d[pos];
			y=d[r];
			d[pos]=y;
			d[r]=x;
			for(imp=0;imp<=up;imp++)
			{
				cout<<d[imp]<<" ";
			}
			cout<<"\n\n";
		}
		else
			cout<<"No es necesario intercambiar\n";
	}
	cout<<"\n\n";
}

//case 23:
void sort(int a[20], int up)
{
	int p=up,c=up,x,y,imp, i, d, band=1,vali=0,vald=up,h;
		for(p=0;band!=0;p++)
		{	
			band=0;
			i=vali;
			d=vald;
			h=d;
			cout<<"\n\nPasada "<<p+1<<"\n";
			cout<<"I="<<i<<"  D="<<d<<"\n";
			cout<<"Derecha a izquierda\n\n";
			for(d;d>i;d--)
			{
				if(a[d-1]<a[d])
				{
					cout<<a[d]<<"<"<<a[d-1]<<"--F  ";
					for(imp=0;imp<=up;imp++)
					{
						cout<<a[imp]<<" ";	
					}
					cout<<"\n";
					band++;
				
				}
				else
				{
					cout<<a[d]<<"<"<<a[d-1]<<"--V  ";
					x=a[d];
					y=a[d-1];
					a[d-1]=x;
					a[d]=y;
					for(imp=0;imp<=up;imp++)
					{
						cout<<a[imp]<<" ";	
					}
					cout<<"\n";
					band++;
					
				}
				
			}
			cout<<"Izquierda a derecha\n\n";
			for(i=d+1;i<h;i++)
			{
				if(a[i]>a[i+1])
				{
					cout<<a[i]<<">"<<a[i+1]<<"--V  ";
					x=a[i];
					y=a[i+1];
					a[i+1]=x;
					a[i]=y;
					for(imp=0;imp<=up;imp++)
					{
						cout<<a[imp]<<" ";	
					}	
					cout<<"\n";
					band++;
				}
				else
				{
					cout<<a[i]<<">"<<a[i+1]<<"--F  ";
					for(imp=0;imp<=up;imp++)
					{
						cout<<a[imp]<<" ";	
					}
					cout<<"\n";
				}
			}
			vali++;
			vald--;
		}
		cout<<"\n";
}

void binaria(int a[20],int up)
{
	int p=up,x,y,imp,band=0,band2=0,aux;
	do{
	for(p=1;p<=up;p++)
	{	
		aux=p-1;
		band2=0;
		cout<<"\n\nPasada "<<aux+1<<"\n";
		do{
			for(aux;aux>=0;aux--)
			{
				band=0;
				if(a[aux+1]<a[aux])
				{
					cout<<"\n"<<a[aux+1]<<"<"<<a[aux]<<"--V  ";
						for(imp=aux;imp<=up;imp++)
				{
					cout<<a[imp]<<" ";	
				}
					x=a[aux+1];
					y=a[aux];
					a[aux]=x;
					a[aux+1]=y;
				
				}
				else
				{
					cout<<"\n"<<a[aux+1]<<"<"<<a[aux]<<"-- F ";
					band++;
					band2++;	
				}
			}
			for(imp=0;imp<=up;imp++)
				{
					cout<<a[imp]<<" ";	
				}
		}while(band=0);
		}
	}while(band2=0);
	cout<<"\n\n";
}

void shaker(int d[],int up){
        int i,j,p=0,b,bandera=1,u=0,k,x1,y1;
        cout<<"Metodo shaker sort \n";
        
        
       for(p=0;bandera!=0;p++){
       	
        bandera=0;
        cout<<"\n Pasada "<<p+1<<"\n";
        
        
        cout<<"derecha izquierda"<<endl;
        for(j=up-u;j>u;j--){
        
        if(d[j]<d[j-1]){
		cout<<d[j]<<"<"<<d[j-1]<<"    v    ";
		x1=d[j-1];
        y1=d[j];
		d[j]=x1;
		d[j-1]=y1;
        
        for(k=0;k<=up;k++){
        cout<<d[k]<<" ";
        }
        cout<<"\n";
			  
        bandera++;
        }
        else{
        
       cout<<d[j]<<"<"<<d[j-1]<<"    f    ";
        
        for(k=0;k<=up;k++){
        cout<<d[k]<<" ";
        }
        cout<<"\n";
        
        }
      
        }
        cout<<"Izquierda a derecha"<<endl;
        for(i=u+1;i<up-u;i++){
        
         if(d[i]>d[i+1]){
	cout<<d[i]<<">"<<d[i+1]<<"    v    ";
		x1=d[i];
        y1=d[i+1];
		d[i+1]=x1;
		d[i]=y1;
			  for(k=0;k<=up;k++){
        cout<<d[k]<<" ";
        }
        cout<<"\n";
        bandera++;
        
        
        }
        else{
        
       cout<<d[i]<<">"<<d[i+1]<<"    f    ";
        
        for(k=0;k<=up;k++){
        cout<<d[k]<<" ";
        }
        cout<<"\n";
        
        
        }    
        }
        
        u++;
        
        }
        }
       

void ins(int d[],int up){
int i,p,aux=0,x,y,k,b=1;
   for(p=0;p<up;p++){
       	cout<<"\n Pasada "<<p+1<<"\n";
       b=1;
for(i=1+aux;b!=0 && i>0;i--){
if(d[i]<d[i-1]){
cout<<d[i]<<"<"<<d[i-1]<<"    v    ";
x=d[i-1];
y=d[i];

d[i]=x;
d[i-1]=y;
			  for(k=0;k<=up;k++){
        cout<<d[k]<<" ";
        }
        cout<<"\n";
}
else {

cout<<d[i]<<"<"<<d[i-1]<<"    f    ";
        
        for(k=0;k<=up;k++){
        	
        cout<<d[k]<<" ";
        }
        cout<<"\n";
        b--;
        } 
}

aux++;
}}

void insb(int d[],int up){
	
	int i,j,p,aux=0,x,y,k,j1,r;
		float div;
   for(p=0;p<up;p++){
       	cout<<"\n Pasada "<<p+1<<"\n";
       			
       	for(i=1+aux;i>0+aux;i--){
       	div=(1+i)/2;
       	r=div-1;
           
       		if(d[i]<d[r]){
               cout<<"pm"<<i+1<<"=";
         cout<<i+1<<"/2="<<div<<"\n";
         cout<<d[i]<<"<"<<d[r]<<"    v    \n";
       				for(j=0;j<i;j++){
                    if(d[i]<d[j]){    
		
     cout<<d[i]<<"<"<<d[j]<<"    v    ";	
x=d[j];
y=d[i];

d[i]=x;
d[j]=y;

	 for(k=0;k<=up;k++)
        cout<<d[k]<<" ";
        
        cout<<"\n";
        
}
else{

cout<<d[i]<<"<"<<d[j]<<"    f    ";
        
        for(k=0;k<=up;k++)
        cout<<d[k]<<" ";
        
        cout<<"\n";

}
}
}
     	else if(d[i]>d[r]){
         cout<<"pm"<<i+1<<"=";
         cout<<i+1<<"/2="<<div<<"\n";
     		for(j1=r;j1<i;j1++){
             
            
   if(d[i]>d[j1])  {
     cout<<d[i]<<"<"<<d[j1]<<"    f    ";
        
        for(k=0;k<=up;k++)
        cout<<d[k]<<" ";
        
        cout<<"\n";
     
            } 
if(d[i]<d[j1]){    
		
     cout<<d[i]<<"<"<<d[j1]<<"    v    ";	
x=d[j1];
y=d[i];

d[i]=x;
d[j1]=y;

	 for(k=0;k<=up;k++){
        cout<<d[k]<<" ";
        }
        cout<<"\n";
}

}
	 }
     
     }
       aux++;
       }
}
