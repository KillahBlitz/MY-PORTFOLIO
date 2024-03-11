#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
using namespace std;

struct Alumno {
    string nombre;
    string apellidoPaterno;
    string apellidoMaterno;
    float calificacion1;
    float calificacion2;
    float calificacion3;
    string entidadFederativa;
    char sexo;
    string fechaNacimiento;
    string curp;
    float promedio;
    Alumno* siguiente;
    Alumno* anterior;
};

struct Nodo {
    Alumno alumno;
    Nodo* siguiente;
    Nodo* anterior;
};

class ListaAlumnos {
private:
    Nodo* primero;
    Nodo* ultimo;

public:
    ListaAlumnos() : primero(nullptr), ultimo(nullptr) {}

    void agregarAlumnoDesdeTeclado() {
        Alumno nuevoAlumno;
        cout << "Ingrese nombre: ";
        cin >> nuevoAlumno.nombre;
        cout << "Ingrese apellido paterno: ";
        cin >> nuevoAlumno.apellidoPaterno;
        cout << "Ingrese apellido materno: ";
        cin >> nuevoAlumno.apellidoMaterno;
        cout << "Ingrese calificación 1: ";
        cin >> nuevoAlumno.calificacion1;
        cout << "Ingrese calificación 2: ";
        cin >> nuevoAlumno.calificacion2;
        cout << "Ingrese calificación 3: ";
        cin >> nuevoAlumno.calificacion3;
        cout << "Ingrese entidad federativa: ";
        cin >> nuevoAlumno.entidadFederativa;
        cout << "Ingrese sexo (M/F): ";
        cin >> nuevoAlumno.sexo;
        cout << "Ingrese fecha de nacimiento (DD/MM/AA): ";
        cin >> nuevoAlumno.fechaNacimiento;

        agregarAlumno(nuevoAlumno);
    }

    void agregarAlumno(Alumno nuevoAlumno) {
        Nodo* nuevoNodo = new Nodo{ nuevoAlumno, nullptr, nullptr };

        // Generar el CURP
        generarCurp(nuevoNodo);

        // Calcular promedio
        nuevoNodo->alumno.promedio = (nuevoAlumno.calificacion1 + nuevoAlumno.calificacion2 + nuevoAlumno.calificacion3) / 3;

        if (!primero) {
            primero = nuevoNodo;
            ultimo = nuevoNodo;
        } else {
            nuevoNodo->anterior = ultimo;
            ultimo->siguiente = nuevoNodo;
            ultimo = nuevoNodo;
        }
    }

    void imprimirLista() {
        Nodo* actual = primero;

        while (actual) {
            cout << "Nombre: " << actual->alumno.nombre << " " << actual->alumno.apellidoPaterno << " " << actual->alumno.apellidoMaterno
                 << ", CURP: " << actual->alumno.curp << ", Promedio: " << fixed << setprecision(2) << actual->alumno.promedio << endl;
            actual = actual->siguiente;
        }
    }

    float obtenerPromedio() {
        Nodo* actual = primero;
        float suma = 0;
        int contador = 0;

        while (actual) {
            suma += actual->alumno.promedio;
            contador++;
            actual = actual->siguiente;
        }

        return (contador != 0) ? suma / contador : 0;
    }

    Nodo* buscarPorNombreApellido(string nombre, string apellido) {
        Nodo* actual = primero;

        while (actual) {
            if (actual->alumno.nombre == nombre && actual->alumno.apellidoPaterno == apellido) {
                return actual;
            }
            actual = actual->siguiente;
        }

        return nullptr;
    }

    Nodo* buscarPorCurp(string curp) {
        Nodo* actual = primero;

        while (actual) {
            if (actual->alumno.curp == curp) {
                return actual;
            }
            actual = actual->siguiente;
        }

        return nullptr;
    }

    void ordenarPorPromedio() {
        Nodo* actual = primero;

        while (actual) {
            Nodo* siguiente = actual->siguiente;

            while (siguiente) {
                if (actual->alumno.promedio > siguiente->alumno.promedio) {
                    swap(actual->alumno, siguiente->alumno);
                }

                siguiente = siguiente->siguiente;
            }

            actual = actual->siguiente;
        }
    }

    void eliminarAlumno(Nodo* nodo) {
        if (nodo) {
            if (nodo->anterior) {
                nodo->anterior->siguiente = nodo->siguiente;
            } else {
                primero = nodo->siguiente;
            }

            if (nodo->siguiente) {
                nodo->siguiente->anterior = nodo->anterior;
            } else {
                ultimo = nodo->anterior;
            }

            delete nodo;
        }
    }

