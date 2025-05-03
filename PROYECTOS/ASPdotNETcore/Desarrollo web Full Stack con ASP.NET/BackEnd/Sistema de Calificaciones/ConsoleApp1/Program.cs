using AcessoDatos.Models;
using AcessoDatos.Operaciones;
using Microsoft.EntityFrameworkCore.Storage;
using System.Timers;

//volvemos a hacer una inicializacion de objeto, aqui al alumno para realizar las operaciones
AlumnoDAO AlumnoOp = new AlumnoDAO();

bool MenuSaliente = true;




//creacion de un menu de interaccion.
do
{
    int opc = 0;
    Console.Clear(); // Limpia toda la consola
    Console.WriteLine("Programa Backend de CRUD");
    Console.WriteLine("Seleccione su Opcion");
    Console.WriteLine("1.Consular datos");
    Console.WriteLine("2.Consultar dato con ID");
    Console.WriteLine("3.Insertar dato");
    Console.WriteLine("4.Modificar Dato");
    Console.WriteLine("5.Eliminar Dato");
    Console.WriteLine("6.Ver Relacion de Entidades");
    Console.WriteLine("0.Salir");
    Console.Write("Seleccione la opcion: ");
    opc = int.Parse(Console.ReadLine());
    switch (opc) { 
        case 0:
            MenuSaliente = false;
            break;
        case 1:
            ListaAlumnos();
            break;
        case 2:
            ConsultaAlumno();
            break;
        case 3:
            InsertarAlumno();
            break;
        case 4:
            ModificarAlumno();
            break;
        case 5:
            EliminarAlumno();
            break;
        case 6:
            VerAlumnosAsignatura();
            break;
        default:
            MenuSaliente = false;
            break;

    }
} while (MenuSaliente);



void ListaAlumnos()
{
    Console.Clear(); // Limpia toda la consola
    //creo una variable que me guarde la lista de los alumnos
    var Alumnos = AlumnoOp.SeleccionarTodos();
    //ciclo for que me imprimira todos los alumnos que hay en la Base de Datos
    foreach (var alumno in Alumnos)
    {
        //atributos de los alumnos
        Console.WriteLine(alumno.Id);
        Console.WriteLine(alumno.Dni);
        Console.WriteLine(alumno.Nombre);
        Console.WriteLine(alumno.Edad);
        Console.WriteLine(alumno.Direccion);
        Console.WriteLine(alumno.Email);
        Console.WriteLine("\n\n");
    }
    Console.WriteLine("\n\n");
    Console.WriteLine("Presiona ENTER para continuar...");
    Console.ReadLine(); // Espera a que el usuario presione Enter
}

void ConsultaAlumno()
{
    Console.Clear(); // Limpia toda la consola
    //funcionalidad de seleccionar alumno 
    //variable bandera para salir del while
    var band = true;
    //aplicacion de condicional while
    while (band)
    {
        //ingreso el id del alumno a consultae
        Console.Write("Ingresa el ID para seleccionar: ");
        var dato = Console.ReadLine();

        //condicional que me evalua que el dato sea un numero entero
        if (int.TryParse(dato, out int numero))
        {

            //imprimir el valor que se ingreso
            Console.WriteLine($"Número válido: {numero}");
            //como retorna un valor tipo objeto Alumno, lo guardamos en la variable seleccionado
            var seleccionado = AlumnoOp.Seleccionar(numero);
            //aqui revisamos que el objeto no sea nulo para no imprimir
            if (seleccionado != null)
            {
                //imprimimos los atributos del seleccionado
                Console.WriteLine($"los datos del alumno seleccionado son: {seleccionado.Dni} {seleccionado.Nombre} {seleccionado.Edad} {seleccionado.Direccion} {seleccionado.Email}");
            }
            else
            {
                Console.WriteLine("No hay ningun alumno con ese ID.");
            }
            //salimos del ciclo while
            band = false;
        }
        else
        {
            //en caso de que se ingrese un valor incorrecto
            Console.WriteLine("Entrada no válida. No es un formato correcto.");
        }
    }
    Console.WriteLine("\n\n");
    Console.WriteLine("Presiona ENTER para continuar...");
    Console.ReadLine(); // Espera a que el usuario presione Enter
}

