using AcessoDatos.Context;
using AcessoDatos.Models;
using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AcessoDatos.Operaciones
{
    //clase de tipo publica para que podamos trabajar con ella en el BackEnd
    public class AlumnoDAO
    {
        //inicializamos el contexto donde trabajamos para poder hacer operaciones CRUD
        public ProyectoContext context = new ProyectoContext();

        //Primer elemento, seleccionar
        //Aqui vamos a seleccionar todos los alumnos que hay en la DB
        public List<Alumno> SeleccionarTodos()
        {
            //llamamos al contexto en su atributo alumnos y lo pasamos en lista
            var Alumnos = context.Alumnos.ToList<Alumno>();
            return Alumnos;
        }

        //metodo para que seleccionemos a algun alumno
        public Alumno Seleccionar(int id)
        {
            //creamos una variable, aqui usamos entity framework, notose que 
            //se usa la condicion where y a dentro va la condicional que se debe cumplir
            //firstordefault es un metodo que devolvera el primero
            var alumno = context.Alumnos.Where(a => a.Id == id).FirstOrDefault();

            //devuelve alumno
            return alumno;
        }

        //metodo para que seleccionemos a algun alumno por el Dni, es un metodo auxiliar que se ocupara para el metodo principal
        public Alumno SeleccionarPorDni(string dni)
        {
            var alumno = context.Alumnos.Where(a => a.Dni.Equals(dni)).FirstOrDefault();

            //devuelve alumno
            return alumno;
        }

        //metodo para insertar un nuevo alumno
        public bool insertar(string dni, string nombre, string direccion, int edad, string email)
        {
            //intento si no hay error el insertar el alumno
            try
            {
                //instancio un objeto de tipo alumno y recolecto los atributos del alumno
                Alumno alumno = new Alumno();
                alumno.Dni = dni;
                alumno.Nombre = nombre;
                alumno.Direccion = direccion;
                alumno.Edad = edad;
                alumno.Email = email;

                //aniado al alumno a la base de datos
                context.Alumnos.Add(alumno);
                //IMPORTANTE guardo los cambios en la base de datos
                context.SaveChanges();
                //regreso un bool para confirmar que si inserte una nueva entidad
                return true;
            }
            catch (Exception ex)
            {
                //si hay algun error, regreso que no hice ningun cambio
                return false;
            }
        }

        //metodo para actualizar los datos de un alumno
        public bool actualizar(int id, string dni, string nombre, string direccion, int edad, string email)
        {
            try
            {
                //llamo a el metodo de seleccion para modificar los datos
                var alumno = Seleccionar(id);
                //si el alumno seleccionado no esta en la lista retorna falso 
                if (alumno == null)
                {
                    return false;
                }
                else
                {
                    //aqui cambio los atributos del alumno
                    alumno.Dni = dni;
                    alumno.Nombre = nombre;
                    alumno.Direccion = direccion;
                    alumno.Edad = edad;
                    alumno.Email = email;

                    //guardamos los cambios de lo que movimos del alumno
                    context.SaveChanges();
                }
                return true;
            }
            catch (Exception ex) //si hay algun error retornara que no se hicieron los cambios
            {
                return false;
            }
        }

        //metodo para borrar algun alumno
        public bool borrar(int id)
        {
            try
            {
                //seleccionamos al alumno que vamos a borrar
                var alumno = Seleccionar(id);
                //so el id no esta en la lista, tetorna false
                if (alumno == null)
                {
                    return false;
                }
                else
                {
                    //removemos al alumno
                    context.Alumnos.Remove(alumno);
                    //guardamos cambios
                    context.SaveChanges();
                    return true;
                }
            }
            catch (Exception ex)//si hay algun error retornara que no se hicieron los cambios
            {
                return false;
            }
        }

        //conexion entre otras tablas relacionadas con el alumno 
        //realizamos una QUERY con una sintaxis especial con entity framework
        public List<AlumnoAsignatura> seleccionarAlumnosAsignaturas() 
        {
            //analisis del query que estamos haciendo
            var query = from a in context.Alumnos //de a en contexto de alumnos
                        join m in context.Matriculas on a.Id equals m.AlumnoId //entra al contexto de matriculas con el id del alumno sea igual al id del alumno dentro del contexto matriculas
                        join asig in context.Asignaturas on m.AsignaturaId equals asig.Id //entrando a el contexto de asignatura, con el id de la asignatura siendo igual al id de la asignatura en el contexto de matriculas
                        select new AlumnoAsignatura //seleccionamos una nueva relacion de cada alumno que tenga relacion con una asignatura
                        {
                            NombreAlumno = a.Nombre, //creamos el atributo del nombre del alumno
                            NombreAsignatura = asig.Nombre //creamos el nombre de la asignatura

                        };
            return query.ToList(); //con esto acabamos el metodo, devuelve la lista del QUERY
        }

        //peticion para tener los alumnos que tiene un profesor por asignatura, analicemos el query
        public List<AlumnoProfesor> seleccionarAlumnosProfesor(string usuario)
        {

            var query = from a in context.Alumnos // en el contexto de alumnos
                        join m in context.Matriculas on a.Id equals m.AlumnoId//entra al contexto de matriculas donde el id de la matricula sea igual a el id en la matricula
                        join asig in context.Asignaturas on m.AsignaturaId equals asig.Id //en el contexto de las asignaturas, donde la el id de asignatura en las matriculas sea igual al id de la asignatura
                        where asig.Profesor == usuario //donde el profesor sea igual al usuario ingresado
                        select new AlumnoProfesor
                        {
                            Id = a.Id, //recupera el id del alumno
                            Dni = a.Dni, //su DNI
                            Nombre = a.Nombre, //su nombre
                            Direccion = a.Direccion, //su direccion
                            Edad = a.Edad, //su edad
                            Email = a.Email, //su email
                            Asignatura = asig.Nombre, //en la asignatura que esta inscrita
                            MatriculaId = m.Id
                        };

                        return query.ToList();
        }

        //metodo para insertar y matricular
        public bool insertarYMatricular(string dni, string nombre, string direccion, int edad, string email, int id_asig)
        {
            try //hacemos un try por cualquier error que pueda ocurrir
            {
                var existe = SeleccionarPorDni(dni); //aqui guardo lo que me retorne la funcion auxiliar
                if (existe == null) //si no existe la matricula ingresada entonces
                {
                    insertar(dni, nombre, direccion, edad, email); //inserto a la nueva entidad alumno
                    var insertado = SeleccionarPorDni(dni); //aqui ya existe, por tanto aqui ya puedo consultar al dni del alumno
                    Matricula m = new Matricula(); //instancio un nuevo objeto matricula
                    m.AlumnoId = insertado.Id; //paso el id del alumno
                    m.AsignaturaId = id_asig; //paso el id de la asignatura donde se aniade el alumno
                    context.Matriculas.Add(m); //aniado a la tabla
                    context.SaveChanges(); //guardo cambios
                }
                else
                {//si existe el alumno por dni
                    Matricula m = new Matricula();  //instancio un nuevo objeto matricula
                    m.AlumnoId = existe.Id; //paso el id del alumno ya existente
                    m.AsignaturaId = id_asig; //paso el id de la asignatura
                    context.Matriculas.Add(m); //aniado todo
                    context.SaveChanges(); //guardo cambios
                }

                return true;
            }
            catch (Exception ex) //por cualquier error que puede pasar
            {
                return false;
            }
        }

        public bool eliminarAlumno(int id) 
        {
            try
            {
                //aqui guardamos al alumno de acuerdo a su Id
                var alumno = context.Alumnos.Where(a => a.Id == id).FirstOrDefault();
                //confirmamos que el alumno existe 
                if (alumno != null)
                {
                    //accedemos a las matriculas del alumno
                    var matriculas = context.Matriculas.Where(m => m.AlumnoId == id);
                    //recorremos todas las matriculas asociadas con el alumno
                    foreach(Matricula m in matriculas)
                    {
                        //aqui guardamos todas las calificaciones que tiene el alumno a traves de sus matriculas
                        var calificaciones = context.Calificacions.Where(c => c.MatriculaId == m.Id);
                        //eliminamos el rango de calificaciones, osea eliminamos todas las calificaciones asociadas por cada matricula
                        context.RemoveRange(calificaciones);
                    }
                    //removemos todas las matriculas asociadas con el alumno
                    context.Matriculas.RemoveRange(matriculas);
                    context.Remove(alumno); //removemos al alumno
                    context.SaveChanges();//guardamos cambios
                    return true;
                }
                else //si el alumno no existe entonces regresamos false
                {
                    return false;
                }
            }
            catch { //uso de catch por cualquier problema
                return false; 
            }
        }
    }
}
