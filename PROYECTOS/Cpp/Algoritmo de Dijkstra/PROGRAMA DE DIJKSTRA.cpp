#include <iostream>
#include <stdlib.h>
#include <climits>

using namespace std;

// Estructura para un nodo de la lista
struct nodo {
    string nombre;
    int dis[10];  // Para almacenar distancias a otros nodos
    nodo* enlace;
};

// Prototipos de funciones
void Insertar(nodo*& p, int g);
void Imprimir(nodo* p);
void IngresarDistancias(nodo* p, int cantidad);
void Dijkstra(nodo* p, int cantidad);
void subDijkstra(nodo* p, string origen, string destino, int cantidad);

int main() {
    nodo* p = NULL;
    int cantidad = 0;

    cout << "Cuantos nodos vas a ingresar? (un maximo de 10 nodos)" << endl;
    cin >> cantidad;
    for (int g = 0; g < cantidad; g++) {
        Insertar(p, g);
    }

    Imprimir(p);
    
    IngresarDistancias(p, cantidad);
    
    Dijkstra(p, cantidad);
    
    return 0;
}

// Función para insertar un nodo en la lista
void Insertar(nodo*& p, int g) {
    nodo* nuevo = new nodo;
    cout << "Ingrese el nombre del nodo " << g + 1 << ": ";
    cin >> nuevo->nombre;
    nuevo->enlace = NULL;

    if (p == NULL) {
        p = nuevo;
    } else {
        nodo* actual = p;
        while (actual->enlace != NULL) {
            actual = actual->enlace;
        }
        actual->enlace = nuevo;
    }
}

// Función para imprimir los nodos de la lista
void Imprimir(nodo* p) {
    if (p == NULL) {
        cout << "La lista está vacía." << endl;
        return;
    }

    cout << "\nElementos en la lista:" << endl;
    nodo* actual = p;
    while (actual != NULL) {
        cout << actual->nombre << " ";
        actual = actual->enlace;
    }
    cout << endl << endl;
}

// Función para ingresar distancias entre nodos
void IngresarDistancias(nodo* p, int cantidad) {
    nodo* actual = p;
    nodo* siguiente = NULL;
    int dist;

    for (int i = 0; actual != NULL; actual = actual->enlace, i++) {
        siguiente = actual->enlace;
        for (int j = i + 1; siguiente != NULL; siguiente = siguiente->enlace, j++) {
            cout << "Que distancia hay de " << actual->nombre << " hacia " << siguiente->nombre << "? ";
            cin >> dist;

            // Si la distancia es 999, indicamos que no hay conexión
            if (dist == 999) {
            	cout << "No hay conexion entre " << actual->nombre << " y " << siguiente->nombre << "." << endl;
                actual->dis[j] = 999;
                siguiente->dis[i] = 999;
            } else {
                actual->dis[j] = dist;
                siguiente->dis[i] = dist;
            }
        }
    }
    
    
     // Mostrar las distancias guardadas
    cout << "\nDistancias entre los nodos:" << endl;
    actual = p;
    for (int i = 0; actual != NULL; actual = actual->enlace, i++) {
        siguiente = actual->enlace;
        for (int j = i + 1; siguiente != NULL; siguiente = siguiente->enlace, j++) {
            cout << "Distancia de " << actual->nombre << " a " << siguiente->nombre << ": ";
            if (actual->dis[j] == 999) {
                cout << "No hay conexion" << endl;
            } else {
                cout << actual->dis[j] << endl;
            }
        }
    }
}

// Función Dijkstra
void Dijkstra(nodo* p, int cantidad) {
    string origen, destino;
    nodo* nodoOrigen = NULL;
    nodo* nodoDestino = NULL;

    while (true) {
        cout << "\nIngrese el nodo de origen: ";
        cin >> origen;
        cout << "Ingrese el nodo de destino: ";
        cin >> destino;

        nodo* actual = p;
        while (actual != NULL) {
            if (actual->nombre == origen) {
                nodoOrigen = actual;
            }
            if (actual->nombre == destino) {
                nodoDestino = actual;
            }
            actual = actual->enlace;
        }

        if (nodoOrigen == NULL || nodoDestino == NULL) {
            cout << "Error: uno o ambos nodos no existen en la lista. Intente nuevamente." << endl;
            nodoOrigen = nodoDestino = NULL;
        } else {
            break;
        }
    }

    cout << "\nNodo de origen: " << nodoOrigen->nombre << endl;
    cout << "Nodo de destino: " << nodoDestino->nombre << endl;

    // Llamamos a la función subDijkstra para ejecutar el algoritmo
    subDijkstra(p, nodoOrigen->nombre, nodoDestino->nombre, cantidad);
}

// Función subDijkstra que implementa el algoritmo de Dijkstra
void subDijkstra(nodo* p, string origen, string destino, int cantidad) {
    nodo* nodos[10];
    int dist[10];  // Distancias desde el nodo de origen
    bool visitado[10];  // Para saber si el nodo ya ha sido visitado
    int indices[10];  // Para mapear nodos a índices

    nodo* actual = p;
    int index = 0;

    // Mapear los nodos a sus índices
    while (actual != NULL) {
        nodos[index] = actual;
        indices[index] = index;
        actual = actual->enlace;
        index++;
    }

    // Inicializamos distancias con INT_MAX (infinito)
    for (int i = 0; i < cantidad; i++) {
        dist[i] = INT_MAX;
        visitado[i] = false;
    }

    // Buscamos los índices de origen y destino
    int origenIndex = -1, destinoIndex = -1;
    for (int i = 0; i < cantidad; i++) {
        if (nodos[i]->nombre == origen) {
            origenIndex = i;
        }
        if (nodos[i]->nombre == destino) {
            destinoIndex = i;
        }
    }

    // Si los nodos no existen, terminamos
    if (origenIndex == -1 || destinoIndex == -1) {
        cout << "Nodo de origen o destino no encontrado." << endl;
        return;
    }

    // La distancia del nodo origen a sí mismo es 0
    dist[origenIndex] = 0;

    // Implementación del algoritmo de Dijkstra
    for (int i = 0; i < cantidad; i++) {
        // Encontramos el nodo con la distancia mínima no visitado
        int nodoMin = -1;
        int minDist = INT_MAX;
        for (int j = 0; j < cantidad; j++) {
            if (!visitado[j] && dist[j] < minDist) {
                minDist = dist[j];
                nodoMin = j;
            }
        }

        // Si no se encuentra más nodos accesibles, terminamos
        if (nodoMin == -1) break;

        visitado[nodoMin] = true;

        // Actualizamos las distancias de los nodos vecinos
        for (int j = 0; j < cantidad; j++) {
            if (!visitado[j] && nodos[nodoMin]->dis[j] != 999) {
                int nuevaDist = dist[nodoMin] + nodos[nodoMin]->dis[j];
                if (nuevaDist < dist[j]) {
                    dist[j] = nuevaDist;
                }
            }
        }
    }

    // Mostrar la distancia más corta al nodo de destino
    if (dist[destinoIndex] == INT_MAX) {
        cout << "No hay ruta entre " << origen << " y " << destino << endl;
    } else {
        cout << "La distancia más corta de " << origen << " a " << destino << " es: " << dist[destinoIndex] << endl;
    }
}