void InsertarAlumno()
{
    Console.Clear();
    //primero lleno los datos que voy a insertar
    Console.Write("Ingresa el DNI: ");
    string dni = Console.ReadLine();
    Console.Write("Ingresa el Nombre: ");
    string nombre = Console.ReadLine();
    Console.Write("Ingresa la Direccion: ");
    string direccion = Console.ReadLine();
    Console.Write("Ingresa la Edad: ");
    int edad = int.Parse(Console.ReadLine());
    Console.Write("Ingresa el correo: ");
    string correo = Console.ReadLine();
    //aqui inserto los datos con el metodo de insertar de mi controlador
    AlumnoOp.insertar(dni,nombre,direccion,edad,correo);

    //cargo que no hubo ningun error
    Console.WriteLine("Alumno agregado exitosamente");
    Console.WriteLine("\n\n");
    Console.WriteLine("Presiona ENTER para continuar...");
    Console.ReadLine(); // Espera a que el usuario presione Enter
}

void ModificarAlumno()
{
    Console.Clear();
    //aqui mezclo la funcion de buscar un elemento por id y luego implemento la modificacion
    var band = true;
    while (band)
    {
        //ingreso el id del alumno a consultae
        Console.Write("Ingresa el ID para seleccionar: ");
        var dato = Console.ReadLine();

        if (int.TryParse(dato, out int numero))
        {
            //como retorna un valor tipo objeto Alumno, lo guardamos en la variable seleccionado
            var seleccionado = AlumnoOp.Seleccionar(numero);
            Console.Write("Ingresa el DNI: ");
            string dni = Console.ReadLine();
            Console.Write("Ingresa el Nombre: ");
            string nombre = Console.ReadLine();
            Console.Write("Ingresa la Direccion: ");
            string direccion = Console.ReadLine();
            Console.Write("Ingresa la Edad: ");
            int edad = int.Parse(Console.ReadLine());
            Console.Write("Ingresa el correo: ");
            string correo = Console.ReadLine();
            //actualizo los datos de acuerdo al ID
            AlumnoOp.actualizar(numero, dni, nombre, direccion, edad, correo);
            band = false;
        }
        else
        {
            //en caso de que se ingrese un valor incorrecto
            Console.WriteLine("Entrada no válida. No es un formato correcto.");
        }
    }
    Console.WriteLine("\n\n");
    Console.WriteLine("Presiona ENTER para continuar...");
    Console.ReadLine(); // Espera a que el usuario presione Enter

}

void EliminarAlumno()
{
    Console.Clear();
    var band = true;
    while (band)
    {
        Console.Write("Coloca el ID del alumno que vas a eliminar: ");
        var dato = Console.ReadLine();

        //condicional que me evalua que el dato sea un numero entero
        if (int.TryParse(dato, out int numero))
        {
            AlumnoOp.borrar(numero);
            Console.Write("Alumno Eliminado Correctamente");
            //salimos del ciclo while
            band = false;
        }
        else
        {
            //en caso de que se ingrese un valor incorrecto
            Console.WriteLine("Entrada no válida. No es un formato correcto.");
        }
    }
    Console.WriteLine("\n\n");
    Console.WriteLine("Presiona ENTER para continuar...");
    Console.ReadLine(); // Espera a que el usuario presione Enter
}

void VerAlumnosAsignatura()
{
    Console.Clear();
    //creo la variable con el objeto que devuelve el metodo de alumnosasignatura
    var alumnasig = AlumnoOp.seleccionarAlumnosAsignaturas();
    Console.WriteLine("Almuno       Asignatura");
    //imprimo todas las relaciones con entidades
    foreach(AlumnoAsignatura alumno in alumnasig)
    {
        Console.WriteLine($"{alumno.NombreAlumno}   {alumno.NombreAsignatura}");
    }
    Console.WriteLine("\n\n");
    Console.WriteLine("Presiona ENTER para continuar...");
    Console.ReadLine(); // Espera a que el usuario presione Enter
}