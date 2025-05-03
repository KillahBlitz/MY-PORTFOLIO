using AcessoDatos.Models;
using AcessoDatos.Operaciones;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace WebApi.Controllers
{
    [Route("api")]
    [ApiController]
    public class AlumnoController : ControllerBase
    {
        //crear un objeto de tipo AlumnoDAO ya que se va a ocupar
        private AlumnoDAO alumnoDAO = new AlumnoDAO();
        //crear EndPoint para que el profesor vea que alumnos tiene
        [HttpGet("alumnosProfesor")]
        //creamos el metodo que devuelve la lista de los alumnos que estan con el profesor
        public List<AlumnoProfesor> alumnoProfesor(string usuario)
        {
            return alumnoDAO.seleccionarAlumnosProfesor(usuario);
        }

        //SINTAXIS de un endpoint
        //[Httpnombredelendpoint("nombredelaruta")]

        //crear un Endpoint para ver datos particulares de un alumno
        [HttpGet("alumno")]
        //creamos el metodo que me da el alumno por id
        public Alumno getAlumno(int id)
        {
            return alumnoDAO.Seleccionar(id);
        }

        //Crear EndPoint para actualizar datos del alumno
        [HttpPut("actalumno")] //mismo nombre porque es diferente Get que Put
        public bool actualizarAlumno([FromBody]Alumno alumno) //se encapsulan los datos en el cuerpo para que sea seguro
        {
            return alumnoDAO.actualizar(alumno.Id, alumno.Dni, alumno.Nombre, alumno.Direccion, alumno.Edad, alumno.Email);
        }

        //crear EnPoint para Matricular Alumnos a una materia o crear alumnos
        [HttpPost("anadiralumno")]
        public bool insertarMatricula([FromBody]Alumno alumno,int id_asig)
        {
            return alumnoDAO.insertarYMatricular(alumno.Dni, alumno.Nombre, alumno.Direccion, alumno.Edad, alumno.Email, id_asig);
        }

        //crear EndPoint para eliminar algun alumno
        [HttpDelete("eliminaralumno")]
        public bool eliminnarAlumno(int id)
        {
            return alumnoDAO.eliminarAlumno(id);
        }
    }
}