    void generarCurp(Nodo* nodo) {
        // Lógica para generar el CURP (puedes implementar tu propia lógica aquí)
        // Por simplicidad, aquí asumimos que el CURP es la concatenación de las primeras letras del nombre y apellidos.
        nodo->alumno.curp = "";
        nodo->alumno.curp += nodo->alumno.nombre.substr(0, 1);
        nodo->alumno.curp += nodo->alumno.apellidoPaterno.substr(0, 1);
        nodo->alumno.curp += nodo->alumno.apellidoMaterno.substr(0, 1);
        // Agregar más lógica si es necesario para el CURP
    }
};

int main() {
    ListaAlumnos lista;
    int opcion;

    do {
        cout << "\nMenú de Operaciones:" << endl;
        cout << "1. Generar CURP" << endl;
        cout << "2. Obtener Promedio" << endl;
        cout << "3. Buscar por Nombre y Apellido" << endl;
        cout << "4. Buscar por CURP" << endl;
        cout << "5. Ordenar por Promedio" << endl;
        cout << "6. Agregar Alumno" << endl;
        cout << "7. Eliminar Alumno" << endl;
        cout << "8. Salir" << endl;

        cout << "Ingrese la opción deseada: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
			    string nombre, apellidoPaterno;
			    cout << "Ingrese el nombre del alumno: ";
			    cin >> nombre;
			    cout << "Ingrese el apellido paterno del alumno: ";
			    cin >> apellidoPaterno;
			
			    // Otras variables necesarias para construir el CURP
			    string fechaNacimiento = "031123";  // Fecha en formato DDMMYY
			    string entidadFederativa = "HM";    // Estado de México según el catálogo de entidades federativas
			    char sexo = 'M';                    // Masculino
			
			    // Construir CURP según la lógica proporcionada
			    string curpGenerado = "";
			    curpGenerado += apellidoPaterno.substr(0, 2);  // Primeras dos letras del apellido paterno
			    curpGenerado += nombre.substr(0, 1);           // Primera letra del nombre
			    curpGenerado += fechaNacimiento;               // Agregar la fecha de nacimiento
			    curpGenerado += sexo;                          // Agregar el sexo
			    curpGenerado += entidadFederativa;             // Agregar la entidad federativa
			
			    // Mostrar el CURP generado
			    cout << "CURP generado exitosamente: " << curpGenerado << endl;
			break;

            }
            case 2:
                cout << "Promedio de los Alumnos: " << lista.obtenerPromedio() << endl;
                break;
            case 3: {
                string nombreBuscar, apellidoBuscar;
                cout << "Ingrese el nombre del alumno: ";
                cin >> nombreBuscar;
                cout << "Ingrese el apellido del alumno: ";
                cin >> apellidoBuscar;

                Nodo* alumno = lista.buscarPorNombreApellido(nombreBuscar, apellidoBuscar);
                if (alumno) {
                    cout << "Alumno encontrado:" << endl;
                    cout << "Nombre: " << alumno->alumno.nombre << " " << alumno->alumno.apellidoPaterno << " " << alumno->alumno.apellidoMaterno
                         << ", CURP: " << alumno->alumno.curp << ", Promedio: " << fixed << setprecision(2) << alumno->alumno.promedio << endl;
                } else {
                    cout << "Alumno no encontrado." << endl;
                }
                break;
            }
            case 4: {
                string curpBuscar;
                cout << "Ingrese el CURP del alumno: ";
                cin >> curpBuscar;

                Nodo* alumno = lista.buscarPorCurp(curpBuscar);
                if (alumno) {
                    cout << "Alumno encontrado:" << endl;
                    cout << "Nombre: " << alumno->alumno.nombre << " " << alumno->alumno.apellidoPaterno << " " << alumno->alumno.apellidoMaterno
                         << ", CURP: " << alumno->alumno.curp << ", Promedio: " << fixed << setprecision(2) << alumno->alumno.promedio << endl;
                } else {
                    cout << "Alumno no encontrado." << endl;
                }
                break;
            }
            case 5:
                cout << "Lista de Alumnos Ordenada por Promedio:" << endl;
                lista.ordenarPorPromedio();
                lista.imprimirLista();
                break;
            case 6:
                lista.agregarAlumnoDesdeTeclado();
                break;
            case 7: {
                string curpEliminar;
                cout << "Ingrese el CURP del alumno a eliminar: ";
                cin >> curpEliminar;

                Nodo* alumno = lista.buscarPorCurp(curpEliminar);
                if (alumno) {
                    lista.eliminarAlumno(alumno);
                    cout << "Alumno eliminado exitosamente." << endl;
                } else {
                    cout << "Alumno no encontrado." << endl;
                }
                break;
            }
            case 8:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, elija una opción del 1 al 8." << endl;
        }
    } while (opcion != 8);

    return 0;
}
